#include <iostream>
#include <vector>
#include <numeric> // ���� accumulate() ����
#include <algorithm> // ���� min_element() �� max_element()

using namespace std;

/*Task 6: Write a C++ program that takes a list of student marks from the user 
and stores them in a vector<int>. The program should allow the user to: 1) Add 
marks to the list. 2) Display all marks. 3) Remove the last entered mark. 4) 
Display the highest and lowest marks. 5) Find average marks of the class.*/

// ��������
void displayMenu();
void addMarks(vector<int>& marks);
void displayAllMarks(const vector<int>& marks);
void removeLastMark(vector<int>& marks);
void displayHighestAndLowest(const vector<int>& marks);
void displayAverage(const vector<int>& marks);

int main6() {
    vector<int> marks; // �洢ѧ���ɼ�������
    int choice;

    do {
        displayMenu();
        cout << "����������ѡ�� (1-6): ";
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
            cout << "�˳�����..." << endl;
            break;
        default:
            cout << "��Ч��ѡ�����������룡" << endl;
        }
    } while (choice != 6);

    return 0;
}

// ��ʾ�˵�
void displayMenu() {
    cout << "\nѧ���ɼ�����ϵͳ" << endl;
    cout << "1. ��ӳɼ�" << endl;
    cout << "2. ��ʾ���гɼ�" << endl;
    cout << "3. ɾ���������ĳɼ�" << endl;
    cout << "4. ��ʾ��ߺ���ͳɼ�" << endl;
    cout << "5. ����ƽ���ɼ�" << endl;
    cout << "6. �˳�" << endl;
}

// ��ӳɼ�
void addMarks(vector<int>& marks) {
    int mark;
    cout << "������ѧ���ɼ� (����-1����): ";
    while (cin >> mark && mark != -1) {
        if (mark >= 0 && mark <= 100) {
            marks.push_back(mark);
            cout << "����ӳɼ�: " << mark << endl;
            cout << "�������������-1����: ";
        }
        else {
            cout << "��Ч�ɼ���������0-100֮��ķ���: ";
        }
    }
}

// ��ʾ���гɼ�
void displayAllMarks(const vector<int>& marks) {
    if (marks.empty()) {
        cout << "��ǰû�гɼ���¼��" << endl;
        return;
    }

    cout << "����ѧ���ɼ�: ";
    for (int mark : marks) {
        cout << mark << " ";
    }
    cout << endl;
}

// ɾ���������ĳɼ�
void removeLastMark(vector<int>& marks) {
    if (marks.empty()) {
        cout << "û�гɼ���ɾ����" << endl;
        return;
    }

    cout << "ɾ���ĳɼ�: " << marks.back() << endl;
    marks.pop_back();
}

// ��ʾ��ߺ���ͳɼ�
void displayHighestAndLowest(const vector<int>& marks) {
    if (marks.empty()) {
        cout << "��ǰû�гɼ���¼��" << endl;
        return;
    }

    auto min_it = min_element(marks.begin(), marks.end());
    auto max_it = max_element(marks.begin(), marks.end());

    cout << "��ͳɼ�: " << *min_it << endl;
    cout << "��߳ɼ�: " << *max_it << endl;
}

// ����ƽ���ɼ�
void displayAverage(const vector<int>& marks) {
    if (marks.empty()) {
        cout << "��ǰû�гɼ���¼��" << endl;
        return;
    }

    double sum = accumulate(marks.begin(), marks.end(), 0);
    double average = sum / marks.size();

    cout << "�༶ƽ���ɼ�: " << average << endl;
}