package Sorting;

/*
 *  Given an array of integers. Find the Inversion Count in the array. 

Inversion Count: For an array, inversion count indicates how far (or close) 
the array is from being sorted. If array is already sorted then the inversion 
count is 0. If an array is sorted in the reverse order then the inversion count
is the maximum. 

Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
 

Example 1:

Input: N = 5, arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 
has three inversions (2, 1), (4, 1), (4, 3).

*/

import java.util.*;

public class count_inversions {
    static long merge(long arr[], int l, int r, int m) {
        // Left subarray
        long[] left = Arrays.copyOfRange(arr, l, m + 1);

        // Right subarray
        long[] right = Arrays.copyOfRange(arr, m + 1, r + 1);

        int i = 0, j = 0, k = l, swaps = 0;

        while (i < left.length && j < right.length) {
            if (left[i] <= right[j])
                arr[k++] = left[i++];
            else {
                arr[k++] = right[j++];
                swaps += (m + 1) - (l + i);
            }
        }
        while (i < left.length)
            arr[k++] = left[i++];
        while (j < right.length)
            arr[k++] = right[j++];
        return swaps;
    }

    static long divideArr(long arr[], int s, int e) {
        if (s >= e)
            return 0;

        int m = s + (e - s) / 2;

        long count = 0;

        count += divideArr(arr, s, m);
        count += divideArr(arr, m + 1, e);

        count += merge(arr, s, e, m);

        return count;
    }

    public static long getInversions(long arr[], int n) {
        // Write your code here.
        long count = 0;

        // follow merge sort
        if (n == 0)
            return count;

        count = divideArr(arr, 0, n - 1);
        return count;
    }
}