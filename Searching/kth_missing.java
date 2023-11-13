Given an array arr of positive integers sorted in a strictly 
increasing order, and an integer k.

Return the kth positive integer that is missing from this array.

 

Example 1:

Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. 
The 5th missing positive integer is 9.



We need a way to check on how many positive integers are missing
before the given array element to use binary search. To do that, let's compare the input array
[2, 3, 4, 7, 11] with an array with no missing integers: [1, 2, 3, 4, 5].
The number of missing integers is a simple difference between the
corresponding elements of these two arrays:

Before 2, there is 2 - 1 = 1 missing integer.

Before 3, there is 3 - 2 = 1 missing integer.

Before 4, there is 4 - 3 = 1 missing integer.

Before 7, there are 7 - 4 = 3 missing integers.

Before 11, there are 11 - 5 = 6 missing integers.

The number of positive integers which are missing before the arr[idx]
is equal to arr[idx] - idx - 1.








class Solution {
    public int findKthPositive(int[] arr, int k) {
        int n = arr.length;
        int l = 0;
        int r = n-1;

        while(l <= r) {
            int m = l + (r-l)/2;

            int diff = arr[m] - m - 1;
            if(diff < k) {
                // k ele in lying before m : 
                l = m+1;
            } else
                r = m-1;
        }

        return l + k;
    }
}
