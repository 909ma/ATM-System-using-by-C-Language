#include <stdio.h>

#define SIZE 5  // �迭�� ũ��

int main() {
    int arr[SIZE] = {1, 2, 3, 4, 5};  // �ʱ�ȭ�� �迭

    // �迭�� ���Ͽ� ����
    FILE *file = fopen("data.txt", "wb");
    fwrite(arr, sizeof(int), SIZE, file);
    fclose(file);

    // �迭�� ���Ͽ��� �о����
    int new_arr[SIZE];
    file = fopen("data.txt", "rb");
    fread(new_arr, sizeof(int), SIZE, file);
    fclose(file);

    // ���ο� �迭 ���
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", new_arr[i]);
    }
    printf("\n");

    return 0;
}

