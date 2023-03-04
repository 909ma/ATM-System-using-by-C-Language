#include <stdio.h>

#define ROWS 3
#define COLS 4

int main() {
    int arr[ROWS][COLS] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};  // �ʱ�ȭ�� 2���� �迭

    // 2���� �迭�� ���Ͽ� ����
    FILE *file = fopen("data.txt", "wb");
    fwrite(arr, sizeof(int), ROWS * COLS, file);
    fclose(file);

    // 2���� �迭�� ���Ͽ��� �о����
    int new_arr[ROWS][COLS];
    file = fopen("data.txt", "rb");
    fread(new_arr, sizeof(int), ROWS * COLS, file);
    fclose(file);

    // ���ο� 2���� �迭 ���
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", new_arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}

