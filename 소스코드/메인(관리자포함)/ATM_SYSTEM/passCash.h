#pragma once
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"PersonStruct.h"
#include"ViewAccount.h"
#include"VoiceStruct.h"
#include"ExtraFunc.h"
#include"User_Function.h"
#include"myAccountInfo.h"//������ �� ���� ��ȸ ��� ����
#include"OtherAccountInfo.h"
#include"passVariable.h"
#define MAX_NUM 150

void passCash(state1, state2){
	read_csv_file("people.csv", people, MAX_NUM);
	printf("�۱��Ͻ� �ݾ��� �Է��ϼ���.\n");
	scanf_s("%d", &depositMoney);
	
	if (people[state1].BankCode != people[state2].BankCode) {//Ÿ�� ��ü, ������ 1,000��
		if (depositMoney <= 0 || depositMoney+1000 > people[state1].NowMoney) {
			printf("�Է��� �߸��Ǿ����ϴ�. �Է��Ͻ� �ݾ��� ���ų� ���� �ܾ׺��� Ů�ϴ�.\n");
			printf("�ٽ� �Է����ּ���.\n");
			return passCash(state1, state2);
		}
		people[state1].NowMoney -= (depositMoney + 1000);//������ ���¿��� ���� ����
		people[state2].NowMoney += (depositMoney + 1000);//�޴� ���¿� ���� �þ		
	}
	else{//���� ��ü, ������ 0��
		if (depositMoney <= 0 || depositMoney > people[state1].NowMoney) {
			printf("�Է��� �߸��Ǿ����ϴ�. �Է��Ͻ� �ݾ��� ���ų� ���� �ܾ׺��� Ů�ϴ�.\n");
			printf("�ٽ� �Է����ּ���.\n");

			return passCash(state1, state2);
		}
		people[state1].NowMoney -= depositMoney;
		people[state2].NowMoney += depositMoney;
	}
	int line = getTotalLine("people.csv");

	printf("�Է��Ͻ� %s %d������ %s �Բ� �۱��Ͻðڽ��ϱ�?\n", &people[state2].BankName, &people[state2].AccountNumber, &people[state2].ClientName);
	printf("%d. ��\n", yes);
	printf("%d. �ƴϿ�\n", no);

	int yn;

	scanf_s("%d", &yn);
	if (yn == yes)
	{
		SaveData("people.csv", people, line);
		printf("\n<��ü �� �ܾ� : %d��>\n", people[state1].NowMoney);
		printf("�۱��� �Ϸ�Ǿ����ϴ�. �̿����ּż� �����մϴ�.\n");
	}
	else if (yn == no)
	{
		printf("�۱��� ��ҵǾ����ϴ�.\n");
		printf("�̿����ּż� �����մϴ�.\n");
	}
}

