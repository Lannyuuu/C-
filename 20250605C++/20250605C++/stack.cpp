#include <iostream>
#include "stack.h"
using namespace std;

//Stack::��ʾ����Stack��ĳ�Ա����
void Stack::push(int value) {
	if (topIndex < 99) data[++topIndex] = value;
}
//++topIndex��ʾ��ָ����һ��λ�ã�Ȼ���ٸ�ֵ
void Stack::pop() {
	if (topIndex >= 0) topIndex--;
}
int Stack::top() const {
	return data[topIndex];
}
int Stack::num_items() const {
	return topIndex + 1;
}