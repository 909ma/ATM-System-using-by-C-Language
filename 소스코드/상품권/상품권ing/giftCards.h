#pragma once
#include <stdio.h>
#include <string.h>
#include "read.h"
#include "GiftStruct.h"

int input_num;
int cash;
int Index;
int num_10000, num_50000, num_100000;
//char expiry_date[11];

int giftCards(gift_struct* gift) {
    //gift=0;
//    while(getchar()!='\n');
    rewind(stdin);
    while(1) {  //for(;;){} 같은 의미임
                // 예외처리 : 상품권 고유번호 16자리 or 18자리만 입력하게 함
        printf(" 상품권 고유번호 : ");
        fgets(gift->gift_num,sizeof(gift->gift_num), stdin);
        if (strlen(gift->gift_num) != 17 && strlen(gift->gift_num) != 15) {
            printf("\n\t\t\t  Error!! \n");
            printf("  \" 잘못된 형식입니다. 다시 입력해주세요. \"\n\n");
            
            // printf("%d",strlen(gift->gift_num));
            // 예외처리 오류시 빨리 확인하는 방법
            continue;
        }
        break;
    }
    for(int i=0; sizeof(gift->gift_num); i++) {
        if (gift->gift_num[i] == '\n') {
            gift->gift_num[i] = '\0'; //후처리
            break;
        }
    }
//    while(getchar()!='\n');
    rewind(stdin);
//    rewind(stdin);
    while (1) {
        printf(" 유효기간(YYYY-MM-DD) : ");
        fgets(gift->expiry_date,sizeof(gift->expiry_date),stdin);
        if(gift->expiry_date[4] != '-') {
            printf("\n\t\t\t  Error!! \n");
            printf("  \" 잘못된 형식입니다. 다시 입력해주세요. \"\n");
            continue;
        }   //예외처리 : whlie과 if문 이용 (continue; 까지 입력)
            //YYYY-MM-DD
            //0123456789
            //i == 4 or i==7일 때, '-'이 있어야 함.
        if(gift->expiry_date[7] != '-') {
            printf("\n\t\t\t  Error!! \n");
            printf("  \" 잘못된 형식입니다. 다시 입력해주세요. \"\n");
            continue;
        }   //7번째 '-'입력 아닐시 예외처리
        if(gift->expiry_date[0] <'0' || gift->expiry_date[0] >'9') {
            printf("\n\t\t\t  Error!! \n");
            printf("  \" 잘못된 형식입니다. 다시 입력해주세요. \"\n");
            continue;
        }   //0번째 숫자 입력 아닐시 예외처리
        if(gift->expiry_date[1] <'0' || gift->expiry_date[1] >'9') {
            printf("\n\t\t\t  Error!! \n");
            printf("  \" 잘못된 형식입니다. 다시 입력해주세요. \"\n");
            continue;
        }
        if(gift->expiry_date[2] <'0' || gift->expiry_date[2] >'9') {
            printf("\n\t\t\t  Error!! \n");
            printf("  \" 잘못된 형식입니다. 다시 입력해주세요. \"\n");
            continue;
        }
        if(gift->expiry_date[3] <'0' || gift->expiry_date[3] >'9') {
            printf("\n\t\t\t  Error!! \n");
            printf("  \" 잘못된 형식입니다. 다시 입력해주세요. \"\n");
            continue;
        }
        if(gift->expiry_date[5] <'0' || gift->expiry_date[5] >'9') {
            printf("\n\t\t\t  Error!! \n");
            printf("  \" 잘못된 형식입니다. 다시 입력해주세요. \"\n");
            continue;
        }
        if(gift->expiry_date[6] <'0' || gift->expiry_date[6] >'9') {
            printf("\n\t\t\t  Error!! \n");
            printf("  \" 잘못된 형식입니다. 다시 입력해주세요. \"\n");
            continue;
        }
        if(gift->expiry_date[8] <'0' || gift->expiry_date[8] >'9') {
            printf("\n\t\t\t  Error!! \n");
            printf("  \" 잘못된 형식입니다. 다시 입력해주세요. \"\n");
            continue;
        }
        if(gift->expiry_date[9] <'0' || gift->expiry_date[9] >'9') {
            printf("\n\t\t\t  Error!! \n");
            printf("  \" 잘못된 형식입니다. 다시 입력해주세요. \"\n");
            continue;
        }
        if(gift->expiry_date[10] != '\n') {
            printf("\n\t\t\t  Error!! \n");
            printf("  \" 잘못된 형식입니다. 다시 입력해주세요. \"\n");
            continue;
        }
            break;
    }
    for(int i=0; sizeof(gift->expiry_date); i++) {
        if (gift->expiry_date[i] == '\n') {
            gift->expiry_date[i] = '\0';
            break;
        }
    }
    while (1) { //예외처리 : 금액 입력시 10000 단위로 입력하게 함
        printf(" 금액 : ");
        scanf("%d",&gift->balance);
        if(gift->balance % 10000 != 0)
        {
            rewind(stdin); // 문자 잘못 입력한 이슈 해결
            printf("\n\t\t\t  Error!! \n");
            printf("\t\" 금액을 올바르게 입력해주세요. \"\n");
            //printf("%d\n", gift->balance);
        }
        else
            break;
        
    }
    printf(" ==================================\n");
    printf(" \t\t[ 거래하실 상품권 정보 ]\n\n");
    printf(" 상품권 고유번호 : %s\n",gift->gift_num);
    printf(" 상품권 유효기간 : %s\n",gift->expiry_date);
    printf(" 상품권 잔액 : %d원\n\n",gift->balance);
    printf(" 상품권 등록이 처리되었습니다.\n");
    printf(" ==================================\n");
    printf(" 1. 현금교환\n 2. 상품권 교환\n 3. 처음으로\n 4. 사용종료\n");
    printf(" ==================================\n");
    printf(" 이용하실 번호를 선택하세요 : ");
    scanf("%d",&Index);
    if (Index == 1) {
       
        while (1) { //예외처리 : 음수 입력 못하게 하기 위함
            printf("\n\t\" 인출하실 매수를 입력하세요. \"");
            printf("\n [ 현금 교환 ]\t 1만원권 : ");
            scanf("%d",&num_10000);
            if (num_10000 <0) {
                printf("\n\t\t\t  Error!! \n");
                printf("\t\t\" 다시 입력해주세요. \"\n");
                continue;
            }
            printf(" \t\t\t 5만원권 : ");
            scanf("%d",&num_50000);
            if (num_50000 <0) {
                printf("\n\t\t\t  Error!! \n");
                printf("\t\t\" 다시 입력해주세요. \"\n");
                continue;
            }
            int now_cash =gift->balance;
            if (now_cash <num_10000*10000 +num_50000*50000) {
                printf("\n\t\t\t Error!! \n");
                printf("\t인출 금액이 상품권 금액보다 큽니다.\n\t\t  다시 입력하세요.\n");
            }
            else
                break;
        }
        printf(" ==================================\n");
        printf("\t\t\t[상품권 거래 완료]\n\n");
        printf(" [ 현금 교환 ]\t 1만원권 : %d매\n\t\t\t 5만원권 : %d매\n",num_10000,num_50000);
        printf(" \t\t\t 합   계 : %d원\n", num_10000 * 10000 + num_50000 * 50000);
        
        int cash_balance =gift->balance;//잔액
        cash_balance = cash_balance - num_10000* 10000 - num_50000* 50000;
        printf(" \t\t\t 잔   액 : %d원\n",cash_balance);
        gift->balance = cash_balance;
        printf("\n\t\t정상적으로 거래가 완료되었습니다.\n");
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
        while (1) { //예외처리 : 음수 입력 못하게 하기 위함
        printf("매수를 입력해주세요. ");
        printf(" \n [ 상품권 교환 ]\t 1만원권 : ");
        scanf("%d",&num_10000);
            if (num_10000 <0) {
//                printf("\n"); //실행시 한줄 띄어서 출력되지 않는 것 같은데...모지...???????
                printf("\n\t\t\t  Error!! \n");
                printf("\t\t\" 다시 입력해주세요. \"\n");
                continue;
            }
        printf(" 5만원권 : ");
        scanf("%d",&num_50000);
            if (num_50000 <0) {
                printf("\n\t\t\t  Error!! \n");
                printf("\t\t\" 다시 입력해주세요. \"\n");
                continue;
            }
        printf(" 10만원권 : ");
        scanf("%d",&num_100000);
            if (num_100000 <0) {
                printf("\n\t\t\t  Error!! \n");
                printf("\t\t\" 다시 입력해주세요. \"\n");
                continue;
            }
            int now_cash =gift->balance;
            if (now_cash <num_10000*10000 + num_50000*50000 + num_100000*100000) {
                printf("\n\t\t\t Error!! \n");
                printf("\t인출 금액이 상품권 금액보다 큽니다.\n\t\t  다시 입력하세요.\n");
            }
            else
                break;
        }
        printf(" ==================================\n");
        printf(" \t\t\t[ 상품권 교환 ]\n\t\t\t 1만원권 : %d매\n\t\t\t 5만원권 : %d매\n\t\t\t10만원권 : %d매\n\n",num_10000,num_50000,num_100000);
        printf(" \t\t 합   계 : %d원\n", num_10000 * 10000 + num_50000 * 50000 + num_100000 * 100000);
        int cash_balance =gift->balance;//잔액
        cash_balance = cash_balance - num_10000* 10000 - num_50000* 50000 -num_100000* 100000;
        printf(" \t\t 잔   액 : %d원\n",cash_balance);
        gift->balance = cash_balance;
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
    
int register_giftCards(char* file_name, gift_struct* gift) {
    FILE* fp = fopen ( file_name, "a"); // fopen 함수일때 "a"모드로 실행한다라고 표현 ("a":덧붙이기,"w" : 쓰기 모드,"r" : 읽기 모드)
    if (fp == NULL) {
        printf("\n 파일을 불러오는데 실패했습니다. : %s\n",file_name);
        return 1;
    }
    printf("\n----------상품권 정보 저장 완료----------\n");
    int line;
    line = countFileLines(file_name);
    fprintf (fp, "%s,%s,%d\n", gift->gift_num, gift->expiry_date, gift->balance);
    fclose(fp);
//    printf(" \n FLIE \"new_gitf.csv\" write success !\n");
//        return 0;
    return  0;
    }

