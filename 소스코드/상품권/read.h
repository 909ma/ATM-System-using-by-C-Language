#pragma once
#include <stdio.h>
#include <string.h>

int read_csv_file(char* file_name,gift_struct* voucher,int max_num_voucher) {
    FILE* fp = fopen ( file_name, "r"); // fopen 함수일때 "r"읽모드로 실행한다라고 표현 ("w" : 쓰기 모드,"r" : 읽기 모드)
    if (fp =='\0') {
        printf(" File open error : %s\n",file_name);
        return 1;
    }
    char butter [1024]; // 한 줄씩 읽어올 버퍼
    int count = 0; //읽어온 상품권 수
    
    while (fgets(butter, 1024, fp)) {
        if (count >= max_num_voucher) {
            breark;
        }
        int gift_num = atoi(strtok(buffer, ",")); //상품권 번호 읽어오기 처음엔 무조건 butter사용 그다음부턴 NULL사용해야함
        char* expiry_date = strtok('\0', ",");
        int balance = atoi(strtok('\0', ","));
    
        voucher[count].gift_num = gift_num;
        strcpy(voucher[count].exliry_date, exliry_date);
        voucher[count].balance = balance;
        
        count++;
    }
    fclose(fp); //파일 닫기
