#include <iostream>
using namespace std;
class Teacher;//Forward declaration
class Student {
private:
	string name;
	const int test; //const要是想要通过构造函数赋值要用列表赋值方式,不能在构造函数体里面赋值const变量
	int id;
	//static变量：类的属性/方法，由类的所有实例共享。一个实例更改，所有实例都改变
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
	//	//static函数：只能使用类的static变量。
	//}
	//运算符重载
	int operator+(const Student& s) {
		return this->getId() + s.id;
	}
	//注意：const的使用时限在constructor之后在destructor之前
	void displayStudentInfo() const { //在函数声明后面写const
		cout << "------------" << endl;
		cout << "Student: " << this->name << "\nId: " << this->id << endl;
	}
	//声明友元函数
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
//基类
class Vehicle {
private:
	string name; // 子类不能访问父类的private成员
	//子类要是想要访问父类中被private修饰的成员，要用父类的构造函数来初始化。
public:
	Vehicle(const string& n) : name(n){}
	virtual void move() {
		cout << "Vehicle is moving." << endl;
	}
	void display(){}
	virtual void honk() const = 0; // 纯虚函数

	virtual ~Vehicle(){} //虚析构函数：父类声明析构函数要用virtual
	//非虚析构函数：直接拆基类，子类部分泄露
	//如果类可能被继承，析构函数必须声明为virtual，析构函数体为空也要写

	//析构函数调用顺序：析构函数调用顺序和构造函数调用顺序正好相反。
	//构造函数：基类->派生类
	//析构函数：派生类->基类
};
class Car : public Vehicle {//public公有继承，private修饰（不声明默认是private）父类：私有继承，
public:
	//子类访问父类的private修饰的成员要用父类的构造函数
	Car() : Vehicle("Xiaoche1"){} //先执行基类非默认构造函数，再执行派生类构造函数
	void move() override {
		cout << "Car is driving on road." << endl;
	}
};

//多态
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
	sd1.testV = 100; //private变量不能通过实例化访问，但是 public可以直接 .调用访问改变
	sd2.testV = 200;
	aFriendFunction(3000);
	sd1.displayStudentInfo();
	sd2.displayStudentInfo();
	//对象指针
	Student sd3("Zhao Si",3);
	Student* ptr = &sd3;
	//通过指针访问成员：
	//方法1：* + .
	(*ptr).displayStudentInfo();
	//方法2：箭头运算符
	ptr->displayStudentInfo();
	//指针+new 要记得在类里面写析构函数+delete删除指针
	Student* ptr2 = new Student("Rob", 20);
	ptr2->displayStudentInfo();
	delete ptr2;
	//类型转换
	int i = (int)1.234f; // 1.234->1（去掉所有小数部分）
	//多态Polymorphism
	Animal* aAnimal = new Animal();
	Animal* aDog = new Dog(); //Upcasting：父类指针指向子类对象
	aAnimal->makeSound();
	aDog->makeSound();
	//Downcasting需要显示转换，不安全
	//非虚函数：通过指针/引用的类型决定调用哪个版本
	//虚函数：通过引用/指针指向的实际对象类型决定调用哪个版本
	//如果一个函数在基类和派生类里面都用 virtual修饰，那么向上转型之后调用该函数，会输出最真实的物体(最小层的)中的函数内容

	//多态容器
	vector<Vehicle*> vehicles;//储存基类指针
	vehicles.push_back(new Car());
	for (Vehicle* v : vehicles) {
		v->display();
	}
	//必须手动释放内存
	for (Vehicle* v : vehicles) {
		delete v;
	}
	return 0;
}
//当使用多继承的时候，即一个子类继承多个父类
//解决方法1：显示调用：适用于多个基类中有同名的成员函数时
// Student::setName()
// Student::getName()
//解决方法2：虚继承
// class babyStudent : virtual public Student{}

//Late binding:晚期绑定：编译的时候无法确定调用哪个版本，只有运行的时候才会决定
//创建一个可能指向任何派生类的基类指针ptr
//ptr = new BaseClass() 可能是基类
//ptr = new SubClass() 可能是啥派生类

//内存管理三要素：
//1.使用new创建对象
//2.必须用delete释放
//3.基类必须有虚析构函数virtual ~Student(){}
