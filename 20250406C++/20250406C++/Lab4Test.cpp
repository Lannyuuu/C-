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
	//��������
	const int SIZE = 100;
	int randomNumberArray[SIZE];
	//��������� �浽��������
	srand(time(0));
	for (int i = 0; i < SIZE; i++) {
		randomNumberArray[i] = rand() % 100;
	}
	//����Ƶ�ʣ��ŵ�Ƶ����������
	int frequency[100] = { 0 };
	for (int i = 0; i < SIZE; i++) {
		frequency[randomNumberArray[i]]++;
	}
	//�ҵ������������ֺ�����Ƶ��
	int maxFrequency = 0;
	int mostFrequencyNumber = 0;
	for (int i = 0; i < 100; i++) {
		if (frequency[i] > maxFrequency) {
			maxFrequency = frequency[i];
			mostFrequencyNumber = i;
		}
	}
	//���
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

	//������newlen����
	for (int i = oldlen; i >= p; i--) {
		oldArray[i + newlen] = oldArray[i];
	}
	//����newArray
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
#include <numeric> //���ۻ���accumulate()
#include <algorithm> //����vector�������Сֵ

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
	cout << endl; //����
}
void removeLastMark(vector<int>& marks) {
	if (marks.empty()) {
		cout << "No mark in the system" << endl;
		return;
	}
	cout << "The mark will remove is:" << marks.back() << endl; //ֻ����ʾ����ɾ����
	marks.pop_back();//ֱ��ɾ��
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
		//��ʾ�˵�
		displayMenu();
		//����
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
	vector<int> numbers;  // �洢�û����������
	map<int, int> frequencyMap;  // �洢���ּ������Ƶ��
	int n, num;

	// ��ȡ�û�Ҫ�������������
	cout << "���������ֵĸ���(N): ";
	cin >> n;

	// ��ȡ�û����������
	cout << "������" << n << "���������ÿո�ָ�: ";
	for (int i = 0; i < n; ++i) {
		cin >> num;
		numbers.push_back(num);  // ��������ӵ�������
	}

	// ͳ��ÿ�����ֵĳ���Ƶ��
	for (int num : numbers) {
		frequencyMap[num]++;  // ������ֲ����ڻ��Զ���������ʼ��Ϊ0
	}

	// ���Ƶ��ͳ�ƽ��
	cout << "\n���ֳ���Ƶ��ͳ�ƽ��:" << endl;
	for (auto const& pair : frequencyMap) {
		cout << pair.first << " -> " << pair.second;
		// ����������ʽ�����
		if (pair.second == 1) {
			cout << " time" << endl;
		}
		else {
			cout << " times" << endl;
		}
	}

	return 0;
}