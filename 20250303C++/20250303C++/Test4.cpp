#include <iostream>
using namespace std;


//�� c++ ��дһ������������ no��Ԫ����������ÿ�����ʵĸ��������ַ��������ʽ��Ϊ�������ݡ�
//������� ��š�giver string �е�Ԫ���͸���

// �������ж��ַ��Ƿ�ΪԪ��
bool isVowel(char ch) {
    ch = tolower(ch); // ���ַ�ת��ΪСд
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

// ����������ÿ�����ʵ�Ԫ���͸�������
void countVowelsAndConsonants(char sentence[]) {
    int vowels = 0, consonants = 0;
    int i = 0;

    while (sentence[i] != '\0') {
        // �����ո�
        if (sentence[i] == ' ') {
            cout << "����: Ԫ�� = " << vowels << ", ���� = " << consonants << endl;
            vowels = 0;
            consonants = 0;
        }
        else {
            // �ж��ַ��Ƿ�Ϊ��ĸ
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

    // ������һ�����ʵ�ͳ�ƽ��
    cout << "����: Ԫ�� = " << vowels << ", ���� = " << consonants << endl;
}

int main() {
    char sentence[1000];

    // �������
    cout << "������һ������: ";
    cin.getline(sentence, 1000);

    // ����ÿ�����ʵ�Ԫ���͸�������
    countVowelsAndConsonants(sentence);

    return 0;
}