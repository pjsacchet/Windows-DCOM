# Windows-Implantless
An access and survey tool that relies on traditional authentication protocols (NTLM, Kerberos etc.) to remotely authenticate with a target and utilize Distributed Component Object Model (DCOM) methods to remotely collect off target. 

## Potential DCOM Objects
Interesting COM objects with an AppID associated with them (we can create remotely):
- Immersive Shell {C2F03A33-21F5-47FA-B4BB-156362A2F239}
  - IServiceProvider {6D5140C1-7436-11CE-8034-00AA006009FA} --> GetServices() (.NET?)
