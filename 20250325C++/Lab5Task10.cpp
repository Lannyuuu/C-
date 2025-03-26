#include <iostream>
#include <vector>
#include <thread>
#include <random>
#include <chrono>

//Task 10��

/*Task 10: Write a multi-threaded C++ program to compute the multiplication of 
two square matrices, each of size 1024 x 1024, containing integer elements. 
The program should take two matrices A and B as input (initialised with 
random values) and compute the result matrix C = A * B using parallel 
processing (based on 8 threads). Each A, B, and C metrices should be created 
as 2D arrays.
Each thread should be responsible for computing a specific row or block of 
rows in the result matrix to optimize performance and reduce computation 
time. Proper synchronization must be ensured to avoid race conditions when 
writing to the result matrix. The program should make efficient use of 
multicore processors by employing std::thread for multi-threading.
��дһ�����̵߳� C++ �������ڼ������� 1024 x 1024 �ķ���Ԫ��Ϊ�������ĳ˷���
�ó���Ӧ���������� A �� B ��Ϊ���루�����ֵ��ʼ��������ʹ�ò��д������� 8 ���̣߳�
���������� C = A * B������ A��B �� C ��Ӧ����Ϊ��ά���顣
Ϊ�Ż����ܲ����ټ���ʱ�䣬ÿ���߳�Ӧ����������������ض���һ�л���п顣��д������
��ʱ������ȷ�������ʵ���ͬ�����Ա�����־�̬�������ó���Ӧͨ��ʹ�� std::thread ���ж�
�̲߳�������Ч���ö�˴�������*/

const int SIZE = 1024;        // �����С
const int NUM_THREADS = 8;    // �߳�����

// �������Ͷ���
using Matrix = std::vector<std::vector<int>>;

// ��ʼ������Ϊ���ֵ
void initializeMatrix(Matrix& mat) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);

    for (auto& row : mat) {
        for (auto& elem : row) {
            elem = dis(gen);
        }
    }
}

// ����˷��̺߳��� (���зֿ�)
void multiplyRows(const Matrix& A, const Matrix& B, Matrix& C,
    int startRow, int endRow) {
    for (int i = startRow; i < endRow; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < SIZE; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main15() {
    // ��������ʼ������
    Matrix A(SIZE, std::vector<int>(SIZE));
    Matrix B(SIZE, std::vector<int>(SIZE));
    Matrix C(SIZE, std::vector<int>(SIZE));

    initializeMatrix(A);
    initializeMatrix(B);

    // ��¼��ʼʱ��
    auto start = std::chrono::high_resolution_clock::now();

    // �����߳�����
    std::vector<std::thread> threads;
    int rowsPerThread = SIZE / NUM_THREADS;

    // �����߳�
    for (int i = 0; i < NUM_THREADS; ++i) {
        int startRow = i * rowsPerThread;
        int endRow = (i == NUM_THREADS - 1) ? SIZE : startRow + rowsPerThread;

        threads.emplace_back(multiplyRows, std::ref(A), std::ref(B), std::ref(C),
            startRow, endRow);
    }

    // �ȴ������߳����
    for (auto& thread : threads) {
        thread.join();
    }

    // ��¼����ʱ��
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    // ���ִ��ʱ��
    std::cout << "����˷����! ��ʱ: " << duration.count() << " ����" << std::endl;

    return 0;
}