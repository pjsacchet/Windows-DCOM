// Patrick Sacchet (@pjsacchet)
// Verison 1.0.
// DCOM-DLL-NTLM.cpp : Handles NTLM creds and setup for RPC things 

#include "DCOM-Dll-NTLM.h"


BOOL handleNTLMLogonPlainText(unsigned char* username, unsigned char* password, char* targetAddress, char* princName, unsigned char* domain)
{
	BOOL status = TRUE;
	CHAR msgBuf[DEFAULT_BUF_LEN];
	RPC_BINDING_HANDLE bind;
	RPC_CSTR serverPrincName;
	SEC_WINNT_AUTH_IDENTITY_A identityHandle;
	RPC_BINDING_HANDLE_TEMPLATE_V1_A bindingTemplate;

	 
	// should set AuthIdentity to pointer to SEC_WINNT_AUTH_IDENTITY if using NTLM

	
	

	// Create template
	bindingTemplate.Version = 1;
	bindingTemplate.Flags = 0;
	bindingTemplate.ProtocolSequence = RPC_PROTSEQ_TCP; // remote machine 
	bindingTemplate.NetworkAddress = (unsigned char*)targetAddress;
	bindingTemplate.StringEndpoint = NULL;
	bindingTemplate.ObjectUuid = GUID_NULL; // need to set ourselves?

	// Create our binding 
		// security and options are optional so we'll set these in separate call
	status = RpcBindingCreateA(&bindingTemplate, NULL, NULL, &bind);
	if (status != RPC_S_OK)
	{
		sprintf_s(msgBuf, "DCOM-Dll-NTLM::handleNTLMLogonPlainText - Failed to create binding! Error %d\n", status);
		OutputDebugStringA(msgBuf);
		goto cleanup;
	}

	identityHandle.User = username;
	identityHandle.UserLength = strlen((const char*)username);
	identityHandle.Domain = domain;
	identityHandle.DomainLength = strlen((const char*)domain);
	identityHandle.Password = password;
	identityHandle.PasswordLength = strlen((const char*)password);
	identityHandle.Flags = SEC_WINNT_AUTH_IDENTITY_ANSI;


	// Set security options
		// Highest encryption level; total encryption and packet verification 
		// Uses NT LAN Manager SSP
	status = RpcBindingSetAuthInfoA(&bind, (RPC_CSTR)princName, RPC_C_AUTHN_LEVEL_PKT_PRIVACY, RPC_C_AUTHN_WINNT, (RPC_AUTH_IDENTITY_HANDLE)&identityHandle, NULL);
	if (status != RPC_S_OK)
	{
		sprintf_s(msgBuf, "DCOM-Dll-NTLM::handleNTLMLogonPlainText - Failed to set auth info! Error %d\n", status);
		OutputDebugStringA(msgBuf);
		goto cleanup;
	}



	// Put it all together!
	// status = RpcBindingBind



	// And connect...

cleanup:
	return status;
}