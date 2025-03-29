#include <iostream>   // 输入输出流库
#include <vector>     // 向量容器库
#include <algorithm>  // 算法库（包含reverse函数）

using namespace std;  // 使用标准命名空间

/*Task 8: Write a C++ program that accepts N integers from the user and stores 
them in a vector<int>. The program should then reverse the stored values in 
the vector and display the vector on screen (from index 0 to N-1).
• Example Input: 5 10 15 20 25
• Example Output: 25 20 15 10 5*/

int main8() {
    vector<int> numbers; // 创建整型向量用于存储数字
    int n, num;         // n-数字个数，num-临时存储输入的数字

    // 获取用户要输入的数字数量
    cout << "请输入数字的个数(N): ";
    cin >> n;

    // 获取用户输入的数字并存入向量
    cout << "请输入" << n << "个整数，用空格分隔: ";
    for (int i = 0; i < n; ++i) {
        cin >> num;             // 读取用户输入的数字
        numbers.push_back(num); // 将数字添加到向量末尾
    }

    // 显示原始向量（可选步骤）
    cout << "原始向量: ";
    for (int num : numbers) {   // 使用范围for循环遍历向量
        cout << num << " ";     // 输出每个数字
    }
    cout << endl;               // 换行

    // 反转向量元素的顺序
    // 使用algorithm库中的reverse函数
    // begin()返回指向第一个元素的迭代器
    // end()返回指向最后一个元素后面位置的迭代器
    reverse(numbers.begin(), numbers.end());

    // 显示反转后的向量
    cout << "反转后的向量: ";
    for (int num : numbers) {   // 再次使用范围for循环
        cout << num << " ";     // 输出反转后的数字
    }
    cout << endl;

    return 0;  // 程序正常结束
}