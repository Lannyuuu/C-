#include <iostream>
#include <string>
#include <array> // ����C++ Array ADT
using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    array<float, 3> marks; // ʹ��array�洢������Ŀ�ĳɼ�

public:
    // ����ѧ����Ϣ
    void setInfo(string n, int roll, float m1, float m2, float m3) {
        name = n;
        rollNumber = roll;
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
    }

    // ��ȡѧ������
    string getName() { return name; }

    // ��ȡѧ��
    int getRollNumber() { return rollNumber; }

    // ��ȡָ����Ŀ�ɼ�
    float getMark(int subject) const{
        if (subject >= 0 && subject < 3)
            return marks[subject];
        return -1; // ��Ч��Ŀ����-1
    }

    // �����ܷ�
    float getTotal() const{
        return marks[0] + marks[1] + marks[2];
    }

    // ��ʾѧ����Ϣ
    void display() const{
        cout << "����: " << name << "\tѧ��: " << rollNumber
            << "\t�ɼ�: " << marks[0] << ", " << marks[1] << ", " << marks[2]
            << "\t�ܷ�: " << getTotal() << endl;
    }
};

int main_task1_2() {
    const int CLASS_SIZE = 10;
    array<Student, CLASS_SIZE> class10; // ʹ��C++ Array ADT�洢10��ѧ��

    // ����ѧ����Ϣ
    cout << "������10��ѧ������Ϣ(���� ѧ�� ���Ƴɼ�):" << endl;
    for (int i = 0; i < CLASS_SIZE; i++) {
        string name;
        int roll;
        float m1, m2, m3;

        cout << "ѧ��" << i + 1 << ": ";
        cin >> name >> roll >> m1 >> m2 >> m3;
        class10[i].setInfo(name, roll, m1, m2, m3);
    }

    // ��ʾ����ѧ����Ϣ
    cout << "\n����ѧ����Ϣ:" << endl;
    for (const auto& student : class10) {
        student.display();
    }

    // �������ƽ����
    array<float, 3> subjectAverages = { 0 };
    for (int subj = 0; subj < 3; subj++) {
        for (const auto& student : class10) {
            subjectAverages[subj] += student.getMark(subj);
        }
        subjectAverages[subj] /= CLASS_SIZE;
    }

    // ��ʾ����ƽ����
    cout << "\n����ƽ����:" << endl;
    cout << "��Ŀ1: " << subjectAverages[0] << endl;
    cout << "��Ŀ2: " << subjectAverages[1] << endl;
    cout << "��Ŀ3: " << subjectAverages[2] << endl;

    return 0;
}