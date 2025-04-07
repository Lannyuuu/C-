#include <iostream>  // 包含输入输出流库
using namespace std; // 使用标准命名空间

// 使用指针交换两个浮点数的函数
void swapFloats(float* ptr1, float* ptr2) {
    float temp = *ptr1;  // 临时存储ptr1指针所指向的值
    *ptr1 = *ptr2;       // 将ptr2指针所指向的值赋给ptr1指向的变量
    *ptr2 = temp;        // 将临时存储的值(原ptr1的值)赋给ptr2指向的变量
}

int main_task2() {
    float num1, num2;  // 声明两个浮点型变量

    // 获取用户输入
    cout << "请输入第一个浮点数: ";
    cin >> num1;
    cout << "请输入第二个浮点数: ";
    cin >> num2;

    // 显示交换前的值
    cout << "\n交换前:" << endl;
    cout << "第一个数: " << num1 << endl;
    cout << "第二个数: " << num2 << endl;

    // 调用交换函数，传入两个变量的地址
    swapFloats(&num1, &num2);

    // 显示交换后的值
    cout << "\n交换后:" << endl;
    cout << "第一个数: " << num1 << endl;
    cout << "第二个数: " << num2 << endl;

    return 0;  // 程序正常结束
}