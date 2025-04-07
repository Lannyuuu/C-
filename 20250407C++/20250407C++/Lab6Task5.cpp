#include <iostream>
#include <cstdlib>  // 用于rand()和srand()
#include <ctime>    // 用于time()
#include <vector>   // 用于临时存储

using namespace std;

// 函数声明
void initializeArray(int arr[], int size);
void rearrangeArray(const int source[], int*& dest, int size);
void printArray(const int arr[], int size);

int main_task5() {
    const int SIZE = 30;
    int arrayA[SIZE];

    // 设置随机种子
    srand(time(0));

    // 初始化数组A (50-100的随机数)
    initializeArray(arrayA, SIZE);

    // 打印原始数组
    cout << "原始数组A:" << endl;
    printArray(arrayA, SIZE);

    // 动态分配数组B并重新排列元素
    int* arrayB = nullptr;
    rearrangeArray(arrayA, arrayB, SIZE);

    // 打印重新排列后的数组B
    cout << "\n重新排列后的数组B (奇数在前，偶数在后):" << endl;
    printArray(arrayB, SIZE);

    // 释放动态分配的内存
    delete[] arrayB;

    return 0;
}

// 用50-100的随机数初始化数组
void initializeArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = 50 + rand() % 51; // 50 + (0到50) = 50到100
    }
}

// 重新排列数组：奇数在前，偶数在后，保持原始顺序
void rearrangeArray(const int source[], int*& dest, int size) {
    vector<int> odds;  // 存储奇数
    vector<int> evens; // 存储偶数

    // 分类奇数和偶数
    for (int i = 0; i < size; i++) {
        if (source[i] % 2 != 0) {
            odds.push_back(source[i]);
        }
        else {
            evens.push_back(source[i]);
        }
    }

    // 动态分配目标数组
    dest = new int[size];

    // 合并奇数和偶数到目标数组
    int index = 0;
    for (int num : odds) {
        dest[index++] = num;
    }
    for (int num : evens) {
        dest[index++] = num;
    }
}

// 打印数组
void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
        if ((i + 1) % 10 == 0) { // 每10个元素换行
            cout << endl;
        }
    }
    cout << endl;
}