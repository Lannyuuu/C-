#pragma once
class Queue {
private:
	int data[100];
	int frontIndex;
	int rearIndex;
public:
	Queue() : frontIndex(0), rearIndex(-1) {}
	void push(int value);
	void pop();
	int front() const;
	bool isEmpty() const;
};