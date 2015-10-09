//SetSpeakerMode1.h

#ifndef _SPEAKERMODE_H_
#define _SPEAKERMODE_H_

//SetSpeakerMode1.h
#include "winioctl.h"
#define FILE_DEVICE_AXVOICE         0x368
#define IOCTL_SET_PREFERRED_DEVICE       \
    CTL_CODE(FILE_DEVICE_AXVOICE,  31, METHOD_BUFFERED, FILE_ANY_ACCESS)

int WINAPI ToggleSpeakerPhone(bool bEnable)
{
	bool bSuccess = false;
	HANDLE hAudDecDriver; 
	DWORD dwCode = IOCTL_SET_PREFERRED_DEVICE; 
	DWORD dwBuffIn = 0 /*SND_DEVICE_HANDSET*/;
	if (bEnable)
	{
		dwBuffIn = 6 /*SND_DEVICE_SPEAKER_PHONE*/;
	}
	hAudDecDriver  = CreateFile(L"WAV1:",0,0,NULL,OPEN_EXISTING,0,NULL); 
	if(hAudDecDriver != INVALID_HANDLE_VALUE) 
	{ 
		if (DeviceIoControl(hAudDecDriver, dwCode, &dwBuffIn, sizeof(dwBuffIn), NULL, 0, NULL, NULL)) 
		{
			bSuccess = true;
		}
		else
		{
			bSuccess = false;
		}
		CloseHandle(hAudDecDriver); 
	}   
	return bSuccess;
}

#endif //_SPEAKERMODE_H_