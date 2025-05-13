#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <exception>

using namespace std;

// ������ࣺAppliance
class Appliance {
protected:
    string deviceID;    // �豸Ψһ��ʶ
    string brand;       // Ʒ��
    bool powerStatus;   // ��Դ״̬����(true)/��(false)

public:
    // ���캯��
    Appliance(const string& id, const string& br)
        : deviceID(id), brand(br), powerStatus(false) {}

    virtual ~Appliance() {}

    // �򿪵�Դ
    void turnOn() {
        powerStatus = true;
        cout << "[" << deviceID << "] �Ѵ�" << endl;
    }

    // �رյ�Դ
    void turnOff() {
        powerStatus = false;
        cout << "[" << deviceID << "] �ѹر�" << endl;
    }

    // ��ʾ�豸״̬
    virtual void showStatus() const {
        cout << "�豸ID: " << deviceID
            << " | Ʒ��: " << brand
            << " | ��Դ: " << (powerStatus ? "��" : "��");
    }

    // ���麯���������豸��Ϊ
    virtual void control() = 0;

    // ��ȡdeviceID
    string getID() const { return deviceID; }

    // ��ȡbrand
    string getBrand() const { return brand; }
};

// �����ࣺLight���ƹ⣩
class Light : public Appliance {
private:
    int brightnessLevel; // ���� 0-100
    string color;        // �ƹ���ɫ

public:
    Light(const string& id, const string& br)
        : Appliance(id, br), brightnessLevel(50), color("�׹�") {}

    // ������ʾ״̬
    void showStatus() const override {
        Appliance::showStatus();
        cout << " | ����: �ƹ�"
            << " | ����: " << brightnessLevel
            << "% | ��ɫ: " << color << endl;
    }

    // ʵ�ֿ��ƺ���
    void control() override {
        if (!powerStatus) {
            cout << "���ȴ򿪵ƹ��豸[" << deviceID << "]�ĵ�Դ��" << endl;
            return;
        }
        try {
            cout << "�������� (0-100): ";
            int b;
            cin >> b;
            if (b < 0 || b > 100) throw invalid_argument("����ֵ������Χ");
            brightnessLevel = b;

            cout << "������ɫ (��: �׹�, ů��, ���): ";
            cin >> color;

            cout << "�ƹ�[" << deviceID << "]������ -> ����: "
                << brightnessLevel << "%, ��ɫ: " << color << endl;
        }
        catch (exception& e) {
            cout << "���Ƶƹ�ʱ����: " << e.what() << endl;
        }
    }
};

// �����ࣺAirConditioner���յ���
class AirConditioner : public Appliance {
private:
    double temperature;  // �¶�
    int fanSpeed;        // ���� 1-5

public:
    AirConditioner(const string& id, const string& br)
        : Appliance(id, br), temperature(24.0), fanSpeed(3) {}

    void showStatus() const override {
        Appliance::showStatus();
        cout << " | ����: �յ�"
            << " | �¶�: " << temperature << "��C"
            << " | ����: " << fanSpeed << endl;
    }

    void control() override {
        if (!powerStatus) {
            cout << "���ȴ򿪿յ��豸[" << deviceID << "]�ĵ�Դ��" << endl;
            return;
        }
        try {
            cout << "����Ŀ���¶� (16.0-30.0��C): ";
            double t;
            cin >> t;
            if (t < 16.0 || t > 30.0) throw invalid_argument("�¶ȳ�����Χ");
            temperature = t;

            cout << "������� (1-5): ";
            int f;
            cin >> f;
            if (f < 1 || f > 5) throw invalid_argument("���ٳ�����Χ");
            fanSpeed = f;

            cout << "�յ�[" << deviceID << "]������ -> �¶�: "
                << temperature << "��C, ����: " << fanSpeed << endl;
        }
        catch (exception& e) {
            cout << "���ƿյ�ʱ����: " << e.what() << endl;
        }
    }
};

// �����ࣺSecurityCamera���������ͷ��
class SecurityCamera : public Appliance {
private:
    bool recordingStatus; // ¼��״̬
    bool nightVision;     // ҹ�ӹ���

public:
    SecurityCamera(const string& id, const string& br)
        : Appliance(id, br), recordingStatus(false), nightVision(false) {}

