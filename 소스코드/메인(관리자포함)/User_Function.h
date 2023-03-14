#pragma once
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ExtraFunc.h"

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
	int AccNum;
	int depositMoney;
	int findAcc = 0;
	int AccountNumber, NowMoney;
	read_csv_file(filename, people, max - 1);

	do
	{
	REDEP:
		printf("\n�Ա��� ���¹�ȣ �Է�: ");
		scanf("%d", &AccNum);
		for (int i = 0; i < max - 1; i++)
		{
			if (people[i].AccountNumber == AccNum) // ���� ���¹�ȣ�� �Է��� ���¹�ȣ�� ��ġ�� ���
			{
				findAcc = 1;
				int pw_count = 0;
				while (pw_count < 3)
				{
					int pw;
					printf("\n��й�ȣ�� �Է��Ͻÿ� : ");
					scanf("%d", &pw);

					if (people[i].AccountPW == pw)
						break;
					else
					{
						pw_count++;
						if (pw_count < 3)
							printf("\n��й�ȣ�� Ʋ�ǽ��ϴ�. �ٽ� �Է��ϼ���(%dȸ ����)\n", pw_count);
						else
							break;
					}
				}
				if (pw_count == 3)
				{
					printf("\n��й�ȣ�� 3ȸ�̻� �߸� �Է��ϼ̽��ϴ�. ���α׷��� �����մϴ�.\n");
					exit(0);
				}
			RE:
				printf("\n�Ա��Ͻ� �ݾ��� �Է��Ͻÿ� : ");
				scanf("%d", &depositMoney);

				if (voicefishing() == 1)
					exit(0);
				people[i].NowMoney += depositMoney;
				printf("\n<�Ա� �� �ܾ� : %d��>\n", people[i].NowMoney);
			}
		}
		
		if (!findAcc) {
			printf("\n�Է��� ���¹�ȣ�� �������� �ʽ��ϴ�.\n");
			goto REDEP;
		}
	} while (findAcc == 0);

}
void withdraw_func(char* filename, Person* people, int max)
{
	int AccNum;
	int withdrawMoney;
	int FindAcc = 0;
	int AccountNumber, AccountPW, NowMoney;
	read_csv_file(filename, people, max - 1);

	do
	{
	REWITH:
		printf("\n����� ���¹�ȣ �Է�: ");
		scanf("%d", &AccNum);
		for (int i = 0; i < max - 1; i++)
		{
			if (people[i].AccountNumber == AccNum) // ���� ���¹�ȣ�� �Է��� ���¹�ȣ�� ��ġ�� ���
			{
				FindAcc = 1;
				int pw_count = 0;
				while (pw_count < 3)
				{
					int pw;
					printf("\n��й�ȣ�� �Է��Ͻÿ� : ");
					scanf("%d", &pw);

					if (people[i].AccountPW == pw)
						break;
					else
					{
						pw_count++;
						if (pw_count < 3)
							printf("\n��й�ȣ�� Ʋ�ǽ��ϴ�. �ٽ� �Է��ϼ���(%dȸ ����)\n", pw_count);
						else
							break;
					}
				}
				if (pw_count == 3)
				{
					printf("\n��й�ȣ�� 3ȸ�̻� �߸� �Է��ϼ̽��ϴ�. ���α׷��� �����մϴ�.\n");
					exit(0);
				}

			RE:
				printf("\n����Ͻ� �ݾ��� �Է��Ͻÿ� : ");
				scanf("%d", &withdrawMoney);
				if (people[i].NowMoney >= withdrawMoney)
				{
					if (voicefishing() == 1)
						exit(0);
					people[i].NowMoney -= withdrawMoney;
					printf("\n<��� �� �ܾ� : %d��>\n", people[i].NowMoney);
				}
				else	//��ݾ��� �ܾ׺��� ���� ���
				{
					printf("�ܾ��� �����մϴ�. ����Ͻ� �ݾ��� �ٽ� �������ּ���.\n");
					goto RE;
				}
			}
		}
		if (!FindAcc) {
			printf("\n�Է��� ���¹�ȣ�� �������� �ʽ��ϴ�.\n");
			goto REWITH;
		}
	} while (FindAcc == 0);

}
int ViewMyCash_func(char* filename, Person* people, int max)
{
	read_csv_file(filename, people, max - 1);

	char answer[10];
	printf("\n");
	printf("   ---------------------------------------\n");
	printf("\n");
	printf("         �����ܾ� ��ȸ�� �����ϼ̽��ϴ�.       \n");
	printf("\n");
	printf("   ---------------------------------------\n");
	printf("        \n");
	printf("\n���̽��ǽ� ���� ������ �����̳���? (��/�ƴϿ�): ");
	scanf("%s", answer);

	if (strcmp(answer, "�ƴϿ�") != 0)
	{
		printf("\n���̽��ǽ� ������ ���� �����մϴ�. �̿����ּż� �����մϴ�.\n");
		return 1;
	}

	int CardNumber, AccountNumber, AccountPW, state = -1, temp;
	int retry_count = 0; // ��õ� Ƚ���� ������ ����

	do {
		printf("\n");
		printf("   ---------------------------------------\n");
		printf("\n");
		printf("             ���ڸ� �Է����ּ���.             \n");
		printf("\n");
		printf("   ---------------------------------------\n");
		printf("\n");

		printf("\nī���ȣ�� �Է����ּ���. (4�ڸ�) : ");
		scanf("%d", &CardNumber);

		printf("\n���¹�ȣ�� �Է����ּ���. (3�ڸ�) : ");
		scanf("%d", &AccountNumber);

		printf("\n��й�ȣ�� �Է����ּ���. (4�ڸ�) : ");
		scanf("%d", &AccountPW);

		for (int i = 0; i < max-1; i++) {
			if (people[i].CardNumber == CardNumber) {
				state = i;

				if (people[i].AccountNumber == AccountNumber) {
					if (people[state].AccountPW == AccountPW) {
						break;
					}
					else {
						state = -1;
					}
				}
			}
		}

		if (state == -1) {
			printf("\n�Է��Ͻ� ������ �ùٸ��� �ʽ��ϴ�. �ٽ� �Է����ּ���.\n");

			retry_count++;

			if (retry_count >= 3) {
				printf("\n3ȸ �̻� �߸��� ������ �Է��ϼ̽��ϴ�. �̿����ּż� �����մϴ�.\n");
				return 1;
			}
		}
	} while (state == -1);

	printf("\n");
	printf("   ---------------------------------------\n");
	printf("\n");
	printf("                ���� �����ܾ� �Դϴ�.            \n");
	printf("\n");
	printf("   ---------------------------------------\n");
	printf("\n");
	printf("   |  No. |    �����    |    ����    |   �����ܾ�   |\n");
	printf("   --------------------------------------------\n");
	printf("   | %3d  |  %5s����  | %8s����  | %8d��    |\n", state, people[state].BankName, people[state].ClientName, people[state].NowMoney);
	printf("   --------------------------------------------\n");

	return 0;
}
int search(char* filename, Person* people, Person* person, int max) {
	int accnum, acpw;
	int i = 1, j;
	printf("\n\n���¹�ȣ�� �Է��ϼ��� : ");
	scanf("%d", &accnum);
	printf("\n\n��й�ȣ�� �Է��ϼ��� : ");
	scanf("%d", &acpw);
	read_csv_file("people.csv", people, max - 1);
	for (j = 0; j < max - 1; j++)
	{
		if (people[j].AccountNumber == accnum)
			*person = people[j];
	}
view:
		if (person->AccountPW == acpw)
		{
			printf("\n\n������ ������ �ҷ��ɴϴ�\n\n");
			printf("\"%s\"�� �ܾ� : %d\\\n\n", person->ClientName, person->NowMoney);
			
		}
		else
		{
			while (i < 3)
			{
				printf("\n\n��й�ȣ�� %dȸ Ʋ�Ƚ��ϴ�.\n", i);
				if (i < 3) printf("�ٽ� �Է��ϼ���\n");
				scanf("%d", &acpw);
				if (person->AccountPW == acpw)
				{
					goto view;
					break;
				}
				i++;
			}
		}
	
	if (i == 3)
	{
		printf("\n\n��й�ȣ�� %dȸ Ʋ�Ƚ��ϴ�\n", i);
		return 1;
	}
	else
		return 0;
}

