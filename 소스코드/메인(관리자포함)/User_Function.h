#pragma once
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ExtraFunc.h"

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
int search(char* filename, Person* people, Person* person, int max) {
	int accnum, acpw;
	int i = 1, j;
	printf("\n\n계좌번호를 입력하세요 : ");
	scanf("%d", &accnum);
	printf("\n\n비밀번호를 입력하세요 : ");
	scanf("%d", &acpw);
	read_csv_file("people.csv", people, max - 1);
	for (j = 0; j < max - 1; j++)
	{
		if (people[j].AccountNumber == accnum)
			*person = people[j];
	}
view:
		if (person->AccountPW == acpw)
		{
			printf("\n\n고객님의 정보를 불러옵니다\n\n");
			printf("\"%s\"님 잔액 : %d\\\n\n", person->ClientName, person->NowMoney);
			
		}
		else
		{
			while (i < 3)
			{
				printf("\n\n비밀번호를 %d회 틀렸습니다.\n", i);
				if (i < 3) printf("다시 입력하세요\n");
				scanf("%d", &acpw);
				if (person->AccountPW == acpw)
				{
					goto view;
					break;
				}
				i++;
			}
		}
	
	if (i == 3)
	{
		printf("\n\n비밀번호를 %d회 틀렸습니다\n", i);
		return 1;
	}
	else
		return 0;
}

int change(char* filename, Person* people, Person* person, int max) // 수정된 정보로 파일에 저장하는 코드
{
	read_csv_file("people.csv", people, 100);
	for (int i = 0; i < 100; i++)
	{
		if (people[i].AccountNumber == person->AccountNumber) // 고객의 계좌번호와 입력한 계좌번호가 일치한 경우
		{
			people[i].NowMoney = person->NowMoney;
		}
	}
	SaveData(filename, people, max);
	return 0;
}

int Fine(Person* person) // 범칙금 납부
{
	int fee;
	if (strcmp(person->BankName, "범칙금") != 0)
	{
		printf("범칙금 납부를 할 수 없는 계정입니다.\n");
		return -1;
	}
	else
	{
		RePay:
		printf("\"%s\" 고객님의 범칙금 납부금액을 입력하세요 : ", person->ClientName);
		scanf("%d", &fee);
		if (person->NowMoney < fee)
		{
			printf("\n납부에 실패하였습니다. 다시 입력해주세요.\n");
			goto RePay;
		}
		else
		{
			person->NowMoney -= fee;
			printf("\n\n납부가 완료되었습니다.\n");
			printf("\n고객명: %s\n", person->ClientName);
			printf("\n납부액: %d\\\n", fee);
			printf("\n잔액: %d\\\n", person->NowMoney);
		}
		printf("\n잠시 후 메인 화면으로 돌아갑니다.\n");
		return 0;
	}
}

int Utilities(Person* person)	//공과금 납부
{
	int fee;
	if (strcmp(person->BankName, "공과금") != 0)
	{
		printf("공과금 납부를 할 수 없는 계정입니다.\n");
		return -1;
	}
	else
	{
		ReUtil:
		printf("\n\"%s\" 고객님의 공과금 납부금액을 입력하세요 : ", person->ClientName);
		scanf("%d", &fee);
		if (person->NowMoney < fee)
		{
			printf("\n\n납부에 실패하였습니다. 다시 입력해주세요.\n");
			goto ReUtil;
		}
		else
		{
			person->NowMoney -= fee;
			printf("\n\n납부가 완료되었습니다.\n");
			printf("\n고객명: %s\n", person->ClientName);
			printf("\n납부액: %d\\\n", fee);
			printf("\n잔액: %d\\\n", person->NowMoney);
		}
		printf("\n잠시 후 메인 화면으로 돌아갑니다.\n");
		return 0;
	}
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