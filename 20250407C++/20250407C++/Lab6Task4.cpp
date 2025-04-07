#include <iostream>
#include <cstdlib>  // 用于rand()和srand()
#include <ctime>    // 用于time()
#include <iomanip>  // 用于setw()

using namespace std;

// 函数声明
void initializeMatrix(int** matrix, int size);
void printMatrix(int** matrix, int size);
void transposeMatrix(int** matrix, int size);
void deallocateMatrix(int** matrix, int size);

int main_task4() {
    const int SIZE = 20; // 矩阵大小
    srand(time(0));      // 设置随机种子

    // 动态分配20×20矩阵
    int** matrix = new int* [SIZE];
    for (int i = 0; i < SIZE; i++) {
        matrix[i] = new int[SIZE];
    }

    // 初始化矩阵
    initializeMatrix(matrix, SIZE);

    // 打印原始矩阵
    cout << "原始矩阵:" << endl;
    printMatrix(matrix, SIZE);

    // 原地转置矩阵
    transposeMatrix(matrix, SIZE);

    // 打印转置后的矩阵
    cout << "\n转置后的矩阵:" << endl;
    printMatrix(matrix, SIZE);

    // 释放内存
    deallocateMatrix(matrix, SIZE);

    return 0;
}

// 用随机数初始化矩阵
void initializeMatrix(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % 100; // 生成0-99的随机数
        }
    }
}

// 打印矩阵
void printMatrix(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << setw(3) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// 原地转置矩阵
void transposeMatrix(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            // 交换matrix[i][j]和matrix[j][i]
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

// 释放矩阵内存
void deallocateMatrix(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}