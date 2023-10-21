class Solution {
    public boolean search(int[] nums, int target) {
        int n = nums.length;
        int s = 0;
        int e = n-1;
        int m = s + (e-s)/2;

        while(s <= e) {
            if(nums[m] == target)
                return true;

            if(nums[m] == nums[s] && nums[m] == nums[e]) {
                s++;
                e--;
                continue;
            }

            if(nums[m] >= nums[s]) {
                // first half
                if(target >= nums[s] && target < nums[m]) {
                    e = m-1 ;
                }else
                    s = m+1;
            }else {
                // second half
                if(target > nums[m] && target <= nums[e])
                    s = m+1;
                else
                    e = m-1;
            }

            m = s + (e-s)/2;
        }

        return false;
    }
}