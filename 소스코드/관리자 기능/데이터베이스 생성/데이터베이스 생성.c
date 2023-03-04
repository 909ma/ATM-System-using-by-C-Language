#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

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

// CSV 파일로 people 배열의 내용을 저장하는 함수
void write_csv_file(char* filename, Person* people) {
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("File open error: %s\n", filename);
        return;
    }

    fprintf(fp, "BankName,BankCode,ClientCode,ClientName,CardNumber,AccountNumber,NowMoney,AccountPW,AccountDate\n");
    fprintf(fp, "%s,%d,%d,%s,%d,%d,%d,%d,%d\n", people->BankName, people->BankCode, people->ClientCode, people->ClientName, people->CardNumber, people->AccountNumber, people->NowMoney, people->AccountPW, people->AccountDate);

    fclose(fp);
}

int main() {
    Person person;
    printf("Enter BankName: ");
    gets(person.BankName);//fgets를 쓰면 데이터에 '\n'가 들어가서 데이터형 개선해야 
    
    printf("Enter BankCode: ");
    scanf("%d", &person.BankCode);
    
    printf("Enter ClientCode: ");
    scanf("%d", &person.ClientCode);
    
    getchar(); // 입력 버퍼 비우기
    printf("Enter ClientName: ");
    gets(person.ClientName);
    
    printf("Enter CardNumber: ");
    scanf("%d", &person.CardNumber);
    
    printf("Enter AccountNumber: ");
    scanf("%d", &person.AccountNumber);
    
    printf("Enter NowMoney: ");
    scanf("%d", &person.NowMoney);
    
    printf("Enter AccountPW: ");
    scanf("%d", &person.AccountPW);
    
    printf("Enter AccountDate: ");
    scanf("%d", &person.AccountDate);

    write_csv_file("new_person.csv", &person);
    printf("File write success!\n");

    return 0;
}

