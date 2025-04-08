#include <iostream>
#include <string>
#include <array> // 包含C++ Array ADT
using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    array<float, 3> marks; // 使用array存储三个科目的成绩

public:
    // 设置学生信息
    void setInfo(string n, int roll, float m1, float m2, float m3) {
        name = n;
        rollNumber = roll;
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
    }

    // 获取学生姓名
    string getName() { return name; }

    // 获取学号
    int getRollNumber() { return rollNumber; }

    // 获取指定科目成绩
    float getMark(int subject) const{
        if (subject >= 0 && subject < 3)
            return marks[subject];
        return -1; // 无效科目返回-1
    }

    // 计算总分
    float getTotal() const{
        return marks[0] + marks[1] + marks[2];
    }

    // 显示学生信息
    void display() const{
        cout << "姓名: " << name << "\t学号: " << rollNumber
            << "\t成绩: " << marks[0] << ", " << marks[1] << ", " << marks[2]
            << "\t总分: " << getTotal() << endl;
    }
};

int main_task1_2() {
    const int CLASS_SIZE = 10;
    array<Student, CLASS_SIZE> class10; // 使用C++ Array ADT存储10个学生

    // 输入学生信息
    cout << "请输入10名学生的信息(姓名 学号 三科成绩):" << endl;
    for (int i = 0; i < CLASS_SIZE; i++) {
        string name;
        int roll;
        float m1, m2, m3;

        cout << "学生" << i + 1 << ": ";
        cin >> name >> roll >> m1 >> m2 >> m3;
        class10[i].setInfo(name, roll, m1, m2, m3);
    }

    // 显示所有学生信息
    cout << "\n所有学生信息:" << endl;
    for (const auto& student : class10) {
        student.display();
    }

    // 计算各科平均分
    array<float, 3> subjectAverages = { 0 };
    for (int subj = 0; subj < 3; subj++) {
        for (const auto& student : class10) {
            subjectAverages[subj] += student.getMark(subj);
        }
        subjectAverages[subj] /= CLASS_SIZE;
    }

    // 显示各科平均分
    cout << "\n各科平均分:" << endl;
    cout << "科目1: " << subjectAverages[0] << endl;
    cout << "科目2: " << subjectAverages[1] << endl;
    cout << "科目3: " << subjectAverages[2] << endl;

    return 0;
}