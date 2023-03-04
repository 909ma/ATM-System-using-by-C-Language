#include <stdio.h>    // ����� ���� �Լ����� ����ϱ� ����
#include <stdlib.h>   // ���� �޸� �Ҵ� �Լ����� ����ϱ� ����
#include <string.h>   // ���ڿ� ó�� �Լ����� ����ϱ� ����


/*
�����ͺ��̽��� people.csv ���Ͽ� ����˴ϴ�.
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
    FILE* fp = fopen(filename, "r");    // ������ �б� ���� ����
    if (fp == NULL) {
        printf("File open error!\n");
        return;
    }

    char buffer[1024];    // �� �پ� �о�� ����
    int count = 0;        // �о�� ��� ��

    while (fgets(buffer, 1024, fp)) {    // �� �پ� �о����
        if (count >= max_num_people) {   // �ִ� �о�� �� �ִ� ��� ���� �ʰ��ϸ� ����
            break;
        }
        char* BankName = strtok(buffer, ",");         // BankName �о����
        int BankCode = atoi(strtok(NULL, ","));        // BankCode �о����
        int ClientCode = atoi(strtok(NULL, ","));       // ClientCode �о����
        char* ClientName = strtok(NULL, ",");         // ClientName �о����
        int CardNumber = atoi(strtok(NULL, ","));        // CardNumber �о����
        int AccountNumber = atoi(strtok(NULL, ","));       // AccountNumber �о����
        int NowMoney = atoi(strtok(NULL, ","));         // NowMoney �о����
        int AccountPW = atoi(strtok(NULL, ","));        // AccountPW �о����
        int AccountDate = atoi(strtok(NULL, ","));       // AccountDate �о����

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

    fclose(fp);    // ���� �ݱ�
}
int main() {
    Person* people = malloc(sizeof(Person) * 10);    // �ִ� 10���� ��� ������ ������ �� �ִ� �迭 ���� �Ҵ�

    read_csv_file("people.csv", people, 10);

    for (int i = 0; i < 10; i++) {
        printf("Bank Name: %s, Bank Code: %d, Clinet Code: %d, ClientName: %s, CardNumber: %d, AccountNumber: %d, NowMoney: %d, AccountPW: %d, AccountDate: %d\n", people[i].BankName, people[i].BankCode, people[i].ClientCode,people[i].ClientName,people[i].CardNumber,people[i].AccountNumber,people[i].NowMoney,people[i].AccountPW,people[i].AccountDate);
    }

    free(people);    // ���� �Ҵ�� �޸� ����

    return 0;
}

