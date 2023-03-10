#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PersonStruct.h"

//고객코드와 비밀번호로 고객을 찾는 함수//
//3회 안에 비밀번호를 맞추지 못할 시 -1 출력, 그 이외는 0 출력//

int search(char* filename, Person* people, int max_num_people) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("File open error!\n");
        return 1;
    }

    int acpw, accnum;
    int i=1;
    printf("계좌번호를 입력하세요\n");
    scanf("%d", &accnum);
    printf("비밀번호를 입력하세요\n");
    scanf("%d", &acpw);

    char buffer[1024];
    int count = 0;

    while (fgets(buffer, 1024, fp)) {
       if (count >= max_num_people) {
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

       if (AccountNumber == accnum)
       {
           strcpy(people->BankName, BankName);
           people->BankCode = BankCode;
           people->ClientCode = ClientCode;
           strcpy(people->ClientName, ClientName);
           people->CardNumber = CardNumber;
           people->AccountNumber = AccountNumber;
           people->NowMoney = NowMoney;
           people->AccountPW = AccountPW;
           people->AccountDate = AccountDate;
           view:
           if (AccountPW == acpw)
           {
               printf("고객님의 정보를 불러옵니다\n");
               printf("%s님 잔액:%d\\\n", people->ClientName, people->NowMoney);
               break;
           }
           else
           {
               while(i<3)
               {
                    printf("비밀번호를 %d회 틀렸습니다.\n",i);
                    if (i < 3) printf("다시 입력하세요\n");
                    scanf("%d", &acpw);
                    if (AccountPW == acpw)
                    {
                        goto view;
                        break;
                    }
                    i++;
               }
           }
       }
       if (count > max_num_people)
       {
           printf("존재하지 않는 계정입니다.\n");
           return -1;
       }
       count++;
       }        
    fclose(fp);    
    if (i == 3)
    {
        printf("비밀번호를 %d회 틀렸습니다\n", i);
        return 1;
    }
    else
        return 0;
}