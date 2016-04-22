#ifndef ITHREADPOOL_H
#define ITHREADPOOL_H

#include <vector>
#include <queue>
#include "task.h"
#include "worker.h"
#include "mutex.h"

class Worker; 

class IThreadPool
{
public:
    virtual int addTask(Task* task) = 0;
    virtual int execute_thread() = 0;
    virtual int joinAll() = 0;
protected:
    std::queue<Task *> mTasks;
    std::vector<Worker *> mWorkers;
    Mutex mMutex;
private:
};

#endif
