// 2016

#include <iostream>

#include "worker.h"

Worker::Worker(pool_func_type pool_func, IThreadPool *p)
{
    mPool = p;
    std::cout << "Worker ctor" << std::endl;
    int ret = pthread_create(&mThread, NULL, pool_func, (void *) mPool);
    if (ret != 0) {
        std::cout << "pthread_create failed" << std::endl;
    }
}

Worker::~Worker()
{
}

void Worker::join()
{
    void *result = NULL;
    int ret = pthread_join(mThread, NULL);
    std::cout << "After pthread_join"  << std::endl;
}



