# Patrick Sacchet
# File serves to implement our structs as defined in our DLL

from ctypes import *

# Struct for COAUTHIDENTITY
'''
typedef struct _COAUTHIDENTITY
    {
    /* [size_is] */ USHORT *User;
    /* [range] */ ULONG UserLength;
    /* [size_is] */ USHORT *Domain;
    /* [range] */ ULONG DomainLength;
    /* [size_is] */ USHORT *Password;
    /* [range] */ ULONG PasswordLength;
    ULONG Flags;
    } 	COAUTHIDENTITY;
'''
class COAUTHIDENTITY(Structure):
    __fields__ = [
        ("User", POINTER(c_ushort)),
        ("UserLength", c_ulong),
        ("Domain", POINTER(c_short)),
        ("DomainLength", c_ulong),
        ("Password", POINTER(c_ushort)),
        ("PasswordLength", c_ulong),
        ("Flags", c_ulong)
    ]

# Struct for COAUTHINFO
'''
typedef struct _COAUTHINFO
    {
    DWORD dwAuthnSvc;
    DWORD dwAuthzSvc;
    LPWSTR pwszServerPrincName;
    DWORD dwAuthnLevel;
    DWORD dwImpersonationLevel;
    COAUTHIDENTITY *pAuthIdentityData;
    DWORD dwCapabilities;
    } 	COAUTHINFO;'''
class COAUTHINFO(Structure):
    __fields__ = [
        ("dwAuthnSvc", c_ulong),
        ("dwAuthzSvc", c_ulong),
        ("pwszServerPrincName", POINTER(c_short)),
        ("dwAuthnLevel", c_ulong),
        ("dwImpersonationLevel", c_ulong),
        ("pAuthIdentityData", POINTER(COAUTHIDENTITY)),
        ("dwCapabilities", c_ulong)
    ]

# Struct for COSERVERINFO 
'''
typedef struct _COSERVERINFO
    {
    DWORD dwReserved1;
    LPWSTR pwszName;
    COAUTHINFO *pAuthInfo;
    DWORD dwReserved2;
    } 	COSERVERINFO;'''
class COSERVERINFO(Structure):
    __fields__ = [

    ]

# Struct for WinRM 
'''
typedef struct WinRM
{
	targetInfo target;
};'''
class WinRM(Structure):
    __fields__ = [

    ]

# Struct for our ImplantlessHandle 
'''
typedef struct ImplantlessHandle
{
	WinRM winrm;
}PImplantlessHandle;'''
class ImplantlessHandle(Structure):
    __fields__ = [

    ]
