#ifndef MUTEX_H
#define MUTEX_H

#include <pthread.h>

class Mutex
{
public:
    Mutex();
    ~Mutex();
    void lock();
    void unlock();
    pthread_mutex_t* get() { return &mMutex; }
private:
    pthread_mutex_t mMutex;
    bool isLocked;
protected:
};

#endif
