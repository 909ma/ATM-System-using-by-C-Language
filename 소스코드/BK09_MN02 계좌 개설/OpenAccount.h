#pragma warning(disable: 4996)
#pragma once
#include<stdio.h>
#include"PrintBankCode.h"
#include"CreatAccount.h"
#include"MergeAccount.h"
#include"NameChange.h"

int OpenAccount(){
	int state = 0;
	PrintBankCode();
	CreatAccount();
	MergeAccount();
	state = NameChange();
	if(state == 0){
		printf("���� ������ �����Ͽ����ϴ�.\n");
	}
	else
		printf("���� ������ �����Ͽ����ϴ�.\n");
	return 0;
}
