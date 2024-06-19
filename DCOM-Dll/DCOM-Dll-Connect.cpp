// Patrick Sacchet (@pjsacchet)
// Verison 1.0.
// DCOM-DLL-Main.cpp : Handles connect info, i.e., identifies connect type and calls appropiate funcitonality 


#include "DCOM-Dll-Connect.h"

/* Our initial 'startup' function which will initialize our handle and perform initial socket work to port 135 to talk to the target's RPC endpoint mapper
    or subsequent calls, the handle will serve to store the highport for the service/object we need to talk to
*/
BOOL handleImplantlessStartup()
{
    BOOL status = SUCCESS;

   


cleanup:
    return status;
}