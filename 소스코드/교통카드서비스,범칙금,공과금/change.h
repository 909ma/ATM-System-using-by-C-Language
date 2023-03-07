#pragma once
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
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
	printf("저장완료\n");
	fclose(fp);
}
void withdraw_func(char* filename, Person* people, int max, Person*person)
{
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

			if (AccountNumber == person->AccountNumber) // 고객의 계좌번호와 입력한 계좌번호가 일치한 경우
			{
				people[count].NowMoney = person->NowMoney;
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
int change(char* filename, Person* people, Person* person)
{
	int line = getTotalLine(filename);
	withdraw_func(filename, people, line, person);
	SaveData(filename, people, line);
	return 0;
}