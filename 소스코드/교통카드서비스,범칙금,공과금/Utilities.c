#include <stdio.h>

int Utilities(int*cash)
{
	int list;
	char name[30] = "";
	int fee;
	printf("�� ����\n");
	scanf("%s", name);
	printf("%s �� ����Ʈ\n", name);
	scanf("%d", &list);
	printf("%d %s ������ ������ ���αݾ��� �Է��ϼ���\n",list,name);
	scanf("%d", &fee);
	if (*cash < fee)
		printf("���ο� �����Ͽ����ϴ�.\n");
	else
	{
		*cash -= fee;
		printf("���ΰ� �Ϸ�Ǿ����ϴ�.\n");
		printf("�� �ڵ�: %d\n", list);
		printf("����: %s\n",name);
		printf("���ξ�: %d\\\n",fee);
		printf("�ܾ�: %d\\\n", *cash);
	}
	printf("\n��� �� ���� ȭ������ ���ư��ϴ�.\n");
	return 0;
}