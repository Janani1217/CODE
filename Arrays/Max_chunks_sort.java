/*
 * *******
 * 
 * Max Chunks To Make Sorted :
 * 
 * You are given an integer array arr.
 * We split arr into some number of chunks (i.e., partitions),
 * and individually sort each chunk.
 * 
 * After concatenating them, the result should equal the sorted array.
 * 
 * Return the largest number of chunks we can make to sort the array.
 * 
 * Input: arr = [5,4,3,2,1]
 * Output: 1
 * 
 * Explanation:
 * Splitting into two or more chunks will not return the required result.
 * For example, splitting into [5, 4], [3, 2, 1] will result in
 * [4, 5, 1, 2, 3], which isn't sorted.
 * 
 * Link for reference of approach :
 * https://leetcode.com/problems/max-chunks-to-make-sorted-ii/solutions/2314803/java-explanation/
 * 
*/

class Solution {
    public int maxChunksToSorted(int[] arr) {
        int n = arr.length;

        // step 1 : find the right min ele for each index
        int[] rightMin = new int[n];
        rightMin[n - 1] = arr[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            rightMin[i] = Math.min(rightMin[i + 1], arr[i]);
        }

        // step 2 : declare for curr max ele found till now
        int maxEleTillNow = Integer.MIN_VALUE;
        ;
        int count = 1;

        // step 3 : loop over arr and find the chunk when larger ele on right
        // encountered
        for (int i = 0; i < n - 1; i++) {
            maxEleTillNow = Math.max(maxEleTillNow, arr[i]);
            if (maxEleTillNow <= rightMin[i + 1])
                count++;
        }

        return count;
    }
}