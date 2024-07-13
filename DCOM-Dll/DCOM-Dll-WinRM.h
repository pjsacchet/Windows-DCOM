#pragma once

#include "DCOM-Dll-Main.h"

#include <wsmandisp.h>

// "WSMAN Automation Class", which implements the IWSManEx interface
GUID CLSID_WSMAN = { 0xbced617b,0xec03,0x420b,{0x85,0x08,0x97,0x7d,0xc7,0xa6,0x86,0xbd} };
GUID IID_IWSManEx = { 0x2d53bdaa,0x798e,0x49e6,{0xa1,0xaa,0x74,0xd0,0x12,0x56,0xf4,0x11} };

BOOL handleWinRMNTLMInitialize(wchar_t* username, wchar_t* password, wchar_t* targetAddress, wchar_t* princName, wchar_t* domain, ImplantlessHandle** handle);

