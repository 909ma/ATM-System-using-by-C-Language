#pragma once
#include<stdio.h>

void showMenu()
{
	printf("\n\n======[    �޴�    ]=======\n\n");
	printf("1.	���� ��ȸ\n\n");
	printf("2.	���� �Ա�\n\n");
	printf("3.	���� ���\n\n");
	printf("4.	���� ��ü\n\n");
	printf("5.	���� ����\n\n");
	printf("6.	�ΰ� ����\n\n");
	printf("7.	��� ����\n\n");

}

void showAdminMenu()
{
	printf("\n\n======[   ������ �޴�    ]=======\n\n");
	printf("1.	������ ��ü ��ȸ\n\n");
	printf("2.	���� ����\n\n");
	printf("3.	���� ����\n\n");
	printf("4.	��� ����\n\n");
}

void payMenu()
{
	printf("\n\n======[   ���� ���� �޴�    ]=======\n\n");
	printf("1.	��Ģ�� ���� ����\n\n");
	printf("2.	������ ���� ����\n\n");
	printf("3.	    �ڷ� ����\n\n");
}

void addtionMenu()
{
	printf("\n\n======[   �ΰ����� �޴�    ]=======\n\n");
	printf("1.	����ī�� ����\n\n");
	printf("2.	��ǰ�� �ŷ� ����\n\n");
	printf("3.	    �ڷ� ����\n\n");
}

void trafficCard()
{
	printf("\n\n======[   ����ī�� �޴�    ]=======\n\n");
	printf("1.	���� ���\n\n");
	printf("2.	ȯ�� ���\n\n");
	printf("2.	��� ���\n\n");
}

void admin_Func()
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
		if (BackToMenu() == 1)
			goto RESHOW;
		break;
	case 2:
		CreatAccount();
		MergeAccount();
		NameChange();
		if (BackToMenu() == 1)
			goto RESHOW; 
		break;
	case 3:
		CloseAccount();
		if (BackToMenu() == 1)
			goto RESHOW;
		break;
	case 4:
		printf("����� �����մϴ�\n");
		break;
	default:
		printf("�ٽ� �Է����ּ���\n");
		goto RE;
	}

}

void pay_Func()
{
	int MenuNum;
	int menuSelect;
	int a;
	int line = getTotalLine("people.csv");
	Person person;
	Person* people = malloc(sizeof(Person) * 150);
RESHOW:
	payMenu();
RE:
	printf("\n���ϴ� ��� ���� : ");
	scanf("%d", &MenuNum);
	switch (MenuNum)
	{
	case 1:
		a = search("people.csv", people, &person, line);
		if (a == 0)
		{
			Fine(&person);
			change("people.csv", people, &person, line);
		}
		else
			printf("������ ��ҵǾ����ϴ�.\n");
		free(people);
		if (BackToMenu() == 1)
			goto RESHOW;
		break;
	case 2:
		a = search("people.csv", people, &person, line);
		if (a == 0)
		{
			Utilities(&person);
			change("people.csv", people, &person, line);
		}
		else
			printf("������ ��ҵǾ����ϴ�.\n");
		free(people);
		if (BackToMenu() == 1)
			goto RESHOW;
		break;
	case 3:
		system("cls");
		main();
		break;
	default:
		printf("�ٽ� �Է����ּ���\n");
		goto RE;
	}
}

void addtion_Func()
{
	int MenuNum;
	int menuSelect;
	int a;
	int line = getTotalLine("people.csv");
	Person person;
	Person* people = malloc(sizeof(Person) * 150);
RESHOW:
	addtionMenu();
RE:
	printf("\n���ϴ� ��� ���� : ");
	scanf("%d", &MenuNum);
	switch (MenuNum)
	{
	case 1:
		a = search("people.csv", people, &person, line);
		if (a == 0)
		{
			TrafficCard(&person);
			change("people.csv", people, &person, line);
		}
		else
			printf("������ ��ҵǾ����ϴ�.\n");
		free(people);
		if (BackToMenu() == 1)
			goto RESHOW;
		break;
	case 2:

		break;
	case 3:
		system("cls");
		main();
		break;
	default:
		printf("�ٽ� �Է����ּ���\n");
		goto RE;
	}
}