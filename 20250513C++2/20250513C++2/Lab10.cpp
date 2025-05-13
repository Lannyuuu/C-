#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <exception>

using namespace std;

// 抽象基类：Appliance
class Appliance {
protected:
    string deviceID;    // 设备唯一标识
    string brand;       // 品牌
    bool powerStatus;   // 电源状态：开(true)/关(false)

public:
    // 构造函数
    Appliance(const string& id, const string& br)
        : deviceID(id), brand(br), powerStatus(false) {}

    virtual ~Appliance() {}

    // 打开电源
    void turnOn() {
        powerStatus = true;
        cout << "[" << deviceID << "] 已打开" << endl;
    }

    // 关闭电源
    void turnOff() {
        powerStatus = false;
        cout << "[" << deviceID << "] 已关闭" << endl;
    }

    // 显示设备状态
    virtual void showStatus() const {
        cout << "设备ID: " << deviceID
            << " | 品牌: " << brand
            << " | 电源: " << (powerStatus ? "开" : "关");
    }

    // 纯虚函数：控制设备行为
    virtual void control() = 0;

    // 获取deviceID
    string getID() const { return deviceID; }

    // 获取brand
    string getBrand() const { return brand; }
};

// 派生类：Light（灯光）
class Light : public Appliance {
private:
    int brightnessLevel; // 亮度 0-100
    string color;        // 灯光颜色

public:
    Light(const string& id, const string& br)
        : Appliance(id, br), brightnessLevel(50), color("白光") {}

    // 重载显示状态
    void showStatus() const override {
        Appliance::showStatus();
        cout << " | 类型: 灯光"
            << " | 亮度: " << brightnessLevel
            << "% | 颜色: " << color << endl;
    }

    // 实现控制函数
    void control() override {
        if (!powerStatus) {
            cout << "请先打开灯光设备[" << deviceID << "]的电源。" << endl;
            return;
        }
        try {
            cout << "输入亮度 (0-100): ";
            int b;
            cin >> b;
            if (b < 0 || b > 100) throw invalid_argument("亮度值超出范围");
            brightnessLevel = b;

            cout << "输入颜色 (如: 白光, 暖白, 冷光): ";
            cin >> color;

            cout << "灯光[" << deviceID << "]已设置 -> 亮度: "
                << brightnessLevel << "%, 颜色: " << color << endl;
        }
        catch (exception& e) {
            cout << "控制灯光时出错: " << e.what() << endl;
        }
    }
};

// 派生类：AirConditioner（空调）
class AirConditioner : public Appliance {
private:
    double temperature;  // 温度
    int fanSpeed;        // 风速 1-5

public:
    AirConditioner(const string& id, const string& br)
        : Appliance(id, br), temperature(24.0), fanSpeed(3) {}

    void showStatus() const override {
        Appliance::showStatus();
        cout << " | 类型: 空调"
            << " | 温度: " << temperature << "°C"
            << " | 风速: " << fanSpeed << endl;
    }

    void control() override {
        if (!powerStatus) {
            cout << "请先打开空调设备[" << deviceID << "]的电源。" << endl;
            return;
        }
        try {
            cout << "输入目标温度 (16.0-30.0°C): ";
            double t;
            cin >> t;
            if (t < 16.0 || t > 30.0) throw invalid_argument("温度超出范围");
            temperature = t;

            cout << "输入风速 (1-5): ";
            int f;
            cin >> f;
            if (f < 1 || f > 5) throw invalid_argument("风速超出范围");
            fanSpeed = f;

            cout << "空调[" << deviceID << "]已设置 -> 温度: "
                << temperature << "°C, 风速: " << fanSpeed << endl;
        }
        catch (exception& e) {
            cout << "控制空调时出错: " << e.what() << endl;
        }
    }
};

// 派生类：SecurityCamera（监控摄像头）
class SecurityCamera : public Appliance {
private:
    bool recordingStatus; // 录制状态
    bool nightVision;     // 夜视功能

public:
    SecurityCamera(const string& id, const string& br)
        : Appliance(id, br), recordingStatus(false), nightVision(false) {}

    void showStatus() const override {
        Appliance::showStatus();
        cout << " | 类型: 监控摄像头"
            << " | 录制: " << (recordingStatus ? "正在录制" : "已停止")
            << " | 夜视: " << (nightVision ? "已启用" : "已禁用") << endl;
    }

