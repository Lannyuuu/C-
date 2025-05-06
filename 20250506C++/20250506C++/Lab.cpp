#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>
#include <algorithm>

using namespace std;

// 图书馆资源的基类
class LibraryResource {
protected:
    string resourceID;
    string title;
    string authors;
    string publisher;
    bool isAvailable;
    string borrowerName;
    string dueDate;

public:
    // 构造函数
    LibraryResource(string id, string t, string a, string p)
        : resourceID(id), title(t), authors(a), publisher(p), isAvailable(true) {}

    // 虚析构函数，确保派生类资源正确释放
    virtual ~LibraryResource() {}

    // 借出资源
    void borrowResource(string borrower, string due) {
        if (isAvailable) {
            isAvailable = false;
            borrowerName = borrower;
            dueDate = due;
            cout << title << " 已被 " << borrower << " 借出，归还日期为 " << dueDate << endl;
        }
        else {
            cout << "错误：" << title << " 已被 " << borrowerName << " 借出" << endl;
        }
    }

    // 归还资源并计算逾期罚金
    int returnResource(string returnDate) {
        if (!isAvailable) {
            isAvailable = true;

            // 计算逾期天数（这里只是简单的字符串比较）
            int penalty = 0;
            if (returnDate > dueDate) {
                // 简单罚金计算：每天£2
                // 实际应用中应使用更准确的日期差值
                penalty = 2 * (stoi(returnDate.substr(0, 2)) - stoi(dueDate.substr(0, 2)));
                cout << "逾期归还！罚金：£" << penalty << endl;
            }

            cout << title << " 已由 " << borrowerName << " 归还" << endl;
            borrowerName = "";
            dueDate = "";
            return penalty;
        }
        else {
            cout << "错误：" << title << " 当前未被借出" << endl;
            return 0;
        }
    }

    // 显示资源信息（虚函数）
    virtual void displayInfo() const {
        cout << "资源ID: " << resourceID << endl;
        cout << "标题: " << title << endl;
        cout << "作者: " << authors << endl;
        cout << "出版社: " << publisher << endl;
        cout << "状态: " << (isAvailable ? "可借阅" : "已被 " + borrowerName + " 借出，归还日期为 " + dueDate) << endl;
    }

    // 获取资源类型（由派生类重写）
    virtual string getType() const = 0;

    // Getter 函数
    string getResourceID() const { return resourceID; }
    string getTitle() const { return title; }
    string getAuthors() const { return authors; }
    bool getAvailability() const { return isAvailable; }

    // 搜索辅助函数（可被重写）
    virtual bool matchesGenre(const string& genre) const { return false; }
    virtual bool matchesIssueNumber(int issue) const { return false; }
    virtual bool matchesPublicationDate(const string& date) const { return false; }
    virtual bool matchesFormat(const string& format) const { return false; }
};

// 图书类（派生类）
class Book : public LibraryResource {
private:
    string ISBN;
    string genre;

public:
    Book(string id, string t, string a, string p, string isbn, string g)
        : LibraryResource(id, t, a, p), ISBN(isbn), genre(g) {}

    void displayInfo() const override {
        LibraryResource::displayInfo();
        cout << "类型: 图书" << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "类别: " << genre << endl;
    }

    string getType() const override { return "Book"; }

    // 图书类别搜索
    bool matchesGenre(const string& g) const override {
        return genre == g;
    }
};

// 期刊类（派生类）
class Journal : public LibraryResource {
private:
    int issueNumber;
    string publicationDate;

public:
    Journal(string id, string t, string a, string p, int issue, string pubDate)
        : LibraryResource(id, t, a, p), issueNumber(issue), publicationDate(pubDate) {}

    void displayInfo() const override {
        LibraryResource::displayInfo();
        cout << "类型: 期刊" << endl;
        cout << "期号: " << issueNumber << endl;
        cout << "出版日期: " << publicationDate << endl;
    }

    string getType() const override { return "Journal"; }

    // 期刊搜索
    bool matchesIssueNumber(int issue) const override {
        return issueNumber == issue;
    }

    bool matchesPublicationDate(const string& date) const override {
        return publicationDate == date;
    }
};

