// Patrick Sacchet (@pjsacchet)
// Verison 1.0.
// DCOM-DLL-NTLM.cpp : Handles NTLM creds and setup for RPC things 

#include "DCOM-Dll-NTLM.h"


BOOL handleNTLMLogonPlainText(char* username, char* password, char* targetAddress)
{
	BOOL status = TRUE;
	CHAR msgBuf[DEFAULT_BUF_LEN];
	RPC_BINDING_HANDLE bind;
	RPC_CSTR serverPrincName;
	//RPC_AUTH_IDENTITY_HANDLE identityHandle;
	SEC_WINNT_AUTH_IDENTITY identityHandle;
	DWORD authLevel, authServ;
	RPC_BINDING_HANDLE_TEMPLATE_V1_A bindingTemplate;
	//RPC_BINDING_HANDLE_SECURITY_V1_A bindingSecurity;
	//RPC_BINDING_HANDLE_OPTIONS_V1 bindingOptions;




	 
	// should set AuthIdentity to pointer to SEC_WINNT_AUTH_IDENTITY if using NTLM

	// Highest encryption level; total encryption and packet verification 
	authLevel = RPC_C_AUTHN_LEVEL_PKT_PRIVACY;

	// Uses NT LAN Manager SSP
	authServ = RPC_C_AUTHN_WINNT;

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

	// Set security options
	//status = RpcBindingSetAuthInfo(&bind, )



	// Put it all together!
	// status = RpcBindingBind



	// And connect...

cleanup:
	return status;
}