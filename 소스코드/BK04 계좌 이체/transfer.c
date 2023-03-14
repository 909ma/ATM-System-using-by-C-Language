#pragma once
#pragma warning(disable:4996)

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include"PersonStruct.h"
#include"ViewAccount.h"
#include"PrintBankCode.h"
#include"VoiceStruct.h"
#include"ExtraFunc.h"
#include"User_Function.h"

#define MAX_NUM 150

int yes = 1;
int no = 2;
int crime1; //���̽��ǽ� ����
int crime2; //���� ����
int choiceBk; //���༭����
int inputNum; //�����Է�
int inputPw; //��й�ȣ �Է�
int state = -1; // -1�� ��� �˻� �ȵ� �� ������ ���� �� ��ȣ
int AccNum; //�۱ݰ���
int depositMoney; //�۱ݱݾ�
int bkCode; //�����ڵ�
char* filename;
Person* people;

int myAccountInfo(); //������Ÿ�� ����(�����Լ� ����)
void passCash();

//������ü
int main(char* filename, Person* people)
{	
	printf("����, ���� �����������̳� �𸣴� ����� ��ȭ�� ��ü�� ��û�Ͽ����ϱ�?\n");
	printf("�Ǵ�, ����ޱ� ���ؼ��� ���� ������, ���� ����� ��ȯ ���� �ʿ��ϴٸ� ��ü�� ��û�Ͽ����ϱ�?\n");
	printf("%d. �� (�ŷ��ߴ�)\n", yes);
	printf("%d. �ƴϿ� (��Ӱŷ�)\n", no);
	scanf_s("%d", &crime1);

	if (crime1 == no)
	{
		printf("�ֱ� �ڵ�ȭ��⿡ ī�� �����⸦ �����Ͽ� ����Ż�븦 �õ��� ��ʰ� �ֻ����\n ī�����Ա��� �Ʒ� ȭ��� �ٸ���쿡�� ����� �ߴ��Ͻð� \n �������̳� ���������� �Ű��Ͽ� �ֽñ� �ٶ��ϴ�.\n");
		printf("%d. �ŷ����", yes);
		printf("%d. �ŷ����\n", no);
		scanf_s("%d", &crime2);

		if (crime2 == no) //���� 2������. �ŷ� ��� ���ý�
		{
			printf("���� �Ǵ� Ÿ����ü�� �����ϼ���.\n");
			printf("%d. ������ü\n", yes);
			printf("%d. Ÿ����ü\n", no);
			scanf_s("%d", &choiceBk);

			if (choiceBk == yes)
			{
				state = myAccountInfo();				

				//�۱� ���� �Է� �� ��ü
				passCash(state, 0);

			}
			else if (choiceBk == no)
			{
				state = myAccountInfo();

				//���༱��
				printf("�۱��Ͻ� ������ �����ϼ���.");
				PrintBankCode();

				//�����ڵ� ���Է� Ȯ��
				while (1)
				{
					scanf_s("%d", &bkCode);

					if (bkCode < 10 || bkCode > 22)
					{
						printf("�߸� �����ϼ̽��ϴ�. �ٽ� �����ϼ���.");
						continue;
					}
					break;
				}
				//�۱� ���� �Է� �� ��ü
				passCash(state, bkCode);
			}
			else
			{
				return 0;
			}
		}
		else if (crime2 == yes) //���� 2������. �ŷ� ��� ���ý�
		{
			printf("�ŷ��� ��� �Ǿ����ϴ�.\nó������ �ٽ� �����Ͽ� �ֽʽÿ�.\n");
			printf("���� ���ô� ������ ������ Ȯ���Ͽ� �ֽʽÿ�.\n");
			printf("�̿����ּż� �����մϴ�.\n");
			printf("Ȯ��");
			return 0;
		}
		else
		{
			return 0;
		}

	}
	else if (crime1 == yes)
	{
		printf("�ŷ��� ��� �Ǿ����ϴ�.\nó������ �ٽ� �����Ͽ� �ֽʽÿ�.\n");
		printf("���� ���ô� ������ ������ Ȯ���Ͽ� �ֽʽÿ�.\n");
		printf("�̿����ּż� �����մϴ�.\n");
		printf("Ȯ��");
		return 0;
	}
	else
	{
		return 0;
	}	
}

int myAccountInfo()
{
	read_csv_file("people.csv", people, MAX_NUM);

	//�����Է�
	while (1)
	{
		printf("���¹�ȣ�� �Է��ϼ���.\n");
		scanf_s("%d", &inputNum);
		if (inputNum > 999 || inputNum < 0)
		{
			printf("���¹�ȣ�� Ʋ�Ƚ��ϴ�. �ٽ� �Է��ϼ���.\n");
			continue;
		}
		break;
	}
	printf("��й�ȣ�� �Է��ϼ���.\n");
	scanf_s("%d", &inputPw);

	//��й�ȣ ���� ����
	for (int i = 0; i < 3; i++)
	{
		if (inputPw > 9999 || inputPw < 0)
		{
			if (i == 2)
			{
				printf("��й�ȣ�� 3ȸ Ʋ�Ƚ��ϴ�. �ŷ��� �Ұ��մϴ�.\n");
				return 0;
			}
			printf("��й�ȣ�� Ʋ�Ƚ��ϴ�. �ٽ� �Է��ϼ���.\n");
			scanf_s("%d", &inputPw);
		}
	}

	//�� ���¿� ��ġ�ϴ� ������ �� ã��
	for (int i = 1; i < MAX_NUM + 1; i++)
	{
		if (people[i].AccountNumber == inputNum)
		{
			state = i;
			if (people[state].AccountNumber == inputNum)
			{
				break;
			}
			else
			{
				printf("��ȸ�� ������ �����ϴ�.\n");
				return 0;
			}
		}
	}

	//��ġ�ϴ� ���� ������ ��������
	printf("%s, %d, %d, %s, %d", people->BankName, people->AccountNumber, people->NowMoney, people->ClientName, people->AccountDate);
	
	return state;
}

void passCash(state, bkCode)
{
	read_csv_file("people.csv", people, MAX_NUM);

	//�۱� ���� �Է��ϱ�
	printf("�۱��Ͻ� ���¸� �Է��ϼ���.");
	scanf_s("%d", &AccNum);

	if (inputNum > 999 || inputNum < 0)
	{
		printf("�Է��� �߸��Ǿ����ϴ�.");
		return 0;
	}

	printf("�۱��Ͻ� �ݾ��� �Է��ϼ���.");
	scanf_s("%d", &depositMoney);
	if (depositMoney < 0 || depositMoney > people->NowMoney)
	{
		printf("�Է��� �߸��Ǿ����ϴ�. \n �Է��Ͻ� �ݾ��� ���ų� ���� �ܾ׺��� Ů�ϴ�.");
		return 0;
	}
	if (voicefishing() == 1)
		exit(0);

	if (bkCode != 0)
	{
		people[state].NowMoney -= (depositMoney+1000);
	}
	else
	{
		people[state].NowMoney -= depositMoney;
	}

	

	int line = getTotalLine("people.csv");
	SaveData("people.csv", people, line);

	printf("\n<��ü �� �ܾ� : %d��>\n", people[state].NowMoney);
	printf("�۱��� �Ϸ�Ǿ����ϴ�. �̿����ּż� �����մϴ�.");
	
}