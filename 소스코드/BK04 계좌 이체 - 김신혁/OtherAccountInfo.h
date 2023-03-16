#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"PersonStruct.h"
#include"ViewAccount.h"
#include"PrintBankCode.h"
#include"VoiceStruct.h"
#include"ExtraFunc.h"
#include"User_Function.h"
#include"myAccountInfo.h"//변수랑 내 계좌 조회 기능 담음
#define MAX_NUM 150
int OtherAccountInfo(int lineA,int typeA){
	read_csv_file("people.csv", people, MAX_NUM);//정보 받아옴
	for(int i = 0; i < 3; i++){//계좌 입력
		printf("송금 받으실 분의 계좌를 입력하세요.\n");
		scanf_s("%d", &AccNum);
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
		if (people[lineA].BankCode != people[state2].BankCode){
			printf("당행 이체에서는 송금 하실 수 없는 계좌입니다.\n");
			return -1;
		}//은행 코드 검사
		printf("고객님께서 입력하신 계좌의 주인은 %s입니다.\n", people[state2].ClientName);
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
			printf("타행 이체에서는 송금 하실 수 없는 계좌입니다.\n");
			return -1;
		}//은행 코드 검사
		printf("고객님께서 입력하신 계좌의 은행은 %s은행이고 계좌의 주인은 %s입니다.\n", people[state2].BankName, people[state2].ClientName);
	}
	return state2;
}