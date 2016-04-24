#include <iostream>
#include <queue>
#include "task.h"
#include "posixthreadpool.h"

void f1(void *p)
{
    std::cout << "\tf1: Start" << std::endl;
    sleep(10);
    std::cout << "\tf1: Done" << std::endl;
}

void f2(void *p)
{
    std::cout << "\tf2: Enter" << std::endl;
    sleep(7);
    std::cout << "\tf2: Done" << std::endl;
}

void f3(void *p)
{
    std::cout << "\tf3: Enter" << std::endl;
    sleep(5);
    std::cout << "\tf3: Done" << std::endl;
}

int main ()
{
  int myint;

  std::cout << "Enter\n";

  PosixThreadPool pool(2);

  Task t1(f1, NULL);
  Task t2(f2, NULL);
  Task t3(f3, NULL);

  pool.addTask(&t1);
  pool.addTask(&t2);
  pool.addTask(&t3);

  pool.waitAll();
  pool.joinAll();

  std::cout << "Exit\n";

  return 0;
}
