#include <iostream>
#include <cstdlib>   // ���� rand() �� srand()
#include <ctime>     // ���� time()
#include <algorithm> // ���� max_element()

using namespace std;

/*Task 4: Write a C++ program that creates a 1D integer array having 100 
elements. Assign random values in the array in the range of (0 to 99). Next, find 
the most occurring element in the array. The program should print the most 
occurring number and its number of occurrences

Example: The most occurring number is 7 and it has appeared 23 times.*/

int main4() {
    const int SIZE = 100; // �����С
    int arr[SIZE];       // ����100��Ԫ�ص�����

    // ��ʼ�����������
    srand(time(0));

    // �������(0-99)�������
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = rand() % 100; // ����0-99�������
    }

    // ����Ƶ�����飬��¼ÿ�����ֳ��ֵĴ���
    int frequency[100] = { 0 }; // ��ʼ��Ϊ0

    // ͳ��ÿ�����ֵĳ��ִ���
    for (int i = 0; i < SIZE; ++i) {
        frequency[arr[i]]++;
    }

    // �ҳ����ִ�����������
    int maxFrequency = 0;
    int mostFrequentNumber = 0;

    for (int i = 0; i < 100; ++i) {
        if (frequency[i] > maxFrequency) {
            maxFrequency = frequency[i];
            mostFrequentNumber = i;
        }
    }

    // ������
    cout << "�����е�����������ɡ�" << endl;
    cout << "������Ƶ���������� " << mostFrequentNumber
        << "���������� " << maxFrequency << " �Ρ�" << endl;

    return 0;
}