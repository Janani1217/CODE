/*

Problem statement :
Joseph's problem : Find the winner of the circular game :
There are "n" frnds sitting is a circle numbered from 1->n in clockwise order.
moving from ith frnd, we will go to i+1th frnd nd moving from nth frnd we will go to ith frnd.

"K" is also given.

Rules of game :
1. start from 1st frnd
2. count next "k" frnds including itself and remove the kth frnd from the loop.
3. This will go in circular fashion , counting twice for some frnds can also happen
4. last frnd whoever remains return that number in op.

Eg:
n = 5 , k = 2 :
1-2-3-4-5-1

1-2 = remove 2
3-4 = remove 4
5-1 = remove 1
3-5 = remove 5

remaining = 3  -> op


Approach:
1. here there is a pattern to observe :
    n=4 , k=2 , op=1
    n=5 , k=2 , op=3
    n=6 , k=2 , op=5
    n=7 , k=2 , op=7

    n=8 , k=2 , op=1
    n=9 , k=2 , op=3
    n=10 , k=2 , op=5
    n=11 , k=2 , op=7

    n=12 , k=2 , op=9
    n=13 , k=2 , op=11
    n=14 , k=2 , op=13

    n=15 , k=2 , op=1
    n=16 , k=2 , op=3
    ..

2. Here we see as if : f(n,k) depends on f(n-1,k)
3. Recurrance relation comes out to be : (f(n-1,k) + k) % n

4. Why mod ? Whenever we look at a pattern whose op keeps repeating again after some iterations
    there we make use of mod operator to produce the repeatable outputs.
5.  here , for n=11 , we got op=7 , i.e 7th node

    But n=12 , we got 9th node as op, because there are total 12 nodes in the circle
    Again n=15 , if we add 13+2=15 , but 15th node cannot itself, it has to move k steps
    forward to cut , after 15 , we have 1st node

6. So it cuts the 1st node.
7. In such cases again the op gets repeated untill the condition is satisfied
8. Hence we use % n to the whole.

9. Here the first node count is 1.

*/

#include <iostream>
using namespace std;

int circularGame(int n, int k)
{
    // base case
    if (n == 1)
    {
        return 0;
    }

    // here the ans will start from 0 since mod
    int ans = (circularGame(n - 1, k) + k) % n;
    cout << "n = " << n << ", ans = " << ans << endl;

    return ans;
}
int main()
{
    int n = 7, k = 2;
    int ans = circularGame(n, k);
    ans = ans + 1;
    // since the count of frnds starts from 1 and not 0.
    // but % operator will give the op starting from 0, so add 1 in op.
    cout << ans;
}
