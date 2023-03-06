#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
CreatAccount()함수는 입력한 정보를 배열에 담아 New_people.csv 파일을 만듭니다.
*/ 
#include"PersonStruct.h"
void write_csv_file(char* filename, Person* people) {
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("File open error: %s\n", filename);
        return;
    }

    fprintf(fp, "BankName,BankCode,ClientCode,ClientName,CardNumber,AccountNumber,NowMoney,AccountPW,AccountDate\n");
    fprintf(fp, "%s,%d,%d,%s,%d,%d,%d,%d,%d\n", people->BankName, people->BankCode, people->ClientCode, people->ClientName, people->CardNumber, people->AccountNumber, people->NowMoney, people->AccountPW, people->AccountDate);

    fclose(fp);
}

int CreatAccount() {
    Person person;
    printf("   Enter BankName:   ");
    gets(person.BankName);//fgets로 바꾸려면 데이터에 '\n'가 들어가서 '\n'을 '\0'으로 바꾸는 작업을 추가해야 한다. 
    
    printf("   Enter BankCode:   ");
    scanf("%d", &person.BankCode);
    
    printf("  Enter ClientCode:  ");
    scanf("%d", &person.ClientCode);
    
    getchar(); // 입력 버퍼 비우기
    printf("  Enter ClientName:  ");
    gets(person.ClientName);
    
    printf("  Enter CardNumber:  ");
    scanf("%d", &person.CardNumber);
    
    printf("Enter AccountNumber: ");
    scanf("%d", &person.AccountNumber);
    
    printf("    Enter NowMoney:  ");
    scanf("%d", &person.NowMoney);
    
    printf("   Enter AccountPW:  ");
    scanf("%d", &person.AccountPW);
    
    printf("  Enter AccountDate: ");
    scanf("%d", &person.AccountDate);

    write_csv_file("new_people.csv", &person);
    printf("File \"new_people.csv\" write success!\n");

    return 0;
}

