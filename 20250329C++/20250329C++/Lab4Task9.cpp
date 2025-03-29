#include <iostream>
#include <vector>
#include <map>  // 用于存储数字及其频率

using namespace std;
/*Task 9: Write a C++ program that accepts N integers from the user, stores 
them in a vector<int>, and calculates the frequency of each unique number in 
the vector.
• Example Input: 1 2 3 1 2 1 4 5 4
• Example Output: 
1 -> 3 times
2 -> 2 times
3 -> 1 time
4 -> 2 times
5 -> 1 time*/

int main9() {
    vector<int> numbers;  // 存储用户输入的数字
    map<int, int> frequencyMap;  // 存储数字及其出现频率
    int n, num;

    // 获取用户要输入的数字数量
    cout << "请输入数字的个数(N): ";
    cin >> n;

    // 获取用户输入的数字
    cout << "请输入" << n << "个整数，用空格分隔: ";
    for (int i = 0; i < n; ++i) {
        cin >> num;
        numbers.push_back(num);  // 将数字添加到向量中
    }

    // 统计每个数字的出现频率
    for (int num : numbers) {
        frequencyMap[num]++;  // 如果数字不存在会自动创建并初始化为0
    }

    // 输出频率统计结果
    cout << "\n数字出现频率统计结果:" << endl;
    for (auto const& pair : frequencyMap) {
        cout << pair.first << " -> " << pair.second;
        // 处理单复数形式的输出
        if (pair.second == 1) {
            cout << " time" << endl;
        }
        else {
            cout << " times" << endl;
        }
    }

    return 0;
}