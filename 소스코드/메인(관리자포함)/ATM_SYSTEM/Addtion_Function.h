// ����ī�� , ��ǰ�� ����

#pragma once
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ExtraFunc.h"
#include "GiftStruct.h"

int input_num;
int cash;
int Index;
int num_10000, num_50000, num_100000;

int TrafficCard(Person* person)
{
	int option = 0;
	int dp, wd, select1 = 0;
	if (strcmp(person->BankName, "����ī��") != 0)
	{
		printf("\n\n����ī�尡 �ƴմϴ�\n");
		return 0;
	}
	else
	{
		printf("\n�����ܾ��� %d���Դϴ�.\n", person->NowMoney);
		printf("\n\n���Ͻô� �޴��� �������ֽʽÿ�\n");
		printf("\n\n 1. ���� 2. ȯ��  3. ���\n");
		printf("\n\n �Է� : ");
		scanf("%d", &option);
		switch (option)
		{
		case 1:
		{
			printf("\n������ �־��ּ��� : ");
			scanf("%d", &dp);
			printf("\n�Ա����Դϴ�.\n");
			person->NowMoney += dp;
			break;
		}
		case 2:
		{
			while (1)
			{
				printf("\nȯ���� �ݾ��� ���ϼ��� : ");
				scanf("%d", &wd);
				if (wd > person->NowMoney)
				{
					printf("\n������ ����Ҽ� �����ϴ�. �ٽ� �Է��Ͻðڽ��ϱ�?\n[1. ��	2. �ƴϿ�]\n");
					scanf("%d", &select1);
					if (select1 == 1);
					else if (select1 == 2)
						break;
				}
				else
				{
					printf("\n������ ������Դϴ�.\n");
					person->NowMoney -= wd;
					break;
				}
			}
			break;
		}
		case 3:
		{
			printf("\n�ŷ��� ��ҵǾ����ϴ�.\n");
			break;
		}
		}
		if (option != 3)printf("\n�� �ܾ��� %d���Դϴ�.\n", person->NowMoney);
		printf("\n��� �� ����ȭ������ ���ư��ϴ�.\n");
		return 0;
	}

}

