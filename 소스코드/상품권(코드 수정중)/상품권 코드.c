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
    printf(" \t\t\t[ �޴� ]\n\n");
    printf(" 1. ��ǰ�� ���\n 2. ��ǰ�� ��� ����\n 3. ��ǰ�� �ŷ�\n 4. ó������\n 5. �������\n");
    printf(" ==================================\n");
    printf(" �̿��Ͻ� ��ȣ�� �����ϼ��� : ");
    scanf("%d", &input);
    if (input == 1) {
        
        printf("\n\t\t [ ��ǰ�� ��� ]\n");
        
        temp=giftCards(&gift);
        register_giftcard("new_gift.csv", &gift);
        if (temp == 1)
            goto START;
        else if (temp == 2)        // �� temp �� ������ temp == 2 return 0;������..????????
            return 0;
    }
    else if (input == 2) {
        printf("\n\t\t [ ��ǰ�� ��� ���� ]\n");
        temp = giftCards_cancle(voucher, &gift, total_line);
        if (temp == 1)
            goto START;
    }
    else if (input == 3) {
        printf("\n\t\t [ ��ǰ�� �ŷ� ]\n");
        temp = deal();
        if (temp == 1)
            goto START;
    }
    else if (input == 4)
        goto START;
    else if (input == 5) {
        printf(" ==================================\n");
        printf(" ���� ���ô� ������ ������ Ȯ���Ͽ� �ֽʽÿ�.\n\t\t �̿����ּż� �����մϴ�. \n\t\t\tTHANK YOU\n");
        printf(" ==================================\n");
        getchar();
        return 0;  //<��Tip!>  getchar(); return 0; �� �ϸ� ���α׷����� ������ �� (�ļ�����)
    }
    else
        printf(" �߸��� �Է��Դϴ�.\n");

    free(voucher);
    return 0;
}

