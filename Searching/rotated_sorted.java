
public class rotated_sorted {
    public int search(int[] nums, int target) {
        int n = nums.length;
        int s = 0, e = n - 1;

        while (s < e) {
            int m = s + (e - s) / 2;

            if (nums[m] >= nums[0]) {
                s = m + 1;
            } else
                e = m;
        }
        return s;
    }
}
