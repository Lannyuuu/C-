#include <iostream>
#include <string>
using namespace std;

int main3() {
    string name; //Name of student
	int age; //Age of student

    cout << "Enter you name : ";
    cin >> name;
    cout << "Enter your age : ";
    cin >> age;

    /* Now print hello message with name and age */
    cout << "Hello " << name << " your age is " << age << " years.";
    return 0;
}
int main2() {
    int num1 = 1, num2 = 2;
    int sum = num1 + num2;
	cout << "The sum of " << num1 << " and " << num2 << " is " << sum << endl;
	return 0; //��дreturn 0ϵͳ��Ĭ�Ϸ���0
}
int main1() {
    cout << "Hello, World! \n";
    return 0;
}
/*
#include <iostream>��������׼��������⣬����ʹ�� std::cout �� std::endl��

int main()������������������￪ʼִ�С�

return 0;����ʾ��������������
*/