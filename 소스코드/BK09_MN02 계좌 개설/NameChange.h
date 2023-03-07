#pragma once
#include <stdio.h>
#include <stdlib.h>
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
    } else {
        printf("%s ������ �����ϴ� ���� ������ �߻��Ͽ����ϴ�.\n", old_filename);
        exit(1);
    }

    // ���� �̸� ����
    ret = rename(new_filename, old_filename);
    if (ret == 0) {
        printf("%s ������ �̸��� %s �� ����Ǿ����ϴ�.\n", new_filename, old_filename);
    } else {
        printf("%s ������ �̸� ���� �� ������ �߻��Ͽ����ϴ�.\n", old_filename);
        exit(1);
    }

    return 0;
}
