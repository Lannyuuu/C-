#include <iostream>
using namespace std;

//Task 7:

/*Task 7: Write a C++ program uses recursive functions to print the following
pattern on the screen. From user, take a input value N (integer type) 
representing the total number of rows (N >=3) in the pattern:*/

/*  *
   ***
  *****
 *******
*********
 *******
  *****
   ***
    *              */

// �ݹ麯������ӡָ���������ַ�
void printChars(int count, char c) {
    if (count <= 0) return;
    cout << c;
    printChars(count - 1, c);
}

// �ݹ麯������ӡ���ε��ϰ벿�֣������м��У�
void printUpperDiamond(int row, int n) {
    if (row > n) return;

    // ��ӡ�ո�
    printChars(n - row, ' ');
    // ��ӡ�Ǻ�
    printChars(2 * row - 1, '*');
    cout << endl;

    // �ݹ鴦����һ��
    printUpperDiamond(row + 1, n);
}

// �ݹ麯������ӡ���ε��°벿��
void printLowerDiamond(int row, int n) {
    if (row <= 0) return;

    // ��ӡ�ո�
    printChars(n - row, ' ');
    // ��ӡ�Ǻ�
    printChars(2 * row - 1, '*');
    cout << endl;

    // �ݹ鴦����һ��
    printLowerDiamond(row - 1, n);
}

int main12() {
    int N;

    cout << "Enter the number of rows for the diamond (odd number >= 3): ";
    cin >> N;

    // ��֤�����Ƿ�Ϊ������>=3
    if (N < 3 || N % 2 == 0) {
        cout << "Please enter an odd number >= 3" << endl;
        return 1;
    }

    int half = N / 2 + 1;

    cout << "Diamond pattern:" << endl;
    printUpperDiamond(1, half);  // ��ӡ�ϰ벿�֣������м��У�
    printLowerDiamond(half - 1, half);  // ��ӡ�°벿��

    return 0;
}