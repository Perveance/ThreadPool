#ifndef WORKER_H
#define WORKER_H

#include <pthread.h>
#include "ithreadpool.h"
#include "task.h"

class IThreadPool;

typedef void *(*pool_func_type)(void *);

class Worker
{
public:
    Worker(pool_func_type pool_func, IThreadPool *p);
    ~Worker();
    void join();
private:
    pthread_t mThread;
    IThreadPool *mPool;
protected:
};

#endif
