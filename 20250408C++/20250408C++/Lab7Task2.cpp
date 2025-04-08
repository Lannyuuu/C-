#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <regex>

using namespace std;

// 图书类定义
class Book {
private:
    string title;           // 书名
    string author;          // 作者
    const int totalPages;   // 总页数（常量）
    string isbn;            // ISBN 编号
    bool available;         // 可借状态：true 可借，false 已借出
    string issuedTo;        // 借阅者姓名，空表示未借出

public:
    // 构造函数
    Book(const string& t, const string& a, int pages, const string& id)
        : title(t), author(a), totalPages(pages), isbn(id), available(true), issuedTo("") {}

    // 获取 ISBN
    string getISBN() const { return isbn; }
    // 获取书名
    string getTitle() const { return title; }
    // 是否可借
    bool isAvailable() const { return available; }
    // 获取借阅者
    string getIssuedTo() const { return issuedTo; }

    // 借出操作
    void issueTo(const string& user) {
        available = false;
        issuedTo = user;
    }

    // 归还操作
    void returnBook() {
        available = true;
        issuedTo.clear();
    }

    // 显示图书详细信息
    void display() const {
        cout << "书名: " << title << endl;
        cout << "作者: " << author << endl;
        cout << "页数: " << totalPages << endl;
        cout << "ISBN: " << isbn << endl;
        if (available) {
            cout << "状态: 可借" << endl;
        }
        else {
            cout << "状态: 已借出, 借阅者: " << issuedTo << endl;
        }
        cout << "--------------------------" << endl;
    }

    // 检查是否匹配标题或 ISBN（用于搜索）
    bool matches(const string& key) const {
        return (title == key || isbn == key);
    }
};

// 全局变量：图书馆馆藏和用户借阅记录
vector<Book> library;             // 图书集合
map<string, int> borrowCount;     // 用户借阅数量记录
const int MAX_BORROW = 3;         // 每个用户最大借阅阈值

// 验证 ISBN 格式（简单：只允许数字和连字符，且非空）
bool validateISBN(const string& isbn) {
    if (isbn.empty()) return false;
    regex pattern("^[0-9-]+$");
    return regex_match(isbn, pattern);
}

// 添加图书
void addBook() {
    string title, author, isbn;
    int pages;
    cout << "输入书名: "; getline(cin, title);
    cout << "输入作者: "; getline(cin, author);
    cout << "输入总页数: "; cin >> pages; cin.ignore();
    cout << "输入 ISBN: "; getline(cin, isbn);

    // 输入验证
    if (title.empty() || author.empty() || pages <= 0 || !validateISBN(isbn)) {
        cout << "输入无效，请检查信息后重试。" << endl;
        return;
    }
    // 防止重复 ISBN
    for (const auto& book : library) {
        if (book.getISBN() == isbn) {
            cout << "该 ISBN 已存在，添加失败。" << endl;
            return;
        }
    }
    // 添加到馆藏
    library.emplace_back(title, author, pages, isbn);
    cout << "图书添加成功！" << endl;
}

// 借书
void issueBook() {
    string key, user;
    cout << "输入书名或 ISBN 进行搜索: "; getline(cin, key);
    // 查找图书
    for (auto& book : library) {
        if (book.matches(key)) {
            if (!book.isAvailable()) {
                cout << "该书已被借出，无法借阅。" << endl;
                return;
            }
            cout << "输入借阅者姓名: "; getline(cin, user);
            if (user.empty()) {
                cout << "借阅者姓名不能为空。" << endl;
                return;
            }
            // 检查用户借阅数量
            if (borrowCount[user] >= MAX_BORROW) {
                cout << "该用户已达最大借阅数 " << MAX_BORROW << " 本，无法再借。" << endl;
                return;
            }
            // 更新状态
            book.issueTo(user);
            borrowCount[user]++;
            cout << "借书成功！" << endl;
            return;
        }
    }
    cout << "未找到匹配的图书。" << endl;
}

// 还书
void returnBook() {
    string isbn;
    cout << "输入要归还的 ISBN: "; getline(cin, isbn);
    for (auto& book : library) {
        if (book.getISBN() == isbn) {
            if (book.isAvailable()) {
                cout << "该书未被借出，无需归还。" << endl;
                return;
            }
            // 更新借阅记录
            string user = book.getIssuedTo();
            book.returnBook();
            borrowCount[user]--;
            cout << "还书成功！" << endl;
            return;
        }
    }
    cout << "未找到该 ISBN 的图书。" << endl;
}

// 显示所有图书
void displayBooks() {
    if (library.empty()) {
        cout << "当前馆藏为空。" << endl;
        return;
    }
    cout << "所有图书信息：" << endl;
    for (const auto& book : library) {
        book.display();
    }
}

// 搜索图书（并显示详情）
void searchBook() {
    string key;
    cout << "输入书名或 ISBN 进行搜索: "; getline(cin, key);
    for (const auto& book : library) {
        if (book.matches(key)) {
            book.display();
            return;
        }
    }
    cout << "未找到匹配的图书。" << endl;
}

int main() {
    int choice;
    while (true) {
        cout << "\n图书管理系统菜单：" << endl;
        cout << "1. 添加图书" << endl;
        cout << "2. 借阅图书" << endl;
        cout << "3. 归还图书" << endl;
        cout << "4. 显示所有图书" << endl;
        cout << "5. 搜索图书" << endl;
        cout << "6. 退出" << endl;
        cout << "选择操作: "; cin >> choice; cin.ignore();

        switch (choice) {
        case 1: addBook(); break;
        case 2: issueBook(); break;
        case 3: returnBook(); break;
        case 4: displayBooks(); break;
        case 5: searchBook(); break;
        case 6: cout << "退出系统，欢迎下次使用！" << endl; return 0;
        default: cout << "无效选择，请重试。" << endl;
        }
    }
    return 0;
}
