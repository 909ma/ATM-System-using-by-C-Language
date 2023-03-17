#pragma once
#include <stdio.h>

//음성 출력 헤더파일과 라이브러리
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")

void checkKey(int key) {
	
	PlaySound(TEXT(".\\BankVoice\\HelloBankMenuChoice.wav"), NULL, SND_FILENAME | SND_ASYNC); //첫인사	
	
	if (key != NULL)
	{
		PlaySound(NULL, 0, 0);
		return;
	}

}


