#include <iostream>
#include <thread>
using namespace std;

// dummy function
void foo(int z)
{
    for (int i = 0; i < z; i++)
    {
        cout << "Foo is executing";
    }
}

// callable object
class thread_obj
{
public:
    void operator()(int x)
    {
        for (int i = 0; i < x; i++)
        {
            cout << "class exec" << endl;
        }
    }
};

int main()
{
    // this thread is launched by using function ptr as callable
    thread th1(foo, 3);

    // using function obj as argument
    thread th2(thread_obj(), 3);

    // wait for thread to complete
    th1.join;
    th2.join;

    return 0;
}

/*
Threads 1 and 2 operate independently


*/