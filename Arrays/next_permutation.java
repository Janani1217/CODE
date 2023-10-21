/*
 *   https://leetcode.com/problems/next-permutation/solutions/13994/readable-code-without-confusing-i-j-and-with-explanation/
 * 
 */

public class next_permutation {
    public int findPivotIndex(int[] nums, int n) {
        for (int i = n - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1])
                return i;
        }
        return 0;
    }

    public int findNextGreaterIdx(int[] nums, int n, int pivot) {
        for (int i = n - 1; i > 0; i--) {
            if (nums[i] > nums[pivot])
                return i;
        }
        return -1;
    }

    public void swap(int[] nums, int pivot, int succ) {
        int t = nums[pivot];
        nums[succ] = nums[pivot];
        nums[pivot] = t;
    }

    public void reverseSuffix(int[] nums, int n, int s) {
        int e = n - 1;
        while (s < n) {
            swap(nums, s++, e--);
        }
    }

    public void nextPermutation(int[] nums) {
        int n = nums.length;

        // 1. find the pivot index : decr suffix next ele
        int pivot_idx = findPivotIndex(nums, n);

        // 2. find the next grester ele in suffix for pivot
        if (pivot_idx != -1) {
            int succ_idx = findNextGreaterIdx(nums, n, pivot_idx);

            // 3. swap
            swap(nums, pivot_idx, succ_idx);
        }

        // 4. reverse the suffix
        reverseSuffix(nums, n, pivot_idx + 1);
    }
}
