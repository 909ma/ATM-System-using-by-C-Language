#pragma once
#include <stdio.h>
#include "typedef_struct.h"
//#include <Windows.h>

int input_num;
char expiry_date[11];
int cash;
int Index;

int giftCards(gift_struct *gift) {
    printf(" ��ǰ�� ��ȣ : ");
    scanf("%s",gift->gift_num);
    printf(" ��ȿ�Ⱓ(YYYY-MM-DD) : ");
    rewind(stdin);
    fgets(gift->expiry_date,sizeof(gift->expiry_date),stdin);
    printf(" �ݾ� : ");
    scanf("%d",&gift->balance);
    printf(" ==================================\n");
    printf(" \t\t[ ����Ͻ� ��ǰ�� ���� ]\n\n");
    printf(" ��ǰ�� ��ȣ : %s\n", gift->gift_num);
    printf(" ��ǰ�� ��ȿ�Ⱓ : %s\n", gift->expiry_date);
    printf(" ��ǰ�� �ܾ� : %d��\n\n", gift->balance);
    printf(" ��ǰ�� ����� ó���Ǿ����ϴ�.\n");
    printf(" ==================================\n");
    printf(" \t\t1. ó������   2. �������\n");
    printf(" ==================================\n");
    printf(" �̿��Ͻ� ��ȣ�� �����ϼ��� : ");

    scanf("%d",&Index);
    if (Index == 1)
        return 1;
    else if (Index ==2) {
        printf(" ==================================\n");
        printf(" ���� ���ô� ������ ������ Ȯ���Ͽ� �ֽʽÿ�.\n\t\t �̿����ּż� �����մϴ�. \n\t\t\tTHANK YOU\n");
        printf(" ==================================\n");
        getchar();
        return 0; 
        }
    return 0;
}
int register_giftcard(char* file_name, gift_struct* gift) {
    FILE* fp = fopen(file_name, "a"); // fopen �Լ��϶� "w"���� �����Ѵٶ�� ǥ�� ("w" : ���� ���,"r" : �б� ���)
    if (fp == NULL) {
        printf("\n File open error : %s\n", file_name);
        return 1;
    }
    printf("����Ϸ�\n");
    int line = getTotalLine(file_name);
    fprintf(fp, "%s,%s,%d\n", gift->gift_num, gift->expiry_date, gift->balance);
    fclose(fp);
}
