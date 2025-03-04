#include<iostream>
#include <cmath>

#define PI 3.14159 //define	����PI û�зֺ�
using namespace std;

class Circle {
private:
	double radius;
public:
	Circle(double r) : radius(r) {};  // ���캯�� 
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