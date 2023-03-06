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
		printf("계좌 개설에 성공하였습니다.\n");
	}
	else
		printf("계좌 개설에 실패하였습니다.\n");
	return 0;
}
