import java.util.HashSet;

/*
 * Given an unsorted array of integers nums, return the length of the 
 * longest consecutive elements sequence.
 * 
 * You must write an algorithm that runs in O(n) time.
 * 
 * Input: nums = [100,4,200,1,3,2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. 
 * Therefore its length is 4.
 * 
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 * 
 */

public class longest_consec_seq {
    /*
     * class Solution {
     * public int longestConsecutive(int[] nums) {
     * int n = nums.length;
     * Map<Integer, Boolean> mp = new HashMap<>();
     * int maxlen = (n > 0) ? 1 : 0;
     * 
     * // add ele into hashset
     * for (int i = 0; i < n; i++) {
     * mp.put(nums[i], false);
     * }
     * int currlen = 0;
     * 
     * for (int i = 0; i < n; i++) {
     * int currVal = nums[i];
     * currlen = 1;
     * 
     * if (mp.get(currVal) == false) {
     * // ele is not yet processed
     * mp.put(currVal, true);
     * 
     * if (mp.containsKey(currVal - 1)) {
     * // check if its prev ele is present or not
     * 
     * while (mp.containsKey(currVal - 1)) {
     * currlen = currlen + 1;
     * currVal = currVal - 1;
     * mp.put(currVal, true);
     * }
     * // loop has ended
     * maxlen = Math.max(maxlen, currlen);
     * currlen = 1;
     * } else {
     * // this ele can start a chain
     * if (mp.containsKey(currVal + 1)) {
     * while (mp.containsKey(currVal + 1)) {
     * currlen = currlen + 1;
     * currVal = currVal + 1;
     * mp.put(currVal, true);
     * }
     * // loop has ended
     * maxlen = Math.max(maxlen, currlen);
     * currlen = 1;
     * }
     * }
     * }
     * }
     * return maxlen;
     * }
     * }
     */

    // 2nd approach :: less TC :

    public int longestConsecutive(int[] nums) {
        // Approach: Using HashSet, T.C:O(n), S.C: O(n)

        // initialize a set
        HashSet<Integer> s = new HashSet<>();
        // add elements to the set
        for (int num : nums) {
            s.add(num);
        }
        // initialize the longest
        int longest = 0;

        // traverse
        for (int n : nums) {
            /*
             * if the index value-1 is not present in our set, that means
             * that is may be the starting index of the sequence
             */
            if (!s.contains(n - 1)) {
                // initialize the length of the sequence
                int length = 0;
                // traverse and count how many values are consequtive
                while (s.contains(n + length)) {
                    length += 1;
                }
                // find the max
                longest = Math.max(longest, length);
            }
        }
        return longest;
    }

}
