#pragma once
#include <stdio.h>
#include "read.h"
#include "GiftStruct.h"
//#include "Exchange.h"
int input_num;

//char expiry_date[11];
int cash;
int Index;
int num_10000, num_50000, num_100000;

int giftCards(gift_struct* gift) {
    //gift=0;
    printf(" 상품권 번호 : ");
    while(getchar()!='\n');
    fgets(gift->gift_num,sizeof(gift->gift_num), stdin);
    printf(" 유효기간(YYYY-MM-DD) : ");
    //rewind(stdin);
    while(getchar()!='\n');
    fgets(gift->expiry_date,sizeof(gift->expiry_date),stdin);
    printf(" 금액 : ");
    scanf("%d",&gift->balance);
    printf(" ==================================\n");
    printf(" \t\t[ 등록하신 상품권 정보 ]\n\n");
    printf(" 상품권 번호 : %s\n",gift->gift_num);
    printf(" 상품권 유효기간 : %s\n",gift->expiry_date);
    printf(" 상품권 잔액 : %d원\n\n",gift->balance);
    printf(" 상품권 등록이 처리되었습니다.\n");
    printf(" ==================================\n");
    printf(" 1. 현금교환\n 2. 상품권 교환\n 3. 처음으로\n 4. 사용종료\n");
    printf(" ==================================\n");
    printf(" 이용하실 번호를 선택하세요 : ");
    scanf("%d",&Index);
    if (Index == 1) {
        // 아래 실행시 실행창에 잔액 보여주면서 1만원권 : \n 5만원권: 한개씩말고 한꺼번에 보이도록해서 입력하게 하고 싶은데 어떻게 구현할까??????
        printf("\n [ 현금 교환 ]\t 1만원권 : ");
        scanf("%d",&num_10000);
        printf(" \t\t\t 5만원권 : ");
        scanf("%d",&num_50000);
        printf(" ==================================\n");
        printf(" [ 현금 교환 ]\t 1만원권 : %d매\n\t\t\t 5만원권 : %d매\n",num_10000,num_50000);
        printf(" \t\t\t 합   계 : %d원\n", num_10000 * 10000 + num_50000 * 50000);
        printf(" \t\t\t 잔   액 : 0원\n"); // 잔액이 0을 해당 상품권에 등록된 총액에서 차감되서 0을 나타나야할텐데..어떻게 구현할까?????
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
    }
    else if (Index == 2) {
        printf("매수를 입력해주세요. ");
        printf(" 1만원권 : ");
        scanf("%d",&num_10000);
        printf(" 5만원권 : ");
        scanf("%d",&num_50000);
        printf(" 10만원권 : ");
        scanf("%d",&num_100000);
        printf(" ==================================\n");
        printf(" \t\t\t[ 상품권 교환 ]\n\t\t\t 1만원권 : %d매\n\t\t\t 5만원권 : %d매\n\t\t\t10만원권 : %d매\n\n",num_10000,num_50000,num_100000);
        printf(" \t\t 합   계 : %d원\n", num_10000 * 10000 + num_50000 * 50000 + num_100000 * 100000);
        printf(" \t\t 잔   액 : 0원\n"); // 잔액이 0을 해당 상품권에 등록된 총액에서 차감되서 0을 나타나야할텐데..어떻게 구현할까?
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
    }
    else if (Index == 3)
        return 1;
    else if (Index ==4) {
        printf(" ==================================\n");
        printf(" 놓고 가시는 물건은 없는지 확인하여 주십시오.\n\t\t 이용해주셔서 감사합니다. \n\t\t\tTHANK YOU\n");
        printf(" ==================================\n");
        getchar();
        return 0;
        }
    return 0;
}
    
    
//
//    ===============================================
//    scanf("%d",&Index);
//    if (Index == 1)
//        return 1;
//    else if (Index ==2) {
//        printf(" ==================================\n");
//        printf(" 놓고 가시는 물건은 없는지 확인하여 주십시오.\n\t\t 이용해주셔서 감사합니다. \n\t\t\tTHANK YOU\n");
//        printf(" ==================================\n");
//        getchar();
//        return 0;
//        }
//    return 0;
//}
int register_giftCards(char* file_name, gift_struct* gift) {
    FILE* fp = fopen ( file_name, "a"); // fopen 함수일때 "a"모드로 실행한다라고 표현 ("a":덧붙이기,"w" : 쓰기 모드,"r" : 읽기 모드)
    if (fp == NULL) {
        printf("\n 파일을 불러오는데 실패했습니다. : %s\n",file_name);
        return 1;
    }
    printf("상품권 등록 저장완료\n");
    int line;
    line = countFileLines(file_name);
    fprintf (fp, "%s,%s,%d\n", gift->gift_num, gift->expiry_date, gift->balance);
    fclose(fp);
//    printf(" \n FLIE \"new_gitf.csv\" write success !\n");
//        return 0;
    return  0;
    }

