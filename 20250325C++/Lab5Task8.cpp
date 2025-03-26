#include <iostream>
#include <iomanip> // 用于setw
using namespace std;

//Task 8:

/*Write a C++ program uses recursive functions to print the following
pattern on the screen. From user, take an input value N (integer type) 
representing the total number of rows (N >=3) in the pattern:*/

// 递归打印一行数字
void printNumbers(int current, int max) {
    if (current > max) {
        cout << endl;
        return;
    }
    cout << current;
    printNumbers(current + 1, max);
}

// 递归打印空格
void printSpaces(int count) {
    if (count <= 0) return;
    cout << " ";
    printSpaces(count - 1);
}

// 递归生成倒三角图案
void printInvertedTriangle(int n, int max) {
    if (n < 1) return;

    // 计算当前行需要的空格数
    int spaces = (max - n) / 2;

    // 打印前导空格
    printSpaces(spaces);

    // 打印数字
    printNumbers(1, n);

    // 递归处理下一行
    printInvertedTriangle(n - 2, max);
}

int main13() {
    int N;

    cout << "Enter an odd starting number (N>=3): ";
    cin >> N;

    // 验证输入是否为奇数且>=3
    if (N < 3 || N % 2 == 0) {
        cout << "Please enter an odd number >=3" << endl;
        return 1;
    }

    cout << "Centered inverted triangle:" << endl;
    printInvertedTriangle(N, N);

    return 0;
}