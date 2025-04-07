#include <iostream>
#include <cstdlib>  // ����rand()��srand()
#include <ctime>    // ����time()
#include <vector>   // ������ʱ�洢

using namespace std;

// ��������
void initializeArray(int arr[], int size);
void rearrangeArray(const int source[], int*& dest, int size);
void printArray(const int arr[], int size);

int main_task5() {
    const int SIZE = 30;
    int arrayA[SIZE];

    // �����������
    srand(time(0));

    // ��ʼ������A (50-100�������)
    initializeArray(arrayA, SIZE);

    // ��ӡԭʼ����
    cout << "ԭʼ����A:" << endl;
    printArray(arrayA, SIZE);

    // ��̬��������B����������Ԫ��
    int* arrayB = nullptr;
    rearrangeArray(arrayA, arrayB, SIZE);

    // ��ӡ�������к������B
    cout << "\n�������к������B (������ǰ��ż���ں�):" << endl;
    printArray(arrayB, SIZE);

    // �ͷŶ�̬������ڴ�
    delete[] arrayB;

    return 0;
}

// ��50-100���������ʼ������
void initializeArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = 50 + rand() % 51; // 50 + (0��50) = 50��100
    }
}

// �����������飺������ǰ��ż���ں󣬱���ԭʼ˳��
void rearrangeArray(const int source[], int*& dest, int size) {
    vector<int> odds;  // �洢����
    vector<int> evens; // �洢ż��

    // ����������ż��
    for (int i = 0; i < size; i++) {
        if (source[i] % 2 != 0) {
            odds.push_back(source[i]);
        }
        else {
            evens.push_back(source[i]);
        }
    }

    // ��̬����Ŀ������
    dest = new int[size];

    // �ϲ�������ż����Ŀ������
    int index = 0;
    for (int num : odds) {
        dest[index++] = num;
    }
    for (int num : evens) {
        dest[index++] = num;
    }
}

// ��ӡ����
void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
        if ((i + 1) % 10 == 0) { // ÿ10��Ԫ�ػ���
            cout << endl;
        }
    }
    cout << endl;
}