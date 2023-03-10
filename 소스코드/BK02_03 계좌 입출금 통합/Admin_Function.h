#pragma once
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ExtraFunc.h"
#include "PersonStruct.h"
#include "ViewAccount.h"

#define MAX_LINE_LEN 1000
#define MAX_LINE_SIZE 1024

void write_csv_file(char* filename, Person* people) {       //파일 쓰기
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("File open error: %s\n", filename);
        return;
    }

    fprintf(fp, "BankName,BankCode,ClientCode,ClientName,CardNumber,AccountNumber,NowMoney,AccountPW,AccountDate\n");
    fprintf(fp, "%s,%d,%d,%s,%d,%d,%d,%d,%d\n", people->BankName, people->BankCode, people->ClientCode, people->ClientName, people->CardNumber, people->AccountNumber, people->NowMoney, people->AccountPW, people->AccountDate);

    fclose(fp);
}

int CreatAccount() {        // 계좌 개설
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

    write_csv_file("new_people.csv", &person);
    printf("File \"new_people.csv\" write success!\n");

    return 0;
}

int MergeAccount() {                //계좌 병합
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
merge.csv 파일을 people.csv 파일로 바꾸는 함수입니다.
*/
int NameChange() {
    char old_filename[] = "people.csv";
    char new_filename[] = "merged.csv";
    int ret;

    // 파일 삭제
    ret = remove(old_filename);
    if (ret == 0) {
        printf("%s 파일이 성공적으로 삭제되었습니다.\n", old_filename);
    }
    else {
        printf("%s 파일을 삭제하는 도중 오류가 발생하였습니다.\n", old_filename);
        exit(1);
    }

    // 파일 이름 변경
    ret = rename(new_filename, old_filename);
    if (ret == 0) {
        printf("%s 파일의 이름이 %s 로 변경되었습니다.\n", new_filename, old_filename);
    }
    else {
        printf("%s 파일의 이름 변경 중 오류가 발생하였습니다.\n", old_filename);
        exit(1);
    }

    return 0;
}

/*
DeleteAccount(파일 경로, 삭제할 데이터의 인덱스)
*/
int DeleteAccount(char file_path[100], int delete_index) {
    // 파일 열기
    FILE* fp = fopen(file_path, "r");
    if (fp == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    // 새로운 파일 생성
    FILE* new_fp = fopen("temp.csv", "w");
    if (new_fp == NULL) {
        printf("Failed to create the new file.\n");
        return 1;
    }

    // 삭제한 줄을 제외한 내용을 새로운 파일에 씀
    char line[MAX_LINE_LEN];
    int line_count = 0;
    while (fgets(line, MAX_LINE_LEN, fp) != NULL) {
        if (line_count != delete_index) {
            fprintf(new_fp, "%s", line);
        }
        line_count++;
    }

    // 파일 닫기
    fclose(fp);
    fclose(new_fp);

    // 기존 파일 삭제
    if (remove(file_path) != 0) {
        printf("Failed to delete the original file.\n");
        return 1;
    }

    // 새로운 파일 이름 변경
    if (rename("temp.csv", file_path) != 0) {
        printf("Failed to rename the new file.\n");
        return 1;
    }

    printf("Line %d has been deleted from the file.\n", delete_index);
    return 0;
}

int CloseAccount() {
    int line = getTotalLine("people.csv");
    Person* people = malloc(sizeof(Person) * 100);// 최대 100명의 사람 정보를 저장할 수 있는 배열 동적 할당
    read_csv_file("people.csv", people, line - 1);//a의 인원수를 조회 

    int InputCardNumber, InputAccountNumber, state = -1, temp;
    char concent;
    /*
    InputCardNumber : 입력된 카드번호
    InputAccountNumber : 입력된 계좌번호
    state : -1이면 검색 안 됨, 검색되면 고객 정보가 담은 그 행 번호
    consent : 해지 동의/비동의 받을 문자 변수
    temp : 해지 성공했는지 확인하는  변수
    */
    printf("카드번호 입력\n");
    scanf("%d", &InputCardNumber);
    printf("계좌번호 입력\n");
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
        printf("조회된 정보가 없습니다.\n");
        return 1;
    }
    while (1) {
        printf("\n해지 하시겠습니까? [Y/N]\n");
        rewind(stdin);
        scanf("%c", &concent);
        if (concent == 'N') {
            printf("해지가 거부되었습니다.\n");
            break;
        }
        else if (concent == 'Y') {
            //해지 내용 
            temp = DeleteAccount("people.csv", state);
            if (temp == 0)
                printf("해지에 성공하였습니다.\n");
            else
                printf("해지에 실패하였습니다.\n");
            break;
        }
        else
            printf("잘못된 입력입니다. Y/N 중 하나로 입력하세요\n");
    }

    free(people);// 동적 할당된 메모리 해제
    return 0;
}