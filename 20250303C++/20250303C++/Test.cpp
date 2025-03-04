#include<iostream>
#include <cmath>

#define PI 3.14159 //define	常量PI 没有分号
using namespace std;

class Circle {
private:
	double radius;
public:
	Circle(double r) : radius(r) {};  // 构造函数 
	//Circle(doubel r) : redius(r){};
	double calculateArea() {
		return PI * pow(radius, 2);
	}
	double calculateCircumference() {
		return 2 * PI * radius;
	}
};

int main() {
	double radius;
	cout << "Enter the radius of the circle: ";
	cin >> radius;
	Circle circle(radius);
	cout << "Area of the circle: " << circle.calculateArea() << endl;
	cout << "Circumference of the circle: " << circle.calculateCircumference() << endl;
	return 0;

}