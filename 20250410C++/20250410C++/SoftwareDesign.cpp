#include <iostream>
#include <algorithm>  // Including the Algorithm Library for certain functions like sort
#include <iostream>   // Including the Input/Output Stream Library
#include <vector>     // Including the Vector Library for using vectors
using namespace std;

// Function to find elements in the vector that are smaller than both adjacent neighbors
vector<int> test(vector<int> nums)
{
	// Initializing an empty vector to store elements that meet the condition
	vector<int> result;
	for (size_t i = 1; i < nums.size() - 1; ++i)
	{
		if (nums[i] < nums[i - 1] && nums[i] < nums[i + 1])
		{
			result.push_back(nums[i]);
		}
	}
	return result;
}

// Main function
int main_software()
{
	// Uncomment either of the following lines to test different sets of numbers
	vector<int> nums = {7, 2, 5, 3, 1, 5, 6}; // Test vector with non - matching elements
	//vector<int> nums = { 1, 2, 5, 0, 3, 1, 7 }; // Test vector with elements smaller than both adjacent neighbors
	cout << "Original Vector elements:\n";
	for (int x : nums)
	{
		cout << x << " "; // Printing the elements of the original vector
	}
	cout << endl;
	// Calling the test function to find elements smaller than both neighbors
	vector<int> res = test(nums);
	cout << "Elements smaller than both neighbors:\n";
	for (int x : res)
	{
		cout << x << " ";
	}
	return 0;
}
class Student {
private:
	string name;
	int age;
public:
	//构造函数练习
	Student(const string& name, int age)
		: name(name), age(age){}

	void setAge(int newAge) {
		if (newAge > 0) age = newAge;
	}
	int getAge() const {
		return age;
	}
	void setName(string newName) {
		name = newName;
	}
	string getName() const {
		return name;
	}
};
class AuthenticationService {
private:
	string username;
	string password;
public:
	//构造函数！！！
	AuthenticationService (const string& un, const string& pw)
		: username(un), password(pw){}

	//认证方法
	bool authenticate(const string& un, const string& pw) {
		return (un == username) && (pw == password);
	}
};
class UserProfile {
private:
	string profileInfo;
public:
	UserProfile(const string& p) : profileInfo(p){}
	//更新资料方法
	void updateProfile(const string& newProfileInfo) {
		profileInfo = newProfileInfo;
	}
	string getProfileInfo() const {
		return profileInfo;
	}
};
class EmailService {
private:
	string emailAddress;
public:
	EmailService(const string& email)
		: emailAddress(email){}
	//发送邮件的方法 输出
	void sendEmail(const string& subject, const string& message) const {
		cout << "Sending email to:" << emailAddress << "\n"
			<< "Subject:" << subject << "\n"
			<< "Message:" << message << endl;
	}
};
class Position {
private:
	int x;
	int y;
public:
	int getX() const {
		return x;
	}
	int getY() const {
		return y;
	}
	void setX(int newX) {
		x = newX;
	}
	void setY(int newY) {
		y = newY;
	}
};