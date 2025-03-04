#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
using namespace std;

int binaryAndExample1 = 128;
int binaryAndExample2 = 12008000;
int binaryAndResult = binaryAndExample1 & binaryAndExample2;
int main7() {
	bitset<8> x(binaryAndExample1); //实现二进制转换
	bitset<8> y(binaryAndExample2);
	bitset<8> z(binaryAndResult);
	cout << x << endl;
	cout << y << endl;
	cout << z << endl;
	//cout << binaryAndResult << endl;
	return 0;
}
int main6() {
	int  x = 40 & 128;
	cout <<  x << endl;
	int y = 92 | 34;
	cout << y << endl;
	bitset<8> a(128); //十进制转换成二进制bitset实现
	cout << a << endl;
	return 0;
}
int main5() {
	int x = 10;
	int y = 50;
	cout << (x == y) << endl;
	bool re = (x < 20) && (y == x);
	cout << re << endl;
	return 0;
}
int main4() {
	int a = 7;
	bool x = (a < 10);
	bool y = (a <= 5);
	bool z = (a >= 5);
	cout << boolalpha << x << endl; //boolalpha:输出bool类型的值，不然会输出0或1
	cout << boolalpha << y << endl;
	cout << boolalpha << z << endl;
	return 0;
}
int main3() {
	//to calculate 8 to the power of 4 8的4次方
	int a = 8;
	int b = 4;
	int c = pow(a, b);
	cout << c << endl;
	int d = pow(9, 3);
	cout << (5 + 6) * d << endl;
	int e = 87 % 8;
	cout << e << endl;
	return 0;
}
int main2() {
	double P = 10492;
	double r = 0.0454;
	int t = 7;
	int n = 1;
	//复利计算公式
	double A = P * pow(1 + r / n, n * t);
	double I = A - P;

	cout << "The interest earned is: £" << I << endl;
	return 0;
} 
int main1() {
	int a = NULL;
	int b = 3;
	float c = 3.2f;
	double d = 3.2;
	string e = "hehe";
	bool f = true;
	char g = 'a';
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d << endl;
	cout << e << endl;
	cout << f << endl;
	cout << g << endl;
	return 0;
}