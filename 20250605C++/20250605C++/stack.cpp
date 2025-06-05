#include <iostream>
#include "stack.h"
using namespace std;

//Stack::表示属于Stack类的成员函数
void Stack::push(int value) {
	if (topIndex < 99) data[++topIndex] = value;
}
//++topIndex表示先指向下一个位置，然后再赋值
void Stack::pop() {
	if (topIndex >= 0) topIndex--;
}
int Stack::top() const {
	return data[topIndex];
}
int Stack::num_items() const {
	return topIndex + 1;
}