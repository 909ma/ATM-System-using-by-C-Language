#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"PersonStruct.h"
#include"DeleteAccount.h"
#include"ViewAccount.h"


int CloseAccount() {
	int a = 99;
	Person* people = malloc(sizeof(Person) * 100);// �ִ� 100���� ��� ������ ������ �� �ִ� �迭 ���� �Ҵ�
	read_csv_file("people.csv", people, a + 1);//a�� �ο����� ��ȸ 

	int InputCardNumber, InputAccountNumber, state = -1, temp;
	char concent;
	/*
	InputCardNumber : �Էµ� ī���ȣ
	InputAccountNumber : �Էµ� ���¹�ȣ
	state : -1�̸� �˻� �� ��, �˻��Ǹ� �� ������ ���� �� �� ��ȣ
	consent : ���� ����/���� ���� ���� ����
	temp : ���� �����ߴ��� Ȯ���ϴ�  ����
	*/
	printf("ī���ȣ �Է�\n");
	scanf("%d", &InputCardNumber);
	printf("���¹�ȣ �Է�\n");
	scanf("%d", &InputAccountNumber);

	for (int i = 1; i < a + 1; i++) {
		if (people[i].CardNumber == InputCardNumber) {
			state = i;
			if (people[state].AccountNumber == InputAccountNumber)
				break;
			else {
				state = -1;
			}
		}
	}

	if (state != -1) {
		printf("No.  BankName  BankCode  ClientCode  ClientName  CardNumber  AccountNumber   NowMoney  AccountPW  AccountDate\n");
		printf("%3d  %8s  %8d  %10d  %10s  %10d  %13d  %9d       %04d  %11d\n", state, people[state].BankName, people[state].BankCode, people[state].ClientCode, people[state].ClientName, people[state].CardNumber, people[state].AccountNumber, people[state].NowMoney, people[state].AccountPW, people[state].AccountDate);
	}
	else {
		printf("��ȸ�� ������ �����ϴ�.\n");
		return 1;
	}
	while (1) {
		printf("\n���� �Ͻðڽ��ϱ�? [Y/N]\n");
		rewind(stdin);
		scanf("%c", &concent);
		if (concent == 'N') {
			printf("������ �źεǾ����ϴ�.\n");
			break;
		}
		else if (concent == 'Y') {
			//���� ���� 
			temp = DeleteAccount("people.csv", state);
			if (temp == 0)
				printf("������ �����Ͽ����ϴ�.\n");
			else
				printf("������ �����Ͽ����ϴ�.\n");
			break;
		}
		else
			printf("�߸��� �Է��Դϴ�. Y/N �� �ϳ��� �Է��ϼ���\n");
	}

	free(people);// ���� �Ҵ�� �޸� ����
	return 0;
}

