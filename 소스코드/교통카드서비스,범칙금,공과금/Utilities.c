#include <stdio.h>

int Utilities(int*cash)
{
	int list;
	char name[30] = "";
	int fee;
	printf("고객 명의\n");
	scanf("%s", name);
	printf("%s 고객 리스트\n", name);
	scanf("%d", &list);
	printf("%d %s 고객님의 공과금 납부금액을 입력하세요\n",list,name);
	scanf("%d", &fee);
	if (*cash < fee)
		printf("납부에 실패하였습니다.\n");
	else
	{
		*cash -= fee;
		printf("납부가 완료되었습니다.\n");
		printf("고객 코드: %d\n", list);
		printf("고객명: %s\n",name);
		printf("납부액: %d\\\n",fee);
		printf("잔액: %d\\\n", *cash);
	}
	printf("\n잠시 후 메인 화면으로 돌아갑니다.\n");
	return 0;
}