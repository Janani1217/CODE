
Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.

 

Example 1:

Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]


  



class Solution {
    public int numSubarraysWithSum(int[] nums, int goal) {
        int n = nums.length;
        int ans = 0;
        int s1 = 0; // Start for the first sum
        int s2 = 0; // Start for the second sum
        int sum1 = 0;
        int sum2 = 0;

        for (int r = 0; r < n; r++) {
            sum1 += nums[r];
            sum2 += nums[r];
            
            /* 
            -> sum1 : this is to calc the sum for window 1 in a normal way
            -> include the curr ele in the window and incr the sum till goal.
            -> if sum exceeds : shrink window with help of s1
            */

            while (s1 < r && sum1 > goal) {
                sum1 -= nums[s1];
                s1++;
            }

            /* 
            -> sum2 : this is to calc the sum for window 2 in the same sum1
            -> include the curr ele in the window and incr the sum till goal.
            -> if sum exceeds : shrink window with help of s2 
                -> while shrinking the window , we will be considering the cases :
                    * when 0's are included and the sum remains the same
                    * when 1's are present, then decr the sum and check for goal
            */

            while (s2 < r && (sum2 > goal || (sum2 == goal && nums[s2] == 0))) {
                sum2 -= nums[s2];
                s2++;
            }

            if (sum1 == goal) {
                ans += s2 - s1 + 1;  // consider the pos btw s1 and s2 into the count of sum == goal for both the windows.
            }
        }

        return ans;
    }
}
