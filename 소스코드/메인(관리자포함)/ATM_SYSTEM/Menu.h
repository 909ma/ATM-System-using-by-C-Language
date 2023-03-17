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

void payMenu()
{
	printf("\n\n======[   계좌 납부 메뉴    ]=======\n\n");
	printf("1.	범칙금 납부 서비스\n\n");
	printf("2.	공과금 납부 서비스\n\n");
	printf("3.	    뒤로 가기\n\n");
}

void addtionMenu()
{
	printf("\n\n======[   부가서비스 메뉴    ]=======\n\n");
	printf("1.	교통카드 서비스\n\n");
	printf("2.	상품권 거래 서비스\n\n");
	printf("3.	    뒤로 가기\n\n");
}

void giftCardMenu()
{
	printf("\n\n======[   상품권 메뉴    ]=======\n\n");
	printf("1.	상품권 거래 서비스\n\n");
	printf("2.	    뒤로 가기\n\n");
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
		printf("사용을 종료합니다\n");
		break;
	default:
		printf("다시 입력해주세요\n");
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
	PlaySound(TEXT(".\\BankVoice\\MenuChoice.wav"), NULL, SND_FILENAME | SND_ASYNC);
	printf("\n원하는 기능 선택 : ");
	scanf("%d", &MenuNum);
	checkKey(MenuNum);

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
		{
			PlaySound(TEXT(".\\BankVoice\\WorkCancel.wav"), NULL, SND_FILENAME | SND_ASYNC);
			printf("결제가 취소되었습니다.\n");
		}
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
		{
			PlaySound(TEXT(".\\BankVoice\\WorkCancel.wav"), NULL, SND_FILENAME | SND_ASYNC);
			printf("결제가 취소되었습니다.\n");
		}
		free(people);
		if (BackToMenu() == 1)
			goto RESHOW;
		break;
	case 3:
		system("cls");
		main();
		break;
	default:
		printf("다시 입력해주세요\n");
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
	PlaySound(TEXT(".\\BankVoice\\MenuChoice.wav"), NULL, SND_FILENAME | SND_ASYNC);
	printf("\n원하는 기능 선택 : ");
	scanf("%d", &MenuNum);
	checkKey(MenuNum);

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
		{
			PlaySound(TEXT(".\\BankVoice\\WorkCancel.wav"), NULL, SND_FILENAME | SND_ASYNC);
			Sleep(2000);
			PlaySound(TEXT(".\\BankVoice\\CheckAndBye.wav"), NULL, SND_FILENAME | SND_ASYNC);
			printf("결제가 취소되었습니다.\n");
		}
		free(people);
		if (BackToMenu() == 1)
			goto RESHOW;
		break;
	case 2:
		GiftCardFunc();
		break;
	case 3:
		system("cls");
		main();
		break;
	default:
		printf("다시 입력해주세요\n");
		goto RE;
	}
}
int GiftCardFunc()
{
	int MenuNum;
	int temp;
	gift_struct gift;
START:
	giftCardMenu();
	printf(" 이용하실 번호를 선택하세요 : ");
	scanf("%d", &MenuNum);
	switch (MenuNum)
	{
	case 1:
		printf("\n\t\t [ 상품권 거래 ]\n");
		temp = giftCards(&gift);
		register_giftCards("new_gift.csv", &gift);
		//if (temp == 1)
		//	goto START;
		break;
	case 2:
		system("cls");
		main();
		break;

	default:
		printf("다시 입력해주세요\n");
		goto START;
	}
	return 0;

}