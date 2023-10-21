/*
 * Reverse Pairs
 * 
Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where:

0 <= i < j < nums.length and
nums[i] > 2 * nums[j].
 

Example 1:

Input: nums = [1,3,2,3,1]
Output: 2
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1
 
 */

package Sorting;

public class reverse_pairs {
    class Solution {
        public int reversePairs(int[] nums) {
            return mergeSort(nums, 0, nums.length - 1);
        }

        private int mergeSort(int[] nums, int start, int end) {
            if (start >= end)
                return 0;

            int mid = start + (end - start) / 2;
            int count = mergeSort(nums, start, mid) + mergeSort(nums, mid + 1, end);

            // Count the pairs across the two halves
            int left = start;
            int right = mid + 1;

            while (left <= mid && right <= end) {
                if ((long) nums[left] > 2 * (long) nums[right]) {
                    count += mid - left + 1;
                    right++;
                } else {
                    left++;
                }
            }

            // Merge the two sorted halves
            merge(nums, start, mid, end);
            return count;
        }

        private void merge(int[] nums, int start, int mid, int end) {
            int[] temp = new int[end - start + 1];
            int i = start;
            int j = mid + 1;
            int k = 0;

            while (i <= mid && j <= end) {
                if (nums[i] <= nums[j]) {
                    temp[k++] = nums[i++];
                } else {
                    temp[k++] = nums[j++];
                }
            }

            while (i <= mid) {
                temp[k++] = nums[i++];
            }

            while (j <= end) {
                temp[k++] = nums[j++];
            }

            System.arraycopy(temp, 0, nums, start, temp.length);
        }
    }

}
