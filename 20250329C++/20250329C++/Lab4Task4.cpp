#include <iostream>
#include <cstdlib>   // 用于 rand() 和 srand()
#include <ctime>     // 用于 time()
#include <algorithm> // 用于 max_element()

using namespace std;

/*Task 4: Write a C++ program that creates a 1D integer array having 100 
elements. Assign random values in the array in the range of (0 to 99). Next, find 
the most occurring element in the array. The program should print the most 
occurring number and its number of occurrences

Example: The most occurring number is 7 and it has appeared 23 times.*/

int main4() {
    const int SIZE = 100; // 数组大小
    int arr[SIZE];       // 声明100个元素的数组

    // 初始化随机数种子
    srand(time(0));

    // 用随机数(0-99)填充数组
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = rand() % 100; // 生成0-99的随机数
    }

    // 创建频率数组，记录每个数字出现的次数
    int frequency[100] = { 0 }; // 初始化为0

    // 统计每个数字的出现次数
    for (int i = 0; i < SIZE; ++i) {
        frequency[arr[i]]++;
    }

    // 找出出现次数最多的数字
    int maxFrequency = 0;
    int mostFrequentNumber = 0;

    for (int i = 0; i < 100; ++i) {
        if (frequency[i] > maxFrequency) {
            maxFrequency = frequency[i];
            mostFrequentNumber = i;
        }
    }

    // 输出结果
    cout << "数组中的随机数已生成。" << endl;
    cout << "出现最频繁的数字是 " << mostFrequentNumber
        << "，它出现了 " << maxFrequency << " 次。" << endl;

    return 0;
}