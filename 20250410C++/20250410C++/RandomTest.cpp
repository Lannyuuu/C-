#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;
int main_cingetline() {
	//�����������飬��һ�����������һ������
	const int SIZE = 100;
	char arr1[SIZE];
	char arr2[SIZE];
	cout << "Please input an array:";
	cin.getline(arr1, 100); //Ҫ������Ķ���char���͵�
	cout << "Please input another array:";
	cin.getline(arr2, 100);
	return 0;
}
int main_randomtest() {
	//�����������
	//step1:
	srand(time(0));
	//step2:������ɵ����ķ�Χ��%�����Ƕ��پ���0-����
	cout << rand() % 100 << endl;
	return 0;
}