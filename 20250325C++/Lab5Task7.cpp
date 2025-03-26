#include <iostream>
using namespace std;

//Task 7:

/*Task 7: Write a C++ program uses recursive functions to print the following
pattern on the screen. From user, take a input value N (integer type) 
representing the total number of rows (N >=3) in the pattern:*/

/*  *
   ***
  *****
 *******
*********
 *******
  *****
   ***
    *              */

// 递归函数：打印指定数量的字符
void printChars(int count, char c) {
    if (count <= 0) return;
    cout << c;
    printChars(count - 1, c);
}

// 递归函数：打印菱形的上半部分（包括中间行）
void printUpperDiamond(int row, int n) {
    if (row > n) return;

    // 打印空格
    printChars(n - row, ' ');
    // 打印星号
    printChars(2 * row - 1, '*');
    cout << endl;

    // 递归处理下一行
    printUpperDiamond(row + 1, n);
}

// 递归函数：打印菱形的下半部分
void printLowerDiamond(int row, int n) {
    if (row <= 0) return;

    // 打印空格
    printChars(n - row, ' ');
    // 打印星号
    printChars(2 * row - 1, '*');
    cout << endl;

    // 递归处理下一行
    printLowerDiamond(row - 1, n);
}

int main12() {
    int N;

    cout << "Enter the number of rows for the diamond (odd number >= 3): ";
    cin >> N;

    // 验证输入是否为奇数且>=3
    if (N < 3 || N % 2 == 0) {
        cout << "Please enter an odd number >= 3" << endl;
        return 1;
    }

    int half = N / 2 + 1;

    cout << "Diamond pattern:" << endl;
    printUpperDiamond(1, half);  // 打印上半部分（包括中间行）
    printLowerDiamond(half - 1, half);  // 打印下半部分

    return 0;
}