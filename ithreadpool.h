#ifndef ITHREADPOOL_H
#define ITHREADPOOL_H

#include <vector>
#include <queue>
#include "task.h"
#include "worker.h"

class IThreadPool
{
public:
    virtual int addTask(Task* task) = 0;
    virtual int execute() = 0;
    virtual int joinAll() = 0;
protected:
private:
    std::queue<Task *> mTasks;
    std::vector<Worker *> mWorkers;
};

#endif
