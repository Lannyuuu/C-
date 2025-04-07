#include <iostream>
#include <cmath> // ���� sqrt() ����
using namespace std;

// �������������һ�����Ƿ�Ϊ����
bool isPrime(int num);

int main_task3() {
    const int SIZE = 10; // �����С
    int arr[SIZE];       // ����һ������10��Ԫ�ص���������
    int* ptr = arr;      // ָ��ָ������ĵ�һ��Ԫ��

    // �û���������Ԫ��
    cout << "������ " << SIZE << " ������:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << "Ԫ�� " << i + 1 << ": ";
        cin >> *(ptr + i); // ʹ��ָ��������������Ԫ��
    }

    // ���Ҳ��������
    cout << "\n�����е�����Ϊ: ";
    bool foundPrime = false; // ����Ƿ��ҵ�����

    for (int i = 0; i < SIZE; i++) {
        if (isPrime(*(ptr + i))) { // ��鵱ǰԪ���Ƿ�Ϊ����
            cout << *(ptr + i) << " ";
            foundPrime = true;
        }
    }

    if (!foundPrime) {
        cout << "û���ҵ�����";
    }
    cout << endl;

    return 0;
}

// �������壺���һ�����Ƿ�Ϊ����
bool isPrime(int num) {
    if (num <= 1) {
        return false; // С�ڵ���1������������
    }
    if (num == 2) {
        return true; // 2������
    }
    if (num % 2 == 0) {
        return false; // �ų�����ż��
    }

    // ����3��sqrt(num)����������
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) {
            return false; // �ҵ���������������
        }
    }
    return true; // û���ҵ�������������
}