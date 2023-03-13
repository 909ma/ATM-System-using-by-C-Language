#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GiftStruct.h"
#define MAX_LINE_LEN 1024

int delete_account(char file_path[100], int delete_index) {
//파일 열기
    FILE* fp =fopen(file_path, "r");
    if (fp == NULL) {
        printf("파일 열기를 실패하였습니다.\n");
        return 1;
    }
//새로운 파일 생성
    FILE* new_fp = fopen("temp.csv", "w");
    if (new_fp == NULL) {
        printf("새로운 파일 생성을 실패하였습니다.\n");
        return 1;
    }
//삭제한 줄을 제외한 내용을 새로운 파일에 씀
    char line[MAX_LINE_LEN];
    int line_count = 0;
    while (fgets(line, MAX_LINE_LEN, fp) != NULL) {
        
        if (line_count != delete_index) {
            fprintf(new_fp, "%s", line);
        }
        line_count++;
    }
//파일 닫기
    fclose(fp);
    fclose(new_fp);
//기존 파일 삭제
    if (remove(file_path) != 0){
        printf("기존 파일 삭제를 실패하였습니다.\n");
        return 1;
    }
//새로운 파일 이름 변경
    if (rename("temp.csv", file_path) != 0) {
        printf("새로운 파일 이름 변경을 실패하였습니다.\n");
        return 1;
    }
    printf("Line %d has been deleted from the file.\n", delete_index);
    return 0;
}
int giftCards_cancle(gift_struct* voucher, gift_struct* gift, int total_line) {
    
    printf(" 상품권 번호 : ");
    scanf("%s",gift->gift_num);
    printf(" 유효기간(YYYY-MM-DD) : ");
    scanf("%s",gift->expiry_date);
//        rewind(stdin);
//        fgets(expiry_date,sizeof(expiry_date),stdin);
    printf(" 금액 : ");
    scanf("%d",&gift->balance);
    printf(" ==================================\n");
    if (gift->balance != 0) {
        printf("상품권을 해지할 수 없습니다.\n");
    }
    else {
        int line = 1;
        printf(" \t\t[ 해지하실 상품권 정보 ]\n\n");
        printf(" 상품권 번호 : %s\n",gift->gift_num);
        printf(" 상품권 유효기간 : %s\n",gift->expiry_date);
        printf(" 상품권 잔액 : %d원\n\n",gift->balance); //  <잔액여부 만들기> 0원일 경우, 등록 해지 완료/0원이 아닐 경우, 어떻게 구현?
        line = getGiftLine("new_gift.csv",voucher, &gift, total_line);
        delete_account("new_gift.csv", line);
        printf(" 상품권 등록 해지가 처리되었습니다.\n");
    }
        printf(" ==================================\n");
        printf(" \t\t1. 처음으로   2. 사용종료\n");
        printf(" ==================================\n");
        printf(" 이용하실 번호를 선택하세요 : ");
        scanf("%d",&Index);
        if (Index == 1)
            return 1;
        else if (Index ==2) {
            printf(" ==================================\n");
            printf(" 놓고 가시는 물건은 없는지 확인하여 주십시오.\n\t\t 이용해주셔서 감사합니다. \n\t\t\tTHANK YOU\n");
            printf(" ==================================\n");
            getchar();
            return 0;
            }
    return 0;
}
