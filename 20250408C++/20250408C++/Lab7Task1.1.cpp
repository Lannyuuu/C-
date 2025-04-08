#include <iostream>
#include <string>
using namespace std;
//Task1.1: D Array
class Student {
private:
    string name;
    int rollNumber;
    float marks[3]; // �洢������Ŀ�ĳɼ�

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
    float getMark(int subject) {
        if (subject >= 0 && subject < 3)
            return marks[subject];
        return -1; // ��Ч��Ŀ����-1
    }

    // �����ܷ�
    float getTotal() {
        return marks[0] + marks[1] + marks[2];
    }

    // ��ʾѧ����Ϣ
    void display() {
        cout << "����: " << name << "\tѧ��: " << rollNumber
            << "\t�ɼ�: " << marks[0] << ", " << marks[1] << ", " << marks[2]
            << "\t�ܷ�: " << getTotal() << endl;
    }
};

int main_task1_1() {
    const int CLASS_SIZE = 10;
    Student class10[CLASS_SIZE]; // ʹ�ô�ͳ1D����洢10��ѧ��

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
    for (int i = 0; i < CLASS_SIZE; i++) {
        class10[i].display();
    }

    // �������ƽ����
    float subjectAverages[3] = { 0 };
    for (int subj = 0; subj < 3; subj++) {
        for (int i = 0; i < CLASS_SIZE; i++) {
            subjectAverages[subj] += class10[i].getMark(subj);
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