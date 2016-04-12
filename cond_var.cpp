
#include "cond_var.h"

CondVar::CondVar()
{
   int ret = pthread_cond_init(&m_cond_var, NULL);
}

CondVar::~CondVar()
{
    int ret = pthread_cond_destroy(&m_cond_var);
}

void CondVar::signal()
{
    int ret = pthread_cond_signal(&m_cond_var);
}

void CondVar::wait(pthread_mutex_t *mutex)
{
    int ret = pthread_cond_wait(&m_cond_var, mutex);
}

void CondVar::broadcast()
{
    int ret = pthread_cond_broadcast(&m_cond_var);
}
