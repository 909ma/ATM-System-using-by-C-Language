#pragma once
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int getTotalLine(char* filename) { // csv������ �� ���� ���� �޴� �ڵ�
	FILE* fp;
	int line = 0;
	char c;
	fp = fopen(filename, "r");
	while ((c = fgetc(fp)) != EOF)
		if (c == '\n') line++;
	fclose(fp);
	return(line);
}
int voicefishing()
{
	int answer;
ReFishing:
	printf("\n\n\n\n�ءءءءءغ��̽��ǽ� ���ؿ��� �ȳ��ءءءءء�\n\n");
	printf("����, ����, �����������̳� �𸣴� ����� ��ȭ��\n");
	printf("��� �� ��ü�� ��û�ϼ̽��ϱ�?\n\n\n");
	printf("1. ��\t\t 2. �ƴϿ�\n");
	printf("\n���� : ");
	scanf_s("%d", &answer);
	if (answer == 1)
		return 1;
	else if (answer == 2)
		return 2;
	else
	{
		printf("�ٽ� �Է��ϼ���\n");
		goto ReFishing;
	}
}
int BackToMenu()
{
	int menuSelect;
	Back:
	printf("\n1. �����޴� ���ư���\t 2. ��� ����\n\n");
	printf("���� : ");
	scanf("%d", &menuSelect);
	if (menuSelect == 1)
		return menuSelect;
	else if (menuSelect == 2)
		printf(" ���� ���ô� ������ ������ Ȯ���Ͽ� �ֽʽÿ�.\n\t\t �̿����ּż� �����մϴ�. \n\t\t\tTHANK YOU\n");
	else
	{
		printf("�ٽ� �Է��ϼ���\n");
		goto Back;
	}
		
}