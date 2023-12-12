#include <stdio.h>
#include<windows.h>
#include <stdlib.h>
#include <conio.h>


#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4

void printAmergecc() {
    printf("Hello from printAmergecc!\n");
}
int keyControl();
void titleDraw();
void gotoxy(int, int);
int menuDraw();
void init();
void infoDraw();
int maplistDraw();
void bubbleSort(int, int);
void printArray(int*, int);
int bubble();
void selectionSort(int, int);
int selection();
void merge(int, int, int);
void printArrayc(int, int);
int mergecc();
void insertionSort(int, int);
void printArrayd(int, int);
int insertion();
void heapify(int, int, int);
void heap_sort(int, int);
void heap_print(int, int);
int heap_main();
int partition(int, int, int);
void quick_sort(int, int, int);
void quick_print(int, int);
int quick();
int purt(int);
int get();
void print_radix(int, int);
void radix_sort(int, int);
int radix_main();
int getMax(int, int);
void countingSort(int, int, int);
void radixSort(int, int);
int rradixmain();
void shell_print(int, int);
void shellSort(int, int);
int shell_main();
int graph();

int main() {
    init();
    while (1) {
        titleDraw();
        int menuCode = menuDraw();
        if (menuCode == 0) {
            int n = maplistDraw();

            if (n == 0) {
                bubble();
            }
            else if (n == 1) {
                selection();
            }
            else if (n == 2) {
                insertion();
            }
            else if (n == 3) {
                mergecc();
            }
            else if (n == 4) {
                quick();
            }
            else if (n == 5) {
                heap_main();
            }
            else if (n == 6) {
                radix_main();

            }
            else if (n == 7) {
                rradixmain();
            }
            else if (n == 8) {
                shell_main();
            }
        }
        else if (menuCode == 1) {
            infoDraw();
        }
        else if (menuCode == 2) {
            return 0;
        }
        /*if (menuCode == 0) {
           infoDraw();
        }
        else if (menuCode == 1) {
           infoDraw();

        }
        else if (menuCode == 2) {
           infoDraw();
        }
        else if (menuCode == 3) {
           infoDraw();
        }*/
        system("cls");
    }
    return 0;
}

void init() {
    system("mode con cols=1000 lines=100 | title 게 임 제 목");

    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ConsoleCursor;
    ConsoleCursor.bVisible = 0;
    ConsoleCursor.dwSize = 1;
    SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}

void titleDraw() {
    printf("\n");
    printf("\t\t\t\t   ##     ##        #####    ####    #####    ######   ######   ##  ##   ##   ## \n");
    printf("\t\t\t\t  ####    ##       ##       ##  ##   ##  ##     ##       ##     ##  ##   ### ### \n");
    printf("\t\t\t\t ##  ##   ##       ##       ##  ##   ##  ##     ##       ##     ######   ####### \n");
    printf("\t\t\t\t ##  ##   ##       ## ###   ##  ##   #####      ##       ##     ##  ##   ## # ## \n");
    printf("\t\t\t\t ######   ##       ##  ##   ##  ##   ## ##      ##       ##     ##  ##   ##   ## \n");
    printf("\t\t\t\t ##  ##   ######    #####    ####    ##  ##   ######     ##     ##  ##   ##   ## \n");
    printf("\n\n");
}

void gotoxy(int x, int y) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(consoleHandle, pos);

}



int keyControl() {
    char temp = _getch();

    if (temp == 'w' || temp == 'W') {
        return UP;
    }
    else if (temp == 'a' || temp == 'A') {
        return LEFT;
    }
    else if (temp == 'd' || temp == 'D') {
        return RIGHT;
    }
    else if (temp == ' ') {
        return SUBMIT;
    }
    else if (temp == 's' || temp == 'S') {
        return DOWN;
    }
}

