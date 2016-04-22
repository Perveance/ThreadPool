#ifndef POSIXTHREADPOOL_H
#define POSIXTHREADPOOL_H

#include "task.h"
#include "cond_var.h"
#include "ithreadpool.h"

enum PoolState {
    STOPPED = 0,
    STARTED = 1,
};

class PosixThreadPool : public IThreadPool
{
public:
    PosixThreadPool(int N);
    ~PosixThreadPool();
    int addTask(Task* task);
    int execute_thread();
    int test();
    int joinAll();
protected:
private:
    CondVar mCondVar;
    PoolState mState;
};

#endif
