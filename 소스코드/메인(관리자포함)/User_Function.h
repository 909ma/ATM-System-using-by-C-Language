#pragma once
#pragma	warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"ExtraFunc.h"
#include"PersonStruct.h"

void SaveData(char* filename, Person* people, int max) //출금 후 수정된 잔액 정보로 재저장
{
	FILE* fp = fopen(filename, "w");
	if (fp == NULL) {
		printf("File open error!\n");
		return;
	}
	fprintf(fp, "BankName,BankCode,ClientCode,ClientName,CardNumber,AccountNumber,NowMoney,AccountPW,AccountDate\n");
	if (people->BankName != NULL)
	{

		for (int i = 0; i < max - 1; i++, people++)
		{
			fprintf(fp, "%s,%d,%d,%s,%d,%d,%d,%d,%d\n", people->BankName, people->BankCode, people->ClientCode, people->ClientName, people->CardNumber, people->AccountNumber, people->NowMoney, people->AccountPW, people->AccountDate);
		}
	}
	printf("저장완료\n\n");

	fclose(fp);
}
void deposit_func(char* filename, Person* people, int max)
{
	int AccNum;
	int depositMoney;
	int findAcc = 0;
	int AccountNumber, NowMoney;
	read_csv_file(filename, people, max - 1);

	do
	{
	REDEP:
		printf("\n입금할 계좌번호 입력: ");
		scanf("%d", &AccNum);
		for (int i = 0; i < max - 1; i++)
		{
			if (people[i].AccountNumber == AccNum) // 고객의 계좌번호와 입력한 계좌번호가 일치한 경우
			{
				findAcc = 1;
			RE:
				printf("\n입금하실 금액을 입력하시오 : ");
				scanf("%d", &depositMoney);

				if (voicefishing() == 1)
					exit(0);
				people[i].NowMoney += depositMoney;
				printf("\n<입금 후 잔액 : %d원>\n", people[i].NowMoney);
			}
		}
		
		if (!findAcc) {
			printf("\n입력한 계좌번호가 존재하지 않습니다.\n");
			goto REDEP;
		}
	} while (findAcc == 0);

}
void withdraw_func(char* filename, Person* people, int max)
{
	int AccNum;
	int withdrawMoney;
	int FindAcc = 0;
	int AccountNumber, AccountPW, NowMoney;
	read_csv_file(filename, people, max - 1);

	do
	{
	REWITH:
		printf("\n출금할 계좌번호 입력: ");
		scanf("%d", &AccNum);
		for (int i = 0; i < max - 1; i++)
		{
			if (people[i].AccountNumber == AccNum) // 고객의 계좌번호와 입력한 계좌번호가 일치한 경우
			{
				FindAcc = 1;
				int pw_count = 0;
				while (pw_count < 3)
				{
					int pw;
					printf("\n비밀번호를 입력하시오 : ");
					scanf("%d", &pw);

					if (people[i].AccountPW == pw)
						break;
					else
					{
						pw_count++;
						if (pw_count < 3)
							printf("\n비밀번호가 틀렷습니다. 다시 입력하세요(%d회 오류)\n", pw_count);
						else
							break;
					}
				}
				if (pw_count == 3)
				{
					printf("\n비밀번호를 3회이상 잘못 입력하셨습니다. 프로그램을 종료합니다.\n");
					exit(0);
				}

			RE:
				printf("\n출금하실 금액을 입력하시오 : ");
				scanf("%d", &withdrawMoney);
				if (people[i].NowMoney >= withdrawMoney)
				{
					if (voicefishing() == 1)
						exit(0);
					people[i].NowMoney -= withdrawMoney;
					printf("\n<출금 후 잔액 : %d원>\n", people[i].NowMoney);
				}
				else	//출금액이 잔액보다 적은 경우
				{
					printf("잔액이 부족합니다. 출금하실 금액을 다시 설정해주세요.\n");
					goto RE;
				}
			}
		}
		if (!FindAcc) {
			printf("\n입력한 계좌번호가 존재하지 않습니다.\n");
			goto REWITH;
		}
	} while (FindAcc == 0);

}
int ViewMyCash_func(char* filename, Person* people, int max)
{
	read_csv_file(filename, people, max - 1);

	char answer[10];
	printf("\n");
	printf("   ---------------------------------------\n");
	printf("\n");
	printf("         보유잔액 조회를 선택하셨습니다.       \n");
	printf("\n");
	printf("   ---------------------------------------\n");
	printf("        \n");
	printf("\n보이스피싱 관련 연락을 받으셨나요? (예/아니오): ");
	scanf("%s", answer);

	if (strcmp(answer, "아니오") != 0)
	{
		printf("\n보이스피싱 방지를 위해 종료합니다. 이용해주셔서 감사합니다.\n");
		return 1;
	}

	int CardNumber, AccountNumber, AccountPW, state = -1, temp;
	int retry_count = 0; // 재시도 횟수를 저장할 변수

	do {
		printf("\n");
		printf("   ---------------------------------------\n");
		printf("\n");
		printf("             숫자를 입력해주세요.             \n");
		printf("\n");
		printf("   ---------------------------------------\n");
		printf("\n");

		printf("\n카드번호를 입력해주세요. (4자리) : ");
		scanf("%d", &CardNumber);

		printf("\n계좌번호를 입력해주세요. (3자리) : ");
		scanf("%d", &AccountNumber);

		printf("\n비밀번호를 입력해주세요. (4자리) : ");
		scanf("%d", &AccountPW);

		for (int i = 0; i < max-1; i++) {
			if (people[i].CardNumber == CardNumber) {
				state = i;

				if (people[i].AccountNumber == AccountNumber) {
					if (people[state].AccountPW == AccountPW) {
						break;
					}
					else {
						state = -1;
					}
				}
			}
		}

		if (state == -1) {
			printf("\n입력하신 정보가 올바르지 않습니다. 다시 입력해주세요.\n");

			retry_count++;

			if (retry_count >= 3) {
				printf("\n3회 이상 잘못된 정보를 입력하셨습니다. 이용해주셔서 감사합니다.\n");
				return 1;
			}
		}
	} while (state == -1);

	printf("\n");
	printf("   ---------------------------------------\n");
	printf("\n");
	printf("                현재 보유잔액 입니다.            \n");
	printf("\n");
	printf("   ---------------------------------------\n");
	printf("\n");
	printf("   |  No. |    은행명    |    고객명    |   보유잔액   |\n");
	printf("   --------------------------------------------\n");
	printf("   | %3d  |  %5s은행  | %8s고객님  | %8d원    |\n", state, people[state].BankName, people[state].ClientName, people[state].NowMoney);
	printf("   --------------------------------------------\n");

	return 0;
}
int withdraw(char* filename, Person* people)
{
	int line = getTotalLine(filename);
	withdraw_func(filename, people, line);
	SaveData(filename, people, line);
	return 0;
}
int deposit(char* filename, Person* people)
{
	int line = getTotalLine(filename);
	deposit_func(filename, people, line);
	SaveData(filename, people, line);
	return 0;
}
int ViewMycash(char* filename, Person* people)
{
	int line = getTotalLine(filename);
	ViewMyCash_func(filename, people, line);
	return 0;
}