int menuDraw() {
    int x = 70;
    int y = 15;
    gotoxy(x - 2, y);
    printf("> 정 렬");
    gotoxy(x, y + 1);
    printf("알 고 리 즘 ");
    gotoxy(x, y + 2);
    printf("그 래 프");
    gotoxy(x, y + 3);
    printf("트 리");
    while (1) {
        int n = keyControl();
        switch (n) {
        case UP: {
            if (y > 15) {
                gotoxy(x - 2, y);
                printf("  ");
                gotoxy(x - 2, --y);
                printf(">");
            }
            break;
        }
        case DOWN: {
            if (y < 18) {
                gotoxy(x - 2, y);
                printf(" ");
                gotoxy(x - 2, ++y);
                printf(">");


            }
            break;
        }
        case SUBMIT: {
            return y - 15;
        }
        }
    }
}


void infoDraw() {
    system("cls");
    printf("\n\n");

    while (1) {
        if (keyControl() == SUBMIT) {
            break;
        }
    }
}

int maplistDraw() {
    int x = 75;
    int y = 6;
    system("cls");
    printf("\n\n");
    printf("\t\t\t\t\t\t\t\t\t[ 정렬 선택 ]\n\n");

    gotoxy(x - 2, y);
    printf("> 버블 정렬");
    gotoxy(x, y + 1);
    printf("선택 정렬");
    gotoxy(x, y + 2);
    printf("삽입 정렬");
    gotoxy(x, y + 3);
    printf("병합 정렬");
    gotoxy(x, y + 4);
    printf("퀵 정렬");
    gotoxy(x, y + 5);
    printf("힙 정렬");
    gotoxy(x, y + 6);
    printf("기수 정렬");
    gotoxy(x, y + 7);
    printf("계수 정렬");
    gotoxy(x, y + 8);
    printf("셸 정렬");
    gotoxy(x, y + 9);
    printf("[ 뒤로 ]");

    while (1) {
        int n = keyControl();
        switch (n) {
        case UP: {
            if (y > 6) {
                gotoxy(x - 2, y);
                printf(" ");
                gotoxy(x - 2, --y);
                printf(">");
            }
            break;
        }
        case DOWN: {
            if (y < 15) {
                gotoxy(x - 2, y);
                printf(" ");
                gotoxy(x - 2, ++y);
                printf(">");
            }
            break;
        }
        case SUBMIT: {
            return y - 6;
        }
        }
    }

}

int graph() {
    int x = 75;
    int y = 6;
    system("cls");
    printf("\n\n");
    printf("\t\t\t\t\t\t\t\t\t[ 알고리즘 선택 ]\n\n");

    gotoxy(x - 2, y);
    printf("> 깊이 우선 탐색");
    gotoxy(x, y + 1);
    printf("너비 우선 탐색");
    gotoxy(x, y + 2);
    printf("크루스칼");
    gotoxy(x, y + 3);
    printf("프림");
    gotoxy(x, y + 4);
    printf("위상정렬");
    gotoxy(x, y + 5);
    printf("[ 뒤로 ]");

    while (1) {
        int n = keyControl();
        switch (n) {
        case UP: {
            if (y > 6) {
                gotoxy(x - 2, y);
                printf(" ");
                gotoxy(x - 2, --y);
                printf(">");
            }
            break;
        }
        case DOWN: {
            if (y < 11) {
                gotoxy(x - 2, y);
                printf(" ");
                gotoxy(x - 2, ++y);
                printf(">");
            }
            break;
        }
        case SUBMIT: {
            return y - 6;
        }
        }
    }
}