    void showStatus() const override {
        Appliance::showStatus();
        cout << " | ����: �������ͷ"
            << " | ¼��: " << (recordingStatus ? "����¼��" : "��ֹͣ")
            << " | ҹ��: " << (nightVision ? "������" : "�ѽ���") << endl;
    }

    void control() override {
        if (!powerStatus) {
            cout << "���ȴ�����ͷ�豸[" << deviceID << "]�ĵ�Դ��" << endl;
            return;
        }
        cout << "�л�¼��״̬ (0: ֹͣ, 1: ��ʼ): ";
        int r;
        cin >> r;
        recordingStatus = (r == 1);

        cout << "�л�ҹ�ӹ��� (0: ����, 1: ����): ";
        int n;
        cin >> n;
        nightVision = (n == 1);

        cout << "����ͷ[" << deviceID << "]������ -> ¼��: "
            << (recordingStatus ? "����¼��" : "��ֹͣ")
            << ", ҹ��: " << (nightVision ? "������" : "�ѽ���") << endl;
    }
};

// ȫ�ֹ���SmartHome
class SmartHome {
private:
    vector<unique_ptr<Appliance>> devices; // �洢�豸������ָ��

    // ���deviceID�Ƿ�Ψһ
    bool isUniqueID(const string& id) {
        return none_of(devices.begin(), devices.end(), [&](const unique_ptr<Appliance>& d) {
            return d->getID() == id;
            });
    }

public:
    // ����豸
    void addDevice() {
        cout << "ѡ���豸����: 1-�ƹ� 2-�յ� 3-�������ͷ: ";
        int type;
        cin >> type;
        cout << "�����豸ID: ";
        string id;
        cin >> id;
        if (!isUniqueID(id)) {
            cout << "����: �豸ID�Ѵ��ڡ�" << endl;
            return;
        }
        cout << "����Ʒ��: ";
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
            cout << "��Ч���͡�" << endl;
            return;
        }
        cout << "�豸[" << id << "] ��ӳɹ���" << endl;
    }

    // ȫ�ֿ�/��
    void globalPower(bool on) {
        for (auto& d : devices) {
            if (on) d->turnOn(); else d->turnOff();
        }
    }

    // ���Ƶ���/�����豸
    void controlDevice() {
        cout << "����Ҫ���Ƶ��豸ID (������ ALL ��������): ";
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
                cout << "δ�ҵ��豸ID: " << id << endl;
            }
        }
    }

    // ��ʾ�����豸״̬
    void showAll() const {
        cout << "------ �����豸״̬ ------" << endl;
        for (const auto& d : devices) {
            d->showStatus();
        }
        cout << "-------------------------" << endl;
    }

    // �����豸
    void searchDevice() const {
        cout << "��ID(1)��Ʒ��(2)����: ";
        int opt;
        cin >> opt;
        if (opt == 1) {
            cout << "�����豸ID: ";
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
            cout << "����Ʒ��: ";
            string br;
            cin >> br;
            for (const auto& d : devices) {
                if (d->getBrand() == br) {
                    d->showStatus();
                }
            }
        }
        else {
            cout << "��Чѡ�" << endl;
        }
    }
};

int main() {
    SmartHome home;
    while (true) {
        cout << "\n=== ���ܼҾ�ϵͳ ===" << endl;
        cout << "1. ����豸" << endl;
        cout << "2. ȫ���豸����" << endl;
        cout << "3. ȫ���豸�ػ�" << endl;
        cout << "4. �����豸" << endl;
        cout << "5. ��ʾ����״̬" << endl;
        cout << "6. �����豸" << endl;
        cout << "0. �˳�" << endl;
        cout << "ѡ�����: ";
        int choice;
        cin >> choice;
        switch (choice) {
        case 1: home.addDevice(); break;
        case 2: home.globalPower(true); break;
        case 3: home.globalPower(false); break;
        case 4: home.controlDevice(); break;
        case 5: home.showAll(); break;
        case 6: home.searchDevice(); break;
        case 0: cout << "�˳�ϵͳ��" << endl; return 0;
        default: cout << "��Чѡ�������ԡ�" << endl;
        }
    }
    return 0;
}
