#pragma once
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GiftStruct.h"
#include "VoiceCheck.h"

int countFileLines(char* file_name) {
	// 파일에서 전체 라인 수를 세는 함수
	FILE* fp;  // 파일 포인터
	int line_count = 0;  // 라인 수
	char c;  // 현재 문자를 저장할 변수

	// 파일 열기
	fp = fopen(file_name, "r");
	if (fp == NULL) {
		fprintf(stderr, "Error opening file '%s'\n", file_name);
		return -1;
	}

	// 파일 끝까지 문자를 하나씩 읽어가면서 개행 문자를 만날 때마다 라인 수 증가
	while ((c = fgetc(fp)) != EOF) {
		if (c == '\n') {
			line_count++;
		}
	}

	// 파일이 비어있는 경우 첫 번째 라인을 헤더로 세지 않음
	if (line_count > 0) {
		line_count--;
	}

	// 파일 닫기
	fclose(fp);

	// 전체 라인 수 반환
	return line_count;
}
int getGiftLine(char* file_name, gift_struct* voucher, gift_struct* gift, int max_num_voucher) {
	FILE* fp = fopen(file_name, "r");
	if (fp == NULL) {
		printf("파일을 여는데 실패했습니다. : %s\n", file_name);
		return 1;
	}
	char buffer[1024]; //한줄씩 읽어올 버퍼
	int count = 0; //읽어온 상품권 수


	while (fgets(buffer, 1024, fp)) {
		if (count >= max_num_voucher) {
			break;
		}
		char* gift_num = strtok(buffer, ","); //상품권 번호 읽어오기 처음엔 무조건 buffer사용 그다음부턴 NULL사용해야함
		char* expiry_date = strtok(NULL, ",");
		int balance = atoi(strtok(NULL, ","));

		if (gift->gift_num == gift_num && gift->expiry_date == expiry_date && gift->balance == balance) {
			break;
		}
		count++;
	}

	if (count > max_num_voucher)
		printf("등록되지 않은 상품권입니다.\n");
	fclose(fp);
	return count;
}
int getTotalLine(char* filename) { // csv파일의 총 라인 수를 받는 코드
	FILE* fp;
	int line = 0;
	char c;
	fp = fopen(filename, "r");
	while ((c = fgetc(fp)) != EOF)
		if (c == '\n') line++;
	fclose(fp);
	return(line);
}
int voicefishing()
{
	int answer;
ReFishing:
	PlaySound(TEXT(".\\BankVoice\\phishingCheck.wav"), NULL, SND_FILENAME | SND_ASYNC);
	printf("\n\n\n\n※※※※※※보이스피싱 피해예방 안내※※※※※※\n\n");
	printf("검찰, 경찰, 금융감독원이나 모르는 사람이 전화로\n");
	printf("출금 및 이체를 요청하셨습니까?\n\n\n");
	printf("1. 예\t\t 2. 아니오\n");
	printf("\n선택 : ");
	scanf_s("%d", &answer);
	checkKey(answer);

	if (answer == 1)
	{
		PlaySound(TEXT(".\\BankVoice\\WorkCancel.wav"), NULL, SND_FILENAME | SND_ASYNC);	
		
		return 1;
	}
	else if (answer == 2)
		return 2;
	else
	{
		printf("다시 입력하세요\n");
		goto ReFishing;
	}
}
int BackToMenu()
{
	int menuSelect;
Back:	
	printf("\n1. 이전메뉴 돌아가기\t 2. 사용 종료\n\n");
	printf("선택 : ");
	scanf("%d", &menuSelect);
	if (menuSelect == 1)
		return menuSelect;
	else if (menuSelect == 2)
	{
		PlaySound(TEXT(".\\BankVoice\\CheckAndBye.wav"), NULL, SND_FILENAME | SND_ASYNC);
		Sleep(3000);
		printf(" \n\n놓고 가시는 물건은 없는지 확인하여 주십시오.\n\t 이용해주셔서 감사합니다. \n\t\tTHANK YOU\n");
	}
	else
	{
		printf("다시 입력하세요\n");
		goto Back;
	}
		
}
