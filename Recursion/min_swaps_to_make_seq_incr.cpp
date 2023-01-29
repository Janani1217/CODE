/*
*****
Problem statement :
Min swaps to make seuence increasing

Given 2 arrs: of same length:
arr1 = [1, 3, 5, 4]
arr2 = [1, 2, 3, 7]

In 1 OPERATION: u can swap only arr1[i] and arr2[i] -> same index ele
can only be swapped in 1 operation
eg :
for index 2 :
after swap :
arr1 = [1, 3, 3, 4]
arr2 = [1, 2, 5, 7]

Now , return min no. of operations to make arr1 and arr2 BOTH strictly incr
The op is always possible as per testcases given (leetcode)

Strictly incr : a1[i] < a1[i+1] .... should not be <= , should always
be < only

................................................................................

Eg:
arr1 = [1, 3, 5, 4]
arr2 = [1, 2, 3, 7]

here in arr1, till index 2, its strictly incr , but not in arr1[3]
So swap with arr2[3]

now both becomes strictly incr
arr1 = [1, 3, 5, 7]
arr2 = [1, 2, 3, 4]

So , op = 1 operation

................................................................................

Approach :

1.  Here we see there is only 1 operation : swap : either we can do it
    or ignore it. Exclude - Include kind of pattern

2.  So , to do that swap , we must take care of the prev number , to find
    strictly incr or not

3.  For arr[0] , prev = -1 for both arrs

4.  CATCH : Need to keep the count/flag , if previous ele was swapped
    or not, if swapped , then incr the count

    So the funct will look as :
    solve(arr1, arr2, prev1, prev2 ,index, swap);

................................................................................

***** GIVES CORRECT ANS IN LEETCODE WITH SAME PROBLEM STATEMENT ******

*/

#include <iostream>
#include <vector>
using namespace std;

int findMinSwaps(vector<int> arr1, vector<int> arr2, int prev1, int prev2, int index)
{
    // base : termination condition
    if (index == arr1.size())
        return 0;

    /*
       since there will be 2 ans : with swap and without swap : need to find min in them so
       init with MAX number
    */
    int swap_1 = INT_MAX;
    int noswap = INT_MAX;

    // no swap case : when already strictly incr
    if ((prev1 < arr1[index]) && (prev2 < arr2[index]))
    {
        noswap = findMinSwaps(arr1, arr2, arr1[index], arr2[index], index + 1);
    }

    /* swap cases : before swap check a1[prev] with a2[i] , so that
    a2[i] will come after a1[prev], so should be greater then only
    swap will satisfy the condition.
    Similarly a1[i] should also be greater than a2[prev], since it will
    come after that in the arr
    */

    if (arr1[index] > prev2 && arr2[index] > prev1)
    {
        swap_1 = 1 + findMinSwaps(arr1, arr2, arr2[index], arr1[index], index + 1);
    }

    return min(swap_1, noswap);
}

int main()
{
    vector<int> arr1;
    arr1.push_back(1);
    arr1.push_back(3);
    arr1.push_back(5);
    arr1.push_back(7);

    vector<int> arr2;
    arr2.push_back(1);
    arr2.push_back(2);
    arr2.push_back(3);
    arr2.push_back(4);

    int prev1 = -1;
    int prev2 = -1;
    int index = 0;

    int result = findMinSwaps(arr1, arr2, prev1, prev2, 0);
    cout << "result = " << result << endl;
}