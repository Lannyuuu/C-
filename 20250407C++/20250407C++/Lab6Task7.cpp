#include <iostream>
#include <cstdlib>  // ����rand()��srand()
#include <ctime>    // ����time()

using namespace std;

int main_task7() {
    // �����������
    srand(time(0));

    // ������еĴ�С
    const int ROWS = 5;
    int rowSizes[ROWS] = { 6, 9, 11, 13, 15 };

    // ����ָ������
    int** jaggedArray = new int* [ROWS];

    // Ϊÿ�з��䲻ͬ��С���ڴ沢��ʼ��
    for (int i = 0; i < ROWS; i++) {
        jaggedArray[i] = new int[rowSizes[i]];
        for (int j = 0; j < rowSizes[i]; j++) {
            jaggedArray[i][j] = rand() % 11; // 0-10�������
        }
    }

    // ���㲢��ʾÿ�еĺ�
    cout << "ÿ��Ԫ�صĺ�:" << endl;
    int totalSum = 0;
    for (int i = 0; i < ROWS; i++) {
        int rowSum = 0;
        for (int j = 0; j < rowSizes[i]; j++) {
            rowSum += jaggedArray[i][j];
        }
        totalSum += rowSum;
        cout << "�� " << i + 1 << " (" << rowSizes[i] << " ��Ԫ��): " << rowSum << endl;
    }
    cout << "�����е��ܺ�: " << totalSum << endl;

    // �ͷ��ڴ�
    for (int i = 0; i < ROWS; i++) {
        delete[] jaggedArray[i];
    }
    delete[] jaggedArray;

    return 0;
}