#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "typedef_struct.h"

int read_csv_file(char* file_name, gift_struct* voucher, int max_num_voucher){
    FILE* fp = fopen ( file_name, "r"); // fopen 함수일때 "r"읽모드로 실행한다라고 표현 ("w" : 쓰기 모드,"r" : 읽기 모드)
    if (fp ==NULL) {
        printf(" File open error : %s\n",file_name);
        return 1;
    }
    char buffer [1024]; // 한 줄씩 읽어올 버퍼
    int count = 0; //읽어온 상품권 수
    
    while (fgets(buffer, 1024, fp)) {
        if (count >= max_num_voucher) {
            break;
        }
        char* gift_num = strtok(buffer, ","); //상품권 번호 읽어오기 처음엔 무조건 buffer사용 그다음부턴 NULL사용해야함
        char* expiry_date = strtok(NULL, ",");
        int balance = atoi(strtok(NULL, ","));

        strcpy(voucher[count].gift_num, gift_num);
        strcpy(voucher[count].expiry_date, expiry_date);
        voucher[count].balance = balance;
        count++;
    }
    fclose(fp); //파일 닫기    
}

int getTotalLine(char* filename) { // csv파일의 총 라인 수를 받는 코드
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
    FILE* fp = fopen(file_name, "r"); // fopen 함수일때 "r"읽모드로 실행한다라고 표현 ("w" : 쓰기 모드,"r" : 읽기 모드)
    if (fp == NULL) {
        printf(" File open error : %s\n", file_name);
        return 1;
    }
    char buffer[1024]; // 한 줄씩 읽어올 버퍼
    int count = 0; //읽어온 상품권 수

    while (fgets(buffer, 1024, fp)) {
        if (count >= max_num_voucher) {
            break;
        }
        char* gift_num = strtok(buffer, ","); //상품권 번호 읽어오기 처음엔 무조건 buffer사용 그다음부턴 NULL사용해야함
        char* expiry_date = strtok(NULL, ",");
        int balance = atoi(strtok(NULL, ","));

        if (gift->gift_num == gift_num && gift->expiry_date == expiry_date && gift->balance == balance)
        {
            break;
        }
        count++;
    }
    if (count > max_num_voucher)
        printf("등록되지 않은 상품권입니다.\n");
    fclose(fp);//파일 닫기
    return count;    
}