// 多媒体类（派生类）
class Multimedia : public LibraryResource {
private:
    string format;
    double duration; // 单位：分钟

public:
    Multimedia(string id, string t, string a, string p, string f, double dur)
        : LibraryResource(id, t, a, p), format(f), duration(dur) {}

    void displayInfo() const override {
        LibraryResource::displayInfo();
        cout << "类型: 多媒体资源" << endl;
        cout << "格式: " << format << endl;
        cout << "时长: " << duration << " 分钟" << endl;
    }

    string getType() const override { return "Multimedia"; }

    // 多媒体格式搜索
    bool matchesFormat(const string& f) const override {
        return format == f;
    }
};

// 图书馆管理系统
class LibrarySystem {
private:
    vector<LibraryResource*> resources;

    // 检查资源ID是否已存在
    bool resourceIDExists(const string& id) const {
        for (const auto& res : resources) {
            if (res->getResourceID() == id) {
                return true;
            }
        }
        return false;
    }

public:
    // 析构函数，释放所有资源
    ~LibrarySystem() {
        for (auto res : resources) {
            delete res;
        }
    }

    // 添加新资源
    void addResource() {
        string type, id, title, authors, publisher;

        cout << "请输入资源类型 (Book/Journal/Multimedia): ";
        cin >> type;
        transform(type.begin(), type.end(), type.begin(), ::tolower);

        cout << "请输入资源ID: ";
        cin >> id;

        if (resourceIDExists(id)) {
            cout << "错误：资源ID已存在" << endl;
            return;
        }

        cin.ignore(); // 清除输入缓冲
        cout << "请输入标题: ";
        getline(cin, title);

        cout << "请输入作者（多个作者用逗号分隔）: ";
        getline(cin, authors);

        cout << "请输入出版社: ";
        getline(cin, publisher);

        if (type == "book") {
            string isbn, genre;
            cout << "请输入ISBN: ";
            getline(cin, isbn);
            cout << "请输入类别: ";
            getline(cin, genre);
            resources.push_back(new Book(id, title, authors, publisher, isbn, genre));
        }
        else if (type == "journal") {
            int issue;
            string pubDate;
            cout << "请输入期号: ";
            cin >> issue;
            cin.ignore();
            cout << "请输入出版日期 (DD-MM-YYYY): ";
            getline(cin, pubDate);
            resources.push_back(new Journal(id, title, authors, publisher, issue, pubDate));
        }
        else if (type == "multimedia") {
            string format;
            double duration;
            cout << "请输入格式 (DVD/Blu-ray/Streaming): ";
            getline(cin, format);
            cout << "请输入时长（分钟）: ";
            cin >> duration;
            resources.push_back(new Multimedia(id, title, authors, publisher, format, duration));
        }
        else {
            cout << "无效的资源类型" << endl;
            return;
        }

        cout << "资源添加成功" << endl;
    }

    // 借出资源
    void borrowResource() {
        string id, borrower, dueDate;

        cout << "请输入要借阅的资源ID: ";
        cin >> id;

        auto it = find_if(resources.begin(), resources.end(),
            [&id](LibraryResource* res) { return res->getResourceID() == id; });

        if (it == resources.end()) {
            cout << "错误：未找到该资源" << endl;
            return;
        }

        if (!(*it)->getAvailability()) {
            cout << "错误：该资源已被借出" << endl;
            return;
        }

        cin.ignore();
        cout << "请输入借阅者姓名: ";
        getline(cin, borrower);

        cout << "请输入归还日期 (DD-MM-YYYY): ";
        getline(cin, dueDate);

        (*it)->borrowResource(borrower, dueDate);
    }

    // 归还资源
    void returnResource() {
        string id, returnDate;
        int totalPenalty = 0;

        cout << "请输入要归还的资源ID: ";
        cin >> id;

        auto it = find_if(resources.begin(), resources.end(),
            [&id](LibraryResource* res) { return res->getResourceID() == id; });

        if (it == resources.end()) {
            cout << "错误：未找到该资源" << endl;
            return;
        }

        cin.ignore();
        cout << "请输入归还日期 (DD-MM-YYYY): ";
        getline(cin, returnDate);

        totalPenalty += (*it)->returnResource(returnDate);

        if (totalPenalty > 0) {
            cout << "总计应缴罚金：£" << totalPenalty << endl;
        }
    }

