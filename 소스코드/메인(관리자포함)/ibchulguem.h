#pragma once
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

void SaveData(char* filename, Person* people, int max) //��� �� ������ �ܾ� ������ ������
{
	FILE* fp = fopen(filename, "w");
	if (fp == NULL) {
		printf("File open error!\n");
		return;
	}
	fprintf(fp, "BankName,BankCode,ClientCode,ClientName,CardNumber,AccountNumber,NowMoney,AccountPW,AccountDate\n");
	if (people->BankName != NULL)
	{

		for (int i = 0; i < max - 1; i++, people++)
		{
			fprintf(fp, "%s,%d,%d,%s,%d,%d,%d,%d,%d\n", people->BankName, people->BankCode, people->ClientCode, people->ClientName, people->CardNumber, people->AccountNumber, people->NowMoney, people->AccountPW, people->AccountDate);
		}
	}
	printf("����Ϸ�\n\n");

	fclose(fp);
}
void deposit_func(char* filename, Person* people, int max)
{
	int num;
	int depositMoney;
	printf("\n�Ա��� ���¹�ȣ �Է�: ");
	scanf("%d", &num);
	FILE* fp = fopen(filename, "r");    // ������ �б� ���� ����
	if (fp == NULL) {
		printf("File open error!\n");
		return;
	}

	char buffer[1024];    // �� �پ� �о�� ����
	int count = 0;        // �о�� ��� ��
	if (fgets(buffer, 1024, fp))
	{

		while (fgets(buffer, 1024, fp)) {    // �� �پ� �о����

			char* BankName = strtok(buffer, ",");                    // BankName �о����
			int BankCode = atoi(strtok(NULL, ","));                 // BankCode �о����
			int ClientCode = atoi(strtok(NULL, ","));              // ClientCode �о����
			char* ClientName = strtok(NULL, ",");                 // ClientName �о����
			int CardNumber = atoi(strtok(NULL, ","));            // CardNumber �о����
			int AccountNumber = atoi(strtok(NULL, ","));        // AccountNumber �о����
			int NowMoney = atoi(strtok(NULL, ","));            // NowMoney �о����
			int AccountPW = atoi(strtok(NULL, ","));          // AccountPW �о����
			int AccountDate = atoi(strtok(NULL, ","));       // AccountDate �о����

			strcpy(people[count].BankName, BankName);
			people[count].BankCode = BankCode;
			people[count].ClientCode = ClientCode;
			strcpy(people[count].ClientName, ClientName);
			people[count].CardNumber = CardNumber;
			people[count].AccountNumber = AccountNumber;
			people[count].NowMoney = NowMoney;
			people[count].AccountPW = AccountPW;
			people[count].AccountDate = AccountDate;

			if (AccountNumber == num) // ���� ���¹�ȣ�� �Է��� ���¹�ȣ�� ��ġ�� ���
			{
			RE:
				printf("\n�Ա��Ͻ� �ݾ��� �Է��Ͻÿ� : ");
				scanf("%d", &depositMoney);

				if (voicefishing() == 1)
					exit(0);
				NowMoney += depositMoney;
				printf("\n<�Ա� �� �ܾ� : %d��>\n", NowMoney);
				people[count].NowMoney = NowMoney;
			}
			count++;
			if (max == count)
				break;
		}
	}

	fclose(fp);    // ���� �ݱ�
}
void withdraw_func(char* filename, Person* people, int max)
{
	int num;
	int withdrawMoney;
	printf("\n����� ���¹�ȣ �Է�: ");
	scanf("%d", &num);
	FILE* fp = fopen(filename, "r");    // ������ �б� ���� ����
	if (fp == NULL) {
		printf("File open error!\n");
		return;
	}

	char buffer[1024];    // �� �پ� �о�� ����
	int count = 0;        // �о�� ��� ��
	if (fgets(buffer, 1024, fp))
	{

		while (fgets(buffer, 1024, fp)) {    // �� �پ� �о����

			char* BankName = strtok(buffer, ",");                    // BankName �о����
			int BankCode = atoi(strtok(NULL, ","));                 // BankCode �о����
			int ClientCode = atoi(strtok(NULL, ","));              // ClientCode �о����
			char* ClientName = strtok(NULL, ",");                 // ClientName �о����
			int CardNumber = atoi(strtok(NULL, ","));            // CardNumber �о����
			int AccountNumber = atoi(strtok(NULL, ","));        // AccountNumber �о����
			int NowMoney = atoi(strtok(NULL, ","));            // NowMoney �о����
			int AccountPW = atoi(strtok(NULL, ","));          // AccountPW �о����
			int AccountDate = atoi(strtok(NULL, ","));       // AccountDate �о����

			strcpy(people[count].BankName, BankName);
			people[count].BankCode = BankCode;
			people[count].ClientCode = ClientCode;
			strcpy(people[count].ClientName, ClientName);
			people[count].CardNumber = CardNumber;
			people[count].AccountNumber = AccountNumber;
			people[count].NowMoney = NowMoney;
			people[count].AccountPW = AccountPW;
			people[count].AccountDate = AccountDate;

			if (AccountNumber == num) // ���� ���¹�ȣ�� �Է��� ���¹�ȣ�� ��ġ�� ���
			{
				int cnt = 0;
				while (cnt < 3)
				{
					int pw;
					printf("\n��й�ȣ�� �Է��Ͻÿ� : ", cnt);
					scanf("%d", &pw);

					if (AccountPW == pw)
						break;
					else
					{
						cnt++;
						if (cnt < 3)
							printf("\n��й�ȣ�� Ʋ�ǽ��ϴ�. �ٽ� �Է��ϼ���(%dȸ ����)\n", cnt);
						else
							break;
					}
				}
				if (cnt == 3)
				{
					printf("\n��й�ȣ�� 3ȸ�̻� �߸� �Է��ϼ̽��ϴ�. ���α׷��� �����մϴ�.\n");
					exit(0);
				}

			RE:
				printf("\n����Ͻ� �ݾ��� �Է��Ͻÿ� : ");
				scanf("%d", &withdrawMoney);
				if (NowMoney >= withdrawMoney)
				{
					if (voicefishing() == 1)
						exit(0);
					NowMoney -= withdrawMoney;
					printf("\n<��� �� �ܾ� : %d��>\n", NowMoney);
					people[count].NowMoney = NowMoney;
				}
				else	//��ݾ��� �ܾ׺��� ���� ���
				{
					printf("�ܾ��� �����մϴ�. ����Ͻ� �ݾ��� �ٽ� �������ּ���.\n");
					goto RE;
				}
			}
			count++;
			if (max == count)
				break;
		}
	}

	fclose(fp);    // ���� �ݱ�
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
int withdraw(char* filename, Person* people)
{
	int line = getTotalLine(filename);
	withdraw_func(filename, people, line);
	SaveData(filename, people, line);
	return 0;
}
int deposit(char* filename, Person* people)
{
	int line = getTotalLine(filename);
	deposit_func(filename, people, line);
	SaveData(filename, people, line);
	return 0;
}