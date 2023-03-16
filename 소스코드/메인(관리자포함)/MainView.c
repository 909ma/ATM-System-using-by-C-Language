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
	printf("원하는 기능 선택 : ");
	scanf("%d", &MenuNum);
	switch (MenuNum)
	{
	case 1:
		ViewAccount();
		printf("\n1. 이전메뉴 돌아가기\t 2. 사용 종료\n\n");
		printf("선택 : ");
		scanf("%d", &menuSelect);
		if (menuSelect == 1)
		{
			system("cls");
			goto RESHOW;
		}
		else
			printf("사용종료\n");
		break;
	case 2:
		CreatAccount();
		printf("\n1. 이전메뉴 돌아가기\t 2. 사용 종료\n\n");
		printf("선택 : ");
		scanf("%d", &menuSelect);
		if (menuSelect == 1)
		{
			system("cls");
			goto RESHOW;
		}
		else
			printf("사용종료\n");
		break;
	case 3:
		CloseAccount();
		printf("\n1. 이전메뉴 돌아가기\t 2. 사용 종료\n\n");
		printf("선택 : ");
		scanf("%d", &menuSelect);
		if (menuSelect == 1)
		{
			system("cls");
			goto RESHOW;
		}
		else
			printf("사용종료\n");
		break;
	case 4:
		remit();
		printf("\n1. 이전메뉴 돌아가기\t 2. 사용 종료\n\n");
		printf("선택 : ");
		scanf("%d", &menuSelect);
		if (menuSelect == 1)
		{
			system("cls");
			goto RESHOW;
		}
		else
			printf("사용종료\n");
		break;
	default:
		printf("다시 입력해주세요\n");
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
	printf("원하는 기능 선택 : ");
	scanf("%d", &MenuNum);
	switch (MenuNum)
	{
	case 1:
		printf("\n");
		ViewMycash("people.csv", people);
		printf("\n1. 이전메뉴 돌아가기\t 2. 사용 종료\n\n");
		printf("선택 : ");
		scanf("%d", &menuSelect);
		if (menuSelect == 1)
		{
			system("cls");
			goto RESHOW;
		}
		else
			printf("사용종료\n");
		break;
	case 2:
		printf("\n");
		deposit("people.csv", people);
		printf("\n1. 이전메뉴 돌아가기\t 2. 사용 종료\n\n");
		printf("선택 : ");
		scanf("%d", &menuSelect);
		if (menuSelect == 1)
		{
			system("cls");
			goto RESHOW;
		}
		else
			printf("사용종료\n");
		break;
	case 3:
		printf("\n");
		withdraw("people.csv", people);
		printf("\n1. 이전메뉴 돌아가기\t 2. 사용 종료\n\n");
		printf("선택 : ");
		scanf("%d", &menuSelect);
		if (menuSelect == 1)
		{
			system("cls");
			goto RESHOW;
		}
		else
			printf("사용종료\n");
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		printf("사용을 종료합니다\n");
		break;
	case 1111:
		printf("관리자 모드 접속 완료\n");
		system("cls");
		admin();
		break;
	default:
		printf("다시 입력해주세요\n");
		goto RE;
	}

	return 0;
}