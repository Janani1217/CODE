/*
Stack prop:
1. Last in first out
2. Functions : push, pop, top

Queue:
1. first in first out
2. functions : enqueue , deque , rear , front

Stack can be impl using 2 queues = q1, q2
Keep newly entered ele = front of q1
pop operation deques from q1
q2 is used to put every new ele in front of q1

Push operation impl:
1. enq x to q2
2. one by one deque from q1 and enq to q2
3. swap queues of q1 and q2

Pop Operation impl:
1. deque ele from q1 and return

** Here we are making push operation costly
*/

#include <iostream>
using namespace std;

class Stack
{
    queue<int> q1, q2;

public:
    void push(int x)
    {
        // push the new ele into empty q2
        q2.push(x);

        // push all rem ele from q1 to q2
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        // swap both queues
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    void pop()
    {
        // pop the ele from q1
        if (q1.empty())
            return;
        q1.pop();
    }

    int top()
    {
        if (q1.empty())
            return;

        return q1.front();
    }

    int size()
    {
        return q1.size();
    }
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << s.top() << endl;

    s.pop();
    cout << s.top() << endl;
}