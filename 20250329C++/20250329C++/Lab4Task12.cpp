#include <iostream>
#include <map>
#include <algorithm> // 用于max_element
#include <limits>    // 用于输入验证

using namespace std;

/*Task 12: Write a C++ program that maintains an employee salary database 
using map<int, double>, where the key is the employee ID, and the value is 
their salary. The program should allow the user to:
• Add new employees with salaries.
• Update an employee’s salary.
• Delete an employee record.
• Find the highest-paid employee.*/

// 函数原型声明
void displayMenu();
void addEmployee(map<int, double>& salaryDB);
void updateSalary(map<int, double>& salaryDB);
void deleteEmployee(map<int, double>& salaryDB);
void findHighestPaid(const map<int, double>& salaryDB);
void displayAll(const map<int, double>& salaryDB);

int main12() {
    map<int, double> salaryDB; // 员工ID和薪资的映射
    int choice;

    do {
        displayMenu();
        cout << "请输入您的选择 (1-6): ";

        // 输入验证
        while (!(cin >> choice) ){
            cin.clear(); // 清除错误状态
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 忽略错误输入
            cout << "无效输入，请重新输入选择 (1-6): ";
        }
        cin.ignore(); // 清除输入缓冲区中的换行符

        switch (choice) {
        case 1:
            addEmployee(salaryDB);
            break;
        case 2:
            updateSalary(salaryDB);
            break;
        case 3:
            deleteEmployee(salaryDB);
            break;
        case 4:
            findHighestPaid(salaryDB);
            break;
        case 5:
            displayAll(salaryDB);
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
    cout << "\n员工薪资管理系统" << endl;
    cout << "1. 添加新员工" << endl;
    cout << "2. 更新员工薪资" << endl;
    cout << "3. 删除员工记录" << endl;
    cout << "4. 查找最高薪资员工" << endl;
    cout << "5. 显示所有员工记录" << endl;
    cout << "6. 退出" << endl;
}

// 添加新员工
void addEmployee(map<int, double>& salaryDB) {
    int id;
    double salary;

    cout << "请输入员工ID: ";
    while (!(cin >> id) || id <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "无效ID，请输入正整数: ";
    }

    if (salaryDB.find(id) != salaryDB.end()) {
        cout << "该员工ID已存在！" << endl;
        return;
    }

    cout << "请输入员工薪资: ";
    while (!(cin >> salary) || salary < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "无效薪资，请输入非负数: ";
    }

    salaryDB[id] = salary;
    cout << "员工 " << id << " 已添加，薪资为 " << salary << endl;
}

// 更新员工薪资
void updateSalary(map<int, double>& salaryDB) {
    int id;
    double newSalary;

    cout << "请输入要更新的员工ID: ";
    while (!(cin >> id)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "无效ID，请重新输入: ";
    }

    if (salaryDB.find(id) == salaryDB.end()) {
        cout << "找不到该员工！" << endl;
        return;
    }

    cout << "当前薪资: " << salaryDB[id] << endl;
    cout << "请输入新薪资: ";
    while (!(cin >> newSalary) || newSalary < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "无效薪资，请输入非负数: ";
    }

    salaryDB[id] = newSalary;
    cout << "员工 " << id << " 的薪资已更新为 " << newSalary << endl;
}

// 删除员工记录
void deleteEmployee(map<int, double>& salaryDB) {
    int id;

    cout << "请输入要删除的员工ID: ";
    while (!(cin >> id)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "无效ID，请重新输入: ";
    }

    if (salaryDB.erase(id)) {
        cout << "员工 " << id << " 的记录已删除。" << endl;
    }
    else {
        cout << "找不到该员工！" << endl;
    }
}

// 查找最高薪资员工
void findHighestPaid(const map<int, double>& salaryDB) {
    if (salaryDB.empty()) {
        cout << "数据库中没有员工记录！" << endl;
        return;
    }

    auto highest = max_element(salaryDB.begin(), salaryDB.end(),
        [](const pair<int, double>& a, const pair<int, double>& b) {
            return a.second < b.second;
        });

    cout << "最高薪资员工: " << endl;
    cout << "ID: " << highest->first << ", 薪资: " << highest->second << endl;
}

// 显示所有员工记录
void displayAll(const map<int, double>& salaryDB) {
    if (salaryDB.empty()) {
        cout << "数据库中没有员工记录！" << endl;
        return;
    }

    cout << "\n所有员工记录:" << endl;
    cout << "ID\t薪资" << endl;
    cout << "----------------" << endl;
    for (const auto& employee : salaryDB) {
        cout << employee.first << "\t" << employee.second << endl;
    }
}