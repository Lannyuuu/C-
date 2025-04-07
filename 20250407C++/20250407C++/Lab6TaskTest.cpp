#include <iostream>
using namespace std;

int main_task1() {
	int a[5] = { 30,50,90,100,40 };
	int* aptr = a;
	(*aptr)--;
	aptr++;
	cout << a[0] << " " << a[1] << " " << *aptr << endl;
	return 0;
}