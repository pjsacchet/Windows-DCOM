// Patrick Sacchet (@pjsacchet)
// Verison 1.0.
// Implantless-DLL-Main.cpp : Handles initialization of our handle and initial connection stuff 

#include "DCOM-Dll-Main.h"

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


/* Our initial 'startup' function which will initialize our handle and perform initial socket work to port 135 to talk to the target's RPC endpoint mapper 
    or subsequent calls, the handle will serve to store the highport for the service/object we need to talk to 
*/
BOOL handleImplantlessStartup()
{
    BOOL status = SUCCESS;

    


cleanup:
    return status;
}