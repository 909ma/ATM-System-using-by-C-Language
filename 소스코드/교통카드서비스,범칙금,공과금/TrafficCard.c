#include <stdio.h>

int TrafficCard(int *cash)
{
	int option = 0;
	int dp, wd,code;
	
	printf("현재잔액은 %d원입니다.\n", *cash);
	printf("원하시는 메뉴를 선택해주십시오\n");
	printf(" 1. 충전\n 2. 환불 \n 3. 취소\n");
	scanf("%d", &option);
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
		if (wd > *cash)
		{
			printf("현금을 출력할수 없습니다.\n다시 입력하시겠습니까?[네/아니오]\n");
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
	int cash=1000;
	TrafficCard(&cash);
	return 0;
}