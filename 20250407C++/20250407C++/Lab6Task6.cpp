#include <iostream>
#include <cstdlib>  // ����rand()��srand()
#include <ctime>    // ����time()
#include <iomanip>  // ����setw()

using namespace std;

// ��������
int* create2DArray(int rows, int cols);
void initializeArray(int* arr, int rows, int cols);
void printDivisibleNumbers(int* arr, int rows, int cols);
void deleteArray(int* arr);

int main_task6() {
    const int ROWS = 8;
    const int COLS = 8;

    // �����������
    srand(time(0));

    // ����8x8��̬���飨��ָ�뷽����
    int* matrix = create2DArray(ROWS, COLS);

    // ��10-30���������ʼ������
    initializeArray(matrix, ROWS, COLS);

    // ��ӡ�ܱ�3��5��7��������
    cout << "�������ܱ�3��5��7������Ԫ��:" << endl;
    printDivisibleNumbers(matrix, ROWS, COLS);

    // �ͷ��ڴ�
    deleteArray(matrix);

    return 0;
}

// ʹ�õ�ָ�뷽��������ά����
int* create2DArray(int rows, int cols) {
    return new int[rows * cols];
}

// ��10-30���������ʼ������
void initializeArray(int* arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i * cols + j] = 10 + rand() % 21; // 10 + (0��20) = 10��30
        }
    }
}

// ��ӡ�ܱ�3��5��7��������
void printDivisibleNumbers(int* arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int num = arr[i * cols + j];
            if (num % 3 == 0 || num % 5 == 0 || num % 7 == 0) {
                cout << setw(3) << num << " ";
            }
            else {
                cout << "   "; // �������
            }
        }
        cout << endl;
    }
}

// �ͷ��ڴ�
void deleteArray(int* arr) {
    delete[] arr;
}