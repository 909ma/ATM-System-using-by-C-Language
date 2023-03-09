#pragma once
#include <stdio.h>

int giftCards_cancle() {
        printf(" 상품권 번호 : ");
        scanf("%d",&input_num);
        printf(" 유효기간(YYYY-MM-DD) : ");
        rewind(stdin);
        fgets(expiry_date,sizeof(expiry_date),stdin);
        printf(" 금액 : ");
        scanf("%d",&cash);
        printf(" ==================================\n");
        printf(" \t\t[ 해지하실 상품권 정보 ]\n\n");
        printf(" 상품권 번호 : %d\n",input_num);
        printf(" 상품권 유효기간 : %s\n",expiry_date);
        printf(" 상품권 잔액 : %d원\n\n",cash);     //  <잔액여부 만들기> 0원일 경우, 등록 해지 완료,
                                                //                0원이 아닐 경우, 구분만들기 어떻게 구현할까???????????
        printf(" 상품권 등록 해지가 처리되었습니다.\n");
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
