#include <iostream>
#include <thread>
#include <unistd.h>

using namespace std;

/*
There is a process P.
Divided this process into 2 subtasks : task A, task B
Created 2 threads t1 and t2
Assigned taskA to thread t1 and task B to thread t2.
*/

void taskA()
{
    for (int i = 0; i < 10; i++)
    {
        sleep(1);
        cout << "task A : " << i << endl;
    }
}

void taskB()
{
    for (int i = 0; i < 10; i++)
    {
        sleep(1);
        cout << "task B : " << i << endl;
    }
}

// this main() is the process : which is the main thread
int main()
{
    thread t1(taskA);
    thread t2(taskB);

    // make the main thread to wait until both the above threads
    // execution completes, other wise it will throe error : abort

    t1.join();
    t2.join();

    return 0;
}