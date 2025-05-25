#include <iostream>
using namespace std;
class Teacher;//Forward declaration
class Student {
private:
	string name;
	const int test; //constҪ����Ҫͨ�����캯����ֵҪ���б�ֵ��ʽ,�����ڹ��캯�������渳ֵconst����
	int id;
	//static�������������/���������������ʵ������һ��ʵ�����ģ�����ʵ�����ı�
	static int studentCount;
public:
	int testV;
	Student(const string& n,int i) : test(12) {
		name = n;
		id = i;
	}
	string getName() const {
		return name;
	}
	int getId() {
		return id;
	}
	void setName(const string& name) {
		this->name = name;
	}
	void setId(int id) {
		this->id = id;
	}
	//static void countTheStudents() {
	//	//static������ֻ��ʹ�����static������
	//}
	//���������
	int operator+(const Student& s) {
		return this->getId() + s.id;
	}
	//ע�⣺const��ʹ��ʱ����constructor֮����destructor֮ǰ
	void displayStudentInfo() const { //�ں�����������дconst
		cout << "------------" << endl;
		cout << "Student: " << this->name << "\nId: " << this->id << endl;
	}
	//������Ԫ����
	friend void aFriendFunction(int i);
	friend class Teacher;
	~Student() {
		cout << "Destructor called for " << name << endl;
	}
};
void aFriendFunction(int i) {
	cout << "test the friend function: " << i << endl;
}
class Teacher {
private:
	int secret;
public:
	void displayStudent(Student& s) {
		cout <<"The student name is:" << s.name;
	}
};
//����
class Vehicle {
private:
	string name; // ���಻�ܷ��ʸ����private��Ա
	//����Ҫ����Ҫ���ʸ����б�private���εĳ�Ա��Ҫ�ø���Ĺ��캯������ʼ����
public:
	Vehicle(const string& n) : name(n){}
	virtual void move() {
		cout << "Vehicle is moving." << endl;
	}
	void display(){}
	virtual void honk() const = 0; // ���麯��

	virtual ~Vehicle(){} //����������������������������Ҫ��virtual
	//��������������ֱ�Ӳ���࣬���ಿ��й¶
	//�������ܱ��̳У�����������������Ϊvirtual������������Ϊ��ҲҪд

	//������������˳��������������˳��͹��캯������˳�������෴��
	//���캯��������->������
	//����������������->����
};
class Car : public Vehicle {//public���м̳У�private���Σ�������Ĭ����private�����ࣺ˽�м̳У�
public:
	//������ʸ����private���εĳ�ԱҪ�ø���Ĺ��캯��
	Car() : Vehicle("Xiaoche1"){} //��ִ�л����Ĭ�Ϲ��캯������ִ�������๹�캯��
	void move() override {
		cout << "Car is driving on road." << endl;
	}
};

//��̬
class Animal {
public:
	virtual void makeSound() {
		cout << "Some sound" << endl;
	}
};
class Dog : public Animal {
public:
	void makeSound() override {
		cout << "Bark" << endl;
	}
};
int main() {
	Student sd1("Zhang San", 1);
	Student sd2{ "Lao Wang",2 };
	sd1.testV = 100; //private��������ͨ��ʵ�������ʣ����� public����ֱ�� .���÷��ʸı�
	sd2.testV = 200;
	aFriendFunction(3000);
	sd1.displayStudentInfo();
	sd2.displayStudentInfo();
	//����ָ��
	Student sd3("Zhao Si",3);
	Student* ptr = &sd3;
	//ͨ��ָ����ʳ�Ա��
	//����1��* + .
	(*ptr).displayStudentInfo();
	//����2����ͷ�����
	ptr->displayStudentInfo();
	//ָ��+new Ҫ�ǵ���������д��������+deleteɾ��ָ��
	Student* ptr2 = new Student("Rob", 20);
	ptr2->displayStudentInfo();
	delete ptr2;
	//����ת��
	int i = (int)1.234f; // 1.234->1��ȥ������С�����֣�
	//��̬Polymorphism
	Animal* aAnimal = new Animal();
	Animal* aDog = new Dog(); //Upcasting������ָ��ָ���������
	aAnimal->makeSound();
	aDog->makeSound();
	//Downcasting��Ҫ��ʾת��������ȫ
	//���麯����ͨ��ָ��/���õ����;��������ĸ��汾
	//�麯����ͨ������/ָ��ָ���ʵ�ʶ������;��������ĸ��汾
	//���һ�������ڻ�������������涼�� virtual���Σ���ô����ת��֮����øú��������������ʵ������(��С���)�еĺ�������

	//��̬����
	vector<Vehicle*> vehicles;//�������ָ��
	vehicles.push_back(new Car());
	for (Vehicle* v : vehicles) {
		v->display();
	}
	//�����ֶ��ͷ��ڴ�
	for (Vehicle* v : vehicles) {
		delete v;
	}
	return 0;
}
//��ʹ�ö�̳е�ʱ�򣬼�һ������̳ж������
//�������1����ʾ���ã������ڶ����������ͬ���ĳ�Ա����ʱ
// Student::setName()
// Student::getName()
//�������2����̳�
// class babyStudent : virtual public Student{}

//Late binding:���ڰ󶨣������ʱ���޷�ȷ�������ĸ��汾��ֻ�����е�ʱ��Ż����
//����һ������ָ���κ�������Ļ���ָ��ptr
//ptr = new BaseClass() �����ǻ���
//ptr = new SubClass() ������ɶ������

//�ڴ������Ҫ�أ�
//1.ʹ��new��������
//2.������delete�ͷ�
//3.�������������������virtual ~Student(){}
