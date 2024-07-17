#pragma once

// Windows Header Files
#include <windows.h>
#include <winsock.h>
#include <rpcdce.h>
#include <stdio.h>

#pragma comment(lib, "rpcrt4.lib") 

#define SUCCESS 1
#define FAILURE 0

const INT DEFAULT_BUF_LEN = 512;


// Maybe split these up by service we're using...
	// WinRM
	// SMB?


typedef struct targetInfo
{
	COSERVERINFO serverInfo;
	COAUTHINFO authInfo;
	COAUTHIDENTITY authIdentity; 
};


typedef struct WinRM
{
	targetInfo target;
};



// Define our own 'handle' we'll be passing around this tool and updating as needed
typedef struct ImplantlessHandle
{
	WinRM winrm;
}PImplantlessHandle;