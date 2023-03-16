#pragma once

int yes = 1;
int no = 2;
int crime1; //보이스피싱 여부
int crime2; //범죄 여부
int choiceBk; //은행서선택
int inputNum; //계좌입력
int inputPw; //비밀번호 입력
int state1 = -1; // -1일 경우 검색 안됨 고객 정보가 담은 행 번호 /보낸사람
int state2 = -1; // -1일 경우 검색 안됨 고객 정보가 담은 행 번호 /받는사람
int AccNum; //송금계좌
int depositMoney; //송금금액
int bkCode; //은행코드
char* filename;
Person* people;