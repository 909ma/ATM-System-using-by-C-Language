#pragma once
#pragma warning(disable:4996)

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"PersonStruct.h"
#include"ViewAccount.h"
#include"VoiceCheck.h"
#include"ExtraFunc.h"
#include"User_Function.h"
#define MAX_NUM 150
#include"passVariable.h"


int myAccountInfo()
{
	read_csv_file("people.csv", people, MAX_NUM);

	//�����Է�
	while (1)
	{
		PlaySound(TEXT(".\\BankVoice\\InputAccOrCardNum.wav"), NULL, SND_FILENAME | SND_ASYNC);
		printf("���¹�ȣ�� �Է��ϼ���.\n");
		scanf_s("%d", &inputNum);
		checkKey(inputNum);
		if (inputNum > 999 || inputNum < 100)//���¹�ȣ ����ó��
		{
			printf("���¹�ȣ�� Ʋ�Ƚ��ϴ�. �ٽ� �Է��ϼ���.\n");
			continue;
		}
		break;
	}
	PlaySound(TEXT(".\\BankVoice\\InputPw.wav"), NULL, SND_FILENAME | SND_ASYNC);
	printf("��й�ȣ�� �Է��ϼ���.\n");
	scanf_s("%d", &inputPw);
	checkKey(inputPw);

	//��й�ȣ ���� ����
	for (int i = 0; i < 3; i++)
	{
		if (inputPw > 9999 || inputPw < 0)// �ڸ� �� ���� ó��
		{
			if (i == 2)
			{
				PlaySound(TEXT(".\\BankVoice\\PwErr.wav"), NULL, SND_FILENAME | SND_ASYNC);
				printf("��й�ȣ�� 3ȸ Ʋ�Ƚ��ϴ�. �ŷ��� �Ұ��մϴ�.\n");
				return -1;//�ŷ� �Ұ� �� -1�� ������
			}
			PlaySound(TEXT(".\\BankVoice\\CheckPw.wav"), NULL, SND_FILENAME | SND_ASYNC);
			printf("��й�ȣ�� Ʋ�Ƚ��ϴ�. �ٽ� �Է��ϼ���.\n");
			scanf_s("%d", &inputPw);
			checkKey(inputPw);
			continue;
		}

		for (int j = 0; j < MAX_NUM - 1; j++) 
		{
			if (people[j].AccountNumber == inputNum)
			{
				state1 = j;
				if (people[state1].AccountPW == inputPw)//��й�ȣ ��ġ
				{
					i = 3;
					break;
				}
				else
				{
					if (i == 2)
					{
						PlaySound(TEXT(".\\BankVoice\\PwErr.wav"), NULL, SND_FILENAME | SND_ASYNC);
						printf("��й�ȣ�� 3ȸ Ʋ�Ƚ��ϴ�. �ŷ��� �Ұ��մϴ�.\n");
						return -1;//�ŷ� �Ұ� �� -1�� ������
					}
					printf("��ȸ�� ������ �����ϴ�. �ٽ� �Է��ϼ���.\n");
					scanf_s("%d", &inputPw);
					checkKey(inputPw);
				}
			}
		}


	}
	return state1;
}
