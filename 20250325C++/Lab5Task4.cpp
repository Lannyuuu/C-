#include <iostream>
using namespace std;

//Task 4:

/*Write a C++ program to check whether a given integer is a palindrome.
A number is considered a palindrome if it reads the same forward and
backward (e.g., 121, 1331, 12321).
The program should:
1. Prompt the user to enter an integer.
2. Implement a function to determine whether the number is a
palindrome.
3. Display an appropriate message indicating whether the number is a
palindrome or not.*/

bool isPalindrome(int n)
{
	int reversed = 0, original = n;
	while (n > 0)
	{
		reversed = reversed * 10 + n % 10;
		n /= 10;
	}
	return original == reversed;
}
int main8() {
	int n;
	cout << "Enter an integer:";
	cin >> n;
	if (isPalindrome(n))
		cout << n << " is a palindrome." << endl;
	else
		cout << n << " is not a palindrome." << endl;
	return 0;
}