    void control() override {
        if (!powerStatus) {
            cout << "请先打开摄像头设备[" << deviceID << "]的电源。" << endl;
            return;
        }
        cout << "切换录制状态 (0: 停止, 1: 开始): ";
        int r;
        cin >> r;
        recordingStatus = (r == 1);

        cout << "切换夜视功能 (0: 禁用, 1: 启用): ";
        int n;
        cin >> n;
        nightVision = (n == 1);

        cout << "摄像头[" << deviceID << "]已设置 -> 录制: "
            << (recordingStatus ? "正在录制" : "已停止")
            << ", 夜视: " << (nightVision ? "已启用" : "已禁用") << endl;
    }
};

// 全局管理：SmartHome
class SmartHome {
private:
    vector<unique_ptr<Appliance>> devices; // 存储设备的智能指针

    // 检查deviceID是否唯一
    bool isUniqueID(const string& id) {
        return none_of(devices.begin(), devices.end(), [&](const unique_ptr<Appliance>& d) {
            return d->getID() == id;
            });
    }

public:
    // 添加设备
    void addDevice() {
        cout << "选择设备类型: 1-灯光 2-空调 3-监控摄像头: ";
        int type;
        cin >> type;
        cout << "输入设备ID: ";
        string id;
        cin >> id;
        if (!isUniqueID(id)) {
            cout << "错误: 设备ID已存在。" << endl;
            return;
        }
        cout << "输入品牌: ";
        string br;
        cin >> br;

        switch (type) {
        case 1:
            devices.emplace_back(make_unique<Light>(id, br));
            break;
        case 2:
            devices.emplace_back(make_unique<AirConditioner>(id, br));
            break;
        case 3:
            devices.emplace_back(make_unique<SecurityCamera>(id, br));
            break;
        default:
            cout << "无效类型。" << endl;
            return;
        }
        cout << "设备[" << id << "] 添加成功。" << endl;
    }

    // 全局开/关
    void globalPower(bool on) {
        for (auto& d : devices) {
            if (on) d->turnOn(); else d->turnOff();
        }
    }

    // 控制单个/所有设备
    void controlDevice() {
        cout << "输入要控制的设备ID (或输入 ALL 控制所有): ";
        string id;
        cin >> id;
        if (id == "ALL") {
            for (auto& d : devices) {
                d->control();
            }
        }
        else {
            auto it = find_if(devices.begin(), devices.end(), [&](const unique_ptr<Appliance>& d) {
                return d->getID() == id;
                });
            if (it != devices.end()) {
                (*it)->control();
            }
            else {
                cout << "未找到设备ID: " << id << endl;
            }
        }
    }

    // 显示所有设备状态
    void showAll() const {
        cout << "------ 所有设备状态 ------" << endl;
        for (const auto& d : devices) {
            d->showStatus();
        }
        cout << "-------------------------" << endl;
    }

    // 搜索设备
    void searchDevice() const {
        cout << "按ID(1)或品牌(2)搜索: ";
        int opt;
        cin >> opt;
        if (opt == 1) {
            cout << "输入设备ID: ";
            string id;
            cin >> id;
            for (const auto& d : devices) {
                if (d->getID() == id) {
                    d->showStatus();
                    return;
                }
            }
        }
        else if (opt == 2) {
            cout << "输入品牌: ";
            string br;
            cin >> br;
            for (const auto& d : devices) {
                if (d->getBrand() == br) {
                    d->showStatus();
                }
            }
        }
        else {
            cout << "无效选项。" << endl;
        }
    }
};

int main() {
    SmartHome home;
    while (true) {
        cout << "\n=== 智能家居系统 ===" << endl;
        cout << "1. 添加设备" << endl;
        cout << "2. 全部设备开机" << endl;
        cout << "3. 全部设备关机" << endl;
        cout << "4. 控制设备" << endl;
        cout << "5. 显示所有状态" << endl;
        cout << "6. 搜索设备" << endl;
        cout << "0. 退出" << endl;
        cout << "选择操作: ";
        int choice;
        cin >> choice;
        switch (choice) {
        case 1: home.addDevice(); break;
        case 2: home.globalPower(true); break;
        case 3: home.globalPower(false); break;
        case 4: home.controlDevice(); break;
        case 5: home.showAll(); break;
        case 6: home.searchDevice(); break;
        case 0: cout << "退出系统。" << endl; return 0;
        default: cout << "无效选择，请重试。" << endl;
        }
    }
    return 0;
}
