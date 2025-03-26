#include <iostream>
using namespace std;

int doWork(int);
int x = 16; int y = 16;
int z = 20;
int main() {
	int t = 99;
	int x = 10;
	int y = 20;
	y *= doWork(4) + 2;
	cout << x << "\t" << y << "\t" << "\t" << z << endl;
	return 0;
}
int doWork(int w = 8) {
	x /= z - y + w;
	return x;
}