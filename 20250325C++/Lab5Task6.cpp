#include <iostream>
using namespace std;
#include <string>
#include <cmath> // ����pow()����

//Task 6:

/*Task 6: Write a C++ program that demonstrates function overloading by 
implementing multiple overloaded versions of a calculate() function. Each 
version of the function should perform different mathematical operations 
based on the arguments passed.
o calculate(int x, int y): Returns the int value of x raised to y.
o calculate(double w, double z): Returns the product of two real
numbers.
o calculate(int x, string str): Returns a string with int(n)
concatenated copies of the parameter.
o calculate(string str, int y): Concatenates two strings (one 
converted from integer y).
The main() function should prompt the user to enter values of variables x, y, w,
z, and str. and call accordingly the appropriate functions and display the results 
with proper messages on the screen.*/

// ����x��y�η�������������
int calculate(int x, int y) {
    return pow(x, y);
}

// ��������ʵ���ĳ˻�
double calculate(double w, double z) {
    return w * z;
}

// �����ַ�����n���ظ�
string calculate(int x, string str) {
    string result;
    for (int i = 0; i < x; i++) {
        result += str;
    }
    return result;
}

// ���ַ������������ַ�����ʽƴ��
string calculate(string str, int y) {
    return str + to_string(y);
}

int main11() {
    int x, y;
    double w, z;
    string str;

    // ��ȡ�û�����
    cout << "Input integer x: ";
    cin >> x;
    cout << "Input integer y: ";
    cin >> y;

    cout << "Input real number w: ";
    cin >> w;
    cout << "Input real number z: ";
    cin >> z;

    cout << "Input string str: ";
    cin.ignore(); // ������뻺����
    getline(cin, str);

    // �����������غ�������ʾ���
    cout << "\nCalculation results:\n";
    cout << x << " to the power of " << y << " is: " << calculate(x, y) << endl;
    cout << "The product of " << w << " and " << z << " is: " << calculate(w, z) << endl;
    cout << "The string \"" << str << "\" repeated " << x << " times: \"" << calculate(x, str) << "\"" << endl;
    cout << "The string \"" << str << "\" concatenated with the integer " << y << ": \"" << calculate(str, y) << "\"" << endl;

    return 0;
}