    // 显示所有可借资源
    void displayAvailableResources() const {
        cout << "\n=== 可借阅资源列表 ===" << endl;
        bool found = false;

        for (const auto& res : resources) {
            if (res->getAvailability()) {
                res->displayInfo();
                cout << "---------------------" << endl;
                found = true;
            }
        }

        if (!found) {
            cout << "当前没有可借资源" << endl;
        }
    }

    // 资源搜索功能
    void searchResources() const {
        int choice;
        cout << "\n搜索方式：\n1. 资源ID\n2. 标题\n3. 作者\n4. 图书类别\n"
            << "5. 期刊期号\n6. 出版日期\n7. 多媒体格式\n请输入选项: ";
        cin >> choice;

        string searchTerm;
        int searchInt;
        bool found = false;

        cin.ignore();
        switch (choice) {
        case 1:
            cout << "请输入资源ID: ";
            getline(cin, searchTerm);
            for (const auto& res : resources) {
                if (res->getResourceID() == searchTerm) {
                    res->displayInfo();
                    found = true;
                }
            }
            break;
        case 2:
            cout << "请输入标题: ";
            getline(cin, searchTerm);
            for (const auto& res : resources) {
                if (res->getTitle().find(searchTerm) != string::npos) {
                    res->displayInfo();
                    found = true;
                }
            }
            break;
        case 3:
            cout << "请输入作者名: ";
            getline(cin, searchTerm);
            for (const auto& res : resources) {
                if (res->getAuthors().find(searchTerm) != string::npos) {
                    res->displayInfo();
                    found = true;
                }
            }
            break;
        case 4:
            cout << "请输入类别: ";
            getline(cin, searchTerm);
            for (const auto& res : resources) {
                if (res->matchesGenre(searchTerm)) {
                    res->displayInfo();
                    found = true;
                }
            }
            break;
        case 5:
            cout << "请输入期号: ";
            cin >> searchInt;
            for (const auto& res : resources) {
                if (res->matchesIssueNumber(searchInt)) {
                    res->displayInfo();
                    found = true;
                }
            }
            break;
        case 6:
            cout << "请输入出版日期: ";
            getline(cin, searchTerm);
            for (const auto& res : resources) {
                if (res->matchesPublicationDate(searchTerm)) {
                    res->displayInfo();
                    found = true;
                }
            }
            break;
        case 7:
            cout << "请输入格式: ";
            getline(cin, searchTerm);
            for (const auto& res : resources) {
                if (res->matchesFormat(searchTerm)) {
                    res->displayInfo();
                    found = true;
                }
            }
            break;
        default:
            cout << "无效选项" << endl;
            return;
        }

        if (!found) {
            cout << "未找到匹配资源" << endl;
        }
    }

    // 显示所有资源（管理员查看）
    void displayAllResources() const {
        cout << "\n=== 图书馆资源总览 ===" << endl;
        for (const auto& res : resources) {
            res->displayInfo();
            cout << "资源类型: " << res->getType() << endl;
            cout << "---------------------" << endl;
        }

        if (resources.empty()) {
            cout << "图书馆当前无资源" << endl;
        }
    }
};

// 主菜单函数
void displayMenu() {
    cout << "\n===== 图书馆管理系统 =====" << endl;
    cout << "1. 添加新资源" << endl;
    cout << "2. 借出资源" << endl;
    cout << "3. 归还资源" << endl;
    cout << "4. 查看可借资源" << endl;
    cout << "5. 搜索资源" << endl;
    cout << "6. 查看所有资源（管理员）" << endl;
    cout << "7. 退出系统" << endl;
    cout << "请输入操作编号: ";
}

int main() {
    LibrarySystem library;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            library.addResource();
            break;
        case 2:
            library.borrowResource();
            break;
        case 3:
            library.returnResource();
            break;
        case 4:
            library.displayAvailableResources();
            break;
        case 5:
            library.searchResources();
            break;
        case 6:
            library.displayAllResources();
            break;
        case 7:
            cout << "系统退出中..." << endl;
            break;
        default:
            cout << "无效选择，请重试。" << endl;
        }
    } while (choice != 7);

    return 0;
}


