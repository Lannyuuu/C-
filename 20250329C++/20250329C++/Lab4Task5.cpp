#include <iostream>
#include <cstring> // 用于 strlen() 函数

using namespace std;

/*Task 5: Write a C++ program that creates a char array named “original” having 
100 elements. Get input from the user in this char array. You are required to 
get input with spaces. Next, take from the user the int type position and a char 
array called “new”. Your program should insert the “new” char array to the 
“original” char array at the specified position. 
Hint: You need to shift elements in original array to accommodate new one. Also, to get 
input with spaces look for function cin.get ()*/

int main5() {
    const int SIZE = 100; // 原始数组大小
    char original[SIZE]; // 原始字符数组
    char newArr[SIZE];   // 要插入的新字符数组
    int position;        // 插入位置

    // 获取用户输入（可以包含空格）
    cout << "请输入原始字符串（最多" << SIZE - 1 << "个字符，可包含空格）: ";
    cin.get(original, SIZE);
    cin.ignore(); // 清除输入缓冲区中的换行符

    // 获取要插入的字符串
    cout << "请输入要插入的字符串（最多" << SIZE - 1 << "个字符，可包含空格）: ";
    cin.get(newArr, SIZE);
    cin.ignore(); // 清除输入缓冲区中的换行符

    // 获取插入位置
    cout << "请输入插入位置（0-" << strlen(original) << "）: ";
    cin >> position;

    // 验证插入位置是否有效
    if (position < 0 || position > strlen(original)) {
        cout << "错误：插入位置无效！" << endl;
        return 1;
    }

    // 检查插入后是否会超出数组大小
    if (strlen(original) + strlen(newArr) >= SIZE) {
        cout << "错误：插入后字符串长度将超出数组大小！" << endl;
        return 1;
    }

    // 移动原始数组中的字符以腾出空间
    int originalLen = strlen(original);
    int newLen = strlen(newArr);

    for (int i = originalLen; i >= position; --i) {
        original[i + newLen] = original[i];
    }

    // 插入新字符串
    for (int i = 0; i < newLen; ++i) {
        original[position + i] = newArr[i];
    }

    // 输出结果
    cout << "\n操作后的字符串: " << original << endl;

    return 0;
}