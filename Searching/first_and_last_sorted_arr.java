package Searching;

public class first_and_last_sorted_arr {
    class Solution {
        public int[] searchRange(int[] nums, int target) {
            int n = nums.length;
            int[] res = new int[2];
            res[0] = -1;
            res[1] = -1;

            // given a sorted arr : we go with binary search approach : log n
            int leftans = -1;
            int rightans = -1;
            int s = 0;
            int e = n - 1;

            // find left ans
            while (s <= e) {
                int mid = s + (e - s) / 2;

                if (nums[mid] == target) {
                    // some occurance is found
                    leftans = mid;
                    e = mid - 1;
                } else if (nums[mid] > target) {
                    e = mid - 1;
                } else
                    s = mid + 1;
            }
            res[0] = leftans;

            s = 0;
            e = n - 1;
            // find right ans
            while (s <= e) {
                int mid = s + (e - s) / 2;

                if (nums[mid] == target) {
                    rightans = mid;
                    s = mid + 1;
                } else if (nums[mid] > target) {
                    e = mid - 1;
                } else
                    s = mid + 1;
            }
            res[1] = rightans;

            return res;
        }
    }
}
