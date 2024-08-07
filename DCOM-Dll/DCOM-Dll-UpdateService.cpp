// Patrick Sacchet (@pjsacchet)
// Verison 1.0.
// DCOM-DLL-UpddateService.cpp : Handles all functionality in regards to the Windows update service

#include "DCOM-Dll-UpdateService.h"


// Could we spoof Windows udpates with our own malicious URLs?
BOOL handleUpdateNTLMInitialize(wchar_t* username, wchar_t* password, wchar_t* targetAddress, wchar_t* princName, wchar_t* domain, ImplantlessHandle** handle)
{
	BOOL status = SUCCESS;
	HRESULT result = S_OK;
	char msgBuf[DEFAULT_BUF_LEN];
	ImplantlessHandle* copyHandle = NULL;
	MULTI_QI results[1] = { 0 };
	long connectionFlags = 0;



	// Start COM library 
	result = CoInitializeEx(NULL, COINIT_MULTITHREADED);
	if (result != S_OK)
	{
		status = FAILURE;
		sprintf_s(msgBuf, "DCOM-Dll-update::handleUpdateNTLMInitialize - Failure recevied from CoInitializeEx %d\n", result);
		OutputDebugStringA(msgBuf);
		goto cleanup;
	}

	// We will copy over our handle struct in ctypes in our Python code and pass a pointer byref to allocate for here 
	copyHandle = (ImplantlessHandle*)malloc(sizeof(ImplantlessHandle));
	if (*handle == NULL)
	{
		status = FAILURE;
		OutputDebugStringA("DCOM-Dll-update::handleUpdateNTLMInitialize - Failed to malloc for our handle!\n");
		goto cleanup;
	}

	memset(copyHandle, 0, sizeof(ImplantlessHandle));

	// Setup target info specific to NTLM
	copyHandle->update.target.authIdentity.User = (USHORT*)username;
	copyHandle->update.target.authIdentity.UserLength = wcslen(username);
	copyHandle->update.target.authIdentity.Domain = (USHORT*)domain;
	copyHandle->update.target.authIdentity.DomainLength = wcslen(domain);
	copyHandle->update.target.authIdentity.Password = (USHORT*)password;
	copyHandle->update.target.authIdentity.PasswordLength = wcslen(password);

	copyHandle->update.target.authInfo.dwAuthnSvc = RPC_C_AUTHN_WINNT;
	copyHandle->update.target.authInfo.dwAuthzSvc = RPC_C_AUTHZ_NONE;
	copyHandle->update.target.authInfo.pwszServerPrincName = NULL;
	copyHandle->update.target.authInfo.dwAuthnLevel = RPC_C_AUTHN_LEVEL_PKT_PRIVACY;
	copyHandle->update.target.authInfo.dwImpersonationLevel = RPC_C_IMP_LEVEL_IMPERSONATE;

	copyHandle->update.target.serverInfo.pwszName = princName;

	// Store the IID we want in our MULTI_QI array
	results[0].pIID = &IID_IUpdateSession3;

	// Create the object 
	result = CoCreateInstanceEx(CLSID_UpdateAgent, NULL, CLSCTX_REMOTE_SERVER, &copyHandle->update.target.serverInfo, 1, results);
	if (result != S_OK)
	{
		sprintf_s(msgBuf, "DCOM-Dll-WinRM::handleUpdateInitialize - Failure recevied from CoCreateInstanceEx %d\n", result);
		OutputDebugStringA(msgBuf);
		status = FAILURE;
	}

	// Create UpdateDownloader
	//result = IUpdateSession3::CreateUpdateDownloader()




cleanup:
	return status;
}