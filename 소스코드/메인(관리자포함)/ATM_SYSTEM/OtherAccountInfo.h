#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"PersonStruct.h"
#include"ViewAccount.h"
#include"VoiceCheck.h"
#include"ExtraFunc.h"
#include"User_Function.h"
#include"myAccountInfo.h"//������ �� ���� ��ȸ ��� ����
#define MAX_NUM 150

int OtherAccountInfo(int lineA,int typeA)
{
	//���� �޾ƿ�
	read_csv_file("people.csv", people, MAX_NUM);

	//���� �Է�
	for(int i = 0; i < 3; i++)
	{
		PlaySound(TEXT(".\\BankVoice\\InputAccOrCardNum.wav"), NULL, SND_FILENAME | SND_ASYNC);
		printf("�۱� ������ ���� ���¸� �Է��ϼ���.\n");
		scanf_s("%d", &AccNum);
		checkKey(AccNum);

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
		if (people[lineA].BankCode != people[state2].BankCode)
		{
			printf("������ ��ü�Ͻô� ����� �۱��Ͻ÷��� ������ ������ �ٸ��ϴ�.\n");
			printf("�۱� ���� : %s \n", &people[state2].BankName);
			printf("Ÿ�� ��ü�� ����˴ϴ�. Ÿ�� ��ü���� �����ᰡ ����˴ϴ�.\n");

			return OtherAccountInfo(lineA, 2);			
		}
		else
		{
			//���� �ڵ� �˻�
			printf("���Բ��� �Է��Ͻ� ������ ������ %s�Դϴ�.\n", people[state2].ClientName);
		}
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
			
			printf("������ ��ü�Ͻô� ����� �۱��Ͻ÷��� ������ ������ �����ϴ�.\n");
			printf("�۱� ���� : %s \n", &people[state2].BankName);
			printf("���� ��ü�� ����˴ϴ�.\n");
			return OtherAccountInfo(lineA, 1);
		}
		else
		{
			//���� �ڵ� �˻�
			printf("���Բ��� �Է��Ͻ� ������ ������ %s�����̰� ������ ������ %s�Դϴ�.\n", people[state2].BankName, people[state2].ClientName);
		}
	}
	return state2;
}