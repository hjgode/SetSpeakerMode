// SetSpeakerMode.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#include "SetSpeakerMode.h"
#include "SetSpeakerMode1.h"


BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
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

/*
// This is the constructor of a class that has been exported.
// see SetSpeakerMode.h for the class definition
CSetSpeakerMode::CSetSpeakerMode()
{ 
	return; 
}
*/
