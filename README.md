# Windows-Implantless
An access and survey tool that relies on traditional authentication protocols (NTLM, Kerberos etc.) to remotely authenticate with a target and utilize Distributed Component Object Model (DCOM) methods to remotely collect off target. 


## How it Works
We will split functionality in accordance to the various Windows services and their exposed COM  objects. This way, we will allow the user to determine which service they would like to use (given proper credentials) and implement the corresponding functionality available to us via COM/DCOM.

## Services Offered
Services include:
- Windows Remote Management (WinRM) 