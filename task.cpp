
#include "task.h"

Task::Task(func_type f, void *args) : m_func(f), m_args(args)
{
}

Task::~Task()
{
}

void Task::execute()
{
    m_func(m_args);
}



