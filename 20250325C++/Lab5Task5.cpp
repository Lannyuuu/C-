#include <iostream>
using namespace std;

//Task 5:

/*Write a C++ program that checks whether a given number is a perfect
number. A perfect number is a positive integer that is equal to the sum of its
proper divisors (excluding itself). For example, 6 is a perfect number because
its divisors are 1, 2, and 3, and 1 + 2 + 3 = 6.
1. Implement a function that takes an integer as input and determines if it
is a perfect number.
2. The function should return true if the number is perfect, otherwise false.
3. In the main() function, prompt the user to enter a number, call the
function, and display whether the number is perfect or not.*/
bool isPerfect(int n)
{
	int sum = 0;
	for (int i = 1; i < n; i++)
	{
		if (n % i == 0)
			sum += i;
	}
	return sum == n;
}

int main9() {
	int n = 0;
	cout << "Enter a number:";
	cin >> n;
	if (isPerfect(n)) {
		cout << n << "is a perfect number";
	}
	else {
		cout << n << "is not a perfect number";
	}
	return 0;
}
