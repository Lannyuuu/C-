#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <regex>

using namespace std;

// ͼ���ඨ��
class Book {
private:
    string title;           // ����
    string author;          // ����
    const int totalPages;   // ��ҳ����������
    string isbn;            // ISBN ���
    bool available;         // �ɽ�״̬��true �ɽ裬false �ѽ��
    string issuedTo;        // �������������ձ�ʾδ���

public:
    // ���캯��
    Book(const string& t, const string& a, int pages, const string& id)
        : title(t), author(a), totalPages(pages), isbn(id), available(true), issuedTo("") {}

    // ��ȡ ISBN
    string getISBN() const { return isbn; }
    // ��ȡ����
    string getTitle() const { return title; }
    // �Ƿ�ɽ�
    bool isAvailable() const { return available; }
    // ��ȡ������
    string getIssuedTo() const { return issuedTo; }

    // �������
    void issueTo(const string& user) {
        available = false;
        issuedTo = user;
    }

    // �黹����
    void returnBook() {
        available = true;
        issuedTo.clear();
    }

    // ��ʾͼ����ϸ��Ϣ
    void display() const {
        cout << "����: " << title << endl;
        cout << "����: " << author << endl;
        cout << "ҳ��: " << totalPages << endl;
        cout << "ISBN: " << isbn << endl;
        if (available) {
            cout << "״̬: �ɽ�" << endl;
        }
        else {
            cout << "״̬: �ѽ��, ������: " << issuedTo << endl;
        }
        cout << "--------------------------" << endl;
    }

    // ����Ƿ�ƥ������ ISBN������������
    bool matches(const string& key) const {
        return (title == key || isbn == key);
    }
};

// ȫ�ֱ�����ͼ��ݹݲغ��û����ļ�¼
vector<Book> library;             // ͼ�鼯��
map<string, int> borrowCount;     // �û�����������¼
const int MAX_BORROW = 3;         // ÿ���û���������ֵ

// ��֤ ISBN ��ʽ���򵥣�ֻ�������ֺ����ַ����ҷǿգ�
bool validateISBN(const string& isbn) {
    if (isbn.empty()) return false;
    regex pattern("^[0-9-]+$");
    return regex_match(isbn, pattern);
}

// ���ͼ��
void addBook() {
    string title, author, isbn;
    int pages;
    cout << "��������: "; getline(cin, title);
    cout << "��������: "; getline(cin, author);
    cout << "������ҳ��: "; cin >> pages; cin.ignore();
    cout << "���� ISBN: "; getline(cin, isbn);

    // ������֤
    if (title.empty() || author.empty() || pages <= 0 || !validateISBN(isbn)) {
        cout << "������Ч��������Ϣ�����ԡ�" << endl;
        return;
    }
    // ��ֹ�ظ� ISBN
    for (const auto& book : library) {
        if (book.getISBN() == isbn) {
            cout << "�� ISBN �Ѵ��ڣ����ʧ�ܡ�" << endl;
            return;
        }
    }
    // ��ӵ��ݲ�
    library.emplace_back(title, author, pages, isbn);
    cout << "ͼ����ӳɹ���" << endl;
}

// ����
void issueBook() {
    string key, user;
    cout << "���������� ISBN ��������: "; getline(cin, key);
    // ����ͼ��
    for (auto& book : library) {
        if (book.matches(key)) {
            if (!book.isAvailable()) {
                cout << "�����ѱ�������޷����ġ�" << endl;
                return;
            }
            cout << "�������������: "; getline(cin, user);
            if (user.empty()) {
                cout << "��������������Ϊ�ա�" << endl;
                return;
            }
            // ����û���������
            if (borrowCount[user] >= MAX_BORROW) {
                cout << "���û��Ѵ��������� " << MAX_BORROW << " �����޷��ٽ衣" << endl;
                return;
            }
            // ����״̬
            book.issueTo(user);
            borrowCount[user]++;
            cout << "����ɹ���" << endl;
            return;
        }
    }
    cout << "δ�ҵ�ƥ���ͼ�顣" << endl;
}

// ����
void returnBook() {
    string isbn;
    cout << "����Ҫ�黹�� ISBN: "; getline(cin, isbn);
    for (auto& book : library) {
        if (book.getISBN() == isbn) {
            if (book.isAvailable()) {
                cout << "����δ�����������黹��" << endl;
                return;
            }
            // ���½��ļ�¼
            string user = book.getIssuedTo();
            book.returnBook();
            borrowCount[user]--;
            cout << "����ɹ���" << endl;
            return;
        }
    }
    cout << "δ�ҵ��� ISBN ��ͼ�顣" << endl;
}

// ��ʾ����ͼ��
void displayBooks() {
    if (library.empty()) {
        cout << "��ǰ�ݲ�Ϊ�ա�" << endl;
        return;
    }
    cout << "����ͼ����Ϣ��" << endl;
    for (const auto& book : library) {
        book.display();
    }
}

// ����ͼ�飨����ʾ���飩
void searchBook() {
    string key;
    cout << "���������� ISBN ��������: "; getline(cin, key);
    for (const auto& book : library) {
        if (book.matches(key)) {
            book.display();
            return;
        }
    }
    cout << "δ�ҵ�ƥ���ͼ�顣" << endl;
}

int main() {
    int choice;
    while (true) {
        cout << "\nͼ�����ϵͳ�˵���" << endl;
        cout << "1. ���ͼ��" << endl;
        cout << "2. ����ͼ��" << endl;
        cout << "3. �黹ͼ��" << endl;
        cout << "4. ��ʾ����ͼ��" << endl;
        cout << "5. ����ͼ��" << endl;
        cout << "6. �˳�" << endl;
        cout << "ѡ�����: "; cin >> choice; cin.ignore();

        switch (choice) {
        case 1: addBook(); break;
        case 2: issueBook(); break;
        case 3: returnBook(); break;
        case 4: displayBooks(); break;
        case 5: searchBook(); break;
        case 6: cout << "�˳�ϵͳ����ӭ�´�ʹ�ã�" << endl; return 0;
        default: cout << "��Чѡ�������ԡ�" << endl;
        }
    }
    return 0;
}
