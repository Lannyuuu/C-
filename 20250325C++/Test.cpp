#include <iostream>
using namespace std;
int sum(int n) {
	if (n == 1) {
		return 1;
	}
	else
		return n + sum(n - 1);
}
int factorial(int n) {
	if (n == 0) {
		return 1;
	}
	else
		return n * factorial(n - 1);
}
int gcd(int x,int y) {
	if (x % y == 0) {
		return y;
	}
	else {
		return (y, x % y);
	}
}
int main1() {
	cout << sum(10) << endl;
	cout << factorial(5) << endl;
	cout << gcd(12,8) << endl;
	return 0;
}