#pragma once
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include"PersonStruct.h"
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
	printf("����Ϸ�\n");
	fclose(fp);
}
void withdraw_func(char* filename, Person* people, int max, Person*person)
{
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

			if (AccountNumber == person->AccountNumber) // ���� ���¹�ȣ�� �Է��� ���¹�ȣ�� ��ġ�� ���
			{
				people[count].NowMoney = person->NowMoney;
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
int change(char* filename, Person* people, Person* person)
{
	int line = getTotalLine(filename);
	withdraw_func(filename, people, line, person);
	SaveData(filename, people, line);
	return 0;
}