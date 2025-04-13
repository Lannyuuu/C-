#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;
int main_cingetline() {
	//输入两个数组，把一个数组插入另一个数组
	const int SIZE = 100;
	char arr1[SIZE];
	char arr2[SIZE];
	cout << "Please input an array:";
	cin.getline(arr1, 100); //要求输入的都是char类型的
	cout << "Please input another array:";
	cin.getline(arr2, 100);
	return 0;
}
int main_randomtest() {
	//随机生成数：
	//step1:
	srand(time(0));
	//step2:随机生成的数的范围：%后面是多少就是0-多少
	cout << rand() % 100 << endl;
	return 0;
}