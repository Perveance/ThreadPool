#ifndef COND_VAR_H
#define COND_VAR_H

#include <pthread.h>

class CondVar
{
public:
    CondVar();
    ~CondVar();
    void wait(pthread_mutex_t *mutex);
    void signal();
    void broadcast();
private:
    pthread_cond_t m_cond_var;
protected:
};

#endif
