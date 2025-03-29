#include <iostream>
#include <map>
#include <string>
#include <cctype> // 用于toupper()
using namespace std;

/*Task 11: Write a C++ program that stores student names and their 
corresponding letter grades using map<string, char>. The program should 
allow the user to:
• Add a new student and grade.
• Update an existing student's grade.
• Remove a student from the map.
• Display all students and their grades.
• Display all students who got ‘A’ grade*/

// 函数原型声明
void displayMenu();
void addStudent(map<string, char>& gradeBook);
void updateGrade(map<string, char>& gradeBook);
void removeStudent(map<string, char>& gradeBook);
void displayAll(const map<string, char>& gradeBook);
void displayAStudents(const map<string, char>& gradeBook);

int main11() {
    map<string, char> gradeBook; // 存储学生姓名和成绩
    int choice;

    do {
        displayMenu();
        cout << "请输入您的选择 (1-6): ";
        cin >> choice;
        cin.ignore(); // 清除输入缓冲区中的换行符

        switch (choice) {
        case 1:
            addStudent(gradeBook);
            break;
        case 2:
            updateGrade(gradeBook);
            break;
        case 3:
            removeStudent(gradeBook);
            break;
        case 4:
            displayAll(gradeBook);
            break;
        case 5:
            displayAStudents(gradeBook);
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
    cout << "1. 添加学生和成绩" << endl;
    cout << "2. 更新学生成绩" << endl;
    cout << "3. 删除学生" << endl;
    cout << "4. 显示所有学生和成绩" << endl;
    cout << "5. 显示所有A等学生" << endl;
    cout << "6. 退出" << endl;
}

// 添加新学生
void addStudent(map<string, char>& gradeBook) {
    string name;
    char grade;

    cout << "请输入学生姓名: ";
    getline(cin, name);

    if (gradeBook.find(name) != gradeBook.end()) {
        cout << "该学生已存在！" << endl;
        return;
    }

    cout << "请输入成绩 (A-F): ";
    cin >> grade;
    grade = toupper(grade); // 转换为大写

    if (grade < 'A' || grade > 'F') {
        cout << "无效的成绩！" << endl;
        return;
    }

    gradeBook[name] = grade;
    cout << "学生 " << name << " 的成绩 " << grade << " 已添加。" << endl;
}

// 更新学生成绩
void updateGrade(map<string, char>& gradeBook) {
    string name;
    char grade;

    cout << "请输入要更新的学生姓名: ";
    getline(cin, name);

    if (gradeBook.find(name) == gradeBook.end()) {
        cout << "找不到该学生！" << endl;
        return;
    }

    cout << "当前成绩: " << gradeBook[name] << endl;
    cout << "请输入新成绩 (A-F): ";
    cin >> grade;
    grade = toupper(grade);

    if (grade < 'A' || grade > 'F') {
        cout << "无效的成绩！" << endl;
        return;
    }

    gradeBook[name] = grade;
    cout << "学生 " << name << " 的成绩已更新为 " << grade << endl;
}

// 删除学生
void removeStudent(map<string, char>& gradeBook) {
    string name;

    cout << "请输入要删除的学生姓名: ";
    getline(cin, name);

    if (gradeBook.erase(name)) {
        cout << "学生 " << name << " 已删除。" << endl;
    }
    else {
        cout << "找不到该学生！" << endl;
    }
}

// 显示所有学生和成绩
void displayAll(const map<string, char>& gradeBook) {
    if (gradeBook.empty()) {
        cout << "没有学生记录！" << endl;
        return;
    }

    cout << "\n所有学生和成绩:" << endl;
    for (const auto& student : gradeBook) {
        cout << student.first << ": " << student.second << endl;
    }
}

// 显示所有A等学生
void displayAStudents(const map<string, char>& gradeBook) {
    bool found = false;

    cout << "\nA等学生名单:" << endl;
    for (const auto& student : gradeBook) {
        if (student.second == 'A') {
            cout << student.first << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "没有A等学生。" << endl;
    }
}