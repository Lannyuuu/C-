#include <iostream>
#include <Array>
using namespace std;
int x = 10; // 全局变量
//----------Parameter-----------
string hello(string name = "laowang", string code = "403CMD") {
	return "Hello " + name + ", welcome to " + code + "!";
}
//注意：要是实参没有定义变量，那么就直接用形参定义的变量，要是实参直接传了定义好的变量，那就用实参
//void change_value(int& RefNum) {
//
//}
int countTime() {
	static int count = 1; //静态变量只被定义和初始化一次
	return count++;
}
//----------Pointer-----------
//array
array<char, 6> myArray = { "Hello" };
int main() {
	int x = 20;
	cout << hello() << endl; //Hello laowang, welcome to 403CMD!
	cout << hello("zhaosi", "2020202") << endl; //Hello zhaosi, welcome to 2020202!
	//访问全局变量-::
	cout << x << endl;
	cout << ::x << endl;
	int ref1 = countTime();
	int ref2 = countTime();
	cout << countTime() << endl;
	int* ptr = &x;
	int y = 30;
	int& refY = y;//&比*更安全
	//动态分配内存：
	int* myInt = new int;//分配4比特给myInt
	*myInt = 50;
	delete myInt;

	//固定大小数组
	int staticArray[10]; //[]里面必须是固定的数
	int* dynamicArray = new int[10];
	int size = 10;
	int* dynamicArray2 = new int[size];//new可以实现[]里面不写具体数字

	//有new就要有delete
	delete dynamicArray;
	delete dynamicArray2;

	//避免悬空指针
	int* ptr2 = new int;
	delete ptr2;
	ptr2 = nullptr; //防止ptr2成为悬空指针
	return 0;
}