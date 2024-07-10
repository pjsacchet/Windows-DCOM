// Patrick Sacchet (@pjsacchet)
// Verison 1.0.
// DCOM-DLL-WinRM.cpp : Handles all functionality in regards to WinRm interaction

#include "DCOM-Dll-WinRM.h"

// Main entry point assuming the user wants to NTLM auth and use WinRM on the target box 
BOOL handleWinRMNTLMInitialize(wchar_t* username, wchar_t* password,  wchar_t* targetAddress, wchar_t* princName, wchar_t* domain, ImplantlessHandle** handle)
{
	BOOL status = SUCCESS;
	HRESULT result = S_OK;
	char msgBuf[DEFAULT_BUF_LEN];
	ImplantlessHandle* copyHandle = NULL;
	MULTI_QI results[1] = { 0 };

	// Start COM library 
	result = CoInitializeEx(NULL, COINIT_MULTITHREADED);
	if (result != S_OK)
	{
		status = FAILURE;
		sprintf_s(msgBuf, "DCOM-Dll-WinRM::handleWinRMNTLMInitialize - Failure recevied from CoInitializeEx %d\n", result);
		OutputDebugStringA(msgBuf);
		goto cleanup;
	}

	// We will copy over our handle struct in ctypes in our Python code and pass a pointer byref to allocate for here 
	copyHandle = (ImplantlessHandle*)malloc(sizeof(ImplantlessHandle));
	if (*handle == NULL)
	{
		status = FAILURE;
		OutputDebugStringA("DCOM-Dll-WinRM::handleWinRMNTLMInitialize - Failed to malloc for our handle!\n");
		goto cleanup;
	}

	memset(copyHandle, 0, sizeof(ImplantlessHandle));

	// Setup target info specific to NTLM
	copyHandle->winrm.target.authIdentity.User = (USHORT*)username;
	// user length
	copyHandle->winrm.target.authIdentity.Domain = (USHORT*)domain;
	// domain length
	copyHandle->winrm.target.authIdentity.Password = (USHORT*)password;
	// password length

	copyHandle->winrm.target.authInfo.dwAuthnSvc = RPC_C_AUTHN_WINNT;
	copyHandle->winrm.target.authInfo.dwAuthzSvc = RPC_C_AUTHZ_NONE;
	copyHandle->winrm.target.authInfo.pwszServerPrincName = NULL;
	copyHandle->winrm.target.authInfo.dwAuthnLevel = RPC_C_AUTHN_LEVEL_PKT_PRIVACY;
	copyHandle->winrm.target.authInfo.dwImpersonationLevel = RPC_C_IMP_LEVEL_IMPERSONATE;


	copyHandle->winrm.target.serverInfo.pwszName = princName;





	result = CoCreateInstanceEx(CLSID_WSMAN, NULL, CLSCTX_REMOTE_SERVER, &copyHandle->winrm.target.serverInfo, 1, results);
	if (result != S_OK)
	{
		// sad

		status = FAILURE;
	}


	*handle = copyHandle;



cleanup:
	return status;
}