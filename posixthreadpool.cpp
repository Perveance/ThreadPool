
#include <iostream>
#include "posixthreadpool.h"

extern "C"
void *thread_run_func(void *arg)
{
    std::cout << "thread_run_func ENTER" << std::endl;
    IThreadPool* ip = (IThreadPool *) arg;
    PosixThreadPool* p = dynamic_cast<PosixThreadPool *>(ip);
    std::cout << "pool ptr = " << p << std::endl;
    p->execute_thread();
    //p->test();

    std::cout << "Thread function " << std::endl;


    

    return NULL;
}

PosixThreadPool::PosixThreadPool(int N)
{
    for (int i = 0; i < N; ++i) {
        Worker *w = new Worker(&thread_run_func, this);
        mWorkers.push_back( w );
    }
    mState = STARTED;
}

PosixThreadPool::~PosixThreadPool()
{
    mMutex.lock();
    mState = STOPPED;
    mMutex.unlock();

    mCondVar.broadcast();
    
    for (std::vector<int>::size_type i = 0; i != mWorkers.size(); i++ ) {
        std::cout << "  i = " << i << " " << mWorkers[i] << std::endl;
        mWorkers[i]->join();
        delete mWorkers[i];
        mCondVar.broadcast(); // In case some threads were not waken up
    }
}

int PosixThreadPool::addTask(Task* task)
{
    mMutex.lock();
    mTasks.push(task);
    mCondVar.signal();
    mMutex.unlock();
    return 0;
}

int PosixThreadPool::test()
{
    return 5;
}
int PosixThreadPool::execute_thread()
{
    //std::cout << "execute_thread is run" << std::endl;
    return 0;
}

int PosixThreadPool::joinAll()
{
    for (std::vector<int>::size_type i = 0; i != mWorkers.size(); i++) {
        mWorkers[i]->join();
    }

    //mCondVar.signal();

    return 0;
}
