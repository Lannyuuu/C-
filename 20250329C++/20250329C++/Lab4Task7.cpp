#include <iostream>
#include <vector>

using namespace std;

/*Task 7: Write a C++ program that accepts N integers from the user and stores 
them in a vector<int>. The program should then display the elements in 
reverse order without modifying the original vector.
• Example Input: 5 10 15 20 25
• Example Output: 25 20 15 10 5*/

int main7() {
    vector<int> numbers; // 创建整型向量存储用户输入
    int n, num;         // n-整数数量，num-临时存储每个整数

    // 获取用户要输入的整数数量
    cout << "请输入要输入的整数数量(N): ";
    cin >> n;

    // 获取N个整数并存储在向量中
    cout << "请输入" << n << "个整数，用空格分隔: ";
    for (int i = 0; i < n; ++i) {
        cin >> num;
        numbers.push_back(num); // 将每个数字添加到向量末尾
    }

    // 显示原始向量（可选）
    cout << "\n原始顺序: ";
    for (int num : numbers) { // 范围for循环遍历向量
        cout << num << " ";
    }

    // 以相反顺序显示向量元素（使用反向迭代器）
    cout << "\n反转顺序: ";
    // rbegin()返回指向最后一个元素的反向迭代器
    // rend()返回指向第一个元素之前位置的反向迭代器
    for (auto it = numbers.rbegin(); it != numbers.rend(); ++it) {
        cout << *it << " "; // 解引用迭代器获取值
    }

    cout << endl;

    return 0;
}