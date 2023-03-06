#include<stdio.h>
#include<conio.h>
#include"ViewAccount.h"
#include"withdraw.h"
#include"Main.h"

int main()
{
	int MenuNum;
	Person* people = malloc(sizeof(Person) * 100);
RESHOW:
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
		printf("1. 이전메뉴 돌아가기\t 2. 사용 종료\n\n");
		int menuSelect;
		printf("선택 : ");
		scanf("%d", &menuSelect);
		if (menuSelect == 1)
		{
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
	default:
		printf("다시 입력해주세요\n");
		goto RE;
	}
 
	return 0;
}
