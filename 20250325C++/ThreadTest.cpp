#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

//thread libraryʵ�ֶ��߳�
void threaded_text(const string& text) {
	static mutex threadMutes; //����һ����̬������
	lock_guard<mutex> lock(threadMutes); //����threadMutex�Զ�����/����
	cout << "[Thread ID: " << this_thread::get_id() << "]" << text << endl;
	//this_thread::get_id()���ص�ǰ�̵߳�ID
}
int main2() {
	//thread T1 = thread(threaded_text, "Threading is fun in C++!");
	//thread T2 = thread(threaded_text, "I love C++ ***");
	thread T1(threaded_text, "Threading is fun in C++!");
	thread T2(threaded_text, "I love C++ ***");
	T1.join(); //���̵߳ȴ�T1�߳̽���
	T2.join(); //���̵߳ȴ�T2�߳̽���
	return 0;
}