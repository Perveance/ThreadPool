
#include <unistd.h>

#include "mutex.h"


Mutex::Mutex()
{
   int ret = pthread_mutex_init(&mMutex, NULL);
   isLocked = false;
}

Mutex::~Mutex()
{
    while ( isLocked )
        sleep(1);
    unlock();

    int ret = pthread_mutex_destroy(&mMutex);
}

void Mutex::lock()
{
    int ret = pthread_mutex_lock(&mMutex);
    isLocked = true;
}

void Mutex::unlock()
{
    isLocked = false;
    int ret = pthread_mutex_unlock(&mMutex);
}
