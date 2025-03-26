#include <iostream>
using namespace std;


/*Write a C++ program uses recursive functions to print the following
pattern on the screen. From user, take a input value N (integer type) 
representing the total number of rows (N >=3) in the pattern*/
//N = 6
//第1行：1个*
//第2行：2个*
//第3行：3个*
//第4行：3个*
//第5行：2个*
//第6行：1个*

/*Write a C++ program that demonstrates function overloading by 
implementing multiple overloaded versions of a calculate() function. Each 
version of the function should perform different mathematical operations 
based on the arguments passed.
o calculate(int x, int y): Returns the int value of x raised to y.
o calculate(double w, double z): Returns the product of two real
numbers.
o calculate(int x, string str): Returns a string with int(n)
concatenated copies of the parameter.
o calculate(string str, int y): Concatenates two strings (one 
converted from integer y).*/
















int waitWhat(int a, int b)
{
	int c = 0;
	return 2 * a + b;
}
float add(int a, int b)
{
	return a + b; //返回值是float类型,所以int类型的a会被转换为float类型
}
int main4()
{
	//cout << add(4, 8.9); //参数是int类型，8.9会被截断为8
	return 0;
}
int main3()
{
	int a = 1, b = 2, c;
	c = waitWhat(a++, --b);
	cout << c << endl;
	return 0;
}