#pragma once

#include "DCOM-Dll-Main.h"


BOOL handleNTLMLogonPlainText(unsigned char* username, unsigned char* password, unsigned char* targetAddress, unsigned char* princName, unsigned char* domain);