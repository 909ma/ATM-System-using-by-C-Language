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
#include"myAccountInfo.h"//변수랑 내 계좌 조회 기능 담음
#include"OtherAccountInfo.h"
#include"passCash.h"
#include"passVariable.h"
#define MAX_NUM 150

//계좌이체
int remit() {

	
	if (voicefishing() == 2)
	{
		people = (Person*)malloc(sizeof(Person) * MAX_NUM);//메모리 할당
		if (crime() == 2)
		{
			printf("당행 또는 타행이체를 선택하세요.\n");
			printf("%d. 당행이체\n", yes);
			printf("%d. 타행이체\n", no);
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
	//당행 이체
	if (choiceBk == yes)
	{
		state1 = myAccountInfo();
		if (state1 == -1) {
			return 0;
		}// 세 번 틀릴 시 -1을 반환 받기에, state1에 -1이 들어있다면 비밀번호를 세 번 틀린 것이다.
		state2 = OtherAccountInfo(state1, 1);
		if (state2 == -1) {
			return 0;
		}//계좌 틀리면 -1
	}
	//타행 이체
	else if (choiceBk == no) {
		state1 = myAccountInfo();
		if (state1 == -1) {
			return 0;
		}// 세 번 틀릴 시 -1을 반환 받기에, state1에 -1이 들어있다면 비밀번호를 세 번 틀린 것이다.
		state2 = OtherAccountInfo(state1, 2);
		if (state2 == -1) {
			return 0;
		}//계좌 틀리면 -1
	}
	else
	{
		return 0;
	}
	passCash(state1, state2);
}

