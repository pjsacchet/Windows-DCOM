# Patrick Sacchet
# Main functionality for user input and corresponding DLL calls

import ctypes

# Assume path to DLL is relative if user cloned our repo without structural changes 
    # TODO: ask user for arch build and debug or release to get proper directory 
def getDll():
    dcom_functions = ctypes.cdll.LoadLibrary("..\\DCOM-Dll\\x64\\Debug\\DCOM-Dll.dll")
    return dcom_functions 


def main():
    dcom_functions = getDll()
    
    # Parse input from user 
    



    print(dcom_functions.handleImplantlessStartup())



if __name__ == '__main__':
    main()
