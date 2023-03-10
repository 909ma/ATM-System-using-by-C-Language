#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PersonStruct.h"

//���ڵ�� ��й�ȣ�� ���� ã�� �Լ�//
//3ȸ �ȿ� ��й�ȣ�� ������ ���� �� -1 ���, �� �ܴ̿� 0 ���//

int search(char* filename, Person* people, int max_num_people) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("File open error!\n");
        return 1;
    }

    int acpw, accnum;
    int i=1;
    printf("���¹�ȣ�� �Է��ϼ���\n");
    scanf("%d", &accnum);
    printf("��й�ȣ�� �Է��ϼ���\n");
    scanf("%d", &acpw);

    char buffer[1024];
    int count = 0;

    while (fgets(buffer, 1024, fp)) {
       if (count >= max_num_people) {
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
               printf("������ ������ �ҷ��ɴϴ�\n");
               printf("%s�� �ܾ�:%d\\\n", people->ClientName, people->NowMoney);
               break;
           }
           else
           {
               while(i<3)
               {
                    printf("��й�ȣ�� %dȸ Ʋ�Ƚ��ϴ�.\n",i);
                    if (i < 3) printf("�ٽ� �Է��ϼ���\n");
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
           printf("�������� �ʴ� �����Դϴ�.\n");
           return -1;
       }
       count++;
       }        
    fclose(fp);    
    if (i == 3)
    {
        printf("��й�ȣ�� %dȸ Ʋ�Ƚ��ϴ�\n", i);
        return 1;
    }
    else
        return 0;
}