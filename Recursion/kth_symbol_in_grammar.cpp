/*
Home work:

1. decode string
2. max points in archery competetion
3. kth symbol in grammer -> complement approach debug

*/

/*
Problem statement :
we build a table of n rows -> 1 indexed
we start by 0 in the 1st row.
in the next we replace every occurance 0 with 01 and 1 with 10 in the next row.
we need to find what is present in the kth index.

eg:
n=3 , k=1
1st row = 0
2nd row = 01
3rd row = 0110
ans = 1

Approach:
This can be approached in 3 ways:
1. Complement :
   let n = 4
   1. 0
   2. 01
   3. 0110
   4. 01101001

    if we observe , in 2. 0 and compl of 0 = 1
    in 3. 01 & complement(01)=10  => 0110
    in 4. 0110 & compl(0110) = 1001 => 01101001

2. Trees :

                    0
            0              1
         0     1        1     0
       0  1   1  0    1  0   0  1

    so when the parent is 0 -> left child  = 0, rt child = 1
    when parent is 1 -> left ch = 1 , rt ch = 0


So , here there is no need on n to calculate the required output.
If we take K , we can find the op.

There are 2 factors required for k to get the op:
1. parent of kth index = 0 or 1
2. whether k is even or odd

If we observe in tree, we can se that the left child of anynode is at odd index and
right child is at even index.
        0
    0       1

left index = 1
right index = 2

2nd eg:
            0
        0        1
      0   1    1   0

here also for last row, left child indexes = 1,3
rt child indexes = 2,4

So the left child always has odd index and rt child always at even index.

So there are 4 options for k now to get the ans:
1. if(k'parent == 0 && k->even) ans = 1
2. if(k'parent == 0 && k->odd) ans = 0
3. if(k'parent == 1 && k->even) ans = 0
4. if(k'parent == 1 && k->odd) ans = 1

now we need to find k'parent:
1. if k value = 6 , i.e 6th index in nth row.
2. its parent's index will be = (k/2 + k%2) // divide by 2 and add the remainder also
    // dry run to get clarity here



*/

#include <iostream>
using namespace std;

int find_kth_symbol(int n, int k)
{
    // base
    if (n == 1)
    {
        return 0;
    }

    /* find the parent of kth index: go to prev row and go to the
       given distance from left */

    int parent = find_kth_symbol(n - 1, k / 2 + k % 2);

    /*
    Here % is a heavy operation so replace it with "&" bit operation.
    k%2 == 0  -> even -> k&1 == 0
    k%2 == 1  -> odd -> k&1 == 1
    */

    if (parent == 0 && k % 2 == 0)
        return 1;
    if (parent == 0 && k % 2 != 0)
        return 0;
    if (parent == 1 && k % 2 == 0)
        return 0;
    if (parent == 1 && k % 2 != 0)
        return 1;
}

int main()
{
    int n = 4;
    int k = 4;

    int result = find_kth_symbol(n, k);
    cout << result << endl;
}