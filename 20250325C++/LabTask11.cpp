#include <iostream>
#include <pthread.h>
#include <cstdlib>
#include <ctime>
#include <chrono>

#define SIZE 1024        // 矩阵和向量的大小
#define NUM_THREADS 4    // 线程数量

// 全局数据结构
struct ThreadData {
    int thread_id;
    int** matrix;
    int* vector;
    int* result;
};

// 初始化矩阵和向量
void initialize(int** matrix, int* vector) {
    std::srand(std::time(nullptr));

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            matrix[i][j] = std::rand() % 100; // 0-99的随机数
        }
        vector[i] = std::rand() % 100;
    }
}

// 线程函数 - 计算部分结果
void* computeElement(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    int elements_per_thread = SIZE / NUM_THREADS;
    int start = data->thread_id * elements_per_thread;
    int end = (data->thread_id == NUM_THREADS - 1) ? SIZE : start + elements_per_thread;

    for (int i = start; i < end; ++i) {
        data->result[i] = 0;
        for (int j = ️0; j < SIZE; ++j) {
            data->result[i] += data->matrix[i][j] * data->vector[j];
        }
    }

    pthread_exit(NULL);
}

int main16() {
    // 动态分配内存
    int** matrix = new int* [SIZE];
    for (int i = 0; i < SIZE; ++i) {
        matrix[i] = new int[SIZE];
    }
    int* vector = new int[SIZE];
    int* result = new int[SIZE];

    // 初始化矩阵和向量
    initialize(matrix, vector);

    // 记录开始时间
    auto start = std::chrono::high_resolution_clock::now();

    // 创建线程
    pthread_t threads[NUM_THREADS];
    ThreadData thread_data[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; ++i) {
        thread_data[i].thread_id = i;
        thread_data[i].matrix = matrix;
        thread_data[i].vector = vector;
        thread_data[i].result = result;

        int rc = pthread_create(&threads[i], NULL, computeElement, (void*)&thread_data[i]);
        if (rc) {
            std::cerr << "无法创建线程 " << i << std::endl;
            exit(-1);
        }
    }

    // 等待所有线程完成
    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    // 记录结束时间
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    // 输出执行时间
    std::cout << "矩阵向量乘法完成! 耗时: " << duration.count() << " 毫秒" << std::endl;

    // 释放内存
    for (int i = 0; i < SIZE; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] vector;
    delete[] result;

    return 0;
}