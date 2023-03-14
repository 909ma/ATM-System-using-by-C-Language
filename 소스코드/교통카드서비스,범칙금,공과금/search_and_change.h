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

int search(char* filename, Person* people, Person*person) {// person=찾으려는 고객의 정보를 나타내는 구조체배열,people=파일의 전체 정보를 담은 구조체 배열
    int accnum, acpw;
    int i=1,j;

    printf("계좌번호를 입력하세요\n");// 찾으려는 고객정보 중 계좌번호
    scanf("%d", &accnum);
    printf("비밀번호를 입력하세요\n");// 찾으려는 고객정보 중 비밀번호
    scanf("%d", &acpw);

    read_csv_file(filename, people, 100);

    for (j = 0; j < 100; j++)//people배열 중 person과 같은 것이 있는지 확인
    {
        if (people[j].AccountNumber == accnum)// 계좌번호 같으면 person에 저장
            *person = people[j];
    }

    view:
    if (person->AccountPW == acpw)// 비밀번호를 올바르게 입력했을 시
    {
        printf("고객님의 정보를 불러옵니다\n");
        printf("%s님 잔액:%d\\\n", person->ClientName, person->NowMoney);
    }

    else
    {
        while (i < 3)// 비밀번호를 3회보다 적게 틀렸을 시
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
    if (i == 3)//비밀번호 3회 틀렸을 시 1반환
    {
        printf("비밀번호를 %d회 틀렸습니다\n", i);
        return 1;
    }

    return 0;//정상작동 시 0 반환
}

int change(char* filename, Person* people, Person* person) // 수정된 정보로 파일에 저장하는 코드
{
	read_csv_file(filename, people,100);// people에 파일 내용 저장
	for (int i = 0; i < 100; i++)
	{
		if (people[i].AccountNumber == person->AccountNumber) // 고객의 계좌번호가 파일 안에 있을 경우 경우 잔액정보 수정
		{
			people[i].NowMoney = person->NowMoney;
		}
	}
	FILE* fp = fopen(filename, "w");// 파일 열기
	if (fp == NULL) {
		printf("File open error!\n");
		return 1;
	}
	fprintf(fp, "BankName,BankCode,ClientCode,ClientName,CardNumber,AccountNumber,NowMoney,AccountPW,AccountDate\n");// 가장 윗줄(정보 구분) 파일에 입력
	if (people->BankName != NULL)
	{
		for (int i = 0; i < 100 - 1; i++, people++)// 전체 고객정보 입력
		{
			fprintf(fp, "%s,%d,%d,%s,%d,%d,%d,%d,%d\n", people->BankName, people->BankCode, people->ClientCode, people->ClientName, people->CardNumber, people->AccountNumber, people->NowMoney, people->AccountPW, people->AccountDate);
		}
	}
	fclose(fp);// 파일 닫기
	return 0;
}