#pragma once
#include<stdio.h>

void showMenu()
{
	printf("\n\n======[    메뉴    ]=======\n\n");
	printf("1.	계좌 조회\n\n");
	printf("2.	계좌 입금\n\n");
	printf("3.	계좌 출금\n\n");
	printf("4.	계좌 이체\n\n");
	printf("5.	계좌 납부\n\n");
	printf("6.	부가 서비스\n\n");
	printf("7.	사용 종료\n\n");

}

void showAdminMenu()
{
	printf("\n\n======[   관리자 메뉴    ]=======\n\n");
	printf("1.	데이터 전체 조회\n\n");
	printf("2.	계좌 개설\n\n");
	printf("3.	계좌 해지\n\n");
	printf("4.	사용 종료\n\n");
}

void addition()
{
	printf("\n\n======[   부가서비스 메뉴    ]=======\n\n");
	printf("1.	교통카드 서비스\n\n");
	printf("2.	상품권 거래 서비스\n\n");
}

void trafficCard()
{
	printf("\n\n======[   교통카드 메뉴    ]=======\n\n");
	printf("1.	충전 기능\n\n");
	printf("2.	환불 기능\n\n");
	printf("2.	취소 기능\n\n");
}

void admin_Func()
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
		if (BackToMenu() == 1)
			goto RESHOW;
		break;
	case 2:
		CreatAccount();
		if (BackToMenu() == 1)
			goto RESHOW;
		break;
	case 3:
		CloseAccount();
		if (BackToMenu() == 1)
			goto RESHOW;
		break;
	case 4:
		printf("사용을 종료합니다\n");
		break;
	default:
		printf("다시 입력해주세요\n");
		goto RE;
	}

}