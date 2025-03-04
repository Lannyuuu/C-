#include <iostream>
#include <bitset>
using namespace std;
int main() {
	int my_int = 123;
	cout << my_int << endl;
	my_int = 321;
	cout << my_int << endl;
	return 0;
}
int main9() {
	int value;
	cout << "Please enter a value: ";
	cin >> value;
	bitset<16> x(value);
	if (x[0] == 1 && x[4] == 1 && x[10] == 1) {
		cout << "ON" << endl;
	}
	else {
		cout << "OFF" << endl;
	}
	return 0;
}
