#include <iostream>
using namespace std;
//Destructor
class Thingy {
private:
	double* ptr;
public:
	//ʵ�������ж�̬������Դ��Rule of 3
	//Constructor
	Thingy(double value) {
		ptr = new double;
		*ptr = value;
	}
	//��д��"="�Ⱥŵ����壬��һ��Thingy���͵ı���ʹ�õȺŵ�ʱ��
	//����ʵ��ͨ��ָ�봫�ݸ���
	//����Ҫ��Ⱥ����ߵ�������������Thingy���͵�
	//Copy assignment operator
	Thingy& operator= (const Thingy& other) {
		*ptr = *(other.ptr);
	}
	//Destructor
	~Thingy() {
		delete ptr;
	}
	//����Rule of 3������Rule of 5
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
	int* aptr = &a; //aptrָ��a�ĵ�ַ
	int b = 20;
	int& bref = b; //brefֱ������
	shared_ptr<int> pointerA = make_shared<int>();
	*pointerA = 42;
	cout << pointerA.use_count() << endl;//����ָ�뱻ʹ�õĴ���
	return 0;
}