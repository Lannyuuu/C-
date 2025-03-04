#include <iostream>
using namespace std;

int main() {
	string name;
	cout << "Enter your name :";
	cin >> name;

	int hours;
	cout << "Enter hours worked :";
	cin >> hours;

	int wage;
	cout << "Enter hourly wage :";
	cin >> wage;

	int total = hours * wage;
	cout << name << "your total weekly salary is :" << "$" << total << endl;
}