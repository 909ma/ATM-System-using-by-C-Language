#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"PersonStruct.h"
#include"ViewAccount.h"
#include"PrintBankCode.h"
#include"VoiceStruct.h"
#include"ExtraFunc.h"
#include"User_Function.h"
#include"myAccountInfo.h"//������ �� ���� ��ȸ ��� ����
#define MAX_NUM 150
int OtherAccountInfo(int lineA,int typeA){
	read_csv_file("people.csv", people, MAX_NUM);//���� �޾ƿ�
	for(int i = 0; i < 3; i++){//���� �Է�
		printf("�۱� ������ ���� ���¸� �Է��ϼ���.\n");
		scanf_s("%d", &AccNum);
		if (AccNum > 999 || AccNum < 0){
			printf("�Է��� �߸��Ǿ����ϴ�.\n");
			if (i == 2){
				printf("�� �� Ʋ���̽��ϴ�. �۱��� �����մϴ�.\n");
				return -1;//�����ϱ� -1 ��ȯ
			}
			continue;
		}
		break;
	}
	if (typeA == 1){//������ ��� typeA == 1���� Ȯ��
		for (int i = 0; i < MAX_NUM - 1; i++){
			if (people[i].AccountNumber == AccNum){
				state2 = i;
				break;
			}
			if (i == MAX_NUM - 2) {
				printf("��ȸ�� ������ �����ϴ�. �۱��� �����մϴ�.\n");
				return -1;
			}
		}
		if (people[lineA].BankCode != people[state2].BankCode){
			printf("���� ��ü������ �۱� �Ͻ� �� ���� �����Դϴ�.\n");
			return -1;
		}//���� �ڵ� �˻�
		printf("���Բ��� �Է��Ͻ� ������ ������ %s�Դϴ�.\n", people[state2].ClientName);
	}
	else if (typeA == 2) {//Ÿ�� ��ü, typeA ==2���� Ȯ��
		for (int i = 0; i < MAX_NUM - 1; i++){
			if (people[i].AccountNumber == AccNum){
				state2 = i;
				break;
			}
			if (i == MAX_NUM - 2) {
				printf("��ȸ�� ������ �����ϴ�. �۱��� �����մϴ�.\n");
				return -1;
			}
		}
		if (people[lineA].BankCode == people[state2].BankCode){
			printf("Ÿ�� ��ü������ �۱� �Ͻ� �� ���� �����Դϴ�.\n");
			return -1;
		}//���� �ڵ� �˻�
		printf("���Բ��� �Է��Ͻ� ������ ������ %s�����̰� ������ ������ %s�Դϴ�.\n", people[state2].BankName, people[state2].ClientName);
	}
	return state2;
}