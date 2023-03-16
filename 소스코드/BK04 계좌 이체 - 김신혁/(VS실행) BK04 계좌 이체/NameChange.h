#pragma once
#include <stdio.h>
#include <stdlib.h>
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
    } else {
        printf("%s 파일을 삭제하는 도중 오류가 발생하였습니다.\n", old_filename);
        exit(1);
    }

    // 파일 이름 변경
    ret = rename(new_filename, old_filename);
    if (ret == 0) {
        printf("%s 파일의 이름이 %s 로 변경되었습니다.\n", new_filename, old_filename);
    } else {
        printf("%s 파일의 이름 변경 중 오류가 발생하였습니다.\n", old_filename);
        exit(1);
    }

    return 0;
}
