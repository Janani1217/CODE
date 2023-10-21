/*
 *  Selection sort : 
 * 
 *  select the min ele and swap !!
 * 
 * 1. traverse the arr , swap the curr index value with the min value present in 
 *    its right.
 * 2. if n = 5 ele in the arr , then total 4 rounds are run to make the arr sorted.
 * 3. in-place algo : doesnt need any auxiliary space.
 * 4. Comarison based sorting technique
 * 5. Unstable algo : doesnt retain the order after the sorting.
 * 
 * .........................................................................................
 * 
 *  TC : O(n2)
 *  SC : O(1)
 * 
 * .........................................................................................
 * 
 *  Best case : already sorted arr as ip : O(n2) : because we need to compare all ele
 *  Worst case : O(n2)
 * 
 * .........................................................................................
 * 
 *  USECASE ::
 *  When the arr size is very small .  
 *  
 * .........................................................................................
 * 
 *   
 */
package Sorting;

public class selection_sort {
    public void swapUtils(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    public int[] sortArray(int[] nums) {
        int n = nums.length;

        for (int i = 0; i < n - 1; i++) {
            int min_index = -1;
            int min_val = nums[i];

            for (int j = i + 1; j < n; j++) {
                if (nums[j] < min_val) {
                    min_val = nums[j];
                    min_index = j;
                }
            }
            if (min_index != -1) {
                // swap the ele
                swapUtils(nums, i, min_index);
            }
        }

        return nums;
    }
}
