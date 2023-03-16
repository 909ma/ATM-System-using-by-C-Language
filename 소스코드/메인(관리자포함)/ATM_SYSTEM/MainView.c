#pragma once
#pragma warning(disable:4996)

#include<stdio.h>
#include<conio.h>
#include"ViewAccount.h" 
#include"User_Function.h"
#include"Menu.h"
#include"Admin_Function.h"
#include"Addtion_Function.h"
#include"remit.h"


int main()
{
	int MenuNum;
	Person* people = malloc(sizeof(Person) * 100);
RESHOW:
	showMenu();
RE:
	printf("원하는 기능을 선택해주세요 : ");
	scanf("%d", &MenuNum);
	switch (MenuNum)
	{
	case 1:
		printf("\n");
		ViewMycash("people.csv", people);
		if (BackToMenu() == 1)
			goto RESHOW;
		break;
	case 2:
		printf("\n");
		deposit("people.csv", people);
		if (BackToMenu() == 1)
			goto RESHOW;
		break;
	case 3:
		printf("\n");
		withdraw("people.csv", people);
		if (BackToMenu() == 1)
			goto RESHOW;
		break;
	case 4:
		printf("\n");
		remit();		
		if (BackToMenu() == 1)
			goto RESHOW;
		break;
	case 5:
		printf("\n");
		pay_Func();
		break;
	case 6:
		system("cls");
		addtion_Func();
		break;
	case 7:
		printf("사용을 종료합니다\n");
		break;
	case 1111:
		system("cls");
		admin_Func();
		break;
	default:
		printf("다시 입력해주세요\n");
		goto RE;
	}

	return 0;
}