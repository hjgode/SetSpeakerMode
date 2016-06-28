
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
