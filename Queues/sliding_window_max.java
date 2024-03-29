/*
   Sliding Window Maximum : 

   You are given an array of integers nums, there is a sliding window of 
   size k which is moving from the very left of the array to the very right. 
   You can only see the k numbers in the window. Each time the sliding window 
   moves right by one position.

  Return the max sliding window.


Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

 * https://leetcode.com/problems/sliding-window-maximum/
 */

import java.util.ArrayDeque;
import java.util.Deque;

class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int n = nums.length;

        // handle null ip cases
        if (nums == null || k <= 0)
            return new int[0];

        int[] res = new int[n - k + 1];
        int j = 0;

        Deque<Integer> dq = new ArrayDeque<>();

        // process the first k ele :
        for (int i = 0; i < k; i++) {

            // check for the useless ele which are present in the curr range
            while (!dq.isEmpty() && nums[i] >= nums[dq.peekLast()])
                dq.removeLast();

            // add the new ele
            dq.addLast(i);
        }

        // process the rem n-k ele
        for (int i = k; i < n; i++) {
            res[j++] = nums[dq.peek()]; // max ele in the curr window

            while (!dq.isEmpty() && dq.peek() <= i - k)
                dq.removeFirst();

            // remove the useless ele
            while (!dq.isEmpty() && nums[i] >= nums[dq.peekLast()])
                dq.removeLast();

            dq.addLast(i);
        }

        // add the max ele
        res[j++] = nums[dq.peek()];
        return res;
    }
}