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
//Ҫ����Ҫ��һ�������а������ַ���/���飬Ҫ��ֻ��������߷��ʲ���Ҫ�ı�Ļ�
//������const
void printArray(const int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
		if ((i + 1) % 10 == 9) cout << endl; //ÿʮ��Ԫ�ػ�һ����
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

	//�ϲ���ż����:����odds��ǰ��ż��evens�ں�
	int index = 0;

	for (int num : odds) {
		dest[index++] = num;
	}
	for (int num : evens) {
		dest[index++] = num;
	}
}
//����������У����Ҷ��з�Χ����
int main() {
	srand(time(0));
	const int SIZE = 30;
	int arrayA[SIZE];

	initializeArray(arrayA, SIZE);
	printArray(arrayA, SIZE);

}
int main_task4() {
	//new�Լ�ָ���﷨��ϰ
	int* p = new int;
	//�﷨��ָ������ ָ����� = new ��������
	double* d = new double;
	//ָ��ָ������
	//ָ������ �������� = new �����ڲ���������[�����С] 
	int* arr1 = new int[5];
	double* arr2 = new double[10];
	//ָ������ά���飺��Ҫ��άָ��
	int** matrix = new int* [3]; //����3��int*���͵����飨��ָ�룩
	//int**:��ά�����ָ����Ҫ�Ƕ�άָ��
	//int*����ά�������汣�����
	for (int i = 0; i < 3; i++) {
		matrix[i] = new int[4]; //��
	}
	return 0;
}
bool foundPrime(int num) {
	//���С�ڵ���1����������
	if (num <= 1) return false;
	//2������
	if (num == 2) return true;
	//ż������������
	if (num % 2 == 0) return false;
	//��3��ʼ������������һֱ������num�����num�Ǳ������ı������Ͳ�������
	for (int i = 3; i < sqrt(num); i += 2) {
		if (num % i == 0) return false;
	}
	return true;
}
int main_testprime() {
	const int SIZE = 10;
	int arr[SIZE];
	int* ptr = arr;
	//ע�⣺�漰�����ҵ�ʱ��Ҫ����һ��flag����ʾ��û�ҵ�����Ȼû�������û�ҵ���
	bool flg = false;//һ������flag���ȳ�ʼ��Ϊfalse
	for (int i = 0; i < SIZE; i++) {
		cout << "Please input the " << i + 1 << " number:";
		cin >> *(ptr + i); //��ָ�����������ÿ��Ԫ��
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