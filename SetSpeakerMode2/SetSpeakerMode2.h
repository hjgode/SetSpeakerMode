#ifndef _SPEAKERMODE_H_
#define _SPEAKERMODE_H_

// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the SETSPEAKERMODE_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// SETSPEAKERMODE_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
#ifdef SETSPEAKERMODE2_EXPORTS
	#define SETSPEAKERMODE_API __declspec(dllexport)
#else
	#define SETSPEAKERMODE_API __declspec(dllimport)
#endif

SETSPEAKERMODE_API int ToggleSpeakerMode(bool);
SETSPEAKERMODE_API int ToggleSpeakerMode2(bool);

/*
// This class is exported from the SetSpeakerMode.dll
class SETSPEAKERMODE_API CSetSpeakerMode {
public:
	CSetSpeakerMode(void);
	// TODO: add your methods here.
};

extern SETSPEAKERMODE_API int nSetSpeakerMode;

SETSPEAKERMODE_API int fnSetSpeakerMode(void);
*/

//from SetSpeakerMode1.h
#include "winioctl.h"
#define FILE_DEVICE_AXVOICE         0x368
#define IOCTL_SET_PREFERRED_DEVICE       \
    CTL_CODE(FILE_DEVICE_AXVOICE,  31, METHOD_BUFFERED, FILE_ANY_ACCESS)

typedef enum
{
    SPK_NORMAL,
    SPK_SPEAKER,
    SPK_LAST        // for bounds checking
} SPEAKERMODE;

typedef HRESULT (*SHSETSPEAKERMODE) (
    SPEAKERMODE mode
);

typedef HRESULT (*SHGETSPEAKERMODE)( 
    SPEAKERMODE *pmode 
);

SHSETSPEAKERMODE  pfnSetSpeakerMode=NULL;
SHGETSPEAKERMODE  pfnGetSpeakerMode=NULL;
HINSTANCE hossvcsDll = NULL;//LoadLibrary(L"ossvcs.dll");

BOOL loadLib(){
	if(!hossvcsDll){
		hossvcsDll = LoadLibrary(L"ossvcs.dll");
		if(hossvcsDll) {
			pfnSetSpeakerMode = (SHSETSPEAKERMODE)GetProcAddress(hossvcsDll,(LPCTSTR)218);
			pfnGetSpeakerMode = (SHGETSPEAKERMODE)GetProcAddress(hossvcsDll, (LPCTSTR)217);
		}
		else
			return FALSE;
	}
	if(pfnGetSpeakerMode && pfnSetSpeakerMode){
		DEBUGMSG(1, (L"LoadLibrary OK\r\n"));
		return TRUE;
	}
	else{
		DEBUGMSG(1, (L"LoadLibrary failed\r\n"));
		return FALSE;
	}
}

void freeLib(){
	if(hossvcsDll) {
		FreeLibrary(hossvcsDll);
		pfnGetSpeakerMode=NULL;
		pfnSetSpeakerMode=NULL;
	}
}

void test(){

	HRESULT hRes=0;
	SPEAKERMODE spMode=SPK_LAST;
	if(!loadLib())
		return;
	if(pfnGetSpeakerMode){
		hRes=pfnGetSpeakerMode(&spMode);
		DEBUGMSG(1, (L"GetSpeakerMode=%i, hRes=%i\n",spMode,hRes));
	}
	else
		DEBUGMSG(1, (L"GetSpeakerMode not found!\n"));

	if(pfnSetSpeakerMode){
		hRes=pfnSetSpeakerMode(SPK_SPEAKER);
		DEBUGMSG(1, (L"SetSpeakerMode SPK_SPEAKER: hRes=%i\n",hRes));
		Sleep(3000);
		hRes=pfnSetSpeakerMode(SPK_NORMAL);
		DEBUGMSG(1, (L"SetSpeakerMode SPK_NORMAL: hRes=%i\n",hRes));
	}
	else
		DEBUGMSG(1, (L"SetSpeakerMode not found!\n"));
	freeLib();
}

HRESULT setSpeaker(SPEAKERMODE mode){
	HRESULT hRes=0;
	if(hossvcsDll) {
		if(pfnSetSpeakerMode){
			hRes=pfnSetSpeakerMode(mode);
		}
	}else
		DEBUGMSG(1, (L"setSpeaker() LoadLibrary failed\r\n"));
	freeLib();
	return hRes;
}

SETSPEAKERMODE_API int ToggleSpeakerPhone2(bool bEnable)
{
	bool bSuccess = false;
	HRESULT hRes=0;

	if(bEnable)
		hRes = setSpeaker(SPK_SPEAKER);
	else
		hRes = setSpeaker(SPK_NORMAL);
	if(hRes){
		DEBUGMSG(1, (L"ToggleSpeakerPhone2: setSpeaker() OK\r\n"));
		bSuccess=TRUE;
	}
	else
		DEBUGMSG(1, (L"ToggleSpeakerPhone2: setSpeaker() failed\r\n"));

	return bSuccess;
}


SETSPEAKERMODE_API int ToggleSpeakerPhone(bool bEnable)
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
			DEBUGMSG(1, (L"ToggleSpeakerPhone: DeviceIoControl ('WAV1:') OK\r\n"));
			bSuccess = true;
		}
		else
		{
			DEBUGMSG(1, (L"ToggleSpeakerPhone: DeviceIoControl ('WAV1:') failed\r\n"));
			bSuccess = false;
		}
		CloseHandle(hAudDecDriver); 
	}   
	else{
		DEBUGMSG(1, (L"ToggleSpeakerPhone: CreateFile ('WAV1:') failed\r\n"));
	}
	return bSuccess;
}


#endif //_SPEAKERMODE_H_