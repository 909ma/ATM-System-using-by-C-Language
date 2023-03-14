#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "search.h"
#include "PersonStruct.h"
#include "search_and_change.h" 

int Utilities(Person *person)
{
	int fee;
	if (strcmp(person->BankName, "������") != 0)
	{
		printf("������ ���θ� �� �� ���� �����Դϴ�.\n");
		return -1;
	}
	else
	{
		printf("%s ������ ������ ���αݾ��� �Է��ϼ���\n",person->ClientName);
		scanf("%d", &fee);
		if (person->NowMoney < fee)
			printf("���ο� �����Ͽ����ϴ�.\n");
		else
		{
			person->NowMoney -= fee;
			printf("���ΰ� �Ϸ�Ǿ����ϴ�.\n");
			printf("����: %s\n", person->ClientName);
			printf("���ξ�: %d\\\n",fee);
			printf("�ܾ�: %d\\\n", person->NowMoney);
		}
		printf("\n��� �� ���� ȭ������ ���ư��ϴ�.\n");
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
		printf("������ ��ҵǾ����ϴ�.\n");

	free(people);

	return 0;
}