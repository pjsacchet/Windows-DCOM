// Patrick Sacchet (@pjsacchet)
// Verison 1.0.
// Implantless-DLL-Main.cpp : Handles initialization of our handle and initial connection stuff 

#include "DCOM-Dll-Main.h"

// Flesh this out for local testing functionality/debugger
BOOL APIENTRY DllMain( HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
        case DLL_PROCESS_ATTACH:
        case DLL_THREAD_ATTACH:
        case DLL_THREAD_DETACH:
        case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}


