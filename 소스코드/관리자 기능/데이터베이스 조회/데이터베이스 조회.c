#include <stdio.h>    // 입출력 관련 함수들을 사용하기 위해
#include <stdlib.h>   // 동적 메모리 할당 함수들을 사용하기 위해
#include <string.h>   // 문자열 처리 함수들을 사용하기 위해


/*
데이터베이스는 people.csv 파일에 저장됩니다.
*/ 
typedef struct {
    char BankName[20];
    int BankCode;
    int ClientCode;
    char ClientName[10];
    int CardNumber;
    int AccountNumber;
    int NowMoney;
    int AccountPW;
    int AccountDate;
} Person;


void read_csv_file(char* filename, Person* people, int max_num_people) {
    FILE* fp = fopen(filename, "r");    // 파일을 읽기 모드로 열기
    if (fp == NULL) {
        printf("File open error!\n");
        return;
    }

    char buffer[1024];    // 한 줄씩 읽어올 버퍼
    int count = 0;        // 읽어온 사람 수

    while (fgets(buffer, 1024, fp)) {    // 한 줄씩 읽어오기
        if (count >= max_num_people) {   // 최대 읽어올 수 있는 사람 수를 초과하면 종료
            break;
        }
        char* BankName = strtok(buffer, ",");         // BankName 읽어오기
        int BankCode = atoi(strtok(NULL, ","));        // BankCode 읽어오기
        int ClientCode = atoi(strtok(NULL, ","));       // ClientCode 읽어오기
        char* ClientName = strtok(NULL, ",");         // ClientName 읽어오기
        int CardNumber = atoi(strtok(NULL, ","));        // CardNumber 읽어오기
        int AccountNumber = atoi(strtok(NULL, ","));       // AccountNumber 읽어오기
        int NowMoney = atoi(strtok(NULL, ","));         // NowMoney 읽어오기
        int AccountPW = atoi(strtok(NULL, ","));        // AccountPW 읽어오기
        int AccountDate = atoi(strtok(NULL, ","));       // AccountDate 읽어오기

        strcpy(people[count].BankName, BankName);
        people[count].BankCode = BankCode;
        people[count].ClientCode = ClientCode;
        strcpy(people[count].ClientName, ClientName);
        people[count].CardNumber = CardNumber;
        people[count].AccountNumber = AccountNumber;
        people[count].NowMoney = NowMoney;
        people[count].AccountPW = AccountPW;
        people[count].AccountDate = AccountDate;

        count++;
    }

    fclose(fp);    // 파일 닫기
}
int main() {
    Person* people = malloc(sizeof(Person) * 10);    // 최대 10명의 사람 정보를 저장할 수 있는 배열 동적 할당

    read_csv_file("people.csv", people, 10);

    for (int i = 0; i < 10; i++) {
        printf("Bank Name: %s, Bank Code: %d, Clinet Code: %d, ClientName: %s, CardNumber: %d, AccountNumber: %d, NowMoney: %d, AccountPW: %d, AccountDate: %d\n", people[i].BankName, people[i].BankCode, people[i].ClientCode,people[i].ClientName,people[i].CardNumber,people[i].AccountNumber,people[i].NowMoney,people[i].AccountPW,people[i].AccountDate);
    }

    free(people);    // 동적 할당된 메모리 해제

    return 0;
}