int change(char* filename, Person* people, Person* person, int max) // ������ ������ ���Ͽ� �����ϴ� �ڵ�
{
	read_csv_file("people.csv", people, 100);
	for (int i = 0; i < 100; i++)
	{
		if (people[i].AccountNumber == person->AccountNumber) // ���� ���¹�ȣ�� �Է��� ���¹�ȣ�� ��ġ�� ���
		{
			people[i].NowMoney = person->NowMoney;
		}
	}
	SaveData(filename, people, max);
	return 0;
}

int Fine(Person* person) // ��Ģ�� ����
{
	int fee;
	if (strcmp(person->BankName, "��Ģ��") != 0)
	{
		printf("��Ģ�� ���θ� �� �� ���� �����Դϴ�.\n");
		return -1;
	}
	else
	{
		RePay:
		printf("\"%s\" ������ ��Ģ�� ���αݾ��� �Է��ϼ��� : ", person->ClientName);
		scanf("%d", &fee);
		if (person->NowMoney < fee)
		{
			printf("\n���ο� �����Ͽ����ϴ�. �ٽ� �Է����ּ���.\n");
			goto RePay;
		}
		else
		{
			person->NowMoney -= fee;
			printf("\n\n���ΰ� �Ϸ�Ǿ����ϴ�.\n");
			printf("\n����: %s\n", person->ClientName);
			printf("\n���ξ�: %d\\\n", fee);
			printf("\n�ܾ�: %d\\\n", person->NowMoney);
		}
		printf("\n��� �� ���� ȭ������ ���ư��ϴ�.\n");
		return 0;
	}
}

int Utilities(Person* person)	//������ ����
{
	int fee;
	if (strcmp(person->BankName, "������") != 0)
	{
		printf("������ ���θ� �� �� ���� �����Դϴ�.\n");
		return -1;
	}
	else
	{
		ReUtil:
		printf("\n\"%s\" ������ ������ ���αݾ��� �Է��ϼ��� : ", person->ClientName);
		scanf("%d", &fee);
		if (person->NowMoney < fee)
		{
			printf("\n\n���ο� �����Ͽ����ϴ�. �ٽ� �Է����ּ���.\n");
			goto ReUtil;
		}
		else
		{
			person->NowMoney -= fee;
			printf("\n\n���ΰ� �Ϸ�Ǿ����ϴ�.\n");
			printf("\n����: %s\n", person->ClientName);
			printf("\n���ξ�: %d\\\n", fee);
			printf("\n�ܾ�: %d\\\n", person->NowMoney);
		}
		printf("\n��� �� ���� ȭ������ ���ư��ϴ�.\n");
		return 0;
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
int ViewMycash(char* filename, Person* people)
{
	int line = getTotalLine(filename);
	ViewMyCash_func(filename, people, line);
	return 0;
} 