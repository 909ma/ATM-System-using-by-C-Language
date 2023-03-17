#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"PersonStruct.h"
#include"ViewAccount.h"
#include"VoiceCheck.h"
#include"ExtraFunc.h"
#include"User_Function.h"
#include"myAccountInfo.h"//변수랑 내 계좌 조회 기능 담음
#define MAX_NUM 150

int OtherAccountInfo(int lineA,int typeA)
{
	//정보 받아옴
	read_csv_file("people.csv", people, MAX_NUM);

	//계좌 입력
	for(int i = 0; i < 3; i++)
	{
		PlaySound(TEXT(".\\BankVoice\\InputAccOrCardNum.wav"), NULL, SND_FILENAME | SND_ASYNC);
		printf("송금 받으실 분의 계좌를 입력하세요.\n");
		scanf_s("%d", &AccNum);
		checkKey(AccNum);

		if (AccNum > 999 || AccNum < 0){
			printf("입력이 잘못되었습니다.\n");
			if (i == 2){				
				printf("세 번 틀리셨습니다. 송금을 중지합니다.\n");
				return -1;//오류니까 -1 반환
			}
			continue;
		}
		break;
	}
	if (typeA == 1){//당행일 경우 typeA == 1인지 확인
		for (int i = 0; i < MAX_NUM - 1; i++){
			if (people[i].AccountNumber == AccNum){
				state2 = i;
				break;
			}
			if (i == MAX_NUM - 2) {
				printf("조회된 정보가 없습니다. 송금을 중지합니다.\n");
				return -1;
			}
		}
		if (people[lineA].BankCode != people[state2].BankCode)
		{
			printf("고객님이 이체하시는 은행과 송금하시려는 계좌의 은행이 다릅니다.\n");
			printf("송금 은행 : %s \n", &people[state2].BankName);
			printf("타행 이체로 적용됩니다. 타행 이체에는 수수료가 적용됩니다.\n");

			return OtherAccountInfo(lineA, 2);			
		}
		else
		{
			//은행 코드 검사
			printf("고객님께서 입력하신 계좌의 주인은 %s입니다.\n", people[state2].ClientName);
		}
	}
	else if (typeA == 2) {//타행 이체, typeA ==2인지 확인
		for (int i = 0; i < MAX_NUM - 1; i++){
			if (people[i].AccountNumber == AccNum){
				state2 = i;
				break;
			}
			if (i == MAX_NUM - 2) {
				printf("조회된 정보가 없습니다. 송금을 중지합니다.\n");
				return -1;
			}
		}
		if (people[lineA].BankCode == people[state2].BankCode){
			
			printf("고객님이 이체하시는 은행과 송금하시려는 계좌의 은행이 같습니다.\n");
			printf("송금 은행 : %s \n", &people[state2].BankName);
			printf("당행 이체로 적용됩니다.\n");
			return OtherAccountInfo(lineA, 1);
		}
		else
		{
			//은행 코드 검사
			printf("고객님께서 입력하신 계좌의 은행은 %s은행이고 계좌의 주인은 %s입니다.\n", people[state2].BankName, people[state2].ClientName);
		}
	}
	return state2;
}