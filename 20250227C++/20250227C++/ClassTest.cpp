#include <iostream>
using namespace std;

//class BankAccount {
//private:
//	string name;
//	double balance;
//public:
//	void setBankAccount(string n, double b) {
//		name = n;
//		balance = b;
//	}
//	void displayBankAccount() {
//		cout << "Name: " << name << endl;
//		cout << "Balance: " << balance << endl;
//	}
//};
class BankAccount {
private:
	string name;
	double balance;
public:
	BankAccount();
	BanKAccount(const string & initName, double initBalance);

	void deposit(double amount);
	void withdraw(double amount);

	double getBalance() const;
	string getName() const;
};
int main() {
	/*BankAccount b1;
	b1.setBankAccount("John", 1000);
	b1.displayBankAccount();*/
}