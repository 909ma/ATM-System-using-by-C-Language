#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
ViewAccount(int a)함수는 people.csv 파일에서 a만큼의 인원수를 읽어옵니다.
최대 100명까지 관리할 수 있습니다. 
*/ 
#include"PersonStruct.h"
void read_csv_file(char* filename, Person* people, int max_num_people) {
    FILE* fp = fopen(filename, "r");    // 파일을 읽기 모드로 열기
    if (fp == NULL) {
        printf("File open error!\n");
        return;
    }

    char buffer[1024];    // 한 줄씩 읽어올 버퍼
    int count = 0;        // 읽어온 사람 수

    while (fgets(buffer, 1024, fp)) {    // 한 줄씩 읽어오기
        if (count >= max_num_people) {   // 최대 읽어올 수 있는 사람 수를 초과하면 종료
            break;
        }
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

        count++;
    }

    fclose(fp);    // 파일 닫기
}
int ViewAccount(int a) {
    Person* people = malloc(sizeof(Person) * 100);// 최대 100명의 사람 정보를 저장할 수 있는 배열 동적 할당

    read_csv_file("people.csv", people, a+1);//a의 인원수를 조회 

    printf("No.  BankName  BankCode  ClientCode  ClientName  CardNumber  AccountNumber   NowMoney  AccountPW  AccountDate\n");
    for (int i = 1; i < a + 1; i++) {
        printf("%3d  %8s  %8d  %10d  %10s  %10d  %13d  %9d       %04d  %11d\n", i,people[i].BankName, people[i].BankCode, people[i].ClientCode, people[i].ClientName, people[i].CardNumber, people[i].AccountNumber, people[i].NowMoney, people[i].AccountPW, people[i].AccountDate);
        if(i%10==0)
            printf("\nNo.  BankName  BankCode  ClientCode  ClientName  CardNumber  AccountNumber   NowMoney  AccountPW  AccountDate\n");
    }
    free(people);// 동적 할당된 메모리 해제

    return 0;
}

