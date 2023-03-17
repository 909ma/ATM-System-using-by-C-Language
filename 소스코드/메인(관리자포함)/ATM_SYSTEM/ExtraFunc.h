#pragma once
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GiftStruct.h"
#include "VoiceCheck.h"

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
int voicefishing()
{
	int answer;
ReFishing:
	PlaySound(TEXT(".\\BankVoice\\phishingCheck.wav"), NULL, SND_FILENAME | SND_ASYNC);
	printf("\n\n\n\n�ءءءءءغ��̽��ǽ� ���ؿ��� �ȳ��ءءءءء�\n\n");
	printf("����, ����, �����������̳� �𸣴� ����� ��ȭ��\n");
	printf("��� �� ��ü�� ��û�ϼ̽��ϱ�?\n\n\n");
	printf("1. ��\t\t 2. �ƴϿ�\n");
	printf("\n���� : ");
	scanf_s("%d", &answer);
	checkKey(answer);

	if (answer == 1)
	{
		PlaySound(TEXT(".\\BankVoice\\WorkCancel.wav"), NULL, SND_FILENAME | SND_ASYNC);	
		
		return 1;
	}
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
	{
		PlaySound(TEXT(".\\BankVoice\\CheckAndBye.wav"), NULL, SND_FILENAME | SND_ASYNC);
		Sleep(3000);
		printf(" \n\n���� ���ô� ������ ������ Ȯ���Ͽ� �ֽʽÿ�.\n\t �̿����ּż� �����մϴ�. \n\t\tTHANK YOU\n");
	}
	else
	{
		printf("�ٽ� �Է��ϼ���\n");
		goto Back;
	}
		
}
