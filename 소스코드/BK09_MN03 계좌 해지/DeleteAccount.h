#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LEN 1000
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
