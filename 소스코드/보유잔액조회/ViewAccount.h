#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
ViewAccount(int a)�Լ��� people.csv ���Ͽ��� a��ŭ�� �ο����� �о�ɴϴ�.
�ִ� 100����� ������ �� �ֽ��ϴ�. 
*/ 
#include"PersonStruct.h"
void read_csv_file(char* filename, Person* people, int max_num_people) {
    FILE* fp = fopen(filename, "r");    // ������ �б� ���� ����
    if (fp == NULL) {
        printf("File open error!\n");
        return;
    }

    char buffer[1024];    // �� �پ� �о�� ����
    int count = 0;        // �о�� ��� ��

    while (fgets(buffer, 1024, fp)) {    // �� �پ� �о����
        if (count >= max_num_people) {   // �ִ� �о�� �� �ִ� ��� ���� �ʰ��ϸ� ����
            break;
        }
        char* BankName = strtok(buffer, ",");                    // BankName �о����
        int BankCode = atoi(strtok(NULL, ","));                 // BankCode �о����
        int ClientCode = atoi(strtok(NULL, ","));              // ClientCode �о����
        char* ClientName = strtok(NULL, ",");                 // ClientName �о����
        int CardNumber = atoi(strtok(NULL, ","));            // CardNumber �о����
        int AccountNumber = atoi(strtok(NULL, ","));        // AccountNumber �о����
        int NowMoney = atoi(strtok(NULL, ","));            // NowMoney �о����
        int AccountPW = atoi(strtok(NULL, ","));          // AccountPW �о����
        int AccountDate = atoi(strtok(NULL, ","));       // AccountDate �о����

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

    fclose(fp);    // ���� �ݱ�
}
int ViewAccount(int a) {
    Person* people = malloc(sizeof(Person) * 100);// �ִ� 100���� ��� ������ ������ �� �ִ� �迭 ���� �Ҵ�

    read_csv_file("people.csv", people, a+1);//a�� �ο����� ��ȸ 

    printf("No.  BankName  BankCode  ClientCode  ClientName  CardNumber  AccountNumber   NowMoney  AccountPW  AccountDate\n");
    for (int i = 1; i < a + 1; i++) {
        printf("%3d  %8s  %8d  %10d  %10s  %10d  %13d  %9d       %04d  %11d\n", i,people[i].BankName, people[i].BankCode, people[i].ClientCode, people[i].ClientName, people[i].CardNumber, people[i].AccountNumber, people[i].NowMoney, people[i].AccountPW, people[i].AccountDate);
        if(i%10==0)
            printf("\nNo.  BankName  BankCode  ClientCode  ClientName  CardNumber  AccountNumber   NowMoney  AccountPW  AccountDate\n");
    }
    free(people);// ���� �Ҵ�� �޸� ����

    return 0;
}