//#include <iostream>
//using namespace std;
//class LibraryResource  {
//private:
//	string resourceID;
//	string title;
//	string authors;
//	string publisher;
//	//这三个参数要先初始化，放在构造含函数的函数体里面
//	bool isAvailable;
//	string borrowerName;
//	string dueDate; //DD-MM-YYYY
//public:
//	//constructor
//	LibraryResource(const string& rID, const string& t, const string& a, const string& p)
//		: resourceID(rID), title(t),authors(a), publisher(p){
//		isAvailable = true;
//		borrowerName = "";
//		dueDate = "";
//	}
//
//	//destructor
//	~LibraryResource() {}
//
//	void borrowResource(const string& borrower, const string& due) {
//		if (isAvailable) {
//			isAvailable = false;
//			borrowerName = borrower;
//			dueDate = due;
//			cout << title << " have been borrowed by " << borrower << " and the due date is " << dueDate << endl;
//		}
//		else {
//			cout << "False: " << title << "has been borrowed by " << borrowerName << " and due date is " << dueDate << endl;
//		}
//	}
//	void returnResource() {
//		if (!isAvailable) {
//			cout << title << " has been returned by " << borrowerName << endl;
//			isAvailable = true;
//			borrowerName = "";
//			dueDate = "";
//		}
//		else {
//			cout << "False: " << title << " is available" << endl;
//		}
//	}
//	virtual void displayInfo() {
//		cout << "resourceID: " << resourceID << endl;
//		cout << "title: " << title << endl;
//		cout << "authors: " << authors << endl;
//		cout << "publisher: " << publisher << endl;
//		cout << "isAvailable: " << (isAvailable ? " is available" : " has been borrowed") << endl;
//		if (!isAvailable) {
//			cout << "borrowerName: " << borrowerName << endl;
//			cout << "dueDate: " << dueDate << endl;
//		}
//	}
//	virtual string getType() const = 0;
//
//	string getResourceID() const { return resourceID; }
//	string getTitle() const { return title; }
//	string getAuthors() const { return authors; }
//	string getPublisher() const { return publisher; }
//	bool getIsAvailability() const { return isAvailable; }
//	string getBorrowerName() const { return borrowerName; }
//	string getDurDate() const { return dueDate; }
//
//	void setResourceID(const string& nResourceID) { resourceID = nResourceID; }
//	void setTitle(const string& nTitle) { title = nTitle; }
//	void setAuthors(const string& nAuthors) { authors = nAuthors; }
//	void setPublisher(const string& nPublisher) { publisher = nPublisher; }
//	void setIsAvailability(bool nIsAvailability) { isAvailable = nIsAvailability; }
//	void setBorrowerName(const string& nBorrowerName) { borrowerName = nBorrowerName; }
//	void setDurDate(const string& nDurDate) { dueDate = nDurDate; }
//
//	// 搜索辅助函数（可被重写）
//	virtual bool matchesGenre(const string& genre) const { return false; }
//	virtual bool matchesIssueNumber(int issue) const { return false; }
//	virtual bool matchesPublicationDate(const string& date) const { return false; }
//	virtual bool matchesFormat(const string& format) const { return false; }
//}
//// 图书类（派生类）
//class Book : public LibraryResource {
//private:
//	string ISBN;
//	string genre;
//
//public:
//	Book(string id, string t, string a, string p, string isbn, string g)
//		: LibraryResource(id, t, a, p), ISBN(isbn), genre(g) {}
//
//	void displayInfo() const override {
//		LibraryResource::displayInfo();
//		cout << "类型: 图书" << endl;
//		cout << "ISBN: " << ISBN << endl;
//		cout << "类别: " << genre << endl;
//	}
//
//	string getType() const override { return "Book"; }
//
//	// 图书类别搜索
//	bool matchesGenre(const string& g) const override {
//		return genre == g;
//	}
//};
//int main() {
//
//	return 0;
//}