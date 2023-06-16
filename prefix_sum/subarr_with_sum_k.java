package prefix_sum;

/*
 * Given an array of integers nums and an integer k, return the total number of 
 * subarrays whose sum equals to k.
    A subarray is a contiguous non-empty sequence of elements within an array.

    https://leetcode.com/problems/subarray-sum-equals-k/description/
 */
public class subarr_with_sum_k {
    public int subarraySum(int[] nums, int k) {
        int n = nums.length;
        int ps[] = new int[n];
        ps[0] = nums[0];

        // find prefix sum
        for (int i = 1; i < n; i++) {
            ps[i] = nums[i] + ps[i - 1];
        }

        int count = 0;
        Map<Integer, Integer> mp = new HashMap<>();
        mp.put(0, 1);

        for (int i = 0; i < n; i++) {
            int cs = ps[i];
            if (mp.containsKey(cs - k)) {
                count = count + mp.get(cs - k);
            }
            if (mp.containsKey(cs)) {
                mp.put(cs, mp.get(cs) + 1);
            } else {
                mp.put(cs, 1);
            }
        }
        return count;
    }
}
