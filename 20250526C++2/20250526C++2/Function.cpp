#include <iostream>
#include <Array>
using namespace std;
int x = 10; // ȫ�ֱ���
//----------Parameter-----------
string hello(string name = "laowang", string code = "403CMD") {
	return "Hello " + name + ", welcome to " + code + "!";
}
//ע�⣺Ҫ��ʵ��û�ж����������ô��ֱ�����βζ���ı�����Ҫ��ʵ��ֱ�Ӵ��˶���õı������Ǿ���ʵ��
//void change_value(int& RefNum) {
//
//}
int countTime() {
	static int count = 1; //��̬����ֻ������ͳ�ʼ��һ��
	return count++;
}
//----------Pointer-----------
//array
array<char, 6> myArray = { "Hello" };
int main() {
	int x = 20;
	cout << hello() << endl; //Hello laowang, welcome to 403CMD!
	cout << hello("zhaosi", "2020202") << endl; //Hello zhaosi, welcome to 2020202!
	//����ȫ�ֱ���-::
	cout << x << endl;
	cout << ::x << endl;
	int ref1 = countTime();
	int ref2 = countTime();
	cout << countTime() << endl;
	int* ptr = &x;
	int y = 30;
	int& refY = y;//&��*����ȫ
	//��̬�����ڴ棺
	int* myInt = new int;//����4���ظ�myInt
	*myInt = 50;
	delete myInt;

	//�̶���С����
	int staticArray[10]; //[]��������ǹ̶�����
	int* dynamicArray = new int[10];
	int size = 10;
	int* dynamicArray2 = new int[size];//new����ʵ��[]���治д��������

	//��new��Ҫ��delete
	delete dynamicArray;
	delete dynamicArray2;

	//��������ָ��
	int* ptr2 = new int;
	delete ptr2;
	ptr2 = nullptr; //��ֹptr2��Ϊ����ָ��
	return 0;
}