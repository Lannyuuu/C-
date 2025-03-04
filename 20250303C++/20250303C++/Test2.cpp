#include <iostream>
using namespace std;

// 使用引用变量交换两个整数的函数
void swapIntegers(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// 使用引用变量交换两个浮点数的函数
void swapFloats(float& x, float& y) {
    float temp = x;
    x = y;
    y = temp;
}

int main() {
    int int1, int2;
    float float1, float2;

    // 输入两个整数
    cout << "请输入两个整数: ";
    cin >> int1 >> int2;

    // 输入两个浮点数
    cout << "请输入两个浮点数: ";
    cin >> float1 >> float2;

    // 交换整数
    swapIntegers(int1, int2);
    cout << "交换后的整数: " << int1 << " " << int2 << endl;

    // 交换浮点数
    swapFloats(float1, float2);
    cout << "交换后的浮点数: " << float1 << " " << float2 << endl;

    return 0;
}