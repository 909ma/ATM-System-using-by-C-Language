#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "search.h"
#include "PersonStruct.h"
#include "search_and_change.h" 

int Utilities(Person *person)
{
	int fee;
	if (strcmp(person->BankName, "공과금") != 0)
	{
		printf("공과금 납부를 할 수 없는 계정입니다.\n");
		return -1;
	}
	else
	{
		printf("%s 고객님의 공과금 납부금액을 입력하세요\n",person->ClientName);
		scanf("%d", &fee);
		if (person->NowMoney < fee)
			printf("납부에 실패하였습니다.\n");
		else
		{
			person->NowMoney -= fee;
			printf("납부가 완료되었습니다.\n");
			printf("고객명: %s\n", person->ClientName);
			printf("납부액: %d\\\n",fee);
			printf("잔액: %d\\\n", person->NowMoney);
		}
		printf("\n잠시 후 메인 화면으로 돌아갑니다.\n");
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
		Utilities(&person);
		change("people.csv", people, &person);
	}
	else
		printf("결제가 취소되었습니다.\n");

	free(people);

	return 0;
}