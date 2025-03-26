#include <iostream>
using namespace std;

//Task 2:

/*Create a function that tracks and displays the number of times it has
been called. For example, it should print: "I have been called 3 times." Then,
write a main() program that prompts the user to call the function. If the user
enters 'y', the function is executed; if 'n' is entered, the program exits.
NOTE: Do not use any global variable or parameters to the function.*/

void track()
{
	static int count = 0; //����һ����̬�ֲ���������֤����������Ϻ󲻻ᱻ����
	count++;
	cout << "I have been called " << count << " times." << endl;
}

int main7() {
	char choice;
	do {
		cout << "Do you want to call the function? (y/n):";
		cin >> choice;
		if (choice == 'y') {
			track();
		}
	} while (choice != 'n');
	return 0;
}