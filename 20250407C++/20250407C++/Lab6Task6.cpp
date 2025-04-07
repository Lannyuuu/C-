#include <iostream>
#include <cstdlib>  // 用于rand()和srand()
#include <ctime>    // 用于time()
#include <iomanip>  // 用于setw()

using namespace std;

// 函数声明
int* create2DArray(int rows, int cols);
void initializeArray(int* arr, int rows, int cols);
void printDivisibleNumbers(int* arr, int rows, int cols);
void deleteArray(int* arr);

int main_task6() {
    const int ROWS = 8;
    const int COLS = 8;

    // 设置随机种子
    srand(time(0));

    // 创建8x8动态数组（单指针方法）
    int* matrix = create2DArray(ROWS, COLS);

    // 用10-30的随机数初始化数组
    initializeArray(matrix, ROWS, COLS);

    // 打印能被3、5或7整除的数
    cout << "数组中能被3、5或7整除的元素:" << endl;
    printDivisibleNumbers(matrix, ROWS, COLS);

    // 释放内存
    deleteArray(matrix);

    return 0;
}

// 使用单指针方法创建二维数组
int* create2DArray(int rows, int cols) {
    return new int[rows * cols];
}

// 用10-30的随机数初始化数组
void initializeArray(int* arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i * cols + j] = 10 + rand() % 21; // 10 + (0到20) = 10到30
        }
    }
}

// 打印能被3、5或7整除的数
void printDivisibleNumbers(int* arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int num = arr[i * cols + j];
            if (num % 3 == 0 || num % 5 == 0 || num % 7 == 0) {
                cout << setw(3) << num << " ";
            }
            else {
                cout << "   "; // 对齐输出
            }
        }
        cout << endl;
    }
}

// 释放内存
void deleteArray(int* arr) {
    delete[] arr;
}