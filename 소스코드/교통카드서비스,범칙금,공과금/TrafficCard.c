#include <stdio.h>

int TrafficCard(int *cash)
{
	int option = 0;
	int dp, wd,code;
	
	printf("�����ܾ��� %d���Դϴ�.\n", *cash);
	printf("���Ͻô� �޴��� �������ֽʽÿ�\n");
	printf(" 1. ����\n 2. ȯ�� \n 3. ���\n");
	scanf("%d", &option);
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
		if (wd > *cash)
		{
			printf("������ ����Ҽ� �����ϴ�.\n�ٽ� �Է��Ͻðڽ��ϱ�?[��/�ƴϿ�]\n");
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
	int cash=1000;
	TrafficCard(&cash);
	return 0;
}