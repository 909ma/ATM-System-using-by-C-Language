#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PersonStruct.h"
#include "search_and_change.h"

int TrafficCard(Person*person)
{
	int option = 0;
	int dp, wd, select1=0;
	if (strcmp(person->BankName,"����ī��")!=0)
	{
		printf("����ī�尡 �ƴմϴ�\n");
		return 0;
	}
	else
	{
		printf("�����ܾ��� %d���Դϴ�.\n",person->NowMoney);
		printf("���Ͻô� �޴��� �������ֽʽÿ�\n");
		printf(" 1. ����\n 2. ȯ�� \n 3. ���\n");
		scanf("%d", &option);
		switch (option)
		{
		case 1:
		{
			printf("������ �־��ּ���\n");
			scanf("%d", &dp);
			printf("�Ա����Դϴ�.\n");
			person->NowMoney += dp;
			break;
		}
		case 2:
		{
			while (1)
			{			
				printf("ȯ���� �ݾ��� ���ϼ���\n");
				scanf("%d", &wd);
				if (wd > person->NowMoney)
				{
					printf("������ ����Ҽ� �����ϴ�.\n�ٽ� �Է��Ͻðڽ��ϱ�?[��:1/�ƴϿ�:2]\n");
					scanf("%d", &select1);
					if (select1 == 1);
					else if (select1 == 2)
						break;
				}
				else
				{
					printf("������ ������Դϴ�.\n");
					person->NowMoney -= wd;
					break;
				}
			}
			break;
		}
		case 3:
		{
			printf("�ŷ��� ��ҵǾ����ϴ�.\n");
			break;
		}
		}
		if (option != 3)printf("�� �ܾ��� %d���Դϴ�.\n", person->NowMoney);
		printf("��� �� ����ȭ������ ���ư��ϴ�.\n");
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
		printf("������ ��ҵǾ����ϴ�.\n");
	free(people);
	return 0;
}