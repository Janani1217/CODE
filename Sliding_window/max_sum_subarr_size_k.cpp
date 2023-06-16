/*
Max Sum subarray with max sum of length K :

You are given an integer array nums and an integer k.
Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:

The length of the subarray is k, and
All the elements of the subarray are distinct.

Return the maximum subarray sum of all the subarrays that meet the conditions.
If no subarray meets the conditions, return 0.

A subarray is a contiguous non-empty sequence of elements within an array.

.................................................................................................

Example :
Input: nums = [1,5,4,2,9,9,9], k = 3
Output: 15
Explanation: The subarrays of nums with length 3 are:
- [1,5,4] which meets the requirements and has a sum of 10.
- [5,4,2] which meets the requirements and has a sum of 11.
- [4,2,9] which meets the requirements and has a sum of 15.
- [2,9,9] which does not meet the requirements because the element 9 is repeated.
- [9,9,9] which does not meet the requirements because the element 9 is repeated.
We return 15 because it is the maximum subarray sum of all the subarrays that meet the conditions

.................................................................................................


Approach : Sliding window
Window size = k

Identification :
1. given ip = arr / string
2. subarr / substr will be asked
3. window size would be given for fixed size
4. for var size , condition would have been given

if the above points are given 85% sliding window approach can be applied

.................................................................................................

Explaination :

1. take 2 ptrs i->start index of window and j->end index of window
2. cs = 0 , ms = 0
   take a set = s to handle the dulpicate ele

3. 1st run a loop till j reaches the end of arr

4. now we need to first form a window

    4.1 if i-j <k and s.size < k => means window size not yet reached
    4.2 calc the cs
    4.3 add ele to s
    4.4 incr the j

5. if suppose the window size is reached

    5.1 we need to check the conditions
    5.2 calc the max sum
    5.3 after this we need move the i and remove from set

6. at the last we need to process the last window which will not
   be calc inside the above while loop.
.................................................................................................

*/

class Solution
{
public
    long maximumSubarraySum(int[] nums, int k)
    {
        int i = 0, j = 0;
        long cs = 0, ms = 0;
        Set<Integer> s = new HashSet<>();
        int n = nums.length;

        while (j < n)
        {
            if (j - i < k && s.size() < k)
            {
                while (s.size() > 0 && s.contains(nums[j]))
                {
                    cs -= nums[i];
                    s.remove(nums[i]);
                    i++;
                }

                cs += nums[j];
                s.add(nums[j]);
                j++;
            }
            else
            {
                if (j - i == k && s.size() == k)
                {
                    ms = Math.max(ms, cs);
                }

                cs -= nums[i];
                s.remove(nums[i]);
                i++;
            }
        }

        if (j - i == k && s.size() == k)
        {
            ms = Math.max(ms, cs);
        }

        return ms;
    }
}