#include <iostream>
using namespace std;

//Task 3:

/*Write a C++ function that checks whether a given integer is a power of
2. The function should take an integer as input and return true if the number
is a power of 2; otherwise, it should return false.
Additionally, implement a main() function that prompts the user to enter an
integer, calls the function, and displays an appropriate message based on the
result.*/
bool isPowerOfTwo(int n)
{
	if (n <= 0)
		return false;
	return (n & (n - 1)) == 0;
}
int main5() {
	int n;
	cout << "Enter an integer:";
	cin >> n;
	if (isPowerOfTwo(n))
		cout << n << " is a power of 2." << endl;
	else
		cout << n << " is not a power of 2." << endl;
	return 0;
}
