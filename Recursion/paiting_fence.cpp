/*

problem statement :
Given n = no. of posts to pain
      k = no. of colours

Condition : no 2 adjacent posts should have same colours
Find no. ways to do so.

Approach :
Explained in NOTES

f(n) = f(last 2 same) + f(last 2 diff)
f(last 2 same) = f(n-2) * (k-1)
f(last 2 diff) = f(n-1) * (k-1)
f(n) = [f(n-2) * (k-1)] + [f(n-1) * (k-1)]

*/

#include <iostream>
using namespace std;

int paintFence(int n, int k)
{
    // base case
    if (n == 1)
        return k;

    if (n == 2)
        return k * k;

    if (k == 1)
        return 0;

    // recursive
    int last_two_same = paintFence(n - 2, k) * (k - 1);
    int last_two_diff = paintFence(n - 1, k) * (k - 1);
    return last_two_same + last_two_diff;
}

int main()
{
    int n = 2, k = 3;
    int result = paintFence(n, k);
    cout << result << endl;
} 