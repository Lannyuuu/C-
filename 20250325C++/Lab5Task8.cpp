#include <iostream>
#include <iomanip> // ����setw
using namespace std;

//Task 8:

/*Write a C++ program uses recursive functions to print the following
pattern on the screen. From user, take an input value N (integer type) 
representing the total number of rows (N >=3) in the pattern:*/

// �ݹ��ӡһ������
void printNumbers(int current, int max) {
    if (current > max) {
        cout << endl;
        return;
    }
    cout << current;
    printNumbers(current + 1, max);
}

// �ݹ��ӡ�ո�
void printSpaces(int count) {
    if (count <= 0) return;
    cout << " ";
    printSpaces(count - 1);
}

// �ݹ����ɵ�����ͼ��
void printInvertedTriangle(int n, int max) {
    if (n < 1) return;

    // ���㵱ǰ����Ҫ�Ŀո���
    int spaces = (max - n) / 2;

    // ��ӡǰ���ո�
    printSpaces(spaces);

    // ��ӡ����
    printNumbers(1, n);

    // �ݹ鴦����һ��
    printInvertedTriangle(n - 2, max);
}

int main13() {
    int N;

    cout << "Enter an odd starting number (N>=3): ";
    cin >> N;

    // ��֤�����Ƿ�Ϊ������>=3
    if (N < 3 || N % 2 == 0) {
        cout << "Please enter an odd number >=3" << endl;
        return 1;
    }

    cout << "Centered inverted triangle:" << endl;
    printInvertedTriangle(N, N);

    return 0;
}