#include<stdio.h>
#include<conio.h>
#include"ViewAccount.h"
#include"withdraw.h"

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

int main()
{
	int MenuNum;
	Person* people = malloc(sizeof(Person) * 100);
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
	default:
		printf("�ٽ� �Է����ּ���\n");
		goto RE;
	}

	return 0;
}