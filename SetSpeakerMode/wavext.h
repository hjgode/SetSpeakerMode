//
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
//
// Use of this source code is subject to the terms of the Microsoft end-user
// license agreement (EULA) under which you licensed this SOFTWARE PRODUCT.
// If you did not accept the terms of the EULA, you are not authorized to use
// this source code. For a copy of the EULA, please see the LICENSE.RTF on your
// install media.
//
//------------------------------------------------------------------------------
//
//  File:  wavext.h
//
#ifndef __WAVEXT_H
#define __WAVEXT_H

#ifdef __cplusplus
extern "C" {
#endif

//------------------------------------------------------------------------------
// Extensions to Wave driver

#define FILE_DEVICE_AXVOICE         0x368

#define IOCTL_CMSI_AUDIO_INFO_SET   \
    CTL_CODE(FILE_DEVICE_AXVOICE,   5, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_CMSI_AUDIO_INFO_GET   \
    CTL_CODE(FILE_DEVICE_AXVOICE,   6, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_GSM_CALL_ACTIVE       \
    CTL_CODE(FILE_DEVICE_AXVOICE,   7, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_GSM_CALL_INACTIVE     \
    CTL_CODE(FILE_DEVICE_AXVOICE,   8, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_NOTIFY_HEADSET        \
    CTL_CODE(FILE_DEVICE_AXVOICE,  10, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_TOGGLE_EXT_SPEAKER    \
    CTL_CODE(FILE_DEVICE_AXVOICE,  11, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_NOTIFY_BT_HEADSET     \
    CTL_CODE(FILE_DEVICE_AXVOICE,  12, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_START_AMR_CAPTURE     \
    CTL_CODE(FILE_DEVICE_AXVOICE,  13, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_STOP_AMR_CAPTURE      \
    CTL_CODE(FILE_DEVICE_AXVOICE,   14, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_EAC_INFO_SET      \
    CTL_CODE(FILE_DEVICE_AXVOICE,   20, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_EAC_INFO_GET      \
    CTL_CODE(FILE_DEVICE_AXVOICE,   21, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_GSM_RESTARTED         \
    CTL_CODE(FILE_DEVICE_AXVOICE,  22, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_NOTIFY_HDMI         \
    CTL_CODE(FILE_DEVICE_AXVOICE,  23, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_NOTIFY_FMTX         \
    CTL_CODE(FILE_DEVICE_AXVOICE,  24, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_NOTIFY_FMRX         \
    CTL_CODE(FILE_DEVICE_AXVOICE,  25, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_NOTIFY_AUDIOMODE \
    CTL_CODE(FILE_DEVICE_AXVOICE,  26, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_VIBRATOR_CONTROL \
    CTL_CODE(FILE_DEVICE_AXVOICE,  27, METHOD_BUFFERED, FILE_ANY_ACCESS)



//------------------------------------------------------------------------------
// Audio Mode
#define AUDIOMODE_DEFAULT       (0)
#define AUDIOMODE_HANDSET       (1 << 0)        // 0x00000001
#define AUDIOMODE_HEADSET       (1 << 1)        // 0x00000002
#define AUDIOMODE_CARKIT        (1 << 2)        // 0x00000004
#define AUDIOMODE_SPEAKER       (1 << 3)        // 0x00000008
#define AUDIOMODE_BTHEADSET     (1 << 4)        // 0x00000010
#define AUDIOMODE_USB           (1 << 5)        // 0x00000020
#define AUDIOMODE_HDMI          (1 << 6)        // 0x00000040
#define AUDIOMODE_FM_TX         (1 << 7)        // 0x00000080
#define AUDIOMODE_FM_RX         (1 << 8)        // 0x00000100
#define AUDIOMODE_MAINMIC       (1 << 9)        // 0x00000200
#define AUDIOMODE_SUBMIC        (1 << 10)       // 0x00000400
#define AUDIOMODE_HEADSETMIC    (1 << 11)       // 0x00000800
#define AUDIOMODE_AUX           (1 << 12)       // 0x00001000
#define AUDIOMODE_VIBRATOR      (1 << 13)       // 0x00002000
#define AUDIOMODE_SPKR_DMIC     (1 << 14)       // 0x00004000
#define AUDIOMODE_OFF           (1 << 31)       // 0x80000000

//------------------------------------------------------------------------------
// IOCTL_NOTIFY_BT_HEADSET defines

#define BT_AUDIO_NONE       0x00000000      // No audio routed to BT device
#define BT_AUDIO_SYSTEM     0x00000001      // System audio routed to BT device
#define BT_AUDIO_MODEM      0x00000002      // Modem audio routed to/from BT device

//------------------------------------------------------------------------------
// Supported Sampling Rates
#define SAMPLING_RATE_8000              8000
#define SAMPLING_RATE_11025             11025
#define SAMPLING_RATE_12000             12000
#define SAMPLING_RATE_16000             16000
#define SAMPLING_RATE_22050             22050
#define SAMPLING_RATE_24000             24000
#define SAMPLING_RATE_32000             32000
#define SAMPLING_RATE_44100             44100
#define SAMPLING_RATE_48000             48000
#define SAMPLING_RATE_88200             88200
#define SAMPLING_RATE_96000             96000

//------------------------------------------------------------------------------
// Supported Audio channel
#define  AUDIO_MONO                     1
#define  AUDIO_STEREO                   2
#define  AUDIO_LEFT                     3
#define  AUDIO_RIGHT                    4


//------------------------------------------------------------------------------
// WAV Message used to inform the audio stream to enable filter processing
//
// Example: MM_WOM_WAVEFILTER_ENABLE
// wParam1 = valid wave filter id
// wParam2 = TRUE or FALSE
#define MM_WOM_WAVEFILTER_ENABLE     (WM_USER + 10)
#define MM_WIM_WAVEFILTER_ENABLE     (WM_USER + 11)


//------------------------------------------------------------------------------
// WAV Filter Message used to send message to the wave filter components
//
// wParam1 = pointer to the WAVE_FILTER_MSG structure
// wParam2 = size of WAVE_FILTER_MSG structure
#define MM_WOM_WAVEFILTER_MSG       (WM_USER + 12)
#define MM_WIM_WAVEFILTER_MSG       (WM_USER + 13)

//------------------------------------------------------------------------------
// WAV Filter Message structure used in MM_WOM_WAVEFILTER_MSG message

typedef struct
{
    DWORD msgType;
    BYTE *pInParam;
    DWORD  nInsize;
    BYTE *pOutParam;
    DWORD  nOutsize;
    PDWORD pdwActualOutSize;
} WAVE_FILTER_MSG;


//------------------------------------------------------------------------------
// CMSI audio settings

typedef struct __CMSI_AUDIO_SETTING {
    BYTE fUpLink;       // true = uplink
    BYTE fMute;         // true = mute
    BYTE bVolume;       // volume (0-128)
} CMSI_AUDIO_SETTING, *PCMSI_AUDIO_SETTING;


//------------------------------------------------------------------------------
// EAC audio settings

typedef struct __EAC_AUDIO_SETTING {
    // EAC control bits
    WORD    S;      // sidetone attenuation
    BOOL    K[12];  // switch Kn
    WORD    DMAVOL; // DMA capture volume
    WORD    M[3];   // Mixer n, att A,B
    // modem control bits

} EAC_AUDIO_SETTING, *PEAC_AUDIO_SETTING;


//------------------------------------------------------------------------------
// Audio configuration
typedef struct {
    BOOL                bEnable;
    DWORD               ffAudioMode;
} AudioModeConfigInfo;

//------------------------------------------------------------------------------
// Vibrator configuration
#define VIBRATOR_MAX_PWM_LEVEL 100
typedef struct {
    BOOL                bEnable;
    BYTE                byPWMLevel;
    BYTE                reserved[3];
} VibratorConfigInfo;

//------------------------------------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif
