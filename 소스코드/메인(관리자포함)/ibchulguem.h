#pragma once
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

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
	int num;
	int depositMoney;
	printf("\n입금할 계좌번호 입력: ");
	scanf("%d", &num);
	FILE* fp = fopen(filename, "r");    // 파일을 읽기 모드로 열기
	if (fp == NULL) {
		printf("File open error!\n");
		return;
	}

	char buffer[1024];    // 한 줄씩 읽어올 버퍼
	int count = 0;        // 읽어온 사람 수
	if (fgets(buffer, 1024, fp))
	{

		while (fgets(buffer, 1024, fp)) {    // 한 줄씩 읽어오기

			char* BankName = strtok(buffer, ",");                    // BankName 읽어오기
			int BankCode = atoi(strtok(NULL, ","));                 // BankCode 읽어오기
			int ClientCode = atoi(strtok(NULL, ","));              // ClientCode 읽어오기
			char* ClientName = strtok(NULL, ",");                 // ClientName 읽어오기
			int CardNumber = atoi(strtok(NULL, ","));            // CardNumber 읽어오기
			int AccountNumber = atoi(strtok(NULL, ","));        // AccountNumber 읽어오기
			int NowMoney = atoi(strtok(NULL, ","));            // NowMoney 읽어오기
			int AccountPW = atoi(strtok(NULL, ","));          // AccountPW 읽어오기
			int AccountDate = atoi(strtok(NULL, ","));       // AccountDate 읽어오기

			strcpy(people[count].BankName, BankName);
			people[count].BankCode = BankCode;
			people[count].ClientCode = ClientCode;
			strcpy(people[count].ClientName, ClientName);
			people[count].CardNumber = CardNumber;
			people[count].AccountNumber = AccountNumber;
			people[count].NowMoney = NowMoney;
			people[count].AccountPW = AccountPW;
			people[count].AccountDate = AccountDate;

			if (AccountNumber == num) // 고객의 계좌번호와 입력한 계좌번호가 일치한 경우
			{
			RE:
				printf("\n입금하실 금액을 입력하시오 : ");
				scanf("%d", &depositMoney);

				if (voicefishing() == 1)
					exit(0);
				NowMoney += depositMoney;
				printf("\n<입금 후 잔액 : %d원>\n", NowMoney);
				people[count].NowMoney = NowMoney;
			}
			count++;
			if (max == count)
				break;
		}
	}

	fclose(fp);    // 파일 닫기
}
void withdraw_func(char* filename, Person* people, int max)
{
	int num;
	int withdrawMoney;
	printf("\n출금할 계좌번호 입력: ");
	scanf("%d", &num);
	FILE* fp = fopen(filename, "r");    // 파일을 읽기 모드로 열기
	if (fp == NULL) {
		printf("File open error!\n");
		return;
	}

	char buffer[1024];    // 한 줄씩 읽어올 버퍼
	int count = 0;        // 읽어온 사람 수
	if (fgets(buffer, 1024, fp))
	{

		while (fgets(buffer, 1024, fp)) {    // 한 줄씩 읽어오기

			char* BankName = strtok(buffer, ",");                    // BankName 읽어오기
			int BankCode = atoi(strtok(NULL, ","));                 // BankCode 읽어오기
			int ClientCode = atoi(strtok(NULL, ","));              // ClientCode 읽어오기
			char* ClientName = strtok(NULL, ",");                 // ClientName 읽어오기
			int CardNumber = atoi(strtok(NULL, ","));            // CardNumber 읽어오기
			int AccountNumber = atoi(strtok(NULL, ","));        // AccountNumber 읽어오기
			int NowMoney = atoi(strtok(NULL, ","));            // NowMoney 읽어오기
			int AccountPW = atoi(strtok(NULL, ","));          // AccountPW 읽어오기
			int AccountDate = atoi(strtok(NULL, ","));       // AccountDate 읽어오기

			strcpy(people[count].BankName, BankName);
			people[count].BankCode = BankCode;
			people[count].ClientCode = ClientCode;
			strcpy(people[count].ClientName, ClientName);
			people[count].CardNumber = CardNumber;
			people[count].AccountNumber = AccountNumber;
			people[count].NowMoney = NowMoney;
			people[count].AccountPW = AccountPW;
			people[count].AccountDate = AccountDate;

			if (AccountNumber == num) // 고객의 계좌번호와 입력한 계좌번호가 일치한 경우
			{
				int cnt = 0;
				while (cnt < 3)
				{
					int pw;
					printf("\n비밀번호를 입력하시오 : ", cnt);
					scanf("%d", &pw);

					if (AccountPW == pw)
						break;
					else
					{
						cnt++;
						if (cnt < 3)
							printf("\n비밀번호가 틀렷습니다. 다시 입력하세요(%d회 오류)\n", cnt);
						else
							break;
					}
				}
				if (cnt == 3)
				{
					printf("\n비밀번호를 3회이상 잘못 입력하셨습니다. 프로그램을 종료합니다.\n");
					exit(0);
				}

			RE:
				printf("\n출금하실 금액을 입력하시오 : ");
				scanf("%d", &withdrawMoney);
				if (NowMoney >= withdrawMoney)
				{
					if (voicefishing() == 1)
						exit(0);
					NowMoney -= withdrawMoney;
					printf("\n<출금 후 잔액 : %d원>\n", NowMoney);
					people[count].NowMoney = NowMoney;
				}
				else	//출금액이 잔액보다 적은 경우
				{
					printf("잔액이 부족합니다. 출금하실 금액을 다시 설정해주세요.\n");
					goto RE;
				}
			}
			count++;
			if (max == count)
				break;
		}
	}

	fclose(fp);    // 파일 닫기
}
int getTotalLine(char* filename) { // csv파일의 총 라인 수를 받는 코드
	FILE* fp;
	int line = 0;
	char c;
	fp = fopen(filename, "r");
	while ((c = fgetc(fp)) != EOF)
		if (c == '\n') line++;
	fclose(fp);
	return(line);
}
int voicefishing()
{
	int answer;
ReFishing:
	printf("\n\n\n\n※※※※※※보이스피싱 피해예방 안내※※※※※※\n\n");
	printf("검찰, 경찰, 금융감독원이나 모르는 사람이 전화로\n");
	printf("출금 및 이체를 요청하셨습니까?\n\n\n");
	printf("1. 예\t\t 2. 아니오\n");
	printf("\n선택 : ");
	scanf_s("%d", &answer);
	if (answer == 1)
		return 1;
	else if (answer == 2)
		return 2;
	else
	{
		printf("다시 입력하세요\n");
		goto ReFishing;
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