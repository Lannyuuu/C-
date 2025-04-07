#include <iostream>
#include <cstdlib>  // 用于rand()和srand()
#include <ctime>    // 用于time()

using namespace std;

int main_task7() {
    // 设置随机种子
    srand(time(0));

    // 定义各行的大小
    const int ROWS = 5;
    int rowSizes[ROWS] = { 6, 9, 11, 13, 15 };

    // 创建指针数组
    int** jaggedArray = new int* [ROWS];

    // 为每行分配不同大小的内存并初始化
    for (int i = 0; i < ROWS; i++) {
        jaggedArray[i] = new int[rowSizes[i]];
        for (int j = 0; j < rowSizes[i]; j++) {
            jaggedArray[i][j] = rand() % 11; // 0-10的随机数
        }
    }

    // 计算并显示每行的和
    cout << "每行元素的和:" << endl;
    int totalSum = 0;
    for (int i = 0; i < ROWS; i++) {
        int rowSum = 0;
        for (int j = 0; j < rowSizes[i]; j++) {
            rowSum += jaggedArray[i][j];
        }
        totalSum += rowSum;
        cout << "行 " << i + 1 << " (" << rowSizes[i] << " 个元素): " << rowSum << endl;
    }
    cout << "所有行的总和: " << totalSum << endl;

    // 释放内存
    for (int i = 0; i < ROWS; i++) {
        delete[] jaggedArray[i];
    }
    delete[] jaggedArray;

    return 0;
}