// Patrick Sacchet (@pjsacchet)
// Verison 1.0.
// DCOM-DLL-NTLM.cpp : Handles NTLM creds and setup for RPC things 

#include "DCOM-Dll-NTLM.h"


BOOL handleNTLMLogonPlainText(char* username, char* password)
{
	BOOL status = TRUE;
	RPC_BINDING_HANDLE bind;
	RPC_CSTR serverPrincName;
	//RPC_AUTH_IDENTITY_HANDLE identityHandle;
	SEC_WINNT_AUTH_IDENTITY identityHandle;
	DWORD authLevel, authServ;

	 
	// should set AuthIdentity to pointer to SEC_WINNT_AUTH_IDENTITY if using NTLM

	// Highest encryption level; total encryption and packet verification 
	authLevel = RPC_C_AUTHN_LEVEL_PKT_PRIVACY;

	// Uses NT LAN Manager SSP
	authServ = RPC_C_AUTHN_WINNT;

	// Create our binding 
	//status = RpcBindingCreateA();




	// Put it all together!
	// status = RpcBindingSetAuthInfo



	// And connect...

cleanup:
	return status;
}