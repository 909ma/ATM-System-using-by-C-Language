#pragma once
#pragma warning(disable:4996)

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include"PersonStruct.h"
#include"ViewAccount.h"
#include"PrintBankCode.h"
#include"VoiceStruct.h"
#include"ExtraFunc.h"
#include"User_Function.h"

#define MAX_NUM 150

int yes = 1;
int no = 2;
int crime1; //보이스피싱 여부
int crime2; //범죄 여부
int choiceBk; //은행서선택
int inputNum; //계좌입력
int inputPw; //비밀번호 입력
int state = -1; // -1일 경우 검색 안됨 고객 정보가 담은 행 번호
int AccNum; //송금계좌
int depositMoney; //송금금액
int bkCode; //은행코드
char* filename;
Person* people;

int myAccountInfo(); //프로토타입 선언(원형함수 선언)
void passCash();

//계좌이체
int main(char* filename, Person* people)
{	
	printf("검찰, 경찰 금융감독원이나 모르는 사람이 전화로 이체를 요청하였습니까?\n");
	printf("또는, 대출받기 위해서는 먼저 수수료, 기존 대출금 상환 등이 필요하다며 이체를 요청하였습니까?\n");
	printf("%d. 예 (거래중단)\n", yes);
	printf("%d. 아니오 (계속거래)\n", no);
	scanf_s("%d", &crime1);

	if (crime1 == no)
	{
		printf("최근 자동화기기에 카드 복제기를 부착하여 정보탈취를 시도한 사례가 있사오니\n 카드투입구가 아래 화면과 다른경우에는 사용을 중단하시고 \n 영업점이나 인터폰으로 신고하여 주시기 바랍니다.\n");
		printf("%d. 거래취소", yes);
		printf("%d. 거래계속\n", no);
		scanf_s("%d", &crime2);

		if (crime2 == no) //범죄 2차검증. 거래 계속 선택시
		{
			printf("당행 또는 타행이체를 선택하세요.\n");
			printf("%d. 당행이체\n", yes);
			printf("%d. 타행이체\n", no);
			scanf_s("%d", &choiceBk);

			if (choiceBk == yes)
			{
				state = myAccountInfo();				

				//송금 계좌 입력 및 이체
				passCash(state, 0);

			}
			else if (choiceBk == no)
			{
				state = myAccountInfo();

				//은행선택
				printf("송금하실 은행을 선택하세요.");
				PrintBankCode();

				//은행코드 오입력 확인
				while (1)
				{
					scanf_s("%d", &bkCode);

					if (bkCode < 10 || bkCode > 22)
					{
						printf("잘못 선택하셨습니다. 다시 선택하세요.");
						continue;
					}
					break;
				}
				//송금 계좌 입력 및 이체
				passCash(state, bkCode);
			}
			else
			{
				return 0;
			}
		}
		else if (crime2 == yes) //범죄 2차검증. 거래 계속 선택시
		{
			printf("거래가 취소 되었습니다.\n처음부터 다시 시작하여 주십시오.\n");
			printf("놓고 가시는 물건이 없는지 확인하여 주십시오.\n");
			printf("이용해주셔서 감사합니다.\n");
			printf("확인");
			return 0;
		}
		else
		{
			return 0;
		}

	}
	else if (crime1 == yes)
	{
		printf("거래가 취소 되었습니다.\n처음부터 다시 시작하여 주십시오.\n");
		printf("놓고 가시는 물건이 없는지 확인하여 주십시오.\n");
		printf("이용해주셔서 감사합니다.\n");
		printf("확인");
		return 0;
	}
	else
	{
		return 0;
	}	
}

int myAccountInfo()
{
	read_csv_file("people.csv", people, MAX_NUM);

	//계좌입력
	while (1)
	{
		printf("계좌번호를 입력하세요.\n");
		scanf_s("%d", &inputNum);
		if (inputNum > 999 || inputNum < 0)
		{
			printf("계좌번호가 틀렸습니다. 다시 입력하세요.\n");
			continue;
		}
		break;
	}
	printf("비밀번호를 입력하세요.\n");
	scanf_s("%d", &inputPw);

	//비밀번호 오류 검증
	for (int i = 0; i < 3; i++)
	{
		if (inputPw > 9999 || inputPw < 0)
		{
			if (i == 2)
			{
				printf("비밀번호가 3회 틀렸습니다. 거래가 불가합니다.\n");
				return 0;
			}
			printf("비밀번호가 틀렸습니다. 다시 입력하세요.\n");
			scanf_s("%d", &inputPw);
		}
	}

	//고객 계좌와 일치하는 파일의 행 찾기
	for (int i = 1; i < MAX_NUM + 1; i++)
	{
		if (people[i].AccountNumber == inputNum)
		{
			state = i;
			if (people[state].AccountNumber == inputNum)
			{
				break;
			}
			else
			{
				printf("조회된 정보가 없습니다.\n");
				return 0;
			}
		}
	}

	//일치하는 행의 정보를 가져오기
	printf("%s, %d, %d, %s, %d", people->BankName, people->AccountNumber, people->NowMoney, people->ClientName, people->AccountDate);
	
	return state;
}

void passCash(state, bkCode)
{
	read_csv_file("people.csv", people, MAX_NUM);

	//송금 계좌 입력하기
	printf("송금하실 계좌를 입력하세요.");
	scanf_s("%d", &AccNum);

	if (inputNum > 999 || inputNum < 0)
	{
		printf("입력이 잘못되었습니다.");
		return 0;
	}

	printf("송금하실 금액을 입력하세요.");
	scanf_s("%d", &depositMoney);
	if (depositMoney < 0 || depositMoney > people->NowMoney)
	{
		printf("입력이 잘못되었습니다. \n 입력하신 금액이 없거나 보유 잔액보다 큽니다.");
		return 0;
	}
	if (voicefishing() == 1)
		exit(0);

	if (bkCode != 0)
	{
		people[state].NowMoney -= (depositMoney+1000);
	}
	else
	{
		people[state].NowMoney -= depositMoney;
	}

	

	int line = getTotalLine("people.csv");
	SaveData("people.csv", people, line);

	printf("\n<이체 후 잔액 : %d원>\n", people[state].NowMoney);
	printf("송금이 완료되었습니다. 이용해주셔서 감사합니다.");
	
}