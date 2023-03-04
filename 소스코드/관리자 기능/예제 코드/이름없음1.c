#include <stdio.h>

#define SIZE 5  // 배열의 크기

int main() {
    int arr[SIZE] = {1, 2, 3, 4, 5};  // 초기화된 배열

    // 배열을 파일에 쓰기
    FILE *file = fopen("data.txt", "wb");
    fwrite(arr, sizeof(int), SIZE, file);
    fclose(file);

    // 배열을 파일에서 읽어오기
    int new_arr[SIZE];
    file = fopen("data.txt", "rb");
    fread(new_arr, sizeof(int), SIZE, file);
    fclose(file);

    // 새로운 배열 출력
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", new_arr[i]);
    }
    printf("\n");

    return 0;
}

