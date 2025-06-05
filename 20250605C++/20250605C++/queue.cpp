#include <iostream>
#include "queue.h"
using namespace std;

void Queue::push(int value) {
	if (rearIndex < 99) data[++rearIndex] = value;
}
void Queue::pop() {
	if (frontIndex <= rearIndex) frontIndex++;
}
int Queue::front() const {
	if (frontIndex <= rearIndex) return data[frontIndex];
	return -1; // or throw an exception
}
bool Queue::isEmpty() const {
	return frontIndex > rearIndex;
}