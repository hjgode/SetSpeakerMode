<html>
<body>
<pre>
<h1>Build Log</h1>
<h3>
--------------------Configuration: SetSpeakerMode - Win32 (WCE ARMV4I) Release--------------------
</h3>
<h3>Command Lines</h3>
Creating temporary file "G:\Temp\RSP1C3.tmp" with contents
[
/nologo /W3 /D _WIN32_WCE=500 /D "ARM" /D "_ARM_" /D "WCE_PLATFORM_CK60Prem" /D "ARMV4I" /D UNDER_CE=500 /D "UNICODE" /D "_UNICODE" /D "NDEBUG" /D "_USRDLL" /D "SETSPEAKERMODE_EXPORTS" /Fp"ARMV4IRel/SetSpeakerMode.pch" /Yu"stdafx.h" /Fo"ARMV4IRel/" /QRarch4T /QRinterwork-return /O2 /MC /c 
"D:\C-Source\test\VoiceDialer\SetSpeakerMode\SetSpeakerMode.cpp"
]
Creating command line "clarm.exe @G:\Temp\RSP1C3.tmp" 
Creating temporary file "G:\Temp\RSP1C4.tmp" with contents
[
/nologo /W3 /D _WIN32_WCE=500 /D "ARM" /D "_ARM_" /D "WCE_PLATFORM_CK60Prem" /D "ARMV4I" /D UNDER_CE=500 /D "UNICODE" /D "_UNICODE" /D "NDEBUG" /D "_USRDLL" /D "SETSPEAKERMODE_EXPORTS" /Fp"ARMV4IRel/SetSpeakerMode.pch" /Yc"stdafx.h" /Fo"ARMV4IRel/" /QRarch4T /QRinterwork-return /O2 /MC /c 
"D:\C-Source\test\VoiceDialer\SetSpeakerMode\StdAfx.cpp"
]
Creating command line "clarm.exe @G:\Temp\RSP1C4.tmp" 
Creating temporary file "G:\Temp\RSP1C5.tmp" with contents
[
commctrl.lib coredll.lib /nologo /base:"0x00100000" /stack:0x10000,0x1000 /entry:"_DllMainCRTStartup" /dll /incremental:no /pdb:"ARMV4IRel/SetSpeakerMode.pdb" /nodefaultlib:"libc.lib /nodefaultlib:libcd.lib /nodefaultlib:libcmt.lib /nodefaultlib:libcmtd.lib /nodefaultlib:msvcrt.lib /nodefaultlib:msvcrtd.lib" /def:".\SetSpeakerMode.def" /out:"ARMV4IRel/SetSpeakerMode.dll" /implib:"ARMV4IRel/SetSpeakerMode.lib" /subsystem:windowsce,5.00 /MACHINE:THUMB 
".\ARMV4IRel\SetSpeakerMode.obj"
".\ARMV4IRel\StdAfx.obj"
]
Creating command line "link.exe @G:\Temp\RSP1C5.tmp"
<h3>Output Window</h3>
Compiling...
StdAfx.cpp
c:\programme\windows ce tools\wce500\windows mobile 5.0 pocket pc sdk\include\armv4i\windbase.h(662) : warning C4068: unknown pragma
Compiling...
SetSpeakerMode.cpp
Linking...
   Creating library ARMV4IRel/SetSpeakerMode.lib and object ARMV4IRel/SetSpeakerMode.exp




<h3>Results</h3>
SetSpeakerMode.dll - 0 error(s), 1 warning(s)
</pre>
</body>
</html>
