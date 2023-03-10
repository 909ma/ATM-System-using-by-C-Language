#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable: 4996)
#pragma once

#include "PersonStruct.h"
#include "ViewAccount.h"

/*
�����ܾ��� ��ȸ�ϴ� �Լ��Դϴ�...
ViewMycash() �Դϴ�...
*/


int ViewMycash()
{
    int a = 99;
    Person* people = malloc(sizeof(Person) * 100); // �ִ� 100���� ��� ������ ������ �� �ִ� �迭 ���� �Ҵ�
    read_csv_file("people.csv", people, a + 1); // a�� �ο����� ��ȸ

    char answer[10];
    printf("\n");
    printf("   ---------------------------------------\n");
    printf("\n");
    printf("         �����ܾ� ��ȸ�� �����ϼ̽��ϴ�.       \n");
    printf("\n");
    printf("   ---------------------------------------\n");
    printf("        \n");
    printf("\n���̽��ǽ� ���� ������ �����̳���? (��/�ƴϿ�): ");
    scanf("%s", answer);

    if (strcmp(answer, "�ƴϿ�") != 0)
    {
        printf("\n���̽��ǽ� ������ ���� �����մϴ�. �̿����ּż� �����մϴ�.\n");
        return 1;
    }

    int CardNumber, AccountNumber, AccountPW, state = -1;
    int retry_count = 0; // ��õ� Ƚ���� ������ ����

    do {
        printf("\n");
        printf("   ---------------------------------------\n");
        printf("\n");
        printf("             ���ڸ� �Է����ּ���.             \n");
        printf("\n");
        printf("   ---------------------------------------\n");
        printf("\n");

        printf("\nī���ȣ�� �Է����ּ���. (4�ڸ�) : ");
        scanf("%d", &CardNumber);

        printf("\n���¹�ȣ�� �Է����ּ���. (3�ڸ�) : ");
        scanf("%d", &AccountNumber);

        printf("\n��й�ȣ�� �Է����ּ���. (4�ڸ�) : ");
        scanf("%d", &AccountPW);

        for (int i = 1; i < a + 1; i++) {
            if (people[i].CardNumber == CardNumber) {
                state = i;

                if (people[i].AccountNumber == AccountNumber) {
                    if (people[state].AccountPW == AccountPW) {
                        break;
                    }
                    else {
                        state = -1;
                    }
                }
            }
        }

        if (state == -1) {
            printf("\n�Է��Ͻ� ������ �ùٸ��� �ʽ��ϴ�. �ٽ� �Է����ּ���.\n");

            retry_count++;

            if (retry_count >= 3) {
                printf("\n3ȸ �̻� �߸��� ������ �Է��ϼ̽��ϴ�. �̿����ּż� �����մϴ�.\n");
                return 1;
            }
        }
    } while (state == -1);

    printf("\n");
    printf("   ---------------------------------------\n");
    printf("\n");
    printf("                ���� �����ܾ� �Դϴ�.            \n");
    printf("\n");
    printf("   ---------------------------------------\n");
    printf("\n");
    printf("   |  No. |    �����    |    ����    |   �����ܾ�   |\n");
    printf("   --------------------------------------------\n");
    printf("   | %3d  |  %5s����  | %8s����  | %8d��    |\n", state, people[state].BankName, people[state].ClientName, people[state].NowMoney);
    printf("   --------------------------------------------\n");

    return 0;
}

