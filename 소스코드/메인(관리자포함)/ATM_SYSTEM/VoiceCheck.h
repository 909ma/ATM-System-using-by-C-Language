#pragma once
#include <stdio.h>

//���� ��� ������ϰ� ���̺귯��
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")

void checkKey(int key) {
	
	PlaySound(TEXT(".\\BankVoice\\HelloBankMenuChoice.wav"), NULL, SND_FILENAME | SND_ASYNC); //ù�λ�	
	
	if (key != NULL)
	{
		PlaySound(NULL, 0, 0);
		return;
	}

}


