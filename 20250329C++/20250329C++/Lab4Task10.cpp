#include <iostream>
#include <map>
#include <string>
#include <sstream>  // 用于字符串分割
#include <cctype>   // 用于字符处理

using namespace std;

/*Task 10: Write a C++ program that reads a paragraph of text from the user and 
counts the frequency of each unique word using map<string, int>.
• Example Input:
"apple banana apple orange banana apple"
• Example Output: 
o apple -> 3 times
o banana -> 2 times
o orange -> 1 time*/

// 函数：将字符串转换为小写
string toLowercase(const string& str) {
    string lowerStr;
    for (char c : str) {
        lowerStr += tolower(c);
    }
    return lowerStr;
}

int main10() {
    map<string, int> wordFrequency;  // 存储单词及其频率
    string paragraph;
    string word;

    // 获取用户输入的段落
    cout << "请输入一段文本（按Enter结束输入）:\n";
    getline(cin, paragraph);

    // 使用字符串流分割单词
    istringstream iss(paragraph);

    // 统计每个单词的频率
    while (iss >> word) {
        // 移除标点符号（简单处理）
        if (ispunct(word.back())) {
            word.pop_back();
        }
        // 转换为小写以确保大小写不敏感
        string lowerWord = toLowercase(word);
        // 增加单词计数
        wordFrequency[lowerWord]++;
    }

    // 输出统计结果
    cout << "\n单词出现频率统计结果:\n";
    for (const auto& pair : wordFrequency) {
        cout << pair.first << " -> " << pair.second;
        // 处理单复数形式的输出
        if (pair.second == 1) {
            cout << " time\n";
        }
        else {
            cout << " times\n";
        }
    }

    return 0;
}