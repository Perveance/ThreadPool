#ifndef TASK_H
#define TASK_H

typedef void (*func_type)(void *);

class Task
{
public:
    Task(func_type f, void *args);
    ~Task();
    void execute();
private:
    func_type m_func;
    void * m_args;
protected:
};

#endif
