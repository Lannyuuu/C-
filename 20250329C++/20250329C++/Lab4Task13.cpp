#include <iostream>
#include <map>
#include <string>
using namespace std;

/*Task 13: Write a C++ program that takes a string as input and finds the first 
non-repeating character using map<char, int>.
• Example Input: "swiss"
• Example Output: 'w' is the first non-repeating character*/

char findFirstNonRepeatingChar(const string& str) {
    map<char, int> charCount; // 存储字符及其出现次数

    // 第一次遍历：统计每个字符的出现次数
    for (char c : str) {
        charCount[c]++;
    }

    // 第二次遍历：查找第一个出现次数为1的字符
    for (char c : str) {
        if (charCount[c] == 1) {
            return c;
        }
    }

    return '\0'; // 如果没有不重复字符，返回空字符
}

int main13() {
    string input;
    cout << "请输入一个字符串: ";
    getline(cin, input);

    char result = findFirstNonRepeatingChar(input);

    if (result != '\0') {
        cout << "'" << result << "' 是第一个不重复的字符" << endl;
    }
    else {
        cout << "字符串中没有不重复的字符" << endl;
    }

    return 0;
}