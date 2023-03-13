#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PersonStruct.h"
#include "search_and_change.h"

int TrafficCard(Person*person)
{
	int option = 0;
	int dp, wd, select1=0;
	if (strcmp(person->BankName,"교통카드")!=0)
	{
		printf("교통카드가 아닙니다\n");
		return 0;
	}
	else
	{
		printf("현재잔액은 %d원입니다.\n",person->NowMoney);
		printf("원하시는 메뉴를 선택해주십시오\n");
		printf(" 1. 충전\n 2. 환불 \n 3. 취소\n");
		scanf("%d", &option);
		switch (option)
		{
		case 1:
		{
			printf("현금을 넣어주세요\n");
			scanf("%d", &dp);
			printf("입금중입니다.\n");
			person->NowMoney += dp;
			break;
		}
		case 2:
		{
			while (1)
			{			
				printf("환불할 금액을 정하세요\n");
				scanf("%d", &wd);
				if (wd > person->NowMoney)
				{
					printf("현금을 출력할수 없습니다.\n다시 입력하시겠습니까?[네:1/아니오:2]\n");
					scanf("%d", &select1);
					if (select1 == 1);
					else if (select1 == 2)
						break;
				}
				else
				{
					printf("현금을 출력중입니다.\n");
					person->NowMoney -= wd;
					break;
				}
			}
			break;
		}
		case 3:
		{
			printf("거래가 취소되었습니다.\n");
			break;
		}
		}
		if (option != 3)printf("총 잔액은 %d원입니다.\n", person->NowMoney);
		printf("잠시 후 메인화면으로 돌아갑니다.\n");
		return 0;
	}
	
}

int main()
{
	Person person;
	Person* people = malloc(sizeof(Person) * 100);
	int a;
	a = search("people.csv", people, &person);
	if (a == 0)
	{
		TrafficCard(&person);
		change("people.csv", people, &person);
	}
	else
		printf("결제가 취소되었습니다.\n");
	free(people);
	return 0;
}