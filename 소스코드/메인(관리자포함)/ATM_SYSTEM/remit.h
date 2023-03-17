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
	people = (Person*)malloc(sizeof(Person) * MAX_NUM);//메모리 할당
	//###################################################################################  범죄
	//PlaySound(TEXT(".\\BankVoice\\phishingCheck.wav"), NULL, SND_FILENAME | SND_ASYNC);

	printf("검찰, 경찰 금융감독원이나 모르는 사람이 전화로 이체를 요청하였습니까?\n");
	printf("또는, 대출받기 위해서는 먼저 수수료, 기존 대출금 상환 등이 필요하다며 이체를 요청하였습니까?\n");
	printf("%d. 예 (거래중단)\n", yes);
	printf("%d. 아니오 (계속거래)\n", no);
	scanf_s("%d", &crime1);
	checkKey(crime1);

	if (crime1 == no) {
		PlaySound(TEXT(".\\BankVoice\\CrimeCheck.wav"), NULL, SND_FILENAME | SND_ASYNC);
		printf("최근 자동화기기에 카드 복제기를 부착하여 정보탈취를 시도한 사례가 있사오니\n 카드투입구가 아래 화면과 다른경우에는 사용을 중단하시고 \n 영업점이나 인터폰으로 신고하여 주시기 바랍니다.\n");
		printf("%d. 거래취소", yes);
		printf("%d. 거래계속\n", no);
		scanf_s("%d", &crime2);
		checkKey(crime2);
		//###################################################################################  범죄
		if (crime2 == no) //범죄 2차검증. 거래 계속 선택시
		{
			printf("당행 또는 타행이체를 선택하세요.\n");
			printf("%d. 당행이체\n", yes);
			printf("%d. 타행이체\n", no);
			scanf_s("%d", &choiceBk);

			if (choiceBk == yes) {//당행 이체
				state1 = myAccountInfo();
				if (state1 == -1) {
					return 0;
				}// 세 번 틀릴 시 -1을 반환 받기에, state1에 -1이 들어있다면 비밀번호를 세 번 틀린 것이다.
				state2 = OtherAccountInfo(state1, 1);
				if (state2 == -1) {
					return 0;
				}//계좌 틀리면 -1
			}
			else if (choiceBk == no) {//타행 이체
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
		else if (crime2 == yes) { //범죄 2차검증. 거래 계속 선택시
			PlaySound(TEXT(".\\BankVoice\\WorkCancel.wav"), NULL, SND_FILENAME | SND_ASYNC);
			PlaySound(TEXT(".\\BankVoice\\CheckAndBye.wav"), NULL, SND_FILENAME | SND_ASYNC);
			printf("거래가 취소 되었습니다.\n처음부터 다시 시작하여 주십시오.\n");
			printf("놓고 가시는 물건이 없는지 확인하여 주십시오.\n");
			printf("이용해주셔서 감사합니다.\n");
			printf("확인");
			return 0;
		}
		else {
			return 0;
		}
	}
	else if (crime1 == yes) {
		PlaySound(TEXT(".\\BankVoice\\WorkCancel.wav"), NULL, SND_FILENAME | SND_ASYNC);
		PlaySound(TEXT(".\\BankVoice\\CheckAndBye.wav"), NULL, SND_FILENAME | SND_ASYNC);

		printf("거래가 취소 되었습니다.\n처음부터 다시 시작하여 주십시오.\n");
		printf("놓고 가시는 물건이 없는지 확인하여 주십시오.\n");
		printf("이용해주셔서 감사합니다.\n");
		printf("확인");
		return 0;
	}
	else
		return 0;
}
