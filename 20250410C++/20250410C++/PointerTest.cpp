#include <iostream>
using namespace std;
//Destructor
class Thingy {
private:
	double* ptr;
public:
	//实现在类中动态分配资源：Rule of 3
	//Constructor
	Thingy(double value) {
		ptr = new double;
		*ptr = value;
	}
	//重写了"="等号的意义，当一个Thingy类型的变量使用等号的时候：
	//可以实现通过指针传递复制
	//但是要求等号两边的两个变量都是Thingy类型的
	//Copy assignment operator
	Thingy& operator= (const Thingy& other) {
		*ptr = *(other.ptr);
	}
	//Destructor
	~Thingy() {
		delete ptr;
	}
	//除了Rule of 3，还有Rule of 5
	//Move constructor
	//Move assignment
	Thingy(Thingy&& other) {
		ptr = other.ptr;
		other.ptr = nullptr;
	}
	/*Thingy& opertator = (Thingy && other){
		swap(ptr,other.ptr);
	};*/
};
int main_pointerTest() {
	int a = 10;
	int* aptr = &a; //aptr指向a的地址
	int b = 20;
	int& bref = b; //bref直接引用
	shared_ptr<int> pointerA = make_shared<int>();
	*pointerA = 42;
	cout << pointerA.use_count() << endl;//计算指针被使用的次数
	return 0;
}