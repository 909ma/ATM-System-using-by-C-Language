#include <stdio.h>

#define ROWS 3
#define COLS 4

int main() {
    int arr[ROWS][COLS] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};  // 초기화된 2차원 배열

    // 2차원 배열을 파일에 쓰기
    FILE *file = fopen("data.txt", "wb");
    fwrite(arr, sizeof(int), ROWS * COLS, file);
    fclose(file);

    // 2차원 배열을 파일에서 읽어오기
    int new_arr[ROWS][COLS];
    file = fopen("data.txt", "rb");
    fread(new_arr, sizeof(int), ROWS * COLS, file);
    fclose(file);

    // 새로운 2차원 배열 출력
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", new_arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}

