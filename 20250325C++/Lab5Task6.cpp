#include <iostream>
using namespace std;
#include <string>
#include <cmath> // 用于pow()函数

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

// 计算x的y次方（两个整数）
int calculate(int x, int y) {
    return pow(x, y);
}

// 计算两个实数的乘积
double calculate(double w, double z) {
    return w * z;
}

// 返回字符串的n次重复
string calculate(int x, string str) {
    string result;
    for (int i = 0; i < x; i++) {
        result += str;
    }
    return result;
}

// 将字符串与整数的字符串形式拼接
string calculate(string str, int y) {
    return str + to_string(y);
}

int main11() {
    int x, y;
    double w, z;
    string str;

    // 获取用户输入
    cout << "Input integer x: ";
    cin >> x;
    cout << "Input integer y: ";
    cin >> y;

    cout << "Input real number w: ";
    cin >> w;
    cout << "Input real number z: ";
    cin >> z;

    cout << "Input string str: ";
    cin.ignore(); // 清空输入缓冲区
    getline(cin, str);

    // 调用所有重载函数并显示结果
    cout << "\nCalculation results:\n";
    cout << x << " to the power of " << y << " is: " << calculate(x, y) << endl;
    cout << "The product of " << w << " and " << z << " is: " << calculate(w, z) << endl;
    cout << "The string \"" << str << "\" repeated " << x << " times: \"" << calculate(x, str) << "\"" << endl;
    cout << "The string \"" << str << "\" concatenated with the integer " << y << ": \"" << calculate(str, y) << "\"" << endl;

    return 0;
}