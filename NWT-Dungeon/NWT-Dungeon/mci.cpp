#include <Windows.h>
#include <mmsystem.h>
#include <Digitalv.h>
#include <string>
#include "mci.h"

UINT bgmID;
UINT effectID;

void PlayBgm(LPCWSTR soundName, int volume) {
	mciSendCommand(bgmID, MCI_CLOSE, NULL, (DWORD)NULL); //RAII

	MCI_OPEN_PARMS openBgm;

	// mp3: mpegvideo, wav: waveaudio, avi: avivideo
	openBgm.lpstrDeviceType = TEXT("mpegvideo");
	openBgm.lpstrElementName = soundName;

	mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD_PTR)&openBgm);
	bgmID = openBgm.wDeviceID;

	std::wstring msg = L"setaudio " + std::wstring(soundName) + L" volume to " + std::to_wstring(volume);
	mciSendString(msg.c_str(), NULL, NULL, NULL);

	MCI_PLAY_PARMS playBgm;
	mciSendCommand(bgmID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD_PTR)&playBgm);

	// Puase
	// mciSendCommand(bgmID, MCI_PAUSE, MCI_NOTIFY, (DWORD_PTR)&playBgm);
	// Resume
	// mciSendCommand(bgmID, MCI_RESUME, NULL, NULL);
	// Close
	// mciSendCommand(bgmID, MCI_CLOSE, NULL, NULL);
}

void PlayEffect(LPCWSTR _soundname) {
	// PLAY
	MCI_PLAY_PARMS playEffect;
	if (effectID != 0) {
		mciSendCommand(effectID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD_PTR)&playEffect);
		mciSendCommand(effectID, MCI_CLOSE, NULL, (DWORD)NULL); // RAII
		effectID = 0;
	}
	// OPEN
	MCI_OPEN_PARMS openEffect;
	// mp3: mpegvideo, wav: waveaudio, avi: avivideo
	openEffect.lpstrDeviceType = TEXT("mpegvideo");
	openEffect.lpstrElementName = _soundname;
	mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD_PTR)&openEffect);
	effectID = openEffect.wDeviceID;


	mciSendCommand(effectID, MCI_PLAY, MCI_NOTIFY, (DWORD_PTR)&playEffect);
	while (mciSendCommand(effectID, MCI_STATUS, MCI_STATUS_MODE, (DWORD_PTR)&playEffect)) {
		break;
	}
}