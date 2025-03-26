#include <iostream>
#include <vector>
#include <thread>
#include <random>
#include <chrono>

//Task 10：

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
编写一个多线程的 C++ 程序，用于计算两个 1024 x 1024 的方阵（元素为整数）的乘法。
该程序应将两个矩阵 A 和 B 作为输入（用随机值初始化），并使用并行处理（基于 8 个线程）
计算结果矩阵 C = A * B。矩阵 A、B 和 C 都应创建为二维数组。
为优化性能并减少计算时间，每个线程应负责计算结果矩阵中特定的一行或多行块。在写入结果矩
阵时，必须确保进行适当的同步，以避免出现竞态条件。该程序应通过使用 std::thread 进行多
线程操作，高效利用多核处理器。*/

const int SIZE = 1024;        // 矩阵大小
const int NUM_THREADS = 8;    // 线程数量

// 矩阵类型定义
using Matrix = std::vector<std::vector<int>>;

// 初始化矩阵为随机值
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

// 矩阵乘法线程函数 (按行分块)
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
    // 创建并初始化矩阵
    Matrix A(SIZE, std::vector<int>(SIZE));
    Matrix B(SIZE, std::vector<int>(SIZE));
    Matrix C(SIZE, std::vector<int>(SIZE));

    initializeMatrix(A);
    initializeMatrix(B);

    // 记录开始时间
    auto start = std::chrono::high_resolution_clock::now();

    // 创建线程数组
    std::vector<std::thread> threads;
    int rowsPerThread = SIZE / NUM_THREADS;

    // 启动线程
    for (int i = 0; i < NUM_THREADS; ++i) {
        int startRow = i * rowsPerThread;
        int endRow = (i == NUM_THREADS - 1) ? SIZE : startRow + rowsPerThread;

        threads.emplace_back(multiplyRows, std::ref(A), std::ref(B), std::ref(C),
            startRow, endRow);
    }

    // 等待所有线程完成
    for (auto& thread : threads) {
        thread.join();
    }

    // 记录结束时间
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    // 输出执行时间
    std::cout << "矩阵乘法完成! 耗时: " << duration.count() << " 毫秒" << std::endl;

    return 0;
}