#include <iostream>
using namespace std;

// 函数：反转字符串
void reverseString(char str[]) {
    int length = 0;

    // 计算字符串的长度
	while (str[length] != '\0') { // 遍历字符数组，直到遇到空字符 '\0'
        length++;
    }

    // 反转字符串
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

// 函数：计算字符串的长度
int countCharacters(char str[]) {
    int length = 0;

    // 遍历字符数组，直到遇到空字符 '\0'
    while (str[length] != '\0') {
        length++;
    }

    return length;
}

int main() {
    char input[100];

    // 输入字符串
    cout << "请输入一个字符串: ";
    cin.getline(input, 100); // 使用 getline 读取一行输入

    // 计算字符串的长度
    int length = countCharacters(input);
    cout << "字符串的长度: " << length << endl;

    // 反转字符串
    reverseString(input);
    cout << "反转后的字符串: " << input << endl;

    return 0;
}