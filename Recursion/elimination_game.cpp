/*
Problem statement :
There is a list of arr of all int starting always from 1 - n in strictly increasing order.
Apply the algo :
1. move from left to right and remove alterante ele till end
2. for the remainng ele , move from right to left and remove alternate elements
3. do the same until 1 element is remained in the final array
4. return that element as op.

Eg:
Input: n = 9
Output: 6
Explanation:
arr = [1, 2, 3, 4, 5, 6, 7, 8, 9]
arr = [2, 4, 6, 8]
arr = [2, 6]
arr = [6]

Approach:

Brute force:
1. take a temp arr to store the remaining ele
2. traverse from l->r and r->l in the recurvise form
3. take a flag to maintain the order of it.

// but this will take a lot of memory -> Memory limit exceeded

Optimized:
1. first if we observe, we will find some recursive relation for this prblm
2. eg, f(n) = used to go from left to right
    f(n) = [1,2,3,4,5,6,7,8]
    every time , the 2nd set of ele will be = [2,4,6,8]
    now we can write this as : 2 * [1,2,3,4]
    so here , it become as : 2 * f(n/2)
    because initial problem was from 1- n and now it becomes 1- n/2

    BUT THE CATCH IS , FOR THIS FUNCTION f(n/2) we need to traverse in
    reverse order, right to left.

    So the function should be same whatever it implements shouls apply for
    all kind of elements. So we need to convert this to left -> right, then only
    it will form a recursive function.

3. now in the subproblem , we go from right->left
    2 * [1,2,3.....n/2]
            <----------[R->L]

    now if we reverse the array as : 2 * [n/2 ..... 3,2,1]
                                        -----------> [L->R]
    now here the traversal order is maintained correctly as per the elements, only the
    elements are reversed.

4. But now , in the actual subproblem , the ele order was [1,2,...n/2].
    So we need to make the modified subarray as this which could be like:
    n/2 ->(convert to) 1  == n/2 - n/2 + 1
    3 == n/2 - 3 + 1 = n/2 - 2

    eg : [1 2 3 4]
    reverse = [4 3 2 1]
    now n/2 represents 4
    and that has to be 1 to form [1 2 3 4] as the actual array

    ele = n/2 - ele + 1
    1 ele = 4 - 4 + 1 = 1
    2 ele = 4 - 3 + 1 = 2
    3 ele = 4 - 2 + 1 = 3
    4 ele = 4 - 1 + 1 = 4

    in this way if we use the formula n/2-ele+1 , we get the actual set of ele

5. so the recursive formula becomes : f(n) = 2 * (n/2 - f(n/2) + 1) )
   which will traverse from L->R


Algorithm:
1. base case , if n == 1 , then return 1
2. apply the recurvise formula

*/

#include <iostream>
using namespace std;

int eliminate(int n)
{
    // base case
    if (n == 1)
    {
        return 1;
    }

    // recursive formula : traverse l->r , with diving ele size by half
    return 2 * (n / 2 - eliminate(n / 2) + 1);
}

int main()
{
    int n = 19;
    int result = eliminate(n);
    cout << result << "\n";
}
