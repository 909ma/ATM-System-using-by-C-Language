#pragma once
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"PersonStruct.h"
#include"ViewAccount.h"
#include"VoiceStruct.h"
#include"ExtraFunc.h"
#include"User_Function.h"
#include"myAccountInfo.h"//변수랑 내 계좌 조회 기능 담음
#include"OtherAccountInfo.h"
#include"passVariable.h"
#define MAX_NUM 150

void passCash(state1, state2){
	read_csv_file("people.csv", people, MAX_NUM);
	printf("송금하실 금액을 입력하세요.\n");
	scanf_s("%d", &depositMoney);
	
	if (people[state1].BankCode != people[state2].BankCode) {//타행 이체, 수수료 1,000원
		if (depositMoney <= 0 || depositMoney+1000 > people[state1].NowMoney) {
			printf("입력이 잘못되었습니다. 입력하신 금액이 없거나 보유 잔액보다 큽니다.\n");
			printf("다시 입력해주세요.\n");
			return passCash(state1, state2);
		}
		people[state1].NowMoney -= (depositMoney + 1000);//보내는 계좌에서 돈이 빠짐
		people[state2].NowMoney += (depositMoney + 1000);//받는 계좌에 돈이 늘어남		
	}
	else{//당행 이체, 수수료 0원
		if (depositMoney <= 0 || depositMoney > people[state1].NowMoney) {
			printf("입력이 잘못되었습니다. 입력하신 금액이 없거나 보유 잔액보다 큽니다.\n");
			printf("다시 입력해주세요.\n");

			return passCash(state1, state2);
		}
		people[state1].NowMoney -= depositMoney;
		people[state2].NowMoney += depositMoney;
	}
	int line = getTotalLine("people.csv");

	printf("입력하신 %s %d계좌의 %s 님께 송금하시겠습니까?\n", &people[state2].BankName, &people[state2].AccountNumber, &people[state2].ClientName);
	printf("%d. 예\n", yes);
	printf("%d. 아니오\n", no);

	int yn;

	scanf_s("%d", &yn);
	if (yn == yes)
	{
		SaveData("people.csv", people, line);
		printf("\n<이체 후 잔액 : %d원>\n", people[state1].NowMoney);
		printf("송금이 완료되었습니다. 이용해주셔서 감사합니다.\n");
	}
	else if (yn == no)
	{
		printf("송금이 취소되었습니다.\n");
		printf("이용해주셔서 감사합니다.\n");
	}
}

