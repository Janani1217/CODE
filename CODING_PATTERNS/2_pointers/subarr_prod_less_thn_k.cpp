/*
Subarray Product Less Than K :

Given an array of integers nums and an integer k, return the number of
contiguous subarrays where the product of all the elements in the subarray is
strictly less than k.

.................................................................................................

Input: nums = [10,5,2,6], k = 100
Output: 8

Explanation: The 8 subarrays that have product less than 100 are:
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]

Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.

.................................................................................................

Algorithm :

USE 2 POINTERS + SLIDING WINDOW APPROACH

1.  have var for prod = 1
2.  count = 0;

3.  1st ptr : left : -> used to point the number which is currently included in the prod
    And if its not in the prod , then it would have been divided from the prod.

4.  loop : 2nd ptr : rt : 0 -> n :

    4.1 calc prod = prod * arr[rt]
    4.2 while ( prod > = k)
        4.2.1 prod = prod/arr[left];  //removing the first number in the subarr : sliding window appr
        4.2.2 left++;

    4.3 finally u have to keep the count of all subarr present in the current subarr:
        count = count + (rt - left) + 1;

5.  return count;

.................................................................................................

*/

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr, int k)
{
    if (k <= 1)
        return 0;

    int count = 0;
    int prod = 1;
    int left = 0;
    int n = arr.size();

    for (int rt = 0; rt < n; rt++)
    {
        prod = prod * arr[rt];

        while (prod >= k)
        {
            prod = prod / arr[left];
            left++;
        }

        count = count + (rt - left) + 1;
    }
    return count;
}