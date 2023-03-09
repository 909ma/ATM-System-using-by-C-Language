#pragma oncde
#include <stdio.h>

typedef struct  {
    int gift_num;
    char expiry_date[11];
    int balance;
    
}gift_struct; // 구조체 이름

int gift_csv_file(char* file_name,gift_struct* gift) {
    FILE* fp = fopen ( file_name, "w"); // fopen 함수일때 "w"모드로 실행한다라고 표현 ("w" : 쓰기 모드,"r" : 읽기 모드)
    if (fp == '\0') {
        printf("\n File open error : %s\n",file_name);
        return 1;
    }
    fprintf (fp, "상품권 번호,유효기간,잔액\n");
    fprintf (fp, "%d,%d,%d\n", gift->gift_num, gift->expiry_date, gift->balance);
    fclose(fp);
//    printf(" \n FLIE \"new_gitf.csv\" write success !\n");
        return 0;
    }

int file() {

    gift_struct gift;
    printf(" 상품권 번호 : ");
    scanf("%d",&gift.gift_num);
    printf(" 유효기간 : ");
    rewind(stdin);
    fgets(gift.expiry_date,sizeof(gift.expiry_date),stdin);
    printf(" 잔  액: ");
    scanf("%d",&gift.balance);
    gift_csv_file("new_gift.csv",&gift);
//    if (temp == 0) // 정상적으로 진행
//    else if(temp == 1) // 오류 발생
//        printf("FLIE \"new_gitf.csv\" write success !\n");
    return 0;
}
