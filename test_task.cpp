#include "task.h"
#include "iostream"

struct Data {
    std::string name;
};

void MyFunc(void *args)
{
    Data* d = (Data *) args;

    std::cout << "My function" << std::endl;
    if (d)
        std::cout << "Hello, " << d->name << "!" << std::endl;
}

int main()
{

    Data d = { "Mikhail" };
    Task t(MyFunc, &d);
    t.execute();
    return 0;
}
