#pragma once
#pragma warning(disable:4996)

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"PersonStruct.h"
#include"ViewAccount.h"
#include"VoiceCheck.h"
#include"ExtraFunc.h"
#include"User_Function.h"
#include"myAccountInfo.h"//������ �� ���� ��ȸ ��� ����
#include"OtherAccountInfo.h"
#include"passCash.h"
#include"passVariable.h"
#define MAX_NUM 150

//������ü
int remit() {
	people = (Person*)malloc(sizeof(Person) * MAX_NUM);//�޸� �Ҵ�
	//###################################################################################  ����
	//PlaySound(TEXT(".\\BankVoice\\phishingCheck.wav"), NULL, SND_FILENAME | SND_ASYNC);

	printf("����, ���� �����������̳� �𸣴� ����� ��ȭ�� ��ü�� ��û�Ͽ����ϱ�?\n");
	printf("�Ǵ�, ����ޱ� ���ؼ��� ���� ������, ���� ����� ��ȯ ���� �ʿ��ϴٸ� ��ü�� ��û�Ͽ����ϱ�?\n");
	printf("%d. �� (�ŷ��ߴ�)\n", yes);
	printf("%d. �ƴϿ� (��Ӱŷ�)\n", no);
	scanf_s("%d", &crime1);
	checkKey(crime1);

	if (crime1 == no) {
		PlaySound(TEXT(".\\BankVoice\\CrimeCheck.wav"), NULL, SND_FILENAME | SND_ASYNC);
		printf("�ֱ� �ڵ�ȭ��⿡ ī�� �����⸦ �����Ͽ� ����Ż�븦 �õ��� ��ʰ� �ֻ����\n ī�����Ա��� �Ʒ� ȭ��� �ٸ���쿡�� ����� �ߴ��Ͻð� \n �������̳� ���������� �Ű��Ͽ� �ֽñ� �ٶ��ϴ�.\n");
		printf("%d. �ŷ����", yes);
		printf("%d. �ŷ����\n", no);
		scanf_s("%d", &crime2);
		checkKey(crime2);
		//###################################################################################  ����
		if (crime2 == no) //���� 2������. �ŷ� ��� ���ý�
		{
			printf("���� �Ǵ� Ÿ����ü�� �����ϼ���.\n");
			printf("%d. ������ü\n", yes);
			printf("%d. Ÿ����ü\n", no);
			scanf_s("%d", &choiceBk);

			if (choiceBk == yes) {//���� ��ü
				state1 = myAccountInfo();
				if (state1 == -1) {
					return 0;
				}// �� �� Ʋ�� �� -1�� ��ȯ �ޱ⿡, state1�� -1�� ����ִٸ� ��й�ȣ�� �� �� Ʋ�� ���̴�.
				state2 = OtherAccountInfo(state1, 1);
				if (state2 == -1) {
					return 0;
				}//���� Ʋ���� -1
			}
			else if (choiceBk == no) {//Ÿ�� ��ü
				state1 = myAccountInfo();
				if (state1 == -1) {
					return 0;
				}// �� �� Ʋ�� �� -1�� ��ȯ �ޱ⿡, state1�� -1�� ����ִٸ� ��й�ȣ�� �� �� Ʋ�� ���̴�.
				state2 = OtherAccountInfo(state1, 2);
				if (state2 == -1) {
					return 0;
				}//���� Ʋ���� -1
			}
			else
			{
				return 0;
			}
			passCash(state1, state2);
		}
		else if (crime2 == yes) { //���� 2������. �ŷ� ��� ���ý�
			PlaySound(TEXT(".\\BankVoice\\WorkCancel.wav"), NULL, SND_FILENAME | SND_ASYNC);
			PlaySound(TEXT(".\\BankVoice\\CheckAndBye.wav"), NULL, SND_FILENAME | SND_ASYNC);
			printf("�ŷ��� ��� �Ǿ����ϴ�.\nó������ �ٽ� �����Ͽ� �ֽʽÿ�.\n");
			printf("���� ���ô� ������ ������ Ȯ���Ͽ� �ֽʽÿ�.\n");
			printf("�̿����ּż� �����մϴ�.\n");
			printf("Ȯ��");
			return 0;
		}
		else {
			return 0;
		}
	}
	else if (crime1 == yes) {
		PlaySound(TEXT(".\\BankVoice\\WorkCancel.wav"), NULL, SND_FILENAME | SND_ASYNC);
		PlaySound(TEXT(".\\BankVoice\\CheckAndBye.wav"), NULL, SND_FILENAME | SND_ASYNC);

		printf("�ŷ��� ��� �Ǿ����ϴ�.\nó������ �ٽ� �����Ͽ� �ֽʽÿ�.\n");
		printf("���� ���ô� ������ ������ Ȯ���Ͽ� �ֽʽÿ�.\n");
		printf("�̿����ּż� �����մϴ�.\n");
		printf("Ȯ��");
		return 0;
	}
	else
		return 0;
}
