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
	printf("�����ܾ��� %d���Դϴ�.\n", *cash);
	printf("���Ͻô� �޴��� �������ֽʽÿ�(����: a)\n");
	printf("  1. ����\n  2. ȯ�� \n  3. ���\n");

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
		printf("������ �־��ּ���\n");
		scanf("%d", &dp);
		printf("�Ա����Դϴ�.\n");
		*cash += dp;
		break;
	}
	case 2:
	{
		printf("ȯ���� �ݾ��� ���ϼ���\n");
		scanf("%d", &wd);
		if (wd > *cash || wd==0||wd%10000!=0)
		{
			printf("������ ����Ҽ� �����ϴ�.\n");
		}
		else
		{
			printf("������ ������Դϴ�.\n");
			*cash -= wd;
		}
		break;
	}
	case 3:
	{
		printf("�ŷ��� ��ҵǾ����ϴ�.\n");
		break;
	}
	}
	if (option != 3)printf("�� �ܾ��� %d���Դϴ�.\n", *cash);
	printf("��� �� ����ȭ������ ���ư��ϴ�.\n");

	return 0;
}

int main()
{
	int cash=10000;
	TrafficCard(&cash);
	return 0;
}