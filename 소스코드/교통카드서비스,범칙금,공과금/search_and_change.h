#pragma once
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include"PersonStruct.h"
#include "ViewAccount.h"

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

int search(char* filename, Person* people,Person*person) {
    int accnum, acpw;
    int i=1,j;
    printf("계좌번호를 입력하세요\n");
    scanf("%d", &accnum);
    printf("비밀번호를 입력하세요\n");
    scanf("%d", &acpw);
    read_csv_file("people.csv", people, 100);
    for (j = 0; j < 100; j++)
    {
        if (people[j].AccountNumber == accnum)
        {
            strcpy(person->BankName, people[j].BankName);
            person->BankCode = people[j].BankCode;
            person->ClientCode = people[j].ClientCode;
            strcpy(person->ClientName, people[j].ClientName);
            person->CardNumber = people[j].CardNumber;
            person->AccountNumber = people[j].AccountNumber;
            person->NowMoney = people[j].NowMoney;
            person->AccountPW = people[j].AccountPW;
            person->AccountDate = people[j].AccountDate;
        }
    view:
        if (person->AccountPW == acpw)
        {
            printf("고객님의 정보를 불러옵니다\n");
            printf("%s님 잔액:%d\\\n", person->ClientName, person->NowMoney);
            break;
        }
        else
        {
            while (i < 3)
            {
                printf("비밀번호를 %d회 틀렸습니다.\n", i);
                if (i < 3) printf("다시 입력하세요\n");
                scanf("%d", &acpw);
                if (people[i].AccountPW == acpw)
                {
                    goto view;
                    break;
                }
                i++;
            }
        }
    }
    if (i == 3)
    {
        printf("비밀번호를 %d회 틀렸습니다\n", i);
        return 1;
    }
    else
        return 0;
}

int change(char* filename, Person* people, Person* person) // 수정된 정보로 파일에 저장하는 코드
{
	read_csv_file("people.csv", people,100);
	for (int i = 0; i < 100; i++)
	{
		if (people[i].AccountNumber == person->AccountNumber) // 고객의 계좌번호와 입력한 계좌번호가 일치한 경우
		{
			people[i].NowMoney = person->NowMoney;
		}
	}
	FILE* fp = fopen(filename, "w");
	if (fp == NULL) {
		printf("File open error!\n");
		return;
	}
	fprintf(fp, "BankName,BankCode,ClientCode,ClientName,CardNumber,AccountNumber,NowMoney,AccountPW,AccountDate\n");
	if (people->BankName != NULL)
	{
		for (int i = 0; i < 100 - 1; i++, people++)
		{
			fprintf(fp, "%s,%d,%d,%s,%d,%d,%d,%d,%d\n", people->BankName, people->BankCode, people->ClientCode, people->ClientName, people->CardNumber, people->AccountNumber, people->NowMoney, people->AccountPW, people->AccountDate);
		}
	}
	printf("저장완료\n");
	fclose(fp);
	return 0;
}