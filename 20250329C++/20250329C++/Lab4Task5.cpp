#include <iostream>
#include <cstring> // ���� strlen() ����

using namespace std;

/*Task 5: Write a C++ program that creates a char array named ��original�� having 
100 elements. Get input from the user in this char array. You are required to 
get input with spaces. Next, take from the user the int type position and a char 
array called ��new��. Your program should insert the ��new�� char array to the 
��original�� char array at the specified position. 
Hint: You need to shift elements in original array to accommodate new one. Also, to get 
input with spaces look for function cin.get ()*/

int main5() {
    const int SIZE = 100; // ԭʼ�����С
    char original[SIZE]; // ԭʼ�ַ�����
    char newArr[SIZE];   // Ҫ��������ַ�����
    int position;        // ����λ��

    // ��ȡ�û����루���԰����ո�
    cout << "������ԭʼ�ַ��������" << SIZE - 1 << "���ַ����ɰ����ո�: ";
    cin.get(original, SIZE);
    cin.ignore(); // ������뻺�����еĻ��з�

    // ��ȡҪ������ַ���
    cout << "������Ҫ������ַ��������" << SIZE - 1 << "���ַ����ɰ����ո�: ";
    cin.get(newArr, SIZE);
    cin.ignore(); // ������뻺�����еĻ��з�

    // ��ȡ����λ��
    cout << "���������λ�ã�0-" << strlen(original) << "��: ";
    cin >> position;

    // ��֤����λ���Ƿ���Ч
    if (position < 0 || position > strlen(original)) {
        cout << "���󣺲���λ����Ч��" << endl;
        return 1;
    }

    // ��������Ƿ�ᳬ�������С
    if (strlen(original) + strlen(newArr) >= SIZE) {
        cout << "���󣺲�����ַ������Ƚ����������С��" << endl;
        return 1;
    }

    // �ƶ�ԭʼ�����е��ַ����ڳ��ռ�
    int originalLen = strlen(original);
    int newLen = strlen(newArr);

    for (int i = originalLen; i >= position; --i) {
        original[i + newLen] = original[i];
    }

    // �������ַ���
    for (int i = 0; i < newLen; ++i) {
        original[position + i] = newArr[i];
    }

    // ������
    cout << "\n��������ַ���: " << original << endl;

    return 0;
}