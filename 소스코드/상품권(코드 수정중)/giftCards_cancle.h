#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "typedef_struct.h"
#define MAX_LINE_LEN 1000

int DeleteAccount(char file_path[100], int delete_index) {
    // ���� ����
    FILE* fp = fopen(file_path, "r");
    if (fp == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    // ���ο� ���� ����
    FILE* new_fp = fopen("temp.csv", "w");
    if (new_fp == NULL) {
        printf("Failed to create the new file.\n");
        return 1;
    }

    // ������ ���� ������ ������ ���ο� ���Ͽ� ��
    char line[MAX_LINE_LEN];
    int line_count = 0;
    while (fgets(line, MAX_LINE_LEN, fp) != NULL) {
        if (line_count != delete_index) {
            fprintf(new_fp, "%s", line);
        }
        line_count++;
    }
    // ���� �ݱ�
    fclose(fp);
    fclose(new_fp);
    // ���� ���� ����
    if (remove(file_path) != 0) {
        printf("Failed to delete the original file.\n");
        return 1;
    }
    // ���ο� ���� �̸� ����
    if (rename("temp.csv", file_path) != 0) {
        printf("Failed to rename the new file.\n");
        return 1;
    }
    printf("Line %d has been deleted from the file.\n", delete_index);
    return 0;
}

int giftCards_cancle(gift_struct * voucher,gift_struct* gift,int total_line) {
    printf(" ��ǰ�� ��ȣ : ");
    scanf("%s", &gift->gift_num);
    printf(" ��ȿ�Ⱓ(YYYY-MM-DD) : ");
    scanf(" %s", &gift->expiry_date);
    printf(" �ݾ� : ");
    scanf("%d", &gift->balance);
    printf(" ==================================\n");
    if (gift->balance != 0)
    {
        printf("��ǰ���� ������ �� �����ϴ�.\n");
    }
    else
    {
        int line=1;
        printf(" \t\t[ �����Ͻ� ��ǰ�� ���� ]\n\n");
        printf(" ��ǰ�� ��ȣ : %s\n", gift->gift_num);
        printf(" ��ǰ�� ��ȿ�Ⱓ : %s\n", gift->expiry_date);
        printf(" ��ǰ�� �ܾ� : %d��\n\n", gift->balance);     //  <�ܾ׿��� �����> 0���� ���, ��� ���� �Ϸ�,
        line=getGiftLine("new_gift.csv", voucher, &gift, total_line);
        DeleteAccount("new_gift.csv", line);
        printf(" ��ǰ�� ��� ������ ó���Ǿ����ϴ�.\n");
    }//                0���� �ƴ� ���, ���и���� ��� �����ұ�???????????
    printf(" ==================================\n");
    printf(" \t\t1. ó������   2. �������\n");
    printf(" ==================================\n");
    printf(" �̿��Ͻ� ��ȣ�� �����ϼ��� : ");
    int Index;
    scanf("%d", &Index);
    if (Index == 1)
        return 1;
    else if (Index == 2) {
        printf(" ==================================\n");
        printf(" ���� ���ô� ������ ������ Ȯ���Ͽ� �ֽʽÿ�.\n\t\t �̿����ּż� �����մϴ�. \n\t\t\tTHANK YOU\n");
        printf(" ==================================\n");
        getchar();
        return 0;
    }
    return 0;
}
