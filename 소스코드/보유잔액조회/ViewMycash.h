#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable: 4996)
#pragma once

#include "PersonStruct.h"
#include "ViewAccount.h"

/*
보유잔액을 조회하는 함수입니다...
ViewMycash() 입니다...
*/


int ViewMycash()
{
    int a = 99;
    Person* people = malloc(sizeof(Person) * 100); // 최대 100명의 사람 정보를 저장할 수 있는 배열 동적 할당
    read_csv_file("people.csv", people, a + 1); // a의 인원수를 조회

    char answer[10];
    printf("\n");
    printf("   ---------------------------------------\n");
    printf("\n");
    printf("         보유잔액 조회를 선택하셨습니다.       \n");
    printf("\n");
    printf("   ---------------------------------------\n");
    printf("        \n");
    printf("\n보이스피싱 관련 연락을 받으셨나요? (예/아니오): ");
    scanf("%s", answer);

    if (strcmp(answer, "아니오") != 0)
    {
        printf("\n보이스피싱 방지를 위해 종료합니다. 이용해주셔서 감사합니다.\n");
        return 1;
    }

    int CardNumber, AccountNumber, AccountPW, state = -1;
    int retry_count = 0; // 재시도 횟수를 저장할 변수

    do {
        printf("\n");
        printf("   ---------------------------------------\n");
        printf("\n");
        printf("             숫자를 입력해주세요.             \n");
        printf("\n");
        printf("   ---------------------------------------\n");
        printf("\n");

        printf("\n카드번호를 입력해주세요. (4자리) : ");
        scanf("%d", &CardNumber);

        printf("\n계좌번호를 입력해주세요. (3자리) : ");
        scanf("%d", &AccountNumber);

        printf("\n비밀번호를 입력해주세요. (4자리) : ");
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
            printf("\n입력하신 정보가 올바르지 않습니다. 다시 입력해주세요.\n");

            retry_count++;

            if (retry_count >= 3) {
                printf("\n3회 이상 잘못된 정보를 입력하셨습니다. 이용해주셔서 감사합니다.\n");
                return 1;
            }
        }
    } while (state == -1);

    printf("\n");
    printf("   ---------------------------------------\n");
    printf("\n");
    printf("                현재 보유잔액 입니다.            \n");
    printf("\n");
    printf("   ---------------------------------------\n");
    printf("\n");
    printf("   |  No. |    은행명    |    고객명    |   보유잔액   |\n");
    printf("   --------------------------------------------\n");
    printf("   | %3d  |  %5s은행  | %8s고객님  | %8d원    |\n", state, people[state].BankName, people[state].ClientName, people[state].NowMoney);
    printf("   --------------------------------------------\n");

    return 0;
}

