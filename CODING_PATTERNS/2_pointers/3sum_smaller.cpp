/*

Given an array arr[] of distinct integers of size N and a value sum, the task
is to find the count of triplets (i, j, k), having (i<j<k) with the sum of
(arr[i] + arr[j] + arr[k]) smaller than the given value sum.

Input: N = 5, sum = 12
arr[] = {5, 1, 3, 4, 7}
Output: 4
Explanation: Below are triplets with
sum less than 12 (1, 3, 4), (1, 3, 5),
(1, 3, 7) and (1, 4, 5).


Approach :

1. using 2 pointers
2. sorting the arr first
3. run a for loop : i=0 till <=n-3
4. while loop for 2 pointers : j=i+1 , k=n-1
5. if sum < target , increment the count to : k - j
6. return count

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    long long countTriplets(long long arr[], int n, long long sum)
    {
        sort(arr, arr + n);
        long long newsum = 0;
        long long count = 0;
        for (int i = 0; i <= n - 3; i++)
        {

            int low = i + 1, high = n - 1;
            while (low < high)
            {
                newsum = arr[i] + arr[low] + arr[high];
                if (newsum >= sum)
                    high--;
                else if (newsum < sum)
                {
                    count += high - low;
                    low++;
                }
            }
        }

        return count;
    }
};