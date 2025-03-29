#include <iostream>
using namespace std;

/*Task 3: Write a C++ program that creates an integer array having 50 elements. 
Take input from the user in the array. Next, input a value from the user and 
search that value in the array. The program should display the found value and 
its location (i.e., index) or display ��not found�� message if that value is not 
present in the array.*/

int main3() {
    const int SIZE = 5; // ���������СΪ50
    int arr[SIZE];      // ����һ������50��Ԫ�ص���������

    // ���û���ȡ��������
    cout << "������5��������" << endl;
    for (int i = 0; i < SIZE; ++i) {
        cout << "����� " << i + 1 << " ��Ԫ��: ";
        cin >> arr[i];
    }

    int searchValue; // Ҫ������ֵ
    cout << "\n������Ҫ����������ֵ: ";
    cin >> searchValue;

    bool found = false; // ����Ƿ��ҵ�

    // ������������
    for (int i = 0; i < SIZE; ++i) {
        if (arr[i] == searchValue) {
            cout << "�ҵ�ֵ " << searchValue << " ��λ��(����) " << i << endl;
            found = true;
            break; // �ҵ���һ��ƥ������˳�ѭ��
        }
    }

    // ���û���ҵ�
    if (!found) {
        cout << "δ�ҵ�ֵ " << searchValue << endl;
    }

    return 0;
}