#ifndef MUTEX_H
#define COND_VAR_H

#include <pthread.h>

class Mutex
{
public:
    Mutex();
    ~Mutex();
    void lock();
    void unlock();
private:
    pthread_mutex_t m_mutex;
    bool isLocked;
protected:
};

#endif
