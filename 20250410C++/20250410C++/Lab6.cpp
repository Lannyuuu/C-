#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
void initializeArray(int array[], int size) {
	for (int i = 0; i < size; i++) {
		array[i] = 50 + rand() % 51;
	}
}
//要是想要传一个参数中包含：字符串/数组，要是只是输出或者访问不想要改变的话
//都加上const
void printArray(const int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
		if ((i + 1) % 10 == 9) cout << endl; //每十个元素换一次行
	}
	cout << endl;
}
void rearrangeArray(const int source[], int*& dest, int size) {
	vector<int> odds;
	vector<int> evens;

	for (int i = 0; i < size; i++) {
		if (source[i] == 2) {
			odds.push_back(source[i]);
		}
		else {
			evens.push_back(source[i]);
		}
	}

	dest = new int[size];

	//合并奇偶数列:奇数odds在前，偶数evens在后
	int index = 0;

	for (int num : odds) {
		dest[index++] = num;
	}
	for (int num : evens) {
		dest[index++] = num;
	}
}
//生成随机数中，左右都有范围的数
int main() {
	srand(time(0));
	const int SIZE = 30;
	int arrayA[SIZE];

	initializeArray(arrayA, SIZE);
	printArray(arrayA, SIZE);

}
int main_task4() {
	//new以及指针语法练习
	int* p = new int;
	//语法：指针类型 指针变量 = new 数据类型
	double* d = new double;
	//指针指向数组
	//指针类型 数组名称 = new 数组内部数据类型[数组大小] 
	int* arr1 = new int[5];
	double* arr2 = new double[10];
	//指针分配二维数组：需要二维指针
	int** matrix = new int* [3]; //分配3个int*类型的数组（行指针）
	//int**:二维数组的指针需要是二维指针
	//int*：二维数组里面保存的是
	for (int i = 0; i < 3; i++) {
		matrix[i] = new int[4]; //列
	}
	return 0;
}
bool foundPrime(int num) {
	//如果小于等于1：不是素数
	if (num <= 1) return false;
	//2是素数
	if (num == 2) return true;
	//偶数都不是素数
	if (num % 2 == 0) return false;
	//从3开始遍历所有奇数一直到根号num，如果num是遍历数的倍数，就不是素数
	for (int i = 3; i < sqrt(num); i += 2) {
		if (num % i == 0) return false;
	}
	return true;
}
int main_testprime() {
	const int SIZE = 10;
	int arr[SIZE];
	int* ptr = arr;
	//注意：涉及到查找的时候要定义一个flag：表示找没找到，不然没法输出找没找到了
	bool flg = false;//一般所有flag都先初始化为false
	for (int i = 0; i < SIZE; i++) {
		cout << "Please input the " << i + 1 << " number:";
		cin >> *(ptr + i); //用指针访问数组中每个元素
	}

	cout << "\nThe prime number is: ";
	for (int i = 0; i < SIZE; i++) {
		if (foundPrime(*(ptr + i))) {
			cout << *(ptr + i) << " ";
			flg = true;
		}
	}
	if (!flg) {
		cout << "There are no prime number in it" << endl;
	}
	return 0;
}
void swapPtr(float* num1, float* num2) {
	float temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
int main_task2() {
	float num1, num2;
	cout << "Please input number1:";
	cin >> num1;
	cout << "Please input number2:";
	cin >> num2;
	cout << "Before exchanging:" << endl;
	cout << "The first number:" << num1 << endl;
	cout << "The swcond number:" << num2 << endl;

	swapPtr(&num1, &num2);
	cout << "After exchanging:" << endl;
	cout << "The first number:" << num1 << endl;
	cout << "The swcond number:" << num2 << endl;
	return 0;
}