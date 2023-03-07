#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LEN 1000
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
