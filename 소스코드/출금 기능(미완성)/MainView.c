#include<stdio.h>
#include<conio.h>
#include"ViewAccount.h"
#include"withdraw.h"

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

int main()
{
	int MenuNum;
	Person* people = malloc(sizeof(Person) * 100);
	showMenu();
RE:
	printf("원하는 기능 선택 : ");
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
		printf("사용을 종료합니다\n");
		break;
	default:
		printf("다시 입력해주세요\n");
		goto RE;
	}

	return 0;
}