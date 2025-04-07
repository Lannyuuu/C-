#include <iostream>
using namespace std;

//Task3
int main_task3() {
	const int SIZE = 5;
	int arr[SIZE];

	cout << "Input" << SIZE << "numbers:" << endl;
	for (int i = 0; i < SIZE; i++) {
		cin >> arr[i];
	}
	int searchVal = 0;
	cout << "Input the number you want:";
	cin >> searchVal;

	bool flg = false;
	for (int i = 0; i < SIZE;i++) {
		if (arr[i] == searchVal) {
			flg = true;
			cout << i << endl;
			break;
		}
	}
	if (!flg) {
		cout << "Not found" << endl;
	}
	return 0;
}
//Task4
#include <cstdlib>
#include <ctime>

int main_task4() {
	//定义数组
	const int SIZE = 100;
	int randomNumberArray[SIZE];
	//随机生成数 存到数组里面
	srand(time(0));
	for (int i = 0; i < SIZE; i++) {
		randomNumberArray[i] = rand() % 100;
	}
	//出现频率，放到频率数组里面
	int frequency[100] = { 0 };
	for (int i = 0; i < SIZE; i++) {
		frequency[randomNumberArray[i]]++;
	}
	//找到出现最多的数字和它的频率
	int maxFrequency = 0;
	int mostFrequencyNumber = 0;
	for (int i = 0; i < 100; i++) {
		if (frequency[i] > maxFrequency) {
			maxFrequency = frequency[i];
			mostFrequencyNumber = i;
		}
	}
	//输出
	cout << "The most occurring number is " << mostFrequencyNumber
		<< " and it has appeared " << maxFrequency << " times." << endl;

	return 0;
}

//Task5
#include <iostream>
#include <cstring> //strlen()

void insert_chars(char oldArray[], char newArray[], int p) {
	int oldlen = strlen(oldArray);
	int newlen = strlen(newArray);

	if (oldlen + newlen >= 100) {
		cout << "TOO LONG: Larger than 100";
		return;
	}

	//往后移newlen长度
	for (int i = oldlen; i >= p; i--) {
		oldArray[i + newlen] = oldArray[i];
	}
	//插入newArray
	for (int j = 0; j < newlen; j++) {
		oldArray[p + j] = newArray[j];
	}
}
int main_task5() {
	char original[100] = { 0 };
	cout << "Input original array(Including spaces,less than 99):";
	cin.getline(original, 100);

	char arr2[100] = { 0 };
	cout << "Input the array you want to insert(Including spaces,less than 99):";
	cin.getline(arr2, 100);

	int position = 0;
	cout << "Input the position you want to insert:";
	cin >> position;

	if (position < 0 || position > strlen(original)) {
		cout << "The position is invalid";
		return 1;
	}

	insert_chars(original, arr2, position);
	cout << "After inserting, the array is:" << original << endl;
	return 0;
}

//Task6
#include <vector>
#include <numeric> //算累积：accumulate()
#include <algorithm> //计算vector中最大最小值

using namespace std;
void displayMenu() {
	cout << "\nStudent Academic Performance Management System" << endl;
	cout << "1. Add marks" << endl;
	cout << "2. Display all marks" << endl;
	cout << "3. Remove the last mark" << endl;
	cout << "4. Display the highest and the lowest marks" << endl;
	cout << "5. Display the average" << endl;
	cout << "6. Get out of the system" << endl;
}
void addMarks(vector<int>& marks) {
	int mark;
	cout << "Please input the mark you want to add(Input -1 to out):";
	cin >> mark;
	while (mark != -1) {
		if (mark >= 0 && mark <= 100) {
			marks.push_back(mark);
			cout << "Successfully added the grade:" << mark << endl;
			cout << "Continue to enter, or enter -1 to end:";
		}
		else {
			cout << "[Invalid] Please input mark(0-100)";
		}
	}
}
void displayMarks(vector<int>& marks) {
	if (marks.empty()) {
		cout << "No mark in the system" << endl;
		return;
	}
	cout << "All stutudents' marks:" << endl;
	for (int mark : marks) {
		cout << mark << " ";
	}
	cout << endl; //换行
}
void removeLastMark(vector<int>& marks) {
	if (marks.empty()) {
		cout << "No mark in the system" << endl;
		return;
	}
	cout << "The mark will remove is:" << marks.back() << endl; //只是显示（不删除）
	marks.pop_back();//直接删除
}
void displayHighestAndLowest(vector<int>& marks) { //min_element, max_element
	if (marks.empty()) {
		cout << "No mark in the system" << endl;
		return;
	}
	auto max_it = max_element(marks.begin(), marks.end());
	auto min_it = min_element(marks.begin(), marks.end());

	cout << "The highest mark is:" << *max_it << endl;
	cout << "The lowest mark is:" << *min_it << endl;
}
void displayAverage(vector<int>& marks) { //accumulate(), marks.size()
	if (marks.empty()) {
		cout << "No mark in the system" << endl;
		return;
	}
	double sum = accumulate(marks.begin(), marks.end(), 0);
	double average = sum / marks.size();

	cout << "The average mark is:" << average << endl;
}
int main_task6() {
	vector<int> marks;
	int choice;

	do{
		//显示菜单
		displayMenu();
		//输入
		cout << "Please input your choice: ";
		cin >> choice;
		//switch
		switch (choice) {
		case 1:
			addMarks(marks);
			break;
		case 2:
			displayMarks(marks);
			break;
		case 3:
			removeLastMark(marks);
			break;
		case 4:
			displayHighestAndLowest(marks);
			break;
		case 5:
			displayAverage(marks);
			break;
		case 6:
			cout << "OUT" << endl;
			break;
		default:
			cout << "Not valid input" << endl;
		}

	} while (choice != 6);
	return 0;
}

//Task7
void reverse_vector_task7(const vector<int> vec) {
	cout << "The reverse vector is:";
	for (int i = vec.size() - 1; i >= 0; i--) {
		cout << vec[i] << " ";
	}
}
//Task8
void reverse_vector_task8(vector<int> vec) {
	int start = 0;
	int end = vec.size() - 1;

	while (start < end) {
		swap(vec[start], vec[end]);
		start++;
		end--;
	}
}
//Task9
#include <map>
int main() {
	vector<int> numbers;  // 存储用户输入的数字
	map<int, int> frequencyMap;  // 存储数字及其出现频率
	int n, num;

	// 获取用户要输入的数字数量
	cout << "请输入数字的个数(N): ";
	cin >> n;

	// 获取用户输入的数字
	cout << "请输入" << n << "个整数，用空格分隔: ";
	for (int i = 0; i < n; ++i) {
		cin >> num;
		numbers.push_back(num);  // 将数字添加到向量中
	}

	// 统计每个数字的出现频率
	for (int num : numbers) {
		frequencyMap[num]++;  // 如果数字不存在会自动创建并初始化为0
	}

	// 输出频率统计结果
	cout << "\n数字出现频率统计结果:" << endl;
	for (auto const& pair : frequencyMap) {
		cout << pair.first << " -> " << pair.second;
		// 处理单复数形式的输出
		if (pair.second == 1) {
			cout << " time" << endl;
		}
		else {
			cout << " times" << endl;
		}
	}

	return 0;
}