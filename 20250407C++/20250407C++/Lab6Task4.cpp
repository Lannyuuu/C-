#include <iostream>
#include <cstdlib>  // ����rand()��srand()
#include <ctime>    // ����time()
#include <iomanip>  // ����setw()

using namespace std;

// ��������
void initializeMatrix(int** matrix, int size);
void printMatrix(int** matrix, int size);
void transposeMatrix(int** matrix, int size);
void deallocateMatrix(int** matrix, int size);

int main_task4() {
    const int SIZE = 20; // �����С
    srand(time(0));      // �����������

    // ��̬����20��20����
    int** matrix = new int* [SIZE];
    for (int i = 0; i < SIZE; i++) {
        matrix[i] = new int[SIZE];
    }

    // ��ʼ������
    initializeMatrix(matrix, SIZE);

    // ��ӡԭʼ����
    cout << "ԭʼ����:" << endl;
    printMatrix(matrix, SIZE);

    // ԭ��ת�þ���
    transposeMatrix(matrix, SIZE);

    // ��ӡת�ú�ľ���
    cout << "\nת�ú�ľ���:" << endl;
    printMatrix(matrix, SIZE);

    // �ͷ��ڴ�
    deallocateMatrix(matrix, SIZE);

    return 0;
}

// ���������ʼ������
void initializeMatrix(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % 100; // ����0-99�������
        }
    }
}

// ��ӡ����
void printMatrix(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << setw(3) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// ԭ��ת�þ���
void transposeMatrix(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            // ����matrix[i][j]��matrix[j][i]
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

// �ͷž����ڴ�
void deallocateMatrix(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}