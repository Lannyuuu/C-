#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

//thread library实现多线程
void threaded_text(const string& text) {
	static mutex threadMutes; //声明一个静态互斥锁
	lock_guard<mutex> lock(threadMutes); //对于threadMutex自动加锁/解锁
	cout << "[Thread ID: " << this_thread::get_id() << "]" << text << endl;
	//this_thread::get_id()返回当前线程的ID
}
int main2() {
	//thread T1 = thread(threaded_text, "Threading is fun in C++!");
	//thread T2 = thread(threaded_text, "I love C++ ***");
	thread T1(threaded_text, "Threading is fun in C++!");
	thread T2(threaded_text, "I love C++ ***");
	T1.join(); //主线程等待T1线程结束
	T2.join(); //主线程等待T2线程结束
	return 0;
}