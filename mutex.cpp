
#include <unistd.h>

#include "mutex.h"


Mutex::Mutex()
{
   int ret = pthread_mutex_init(&m_mutex, NULL);
   isLocked = false;
}

Mutex::~Mutex()
{
    while ( isLocked )
        sleep(1);
    unlock();

    int ret = pthread_mutex_destroy(&m_mutex);
}

void Mutex::lock()
{
    int ret = pthread_mutex_lock(&m_mutex);
    isLocked = true;
}

void Mutex::unlock()
{
    isLocked = false;
    int ret = pthread_mutex_unlock(&m_mutex);
}
