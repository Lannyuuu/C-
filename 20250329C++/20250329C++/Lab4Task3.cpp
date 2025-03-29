#include <iostream>
using namespace std;

/*Task 3: Write a C++ program that creates an integer array having 50 elements. 
Take input from the user in the array. Next, input a value from the user and 
search that value in the array. The program should display the found value and 
its location (i.e., index) or display “not found” message if that value is not 
present in the array.*/

int main3() {
    const int SIZE = 5; // 定义数组大小为50
    int arr[SIZE];      // 声明一个包含50个元素的整数数组

    // 从用户获取数组输入
    cout << "请输入5个整数：" << endl;
    for (int i = 0; i < SIZE; ++i) {
        cout << "输入第 " << i + 1 << " 个元素: ";
        cin >> arr[i];
    }

    int searchValue; // 要搜索的值
    cout << "\n请输入要搜索的整数值: ";
    cin >> searchValue;

    bool found = false; // 标记是否找到

    // 线性搜索数组
    for (int i = 0; i < SIZE; ++i) {
        if (arr[i] == searchValue) {
            cout << "找到值 " << searchValue << " 在位置(索引) " << i << endl;
            found = true;
            break; // 找到第一个匹配项后退出循环
        }
    }

    // 如果没有找到
    if (!found) {
        cout << "未找到值 " << searchValue << endl;
    }

    return 0;
}