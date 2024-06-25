// Patrick Sacchet (@pjsacchet)
// Verison 1.0.
// DCOM-DLL-NTLM.cpp : Handles NTLM creds and setup for RPC things 

#include "DCOM-Dll-NTLM.h"


BOOL handleNTLMLogonPlainText(unsigned char* username, unsigned char* password, unsigned char* targetAddress, unsigned char* princName, unsigned char* domain)
{
	BOOL status = TRUE;
	HRESULT result = S_OK;
	CHAR msgBuf[DEFAULT_BUF_LEN];
	COSERVERINFO serverInfo = { 0 };
	COAUTHINFO authInfo = { 0 };
	// Object we're using 
	REFCLSID clsid = { 0 };



	// Set our auth to NTLM (should be default anyway)
	authInfo.dwAuthnSvc = RPC_C_AUTHN_WINNT;
	authInfo.dwAuthzSvc = RPC_C_AUTHZ_NONE;

	// Remotely create our object 
	//status = CoCreateInstanceEx
	
	



cleanup:
	return status;
}