#include <iostream>
using namespace std;

// ʹ�����ñ����������������ĺ���
void swapIntegers(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// ʹ�����ñ������������������ĺ���
void swapFloats(float& x, float& y) {
    float temp = x;
    x = y;
    y = temp;
}

int main() {
    int int1, int2;
    float float1, float2;

    // ������������
    cout << "��������������: ";
    cin >> int1 >> int2;

    // ��������������
    cout << "����������������: ";
    cin >> float1 >> float2;

    // ��������
    swapIntegers(int1, int2);
    cout << "�����������: " << int1 << " " << int2 << endl;

    // ����������
    swapFloats(float1, float2);
    cout << "������ĸ�����: " << float1 << " " << float2 << endl;

    return 0;
}