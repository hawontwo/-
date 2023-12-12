#include <stdio.h>

// ���� ���� �Լ�
void selectionSort(int array[], int n) {
    int i, j, min_idx;

    // �迭�� ��ȸ�ϸ鼭 �ּҰ��� ã�� ����
    for (i = 0; i < n - 1; i++) {
        // ���� �ε����� �ּҰ����� ����
        min_idx = i;

        // �ּҰ��� ã��
        for (j = i + 1; j < n; j++) {
            if (array[j] < array[min_idx]) {
                min_idx = j;
            }
        }

        // �ּҰ��� ���� �ε����� ��ȯ
        int temp = array[min_idx];
        array[min_idx] = array[i];
        array[i] = temp;
    }
}

// �迭 ��� ��� �Լ�
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int array[] = { 64, 25, 12, 22, 11 };
    int n = sizeof(array) / sizeof(array[0]);

    printf("���� �� �迭: \n");
    printArray(array, n);

    selectionSort(array, n);

    printf("���� ���� �� �迭: \n");
    printArray(array, n);

    return 0;
}