//버블
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // 현재 원소와 다음 원소를 비교하여 순서가 잘못되어 있으면 교환
            if (arr[j] > arr[j + 1]) {
                // 두 원소를 교환
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                printArray(arr, n);
            }
        }
    }
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int bubble() {
    system("cls");
    int n;

    printf("배열의 크기를 입력하세요: ");
    scanf_s("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int)); // 동적으로 메모리 할당

    if (arr == NULL) {
        printf("메모리 할당 오류\n");
        return -1;
    }

    printf("배열의 요소를 입력하세요:\n");
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &arr[i]);
    }

    printf("입력한 배열: \n");
    printArray(arr, n);

    bubbleSort(arr, n);

    printf("정렬 후 배열: \n");
    printArray(arr, n);

    free(arr); // 동적으로 할당한 메모리 해제

    while (1) {
        if (keyControl() == SUBMIT) {
            main();
        }

    }
}
// 선택정렬

// 선택 정렬 함수
void selectionSort(int arr[], int n) {
    int i, j, min_index;

    for (i = 0; i < n - 1; i++) {
        min_index = i;

        // 현재 위치부터 배열의 마지막까지 최솟값을 찾음
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        // 최솟값을 현재 위치(i)와 교환
        int temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;

        // 1회전이 끝날 때마다 배열의 상태 출력
        printf("반복 %d 후: ", i + 1);
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}

int selection() {
    system("cls");
    int arr[20];
    int n;

    printf("배열의 크기를 입력하세요: ");
    scanf_s("%d", &n);

    printf("배열의 요소를 입력하세요:\n");
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &arr[i]);
    }

    printf("입력한 배열: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    selectionSort(arr, n);

    while (1) {
        if (keyControl() == SUBMIT) {
            main();
        }

    }
}

// 병합정렬
void merge(int arr[], int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // 임시 배열 생성
    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    // 임시 배열에 데이터 복사
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    i = 0;
    j = 0;
    k = left;

    // 임시 배열을 합쳐서 정렬된 배열을 만듦
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // 남은 요소들을 복사
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// 병합 정렬 함수
void mergeSort(int arr[], int left, int right, int n) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        // 왼쪽과 오른쪽 부분 배열 정렬
        mergeSort(arr, left, middle, n);
        mergeSort(arr, middle + 1, right, n);

        // 정렬된 부분 배열 병합
        merge(arr, left, middle, right);
        printArray(arr, n);
    }
}

// 배열 요소 출력 함수
void printArrayc(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int mergecc() {
    system("cls");
    int n;

    printf("배열의 크기를 입력하세요: ");
    scanf_s("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int)); // 배열 동적 할당

    if (arr == NULL) {
        printf("메모리 할당 오류\n");
        return -1;
    }

    printf("배열의 요소를 입력하세요:\n");
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &arr[i]);
    }

    printf("입력한 배열: \n");
    printArray(arr, n);

    mergeSort(arr, 0, n - 1, n);

    printf("정렬 후 배열: \n");
    printArray(arr, n);

    free(arr); // 동적으로 할당한 메모리 해제

    while (1) {
        if (keyControl() == SUBMIT) {
            main();
        }

    }
}

//삽입정렬

// 삽입 정렬 함수
void insertionSort(int arr[], int n) {
    int i, key, j;

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // 정렬된 배열 부분에서 삽입할 위치 찾기
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        printArray(arr, n);
    }
}

// 배열 요소 출력 함수
void printArrayd(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int insertion() {
    system("cls");
    int arr[20];
    int n;

    printf("배열의 크기를 입력하세요: ");
    scanf_s("%d", &n);


    printf("배열의 요소를 입력하세요:\n");
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &arr[i]);
    }

    printf("입력한 배열: \n");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("정렬 후 배열: \n");
    printArray(arr, n);

    while (1) {
        if (keyControl() == SUBMIT) {
            main();
        }

    }
}


//퀵정렬
// 퀵 정렬을 위한 파티션 함수
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            // swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // swap arr[i+1] and arr[high] (pivot)
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

// 퀵 정렬 함수
void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int partition_index = partition(arr, low, high);

        // 정렬 과정 출력
        printf("회전 결과: ");
        for (int i = low; i <= high; i++)
            printf("%d ", arr[i]);
        printf("\n");

        quick_sort(arr, low, partition_index - 1);
        quick_sort(arr, partition_index + 1, high);
    }
}

