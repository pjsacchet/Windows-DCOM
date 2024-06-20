#pragma once

#include "DCOM-Dll-Main.h"


BOOL handleNTLMLogonPlainText(unsigned char* username, unsigned char* password, char* targetAddress, char* princName, unsigned char* domain);