int giftCards(gift_struct* gift) {

    rewind(stdin);
    while (1) {  
        // ����ó�� : ��ǰ�� ������ȣ 16�ڸ� or 18�ڸ��� �Է��ϰ� ��
        printf(" ��ǰ�� ������ȣ : ");
        fgets(gift->gift_num, sizeof(gift->gift_num), stdin);
        if (strlen(gift->gift_num) != 17 && strlen(gift->gift_num) != 15) {
            printf("\n\t\t\t  Error!! \n");
            printf("  \" �߸��� �����Դϴ�. �ٽ� �Է����ּ���. \"\n\n");
            continue;
        }
        break;
    }
    for (int i = 0; sizeof(gift->gift_num); i++) {
        if (gift->gift_num[i] == '\n') {
            gift->gift_num[i] = '\0'; //��ó��
            break;
        }
    }
    rewind(stdin);
    while (1) {
        printf(" ��ȿ�Ⱓ(YYYY-MM-DD) : ");
        fgets(gift->expiry_date, sizeof(gift->expiry_date), stdin);

        if (gift->expiry_date[4] != '-') {
            printf("\n\t\t\t  Error!! \n");
            printf("  \" �߸��� �����Դϴ�. �ٽ� �Է����ּ���. \"\n");
            continue;
        }   
        if (gift->expiry_date[7] != '-') {
            printf("\n\t\t\t  Error!! \n");
            printf("  \" �߸��� �����Դϴ�. �ٽ� �Է����ּ���. \"\n");
            continue;
        }   //7��° '-'�Է� �ƴҽ� ����ó��
        if (gift->expiry_date[0] < '0' || gift->expiry_date[0] >'9') {
            printf("\n\t\t\t  Error!! \n");
            printf("  \" �߸��� �����Դϴ�. �ٽ� �Է����ּ���. \"\n");
            continue;
        }   //0��° ���� �Է� �ƴҽ� ����ó��
        if (gift->expiry_date[1] < '0' || gift->expiry_date[1] >'9') {
            printf("\n\t\t\t  Error!! \n");
            printf("  \" �߸��� �����Դϴ�. �ٽ� �Է����ּ���. \"\n");
            continue;
        }
        if (gift->expiry_date[2] < '0' || gift->expiry_date[2] >'9') {
            printf("\n\t\t\t  Error!! \n");
            printf("  \" �߸��� �����Դϴ�. �ٽ� �Է����ּ���. \"\n");
            continue;
        }
        if (gift->expiry_date[3] < '0' || gift->expiry_date[3] >'9') {
            printf("\n\t\t\t  Error!! \n");
            printf("  \" �߸��� �����Դϴ�. �ٽ� �Է����ּ���. \"\n");
            continue;
        }
        if (gift->expiry_date[5] < '0' || gift->expiry_date[5] >'9') {
            printf("\n\t\t\t  Error!! \n");
            printf("  \" �߸��� �����Դϴ�. �ٽ� �Է����ּ���. \"\n");
            continue;
        }
        if (gift->expiry_date[6] < '0' || gift->expiry_date[6] >'9') {
            printf("\n\t\t\t  Error!! \n");
            printf("  \" �߸��� �����Դϴ�. �ٽ� �Է����ּ���. \"\n");
            continue;
        }
        if (gift->expiry_date[8] < '0' || gift->expiry_date[8] >'9') {
            printf("\n\t\t\t  Error!! \n");
            printf("  \" �߸��� �����Դϴ�. �ٽ� �Է����ּ���. \"\n");
            continue;
        }
        if (gift->expiry_date[9] < '0' || gift->expiry_date[9] >'9') {
            printf("\n\t\t\t  Error!! \n");
            printf("  \" �߸��� �����Դϴ�. �ٽ� �Է����ּ���. \"\n");
            continue;
        }
        if (gift->expiry_date[10] != '\n') {
            printf("\n\t\t\t  Error!! \n");
            printf("  \" �߸��� �����Դϴ�. �ٽ� �Է����ּ���. \"\n");
            continue;
        }
        break;
    }
    for (int i = 0; sizeof(gift->expiry_date); i++) {
        if (gift->expiry_date[i] == '\n') {
            gift->expiry_date[i] = '\0';
            break;
        }
    }
    while (1) { //����ó�� : �ݾ� �Է½� 10000 ������ �Է��ϰ� ��
        printf(" �ݾ� : ");
        scanf("%d", &gift->balance);
        if (gift->balance % 10000 != 0)
        {
            rewind(stdin); // ���� �߸� �Է��� �̽� �ذ�
            printf("\n\t\t\t  Error!! \n");
            printf("\t\" �ݾ��� �ùٸ��� �Է����ּ���. \"\n");
        }
        else
            break;

    }
    printf(" ==================================\n");
    printf(" \t\t[ �ŷ��Ͻ� ��ǰ�� ���� ]\n\n");
    printf(" ��ǰ�� ������ȣ : %s\n", gift->gift_num);
    printf(" ��ǰ�� ��ȿ�Ⱓ : %s\n", gift->expiry_date);
    printf(" ��ǰ�� �ܾ� : %d��\n\n", gift->balance);
    printf(" ��ǰ�� ����� ó���Ǿ����ϴ�.\n");
    printf(" ==================================\n");
    printf(" 1. ���ݱ�ȯ\n 2. ��ǰ�� ��ȯ\n 3. ó������\n 4. �������\n");
    printf(" ==================================\n");
    printf(" �̿��Ͻ� ��ȣ�� �����ϼ��� : ");
    scanf("%d", &Index);
    if (Index == 1) {

        while (1) { //����ó�� : ���� �Է� ���ϰ� �ϱ� ����
            printf("\n\t\" �����Ͻ� �ż��� �Է��ϼ���. \"");
            printf("\n [ ���� ��ȯ ]\t 1������ : ");
            scanf("%d", &num_10000);
            if (num_10000 < 0) {
                printf("\n\t\t\t  Error!! \n");
                printf("\t\t\" �ٽ� �Է����ּ���. \"\n");
                continue;
            }
            printf(" \t\t\t 5������ : ");
            scanf("%d", &num_50000);
            if (num_50000 < 0) {
                printf("\n\t\t\t  Error!! \n");
                printf("\t\t\" �ٽ� �Է����ּ���. \"\n");
                continue;
            }
            int now_cash = gift->balance;
            if (now_cash < num_10000 * 10000 + num_50000 * 50000) {
                printf("\n\t\t\t Error!! \n");
                printf("\t���� �ݾ��� ��ǰ�� �ݾ׺��� Ů�ϴ�.\n\t\t  �ٽ� �Է��ϼ���.\n");
            }
            else
                break;
        }
        printf(" ==================================\n");
        printf("\t\t\t[��ǰ�� �ŷ� �Ϸ�]\n\n");
        printf(" [ ���� ��ȯ ]\t 1������ : %d��\n\t\t\t 5������ : %d��\n", num_10000, num_50000);
        printf(" \t\t\t ��   �� : %d��\n", num_10000 * 10000 + num_50000 * 50000);

        int cash_balance = gift->balance;//�ܾ�
        cash_balance = cash_balance - num_10000 * 10000 - num_50000 * 50000;
        printf(" \t\t\t ��   �� : %d��\n", cash_balance);
        gift->balance = cash_balance;
        printf("\n\t\t���������� �ŷ��� �Ϸ�Ǿ����ϴ�.\n");
        printf(" ==================================\n");
        if (BackToMenu() == 1)
        {
            system("cls");
            main();
        }
    }
    else if (Index == 2) {
        while (1) { //����ó�� : ���� �Է� ���ϰ� �ϱ� ����
            printf("�ż��� �Է����ּ���. ");
            printf(" \n [ ��ǰ�� ��ȯ ]\t 1������ : ");
            scanf("%d", &num_10000);
            if (num_10000 < 0) {
                printf("\n\t\t\t  Error!! \n");
                printf("\t\t\" �ٽ� �Է����ּ���. \"\n");
                continue;
            }
            printf(" 5������ : ");
            scanf("%d", &num_50000);
            if (num_50000 < 0) {
                printf("\n\t\t\t  Error!! \n");
                printf("\t\t\" �ٽ� �Է����ּ���. \"\n");
                continue;
            }
            printf(" 10������ : ");
            scanf("%d", &num_100000);
            if (num_100000 < 0) {
                printf("\n\t\t\t  Error!! \n");
                printf("\t\t\" �ٽ� �Է����ּ���. \"\n");
                continue;
            }
            int now_cash = gift->balance;
            if (now_cash < num_10000 * 10000 + num_50000 * 50000 + num_100000 * 100000) {
                printf("\n\t\t\t Error!! \n");
                printf("\t���� �ݾ��� ��ǰ�� �ݾ׺��� Ů�ϴ�.\n\t\t  �ٽ� �Է��ϼ���.\n");
            }
            else
                break;
        }
        printf(" ==================================\n");
        printf(" \t\t\t[ ��ǰ�� ��ȯ ]\n\t\t\t 1������ : %d��\n\t\t\t 5������ : %d��\n\t\t\t10������ : %d��\n\n", num_10000, num_50000, num_100000);
        printf(" \t\t ��   �� : %d��\n", num_10000 * 10000 + num_50000 * 50000 + num_100000 * 100000);
        int cash_balance = gift->balance;//�ܾ�
        cash_balance = cash_balance - num_10000 * 10000 - num_50000 * 50000 - num_100000 * 100000;
        printf(" \t\t ��   �� : %d��\n", cash_balance);
        gift->balance = cash_balance;
        printf(" ==================================\n");
        if (BackToMenu() == 1)
        {
            system("cls");
            main();
        }
    }
    else if (Index == 3)
    {
        system("cls");
        main();
    }

    return 0;
}

int register_giftCards(char* file_name, gift_struct* gift) {
    FILE* fp = fopen(file_name, "a"); // fopen �Լ��϶� "a"���� �����Ѵٶ�� ǥ�� ("a":�����̱�,"w" : ���� ���,"r" : �б� ���)
    if (fp == NULL) {
        printf("\n ������ �ҷ����µ� �����߽��ϴ�. : %s\n", file_name);
        return 1;
    }
    printf("\n----------��ǰ�� ���� ���� �Ϸ�----------\n");
    int line;
    line = countFileLines(file_name);
    fprintf(fp, "%s,%s,%d\n", gift->gift_num, gift->expiry_date, gift->balance);
    fclose(fp);
    return  0;
}

