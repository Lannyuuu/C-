#include <iostream>
#include <cmath> // 用于 sqrt() 函数
using namespace std;

// 函数声明：检查一个数是否为素数
bool isPrime(int num);

int main_task3() {
    const int SIZE = 10; // 数组大小
    int arr[SIZE];       // 声明一个包含10个元素的整型数组
    int* ptr = arr;      // 指针指向数组的第一个元素

    // 用户输入数组元素
    cout << "请输入 " << SIZE << " 个整数:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << "元素 " << i + 1 << ": ";
        cin >> *(ptr + i); // 使用指针算术访问数组元素
    }

    // 查找并输出素数
    cout << "\n数组中的素数为: ";
    bool foundPrime = false; // 标记是否找到素数

    for (int i = 0; i < SIZE; i++) {
        if (isPrime(*(ptr + i))) { // 检查当前元素是否为素数
            cout << *(ptr + i) << " ";
            foundPrime = true;
        }
    }

    if (!foundPrime) {
        cout << "没有找到素数";
    }
    cout << endl;

    return 0;
}

// 函数定义：检查一个数是否为素数
bool isPrime(int num) {
    if (num <= 1) {
        return false; // 小于等于1的数不是素数
    }
    if (num == 2) {
        return true; // 2是素数
    }
    if (num % 2 == 0) {
        return false; // 排除所有偶数
    }

    // 检查从3到sqrt(num)的奇数除数
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) {
            return false; // 找到除数，不是素数
        }
    }
    return true; // 没有找到除数，是素数
}