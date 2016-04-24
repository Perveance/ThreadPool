#ifndef COND_VAR_H
#define COND_VAR_H

#include <pthread.h>
#include "mutex.h"

class CondVar
{
public:
    CondVar();
    ~CondVar();
    void wait(Mutex *mutex);
    void signal();
    void broadcast();
private:
    pthread_cond_t m_cond_var;
protected:
};

#endif
