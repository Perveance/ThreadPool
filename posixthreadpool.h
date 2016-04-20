#ifndef POSIXTHREADPOOL_H
#define POSIXTHREADPOOL_H

#include "task.h"
#include "ithreadpool.h"

class PosixThreadPool : public IThreadPool
{
public:
    int addTask(Task* task);
    virtual int execute();
    virtual int joinAll();
protected:
private:
};

#endif