// 배열을 출력하는 함수
void quick_print(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int quick() {
    int n;
    system("cls");

    // 사용자로부터 배열 크기 입력
    printf("배열 크기를 입력하세요: ");
    scanf_s("%d", &n);

    // 동적으로 메모리 할당
    int* arr = (int*)malloc(n * sizeof(int));

    // 사용자로부터 배열 원소 입력
    printf("배열 원소를 입력하세요:\n");
    for (int i = 0; i < n; i++)
        scanf_s("%d", &arr[i]);

    printf("퀵 정렬 전 배열:\n");
    quick_print(arr, n);

    quick_sort(arr, 0, n - 1);

    printf("퀵 정렬 후 배열:\n");
    quick_print(arr, n);

    // 동적으로 할당한 메모리 해제
    free(arr);

    while (1) {
        if (keyControl() == SUBMIT) {
            main();
        }

    }
}



// 힙 정렬을 위한 heapify 함수
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left_child = 2 * i + 1;
    int right_child = 2 * i + 2;

    if (left_child < n && arr[left_child] > arr[largest])
        largest = left_child;

    if (right_child < n && arr[right_child] > arr[largest])
        largest = right_child;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

// 힙 정렬 함수
void heap_sort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);

        // 정렬 과정 출력
        printf("회전 %d 결과: ", n - i);
        for (int j = 0; j < n; j++)
            printf("%d ", arr[j]);
        printf("\n");
    }
}

// 배열을 출력하는 함수
void heap_print(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int heap_main() {
    int n;
    system("cls");

    // 사용자로부터 배열 크기 입력
    printf("배열 크기를 입력하세요: ");
    scanf_s("%d", &n);

    // 동적으로 메모리 할당
    int* arr = (int*)malloc(n * sizeof(int));

    // 사용자로부터 배열 원소 입력
    printf("배열 원소를 입력하세요:\n");
    for (int i = 0; i < n; i++)
        scanf_s("%d", &arr[i]);

    printf("힙 정렬 전 배열:\n");
    heap_print(arr, n);

    heap_sort(arr, n);

    // 동적으로 할당한 메모리 해제
    free(arr);

    while (1) {
        if (keyControl() == SUBMIT) {
            main();
        }

    }
}

//기수
#define MAX 20
int queue[MAX];
int front = 0, rear = 0;

// 기수 정렬을 위한 큐 함수들
int put(int k) {
    if ((rear + 1) % MAX == front) {
        printf("QUEUE OVERFLOW!\n\n");
        return -1;
    }
    else {
        queue[rear] = k;
        rear = ++rear % MAX;
        return 1;
    }
}

int get() {
    int k;
    if (front == rear) {
        printf("QUEUE UNDERFLOW!\n\n");
        return -1;
    }
    else {
        k = queue[front];
        front = ++front % MAX;
        return k;
    }
}

void print_radix(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%-4d", array[i]);
    }
    printf("\n");
}

void radix_sort(int array[], int size) {
    int max = array[0];
    int digit = 0;
    int factor = 1;

    for (int i = 1; i < size; i++) {
        if (max < array[i]) max = array[i];
    }

    for (int i = max; i > 0; i /= 10) {
        digit++;
    }

    for (int i = 0; i < digit; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < size; k++) {
                if ((array[k] / factor) % 10 == j) {
                    put(array[k]);
                }
            }
        }

        factor *= 10;

        for (int i = front; i != rear; i++) {
            array[i] = get();
        }

        printf("########### %d ROUND ###########\n", i + 1);
        print_radix(array, size);

        front = rear = 0;
    }
}

