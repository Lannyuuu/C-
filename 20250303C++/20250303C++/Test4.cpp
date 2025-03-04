#include <iostream>
using namespace std;


//用 c++ 编写一个程序来计数 no。元音，句子中每个单词的辅音，以字符数组的形式作为参数传递。
//程序计数 编号。giver string 中的元音和辅音

// 函数：判断字符是否为元音
bool isVowel(char ch) {
    ch = tolower(ch); // 将字符转换为小写
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

// 函数：计算每个单词的元音和辅音数量
void countVowelsAndConsonants(char sentence[]) {
    int vowels = 0, consonants = 0;
    int i = 0;

    while (sentence[i] != '\0') {
        // 跳过空格
        if (sentence[i] == ' ') {
            cout << "单词: 元音 = " << vowels << ", 辅音 = " << consonants << endl;
            vowels = 0;
            consonants = 0;
        }
        else {
            // 判断字符是否为字母
            if (isalpha(sentence[i])) {
                if (isVowel(sentence[i])) {
                    vowels++;
                }
                else {
                    consonants++;
                }
            }
        }
        i++;
    }

    // 输出最后一个单词的统计结果
    cout << "单词: 元音 = " << vowels << ", 辅音 = " << consonants << endl;
}

int main() {
    char sentence[1000];

    // 输入句子
    cout << "请输入一个句子: ";
    cin.getline(sentence, 1000);

    // 计算每个单词的元音和辅音数量
    countVowelsAndConsonants(sentence);

    return 0;
}