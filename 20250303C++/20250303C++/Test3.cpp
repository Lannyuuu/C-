#include <iostream>
using namespace std;

// ��������ת�ַ���
void reverseString(char str[]) {
    int length = 0;

    // �����ַ����ĳ���
	while (str[length] != '\0') { // �����ַ����飬ֱ���������ַ� '\0'
        length++;
    }

    // ��ת�ַ���
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

// �����������ַ����ĳ���
int countCharacters(char str[]) {
    int length = 0;

    // �����ַ����飬ֱ���������ַ� '\0'
    while (str[length] != '\0') {
        length++;
    }

    return length;
}

int main() {
    char input[100];

    // �����ַ���
    cout << "������һ���ַ���: ";
    cin.getline(input, 100); // ʹ�� getline ��ȡһ������

    // �����ַ����ĳ���
    int length = countCharacters(input);
    cout << "�ַ����ĳ���: " << length << endl;

    // ��ת�ַ���
    reverseString(input);
    cout << "��ת����ַ���: " << input << endl;

    return 0;
}