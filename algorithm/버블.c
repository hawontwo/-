#include <stdio.h>

// 선택 정렬 함수
void selectionSort(int array[], int n) {
    int i, j, min_idx;

    // 배열을 순회하면서 최소값을 찾아 정렬
    for (i = 0; i < n - 1; i++) {
        // 현재 인덱스를 최소값으로 가정
        min_idx = i;

        // 최소값을 찾음
        for (j = i + 1; j < n; j++) {
            if (array[j] < array[min_idx]) {
                min_idx = j;
            }
        }

        // 최소값을 현재 인덱스와 교환
        int temp = array[min_idx];
        array[min_idx] = array[i];
        array[i] = temp;
    }
}

// 배열 요소 출력 함수
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int array[] = { 64, 25, 12, 22, 11 };
    int n = sizeof(array) / sizeof(array[0]);

    printf("정렬 전 배열: \n");
    printArray(array, n);

    selectionSort(array, n);

    printf("선택 정렬 후 배열: \n");
    printArray(array, n);

    return 0;
}