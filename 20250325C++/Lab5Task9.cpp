#include <iostream>
using namespace std;

//Task 9��

/*Task 9: Write a C++ program that calculates the Greatest Common Divisor 
(GCD) of two integers using recursion. The GCD of two integers is the largest 
integer that divides both without leaving a remainder value. 
For example: GCD (56, 98) should return 14.*/
// �ݹ麯����ʹ��ŷ������㷨�������Լ��

int calculateGCD(int a, int b) {
    // �����������bΪ0ʱ��a����GCD
    if (b == 0) {
        return a;
    }
    // �ݹ������GCD(a, b) = GCD(b, a % b)
    return calculateGCD(b, a % b);
}

int main14() {
    int num1, num2;

    // ��ȡ�û�����
    cout << "�������һ������: ";
    cin >> num1;
    cout << "������ڶ�������: ";
    cin >> num2;

    // �����������GCD����������
    num1 = abs(num1);
    num2 = abs(num2);

    // ���㲢��ʾ���
    cout << num1 << " �� " << num2 << " �����Լ����: " << calculateGCD(num1, num2) << endl;

    return 0;
}