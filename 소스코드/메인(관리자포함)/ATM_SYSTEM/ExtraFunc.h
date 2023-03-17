#pragma once
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GiftStruct.h"
int countFileLines(char* file_name) {
	// ���Ͽ��� ��ü ���� ���� ���� �Լ�
	FILE* fp;  // ���� ������
	int line_count = 0;  // ���� ��
	char c;  // ���� ���ڸ� ������ ����

	// ���� ����
	fp = fopen(file_name, "r");
	if (fp == NULL) {
		fprintf(stderr, "Error opening file '%s'\n", file_name);
		return -1;
	}

	// ���� ������ ���ڸ� �ϳ��� �о�鼭 ���� ���ڸ� ���� ������ ���� �� ����
	while ((c = fgetc(fp)) != EOF) {
		if (c == '\n') {
			line_count++;
		}
	}

	// ������ ����ִ� ��� ù ��° ������ ����� ���� ����
	if (line_count > 0) {
		line_count--;
	}

	// ���� �ݱ�
	fclose(fp);

	// ��ü ���� �� ��ȯ
	return line_count;
}
int getGiftLine(char* file_name, gift_struct* voucher, gift_struct* gift, int max_num_voucher) {
	FILE* fp = fopen(file_name, "r");
	if (fp == NULL) {
		printf("������ ���µ� �����߽��ϴ�. : %s\n", file_name);
		return 1;
	}
	char buffer[1024]; //���پ� �о�� ����
	int count = 0; //�о�� ��ǰ�� ��


	while (fgets(buffer, 1024, fp)) {
		if (count >= max_num_voucher) {
			break;
		}
		char* gift_num = strtok(buffer, ","); //��ǰ�� ��ȣ �о���� ó���� ������ buffer��� �״������� NULL����ؾ���
		char* expiry_date = strtok(NULL, ",");
		int balance = atoi(strtok(NULL, ","));

		if (gift->gift_num == gift_num && gift->expiry_date == expiry_date && gift->balance == balance) {
			break;
		}
		count++;
	}

	if (count > max_num_voucher)
		printf("��ϵ��� ���� ��ǰ���Դϴ�.\n");
	fclose(fp);
	return count;
}
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
int crime()
{
	int crime;
ReCrime:
	printf("����, ���� �����������̳� �𸣴� ����� ��ȭ�� ��ü�� ��û�Ͽ����ϱ�?\n");
	printf("�Ǵ�, ����ޱ� ���ؼ��� ���� ������, ���� ����� ��ȯ ���� �ʿ��ϴٸ� ��ü�� ��û�Ͽ����ϱ�?\n");
	printf("1. �� (�ŷ��ߴ�)\n");
	printf("2. �ƴϿ� (��Ӱŷ�)\n");
	scanf_s("%d", &crime);
	if (crime == 1)
		return 1;
	else if (crime == 2)
	{
		printf("�ŷ��� ��� �Ǿ����ϴ�.\nó������ �ٽ� �����Ͽ� �ֽʽÿ�.\n");
		printf("���� ���ô� ������ ������ Ȯ���Ͽ� �ֽʽÿ�.\n");
		printf("�̿����ּż� �����մϴ�.\n");
		printf("Ȯ��");
		return 2;
	}
	else
	{
		printf("�ٽ� �Է��ϼ���\n");
		goto ReCrime;
	}
}
int voicefishing()
{
	int answer;
ReFishing:
	printf("����, ���� �����������̳� �𸣴� ����� ��ȭ�� ��ü�� ��û�Ͽ����ϱ�?\n");
	printf("�Ǵ�, ����ޱ� ���ؼ��� ���� ������, ���� ����� ��ȯ ���� �ʿ��ϴٸ� ��ü�� ��û�Ͽ����ϱ�?\n");
	printf("1. �� (�ŷ��ߴ�)\n");
	printf("2. �ƴϿ� (��Ӱŷ�)\n");
	scanf_s("%d", &answer);
	if (answer == 1)
		return 1;
	else if (answer == 2)
	{
		printf("�ŷ��� ��� �Ǿ����ϴ�.\nó������ �ٽ� �����Ͽ� �ֽʽÿ�.\n");
		printf("���� ���ô� ������ ������ Ȯ���Ͽ� �ֽʽÿ�.\n");
		printf("�̿����ּż� �����մϴ�.\n");
		printf("Ȯ��");
		return 2;
	}
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
		printf(" \n\n���� ���ô� ������ ������ Ȯ���Ͽ� �ֽʽÿ�.\n\t �̿����ּż� �����մϴ�. \n\t\tTHANK YOU\n");
	else
	{
		printf("�ٽ� �Է��ϼ���\n");
		goto Back;
	}
		
}
int PrintBankCode() {
	printf("��������������������������������������������������������\n");
	printf("��    BankCode  ��    Name   ��\n");
	printf("��������������������������������������������������������\n");
	printf("��       10     ��   K B     ��\n");
	printf("��       11     ��   iBK     ��\n");
	printf("��       12     ��   N H     ��\n");
	printf("��       13     ��   ����    ��\n");
	printf("��       14     ��   �츮    ��\n");
	printf("��       15     ��   �ϳ�    ��\n");
	printf("��       16     ��   ��ȯ    ��\n");
	printf("��       17     ��   ��Ƽ    ��\n");
	printf("��       18     ��   �뱸    ��\n");
	printf("��       19     ��   �λ�    ��\n");
	printf("��       20     ��   ����    ��\n");
	printf("��       21     ��   ����    ��\n");
	printf("��       22     ��  īī��   ��\n");
	printf("��       30     �� ����ī��  ��\n");
	printf("��       40     ��  ������   ��\n");
	printf("��       41     ��  ��Ģ��   ��\n");
	printf("��������������������������������������������������������\n");

	return 0;
}
