#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include"ViewAccount.h"

void gotoxy(int x, int y)
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int TrafficCard(int *cash)
{
	int option = 0;
	char select;
	int dp, wd;
	int x=0, y=2;
	system("cls");
	printf("현재잔액은 %d원입니다.\n", *cash);
	printf("원하시는 메뉴를 선택해주십시오(선택: a)\n");
	printf("  1. 충전\n  2. 환불 \n  3. 취소\n");

	gotoxy(x, y);
	while(1)
	{
		printf(">>\b\b");

		if ((select = getch()) == 'a')
			break;
		if (select == 72&&y>2)
		{		
			printf("  \b\b");
			y--;
		}
		if (select == 80&&y<4)
		{
			printf("  \b\b");
			y++;
		}
		gotoxy(x, y);
	}
	option = y-1;	
	gotoxy(0, 5);


	switch (option)
	{
	case 1:
	{
		printf("현금을 넣어주세요\n");
		scanf("%d", &dp);
		printf("입금중입니다.\n");
		*cash += dp;
		break;
	}
	case 2:
	{
		printf("환불할 금액을 정하세요\n");
		scanf("%d", &wd);
		if (wd > *cash || wd==0||wd%10000!=0)
		{
			printf("현금을 출력할수 없습니다.\n");
		}
		else
		{
			printf("현금을 출력중입니다.\n");
			*cash -= wd;
		}
		break;
	}
	case 3:
	{
		printf("거래가 취소되었습니다.\n");
		break;
	}
	}
	if (option != 3)printf("총 잔액은 %d원입니다.\n", *cash);
	printf("잠시 후 메인화면으로 돌아갑니다.\n");

	return 0;
}

int main()
{
	int cash=10000;
	TrafficCard(&cash);
	return 0;
}