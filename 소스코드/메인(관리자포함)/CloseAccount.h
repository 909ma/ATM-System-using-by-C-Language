#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"PersonStruct.h"
#include"DeleteAccount.h"
#include"ViewAccount.h"


int CloseAccount() {
	int a = 99;
	Person* people = malloc(sizeof(Person) * 100);// 최대 100명의 사람 정보를 저장할 수 있는 배열 동적 할당
	read_csv_file("people.csv", people, a + 1);//a의 인원수를 조회 

	int InputCardNumber, InputAccountNumber, state = -1, temp;
	char concent;
	/*
	InputCardNumber : 입력된 카드번호
	InputAccountNumber : 입력된 계좌번호
	state : -1이면 검색 안 됨, 검색되면 고객 정보가 담은 그 행 번호
	consent : 해지 동의/비동의 받을 문자 변수
	temp : 해지 성공했는지 확인하는  변수
	*/
	printf("카드번호 입력\n");
	scanf("%d", &InputCardNumber);
	printf("계좌번호 입력\n");
	scanf("%d", &InputAccountNumber);

	for (int i = 1; i < a + 1; i++) {
		if (people[i].CardNumber == InputCardNumber) {
			state = i;
			if (people[state].AccountNumber == InputAccountNumber)
				break;
			else {
				state = -1;
			}
		}
	}

	if (state != -1) {
		printf("No.  BankName  BankCode  ClientCode  ClientName  CardNumber  AccountNumber   NowMoney  AccountPW  AccountDate\n");
		printf("%3d  %8s  %8d  %10d  %10s  %10d  %13d  %9d       %04d  %11d\n", state, people[state].BankName, people[state].BankCode, people[state].ClientCode, people[state].ClientName, people[state].CardNumber, people[state].AccountNumber, people[state].NowMoney, people[state].AccountPW, people[state].AccountDate);
	}
	else {
		printf("조회된 정보가 없습니다.\n");
		return 1;
	}
	while (1) {
		printf("\n해지 하시겠습니까? [Y/N]\n");
		rewind(stdin);
		scanf("%c", &concent);
		if (concent == 'N') {
			printf("해지가 거부되었습니다.\n");
			break;
		}
		else if (concent == 'Y') {
			//해지 내용 
			temp = DeleteAccount("people.csv", state);
			if (temp == 0)
				printf("해지에 성공하였습니다.\n");
			else
				printf("해지에 실패하였습니다.\n");
			break;
		}
		else
			printf("잘못된 입력입니다. Y/N 중 하나로 입력하세요\n");
	}

	free(people);// 동적 할당된 메모리 해제
	return 0;
}