int radix_main() {
    system("cls");
    int t;
    printf("배열의 크기를 입력하세요: ");
    scanf_s("%d", &t);

    if (t <= 0) {
        printf("유효하지 않은 크기입니다. 양수를 입력하세요.\n");
        return 1;
    }

    int* radixArr = (int*)malloc(t * sizeof(int));
    if (radixArr == NULL) {
        printf("메모리 할당 실패\n");
        return 1;
    }

    system("cls");
    printf("배열의 요소를 입력하세요:\n");
    for (int i = 0; i < t; i++) {
        printf("radixArr[%d]: ", i);
        scanf_s("%d", &radixArr[i]);
    }

    system("cls");
    printf("사용자가 입력한 배열은: \n\t\t");
    for (int i = 0; i < t; i++) {
        printf("%d ", radixArr[i]);
    }

    printf("\n");

    printf("########### Sorting before ###########\n");
    print_radix(radixArr, t);
    radix_sort(radixArr, t);

    printf("기수 정렬 결과:\n");
    for (int i = 0; i < t; i++) {
        printf("%d ", radixArr[i]);
    }
    printf("\n");

    free(radixArr); // 동적 메모리 해제

    while (1) {
        if (keyControl() == SUBMIT) {
            main();
        }

    }
}


//계수정렬
// 배열 중에서 가장 큰 값을 찾아 반환
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// 계수 정렬 함수
void countingSort(int arr[], int n, int exp) {
    const int base = 10;

    int* output = (int*)malloc(n * sizeof(int*)); // 정렬된 결과를 저장할 배열
    int* count = (int*)malloc(base * sizeof(int*)); // 0부터 9까지의 자릿수 개수를 저장할 배열

    // 현재 자릿수에 따라 숫자를 세어 count 배열에 저장
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % base]++;
    }

    // 누적 개수 계산
    for (int i = 1; i < base; i++) {
        count[i] += count[i - 1];
    }

    // output 배열에 정렬된 순서대로 원소 저장
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % base] - 1] = arr[i];
        count[(arr[i] / exp) % base]--;
    }

    // output 배열을 원래 배열에 복사
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// 계수 정렬 수행
void radixSort(int arr[], int n) {
    int max = getMax(arr, n); // 배열에서 가장 큰 값
    int exp = 1; // 1의 자리부터 시작

    // 각 자릿수에 대해 반복
    while (max / exp > 0) {
        countingSort(arr, n, exp);

        // 현재 회전 결과 출력
        printf("회전 결과: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        // 다음 자릿수로 이동
        exp *= 10;
    }
}

int rradixmain() {
    system("cls");
    int n;

    // 배열 크기 입력
    printf("배열의 크기를 입력하세요: ");
    scanf_s("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int*));
    // 배열 요소 입력
    printf("배열의 요소를 입력하세요:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d]: ", i);
        scanf_s("%d", &arr[i]);
    }

    // 초기 배열 출력
    printf("초기 배열: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 계수 정렬 수행
    radixSort(arr, n);

    // 정렬 결과 출력
    printf("최종 정렬 결과: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    while (1) {
        if (keyControl() == SUBMIT) {
            main();
        }

    }
}

//셸
// 배열 출력 함수
void shell_print(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 셸 정렬 함수
void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;

            // 각 회전 결과 출력
            printf("회전 결과 (gap %d): ", gap);
            printArray(arr, n);
        }
    }
}

int shell_main() {
    system("cls");
    int n;

    // 배열 크기 입력
    printf("배열의 크기를 입력하세요: ");
    scanf_s("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int*));

    // 배열 요소 입력
    printf("배열의 요소를 입력하세요:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d]: ", i);
        scanf_s("%d", &arr[i]);
    }

    // 초기 배열 출력
    printf("초기 배열: ");
    shell_print(arr, n);

    // 셸 정렬 수행
    shellSort(arr, n);

    // 최종 정렬 결과 출력
    printf("최종 정렬 결과: ");
    shell_print(arr, n);

    while (1) {
        if (keyControl() == SUBMIT) {
            main();
        }

    }
}
