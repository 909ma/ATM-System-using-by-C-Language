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

	
	if (voicefishing() == 2)
	{
		people = (Person*)malloc(sizeof(Person) * MAX_NUM);//�޸� �Ҵ�
		if (crime() == 2)
		{
			printf("���� �Ǵ� Ÿ����ü�� �����ϼ���.\n");
			printf("%d. ������ü\n", yes);
			printf("%d. Ÿ����ü\n", no);
			scanf_s("%d", &choiceBk);
		}
		else
		{
			return;
		}
		
	}
	else
	{
		return;
	}	
	//���� ��ü
	if (choiceBk == yes)
	{
		state1 = myAccountInfo();
		if (state1 == -1) {
			return 0;
		}// �� �� Ʋ�� �� -1�� ��ȯ �ޱ⿡, state1�� -1�� ����ִٸ� ��й�ȣ�� �� �� Ʋ�� ���̴�.
		state2 = OtherAccountInfo(state1, 1);
		if (state2 == -1) {
			return 0;
		}//���� Ʋ���� -1
	}
	//Ÿ�� ��ü
	else if (choiceBk == no) {
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

