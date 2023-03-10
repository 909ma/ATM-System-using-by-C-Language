#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "typedef_struct.h"

int read_csv_file(char* file_name, gift_struct* voucher, int max_num_voucher){
    FILE* fp = fopen ( file_name, "r"); // fopen �Լ��϶� "r"�и��� �����Ѵٶ�� ǥ�� ("w" : ���� ���,"r" : �б� ���)
    if (fp ==NULL) {
        printf(" File open error : %s\n",file_name);
        return 1;
    }
    char buffer [1024]; // �� �پ� �о�� ����
    int count = 0; //�о�� ��ǰ�� ��
    
    while (fgets(buffer, 1024, fp)) {
        if (count >= max_num_voucher) {
            break;
        }
        char* gift_num = strtok(buffer, ","); //��ǰ�� ��ȣ �о���� ó���� ������ buffer��� �״������� NULL����ؾ���
        char* expiry_date = strtok(NULL, ",");
        int balance = atoi(strtok(NULL, ","));

        strcpy(voucher[count].gift_num, gift_num);
        strcpy(voucher[count].expiry_date, expiry_date);
        voucher[count].balance = balance;
        count++;
    }
    fclose(fp); //���� �ݱ�    
}

int getTotalLine(char* filename) { // csv������ �� ���� ���� �޴� �ڵ�
    FILE* fp;
    int line = -1;
    char c;
    fp = fopen(filename, "r");
    while ((c = fgetc(fp)) != EOF)
        if (c == '\n') line++;
    fclose(fp);
    return line;
}

int getGiftLine(char* file_name, gift_struct* voucher,gift_struct*gift, int max_num_voucher) {
    FILE* fp = fopen(file_name, "r"); // fopen �Լ��϶� "r"�и��� �����Ѵٶ�� ǥ�� ("w" : ���� ���,"r" : �б� ���)
    if (fp == NULL) {
        printf(" File open error : %s\n", file_name);
        return 1;
    }
    char buffer[1024]; // �� �پ� �о�� ����
    int count = 0; //�о�� ��ǰ�� ��

    while (fgets(buffer, 1024, fp)) {
        if (count >= max_num_voucher) {
            break;
        }
        char* gift_num = strtok(buffer, ","); //��ǰ�� ��ȣ �о���� ó���� ������ buffer��� �״������� NULL����ؾ���
        char* expiry_date = strtok(NULL, ",");
        int balance = atoi(strtok(NULL, ","));

        if (gift->gift_num == gift_num && gift->expiry_date == expiry_date && gift->balance == balance)
        {
            break;
        }
        count++;
    }
    if (count > max_num_voucher)
        printf("��ϵ��� ���� ��ǰ���Դϴ�.\n");
    fclose(fp);//���� �ݱ�
    return count;    
}