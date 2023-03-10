#pragma once
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include"PersonStruct.h"

void change_func(char* filename, Person* people, int max, Person*person) // ������ ������ �а� ������ �迭�� �����ϴ� �ڵ�
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
int change(char* filename, Person* people, Person* person) // ������ ������ ���Ͽ� �����ϴ� �ڵ�
{
	int line = getTotalLine(filename);
	change_func(filename, people, line, person);
	SaveData(filename, people, line);
	return 0;
}