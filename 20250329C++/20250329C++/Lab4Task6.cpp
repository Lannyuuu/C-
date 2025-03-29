#include <iostream>
#include <vector>
#include <numeric> // 用于 accumulate() 函数
#include <algorithm> // 用于 min_element() 和 max_element()

using namespace std;

/*Task 6: Write a C++ program that takes a list of student marks from the user 
and stores them in a vector<int>. The program should allow the user to: 1) Add 
marks to the list. 2) Display all marks. 3) Remove the last entered mark. 4) 
Display the highest and lowest marks. 5) Find average marks of the class.*/

// 函数声明
void displayMenu();
void addMarks(vector<int>& marks);
void displayAllMarks(const vector<int>& marks);
void removeLastMark(vector<int>& marks);
void displayHighestAndLowest(const vector<int>& marks);
void displayAverage(const vector<int>& marks);

int main6() {
    vector<int> marks; // 存储学生成绩的向量
    int choice;

    do {
        displayMenu();
        cout << "请输入您的选择 (1-6): ";
        cin >> choice;

        switch (choice) {
        case 1:
            addMarks(marks);
            break;
        case 2:
            displayAllMarks(marks);
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
            cout << "退出程序..." << endl;
            break;
        default:
            cout << "无效的选择，请重新输入！" << endl;
        }
    } while (choice != 6);

    return 0;
}

// 显示菜单
void displayMenu() {
    cout << "\n学生成绩管理系统" << endl;
    cout << "1. 添加成绩" << endl;
    cout << "2. 显示所有成绩" << endl;
    cout << "3. 删除最后输入的成绩" << endl;
    cout << "4. 显示最高和最低成绩" << endl;
    cout << "5. 计算平均成绩" << endl;
    cout << "6. 退出" << endl;
}

// 添加成绩
void addMarks(vector<int>& marks) {
    int mark;
    cout << "请输入学生成绩 (输入-1结束): ";
    while (cin >> mark && mark != -1) {
        if (mark >= 0 && mark <= 100) {
            marks.push_back(mark);
            cout << "已添加成绩: " << mark << endl;
            cout << "继续输入或输入-1结束: ";
        }
        else {
            cout << "无效成绩！请输入0-100之间的分数: ";
        }
    }
}

// 显示所有成绩
void displayAllMarks(const vector<int>& marks) {
    if (marks.empty()) {
        cout << "当前没有成绩记录。" << endl;
        return;
    }

    cout << "所有学生成绩: ";
    for (int mark : marks) {
        cout << mark << " ";
    }
    cout << endl;
}

// 删除最后输入的成绩
void removeLastMark(vector<int>& marks) {
    if (marks.empty()) {
        cout << "没有成绩可删除！" << endl;
        return;
    }

    cout << "删除的成绩: " << marks.back() << endl;
    marks.pop_back();
}

// 显示最高和最低成绩
void displayHighestAndLowest(const vector<int>& marks) {
    if (marks.empty()) {
        cout << "当前没有成绩记录。" << endl;
        return;
    }

    auto min_it = min_element(marks.begin(), marks.end());
    auto max_it = max_element(marks.begin(), marks.end());

    cout << "最低成绩: " << *min_it << endl;
    cout << "最高成绩: " << *max_it << endl;
}

// 计算平均成绩
void displayAverage(const vector<int>& marks) {
    if (marks.empty()) {
        cout << "当前没有成绩记录。" << endl;
        return;
    }

    double sum = accumulate(marks.begin(), marks.end(), 0);
    double average = sum / marks.size();

    cout << "班级平均成绩: " << average << endl;
}