//SetSpeakerMode1.h

#ifndef _SPEAKERMODE_H_
#define _SPEAKERMODE_H_

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
	if(pfnGetSpeakerMode && pfnSetSpeakerMode)
		return TRUE;
	else
		return FALSE;
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
}

HRESULT setSpeaker(SPEAKERMODE mode){
	HRESULT hRes=0;
	if(hossvcsDll) {
		if(pfnSetSpeakerMode){
			hRes=pfnSetSpeakerMode(mode);
		}
	}
	return hRes;
}

int WINAPI ToggleSpeakerPhone(bool bEnable)
{
	bool bSuccess = false;
	HRESULT hRes=0;

	if(bEnable)
		hRes = setSpeaker(SPK_SPEAKER);
	else
		hRes = setSpeaker(SPK_NORMAL);
	if(hRes)
		bSuccess=TRUE;

	return bSuccess;
}

#endif //_SPEAKERMODE_H_