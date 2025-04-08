#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int calculate(int x, int y) {
	return pow(x, y);
}
double calculate(double w, double z) {
	return w * z;
}
string calculate(int x, string str) {
	string result;
	for (int i = 0; i < x; i++) {
		result += str;
	}
	return result;
}
string calculate(string str, int y) {
	return str + to_string(y);
}
bool isPerfectNumber(int n) {
	int sum = 0;
	//不包含它自己
	for (int i = 1; i < n; i++) {
		if (n % i == 0) {
			sum += i;
		}
	}
	return sum == n;
}
int main_task5() {
	int num2 = 0;
	cout << "Please input a number:";
	cin >> num2;
	if (isPerfectNumber(num2)) {
		cout << "The number is a perfect number" << endl;
	}
	else {
		cout << "The number is not a perfect number " << endl;
	}
	return 0;
}
bool isPalindrome(int n) {
	int reverse = 0;
	int original = n;
	while (n > 0) {
		reverse = reverse * 10 + n % 10;
		n /= 10;
	}
	return original == reverse;
}

int main_task4() {
	int number = 0;
	cout << "Please input a number:";
	cin >> number;
	if (isPalindrome(number)) cout << "The number is palidrome" << endl;
	else cout << "The number is not a palidrome" << endl;
	return 0;
}
bool isPowerOfTwo(int n) {
	return ((n > 0) && (n & (n - 1)) == 0);
}

int main_task3() {
	int num;
	cout << "Please input a number :";
	cin >> num;
	if (isPowerOfTwo(num)) cout << "The number is a power of 2" << endl;
	else cout << "The number is not a power of 2" << endl;
	return 0;
}
void track() {
	static int count = 0;
	count++;
	cout << "I have been incoked " << count << " times" << endl;
}

int main_task2() {
	char choice;
	do {
		cout << "Do you want to use that function? (y/n) :";
		cin >> choice;
		if (choice == 'y') {
			track();
		}
	} while (choice != 'n');

	return 0;
}