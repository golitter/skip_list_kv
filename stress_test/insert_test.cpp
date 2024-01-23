#include <iostream>
#include <chrono>
#include <cstdlib>
#include <pthread.h>
#include <time.h>
#include "../include/skip_list.hpp"  // 请替换为实际的头文件路径

#define NUM_THREADS 1  // 根据需要设置线程数量
#define TEST_COUNT 100000
SkipList<int, std::string> skipList(18);

void *insertElement(void* threadid) {
    long tid; 
    tid = (long)threadid;
    std::cout << "Insert Thread ID: " << tid << std::endl;  
    int tmp = TEST_COUNT / NUM_THREADS; 
    for (int i = tid * tmp, count = 0; count < tmp; i++) {
        count++;
        skipList.insert_element(rand() % TEST_COUNT, "glt"); 
    }
    pthread_exit(NULL);
}

int main() {
    srand (time(NULL));  
    pthread_t threads[NUM_THREADS];

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < NUM_THREADS; i++) {
        std::cout << "main() : creating insert thread, " << i << std::endl;
        int rc = pthread_create(&threads[i], NULL, insertElement, (void *)i);

        if (rc) {
            std::cout << "Error: unable to create thread, " << rc << std::endl;
            exit(-1);
        }
    }

    void *ret;
    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(threads[i], &ret) != 0)  {
            perror("pthread_join() error"); 
            exit(3);
        }
    }

    auto finish = std::chrono::high_resolution_clock::now(); 
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "Insert elapsed: " << elapsed.count() << " seconds" << std::endl;
    return 0;
}
