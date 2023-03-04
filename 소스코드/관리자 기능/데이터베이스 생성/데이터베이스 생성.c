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

// CSV ���Ϸ� people �迭�� ������ �����ϴ� �Լ�
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
    gets(person.BankName);//fgets�� ���� �����Ϳ� '\n'�� ���� �������� �����ؾ� 
    
    printf("Enter BankCode: ");
    scanf("%d", &person.BankCode);
    
    printf("Enter ClientCode: ");
    scanf("%d", &person.ClientCode);
    
    getchar(); // �Է� ���� ����
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

