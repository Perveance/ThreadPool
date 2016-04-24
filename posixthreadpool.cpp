
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
    if (mState != STOPPED)
        joinAll();
}

/* Add a new task to the pool. If tasks queue is empth, a thread is 
waken up to execute the job. */
int PosixThreadPool::addTask(Task* task)
{
    mMutex.lock();
    mTasks.push(task);
    mCondVar.signal();
    mMutex.unlock();
    return 0;
}

int PosixThreadPool::execute_thread()
{
    while (true) {
        // First, check if pool is stopped
        if (mState == STOPPED)
            break;

        //Deque a task
        mMutex.lock();
        std::cout << "mTasks size = " << mTasks.size() << std::endl;
        while ((mTasks.size() == 0) && mState != STOPPED) 
        {
            mCondVar.wait(&mMutex);
        }
        if (mState == STOPPED) {
            // Exiting
            mMutex.unlock();
            break;
        }

        Task *t = mTasks.front();
        mTasks.pop();
        mMutex.unlock();

        t->execute();
    }
    
    return 0;
}

int PosixThreadPool::joinAll()
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

    return 0;
}
