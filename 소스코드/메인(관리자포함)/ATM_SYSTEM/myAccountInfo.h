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

	//계좌입력
	while (1)
	{
		PlaySound(TEXT(".\\BankVoice\\InputAccOrCardNum.wav"), NULL, SND_FILENAME | SND_ASYNC);
		printf("계좌번호를 입력하세요.\n");
		scanf_s("%d", &inputNum);
		checkKey(inputNum);
		if (inputNum > 999 || inputNum < 100)//계좌번호 예외처리
		{
			printf("계좌번호가 틀렸습니다. 다시 입력하세요.\n");
			continue;
		}
		break;
	}
	PlaySound(TEXT(".\\BankVoice\\InputPw.wav"), NULL, SND_FILENAME | SND_ASYNC);
	printf("비밀번호를 입력하세요.\n");
	scanf_s("%d", &inputPw);
	checkKey(inputPw);

	//비밀번호 오류 검증
	for (int i = 0; i < 3; i++)
	{
		if (inputPw > 9999 || inputPw < 0)// 자리 수 예외 처리
		{
			if (i == 2)
			{
				PlaySound(TEXT(".\\BankVoice\\PwErr.wav"), NULL, SND_FILENAME | SND_ASYNC);
				printf("비밀번호가 3회 틀렸습니다. 거래가 불가합니다.\n");
				return -1;//거래 불가 시 -1을 돌려줌
			}
			PlaySound(TEXT(".\\BankVoice\\CheckPw.wav"), NULL, SND_FILENAME | SND_ASYNC);
			printf("비밀번호가 틀렸습니다. 다시 입력하세요.\n");
			scanf_s("%d", &inputPw);
			checkKey(inputPw);
			continue;
		}

		for (int j = 0; j < MAX_NUM - 1; j++) 
		{
			if (people[j].AccountNumber == inputNum)
			{
				state1 = j;
				if (people[state1].AccountPW == inputPw)//비밀번호 일치
				{
					i = 3;
					break;
				}
				else
				{
					if (i == 2)
					{
						PlaySound(TEXT(".\\BankVoice\\PwErr.wav"), NULL, SND_FILENAME | SND_ASYNC);
						printf("비밀번호가 3회 틀렸습니다. 거래가 불가합니다.\n");
						return -1;//거래 불가 시 -1을 돌려줌
					}
					printf("조회된 정보가 없습니다. 다시 입력하세요.\n");
					scanf_s("%d", &inputPw);
					checkKey(inputPw);
				}
			}
		}


	}
	return state1;
}
