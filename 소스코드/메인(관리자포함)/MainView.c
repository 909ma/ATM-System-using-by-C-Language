#include<stdio.h>
#include<conio.h>
#include"ViewAccount.h"
#include"CreatAccount.h"
#include"withdraw.h"
#include"Menu.h"

void admin()
{
	int MenuNum;
	int menuSelect;
	Person* people = malloc(sizeof(Person) * 100);
RESHOW:
	showAdminMenu();
RE:
	printf("���ϴ� ��� ���� : ");
	scanf("%d", &MenuNum);
	switch (MenuNum)
	{
	case 1:
		ViewAccount(90);		
		printf("1. �����޴� ���ư���\t 2. ��� ����\n\n");
		printf("���� : ");
		scanf("%d", &menuSelect);
		if (menuSelect == 1)
		{
			system("cls");
			goto RESHOW;
		}
		else
			printf("�������\n");
		break;
	case 2:
		CreatAccount();
		printf("1. �����޴� ���ư���\t 2. ��� ����\n\n");
		printf("���� : ");
		scanf("%d", &menuSelect);
		if (menuSelect == 1)
		{
			system("cls");
			goto RESHOW;
		}
		else
			printf("�������\n");
		break;
	case 3:
		break;
	case 4:
		printf("����� �����մϴ�\n");
		break;
	default:
		printf("�ٽ� �Է����ּ���\n");
		goto RE;
	}
}
int main()
{
	int MenuNum;
	Person* people = malloc(sizeof(Person) * 100);
RESHOW:
	showMenu();
RE:
	printf("���ϴ� ��� ���� : ");
	scanf("%d", &MenuNum);
	switch (MenuNum)
	{
	case 1:
		break;
	case 2:
		break;
	case 3:
		printf("\n");
		withdraw("people.csv", people);
		printf("1. �����޴� ���ư���\t 2. ��� ����\n\n");
		int menuSelect;
		printf("���� : ");
		scanf("%d", &menuSelect);
		if (menuSelect == 1)
		{
			system("cls");
			goto RESHOW;
		}
		else
			printf("�������\n");
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		printf("����� �����մϴ�\n");
		break;
	case 1111:
		printf("������ ��� ���� �Ϸ�\n");
		system("cls");
		admin();
		break;
	default:
		printf("�ٽ� �Է����ּ���\n");
		goto RE;
	}

	return 0;
}