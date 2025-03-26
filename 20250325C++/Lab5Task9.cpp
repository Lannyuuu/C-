#include <iostream>
using namespace std;

//Task 9：

/*Task 9: Write a C++ program that calculates the Greatest Common Divisor 
(GCD) of two integers using recursion. The GCD of two integers is the largest 
integer that divides both without leaving a remainder value. 
For example: GCD (56, 98) should return 14.*/
// 递归函数：使用欧几里得算法计算最大公约数

int calculateGCD(int a, int b) {
    // 基本情况：当b为0时，a就是GCD
    if (b == 0) {
        return a;
    }
    // 递归情况：GCD(a, b) = GCD(b, a % b)
    return calculateGCD(b, a % b);
}

int main14() {
    int num1, num2;

    // 获取用户输入
    cout << "请输入第一个整数: ";
    cin >> num1;
    cout << "请输入第二个整数: ";
    cin >> num2;

    // 处理负数情况（GCD总是正数）
    num1 = abs(num1);
    num2 = abs(num2);

    // 计算并显示结果
    cout << num1 << " 和 " << num2 << " 的最大公约数是: " << calculateGCD(num1, num2) << endl;

    return 0;
}