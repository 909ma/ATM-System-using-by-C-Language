#include<stdio.h>
#include<conio.h>
#include"ViewAccount.h"
#include"User_Function.h"
#include"Menu.h"
#include"Admin_Function.h"
#include"remit.h"
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
		ViewAccount();
		printf("\n1. �����޴� ���ư���\t 2. ��� ����\n\n");
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
		printf("\n1. �����޴� ���ư���\t 2. ��� ����\n\n");
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
		CloseAccount();
		printf("\n1. �����޴� ���ư���\t 2. ��� ����\n\n");
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
		remit();
		printf("\n1. �����޴� ���ư���\t 2. ��� ����\n\n");
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
	default:
		printf("�ٽ� �Է����ּ���\n");
		goto RE;
	}

}
int main()
{
	int MenuNum;
	int menuSelect;
	Person* people = malloc(sizeof(Person) * 100);
RESHOW:
	showMenu();
RE:
	printf("���ϴ� ��� ���� : ");
	scanf("%d", &MenuNum);
	switch (MenuNum)
	{
	case 1:
		printf("\n");
		ViewMycash("people.csv", people);
		printf("\n1. �����޴� ���ư���\t 2. ��� ����\n\n");
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
		printf("\n");
		deposit("people.csv", people);
		printf("\n1. �����޴� ���ư���\t 2. ��� ����\n\n");
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
		printf("\n");
		withdraw("people.csv", people);
		printf("\n1. �����޴� ���ư���\t 2. ��� ����\n\n");
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