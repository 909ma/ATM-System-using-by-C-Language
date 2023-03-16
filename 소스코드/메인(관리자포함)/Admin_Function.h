#pragma once
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ExtraFunc.h"
#include "PersonStruct.h"
#include "ViewAccount.h"

#define MAX_LINE_LEN 1000
#define MAX_LINE_SIZE 1024

void write_csv_file(char* filename, Person* people) {       //���� ����
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("File open error: %s\n", filename);
        return;
    }

    fprintf(fp, "BankName,BankCode,ClientCode,ClientName,CardNumber,AccountNumber,NowMoney,AccountPW,AccountDate\n");
    fprintf(fp, "%s,%d,%d,%s,%d,%d,%d,%d,%d\n", people->BankName, people->BankCode, people->ClientCode, people->ClientName, people->CardNumber, people->AccountNumber, people->NowMoney, people->AccountPW, people->AccountDate);

    fclose(fp);
}

int CreatAccount() {        // ���� ����
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

    write_csv_file("new_people.csv", &person);
    printf("File \"new_people.csv\" write success!\n");

    return 0;
}

int MergeAccount() {                //���� ����
    char file1[] = "people.csv";
    char file2[] = "new_people.csv";
    char output[] = "merged.csv";

    FILE* fp1 = fopen(file1, "r");
    if (fp1 == NULL) {
        printf("Error: Failed to open %s\n", file1);
        exit(EXIT_FAILURE);
    }

    FILE* fp2 = fopen(file2, "r");
    if (fp2 == NULL) {
        printf("Error: Failed to open %s\n", file2);
        exit(EXIT_FAILURE);
    }

    FILE* fp_out = fopen(output, "w");
    if (fp_out == NULL) {
        printf("Error: Failed to create %s\n", output);
        exit(EXIT_FAILURE);
    }

    // Write header
    fprintf(fp_out, "BankName,BankCode,ClientCode,ClientName,CardNumber,AccountNumber,NowMoney,AccountPW,AccountDate\n");

    // Skip header line in both files
    char line[MAX_LINE_SIZE];
    fgets(line, MAX_LINE_SIZE, fp1);
    fgets(line, MAX_LINE_SIZE, fp2);

    // Merge files
    while (fgets(line, MAX_LINE_SIZE, fp1) != NULL) {
        fprintf(fp_out, "%s", line);
    }

    while (fgets(line, MAX_LINE_SIZE, fp2) != NULL) {
        fprintf(fp_out, "%s", line);
    }

    fclose(fp1);
    fclose(fp2);
    fclose(fp_out);

    printf("Merged file saved to %s\n", output);

    return 0;
}


/*
merge.csv ������ people.csv ���Ϸ� �ٲٴ� �Լ��Դϴ�.
*/
int NameChange() {
    char old_filename[] = "people.csv";
    char new_filename[] = "merged.csv";
    int ret;

    // ���� ����
    ret = remove(old_filename);
    if (ret == 0) {
        printf("%s ������ ���������� �����Ǿ����ϴ�.\n", old_filename);
    }
    else {
        printf("%s ������ �����ϴ� ���� ������ �߻��Ͽ����ϴ�.\n", old_filename);
        exit(1);
    }

    // ���� �̸� ����
    ret = rename(new_filename, old_filename);
    if (ret == 0) {
        printf("%s ������ �̸��� %s �� ����Ǿ����ϴ�.\n", new_filename, old_filename);
    }
    else {
        printf("%s ������ �̸� ���� �� ������ �߻��Ͽ����ϴ�.\n", old_filename);
        exit(1);
    }

    return 0;
}

/*
DeleteAccount(���� ���, ������ �������� �ε���)
*/
int DeleteAccount(char file_path[100], int delete_index) {
    // ���� ����
    FILE* fp = fopen(file_path, "r");
    if (fp == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    // ���ο� ���� ����
    FILE* new_fp = fopen("temp.csv", "w");
    if (new_fp == NULL) {
        printf("Failed to create the new file.\n");
        return 1;
    }

    // ������ ���� ������ ������ ���ο� ���Ͽ� ��
    char line[MAX_LINE_LEN];
    int line_count = 0;
    while (fgets(line, MAX_LINE_LEN, fp) != NULL) {
        if (line_count != delete_index) {
            fprintf(new_fp, "%s", line);
        }
        line_count++;
    }

    // ���� �ݱ�
    fclose(fp);
    fclose(new_fp);

    // ���� ���� ����
    if (remove(file_path) != 0) {
        printf("Failed to delete the original file.\n");
        return 1;
    }

    // ���ο� ���� �̸� ����
    if (rename("temp.csv", file_path) != 0) {
        printf("Failed to rename the new file.\n");
        return 1;
    }

    printf("Line %d has been deleted from the file.\n", delete_index);
    return 0;
}

int CloseAccount() {
    int line = getTotalLine("people.csv");
    Person* people = malloc(sizeof(Person) * 100);// �ִ� 100���� ��� ������ ������ �� �ִ� �迭 ���� �Ҵ�
    read_csv_file("people.csv", people, line - 1);//a�� �ο����� ��ȸ 

    int InputCardNumber, InputAccountNumber, state = -1, temp;
    char concent;
    /*
    InputCardNumber : �Էµ� ī���ȣ
    InputAccountNumber : �Էµ� ���¹�ȣ
    state : -1�̸� �˻� �� ��, �˻��Ǹ� �� ������ ���� �� �� ��ȣ
    consent : ���� ����/���� ���� ���� ����
    temp : ���� �����ߴ��� Ȯ���ϴ�  ����
    */
    printf("ī���ȣ �Է�\n");
    scanf("%d", &InputCardNumber);
    printf("���¹�ȣ �Է�\n");
    scanf("%d", &InputAccountNumber);

    for (int i = 0; i < line-1; i++) {
        if (people[i].CardNumber == InputCardNumber) {
            state = i;
            if (people[state].AccountNumber == InputAccountNumber)
                break;
            else {
                state = -1;
            }
        }
    }

    if (state != -1) {
        printf("No.  BankName  BankCode  ClientCode  ClientName  CardNumber  AccountNumber   NowMoney  AccountPW  AccountDate\n");
        printf("%3d  %8s  %8d  %10d  %10s  %10d  %13d  %9d       %04d  %11d\n", state, people[state].BankName, people[state].BankCode, people[state].ClientCode, people[state].ClientName, people[state].CardNumber, people[state].AccountNumber, people[state].NowMoney, people[state].AccountPW, people[state].AccountDate);
    }
    else {
        printf("��ȸ�� ������ �����ϴ�.\n");
        return 1;
    }
    while (1) {
        printf("\n���� �Ͻðڽ��ϱ�? [Y/N]\n");
        rewind(stdin);
        scanf("%c", &concent);
        if (concent == 'N') {
            printf("������ �źεǾ����ϴ�.\n");
            break;
        }
        else if (concent == 'Y') {
            //���� ���� 
            temp = DeleteAccount("people.csv", state);
            if (temp == 0)
                printf("������ �����Ͽ����ϴ�.\n");
            else
                printf("������ �����Ͽ����ϴ�.\n");
            break;
        }
        else
            printf("�߸��� �Է��Դϴ�. Y/N �� �ϳ��� �Է��ϼ���\n");
    }

    free(people);// ���� �Ҵ�� �޸� ����
    return 0;
}