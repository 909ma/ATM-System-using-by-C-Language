#include "typedef_struct.h"
//int main(){
//    file();
//        return 0;
//}
#include <stdio.h>
#include "giftCards.h"
#include "giftCards_cancle.h"
#include "deal.h"
#include "read.h"
int main() {
    int input;
    int temp;
    int total_line = getTotalLine("new_gift.csv");
    gift_struct gift;
    gift_struct* voucher=malloc(sizeof(gift_struct)*total_line);
    int gift_line = getGiftLine("new_gift.csv", voucher, &gift, total_line);
        //=malloc(100*sizeof(gift_struct));

START:
    printf(" \n==================================\n");
    printf(" \t\t\t[ 메뉴 ]\n\n");
    printf(" 1. 상품권 등록\n 2. 상품권 등록 해지\n 3. 상품권 거래\n 4. 처음으로\n 5. 사용종료\n");
    printf(" ==================================\n");
    printf(" 이용하실 번호를 선택하세요 : ");
    scanf("%d", &input);
    if (input == 1) {
        
        printf("\n\t\t [ 상품권 등록 ]\n");
        
        temp=giftCards(&gift);
        register_giftcard("new_gift.csv", &gift);
        if (temp == 1)
            goto START;
        else if (temp == 2)        // 왜 temp 로 했으며 temp == 2 return 0;했을까..????????
            return 0;
    }
    else if (input == 2) {
        printf("\n\t\t [ 상품권 등록 해지 ]\n");
        temp = giftCards_cancle(voucher, &gift, total_line);
        if (temp == 1)
            goto START;
    }
    else if (input == 3) {
        printf("\n\t\t [ 상품권 거래 ]\n");
        temp = deal();
        if (temp == 1)
            goto START;
    }
    else if (input == 4)
        goto START;
    else if (input == 5) {
        printf(" ==================================\n");
        printf(" 놓고 가시는 물건은 없는지 확인하여 주십시오.\n\t\t 이용해주셔서 감사합니다. \n\t\t\tTHANK YOU\n");
        printf(" ==================================\n");
        getchar();
        return 0;  //<꿀Tip!>  getchar(); return 0; 을 하면 프로그램에서 나가기 됨 (꼼수버젼)
    }
    else
        printf(" 잘못된 입력입니다.\n");

    free(voucher);
    return 0;
}

