#pragma once
class Stack {
private:
	int data[100];
	int topIndex; //ջ��ָ��
public:
	Stack() : topIndex(-1){}
	void push(int value);
	void pop();
	int top() const;
	int num_items() const;
};