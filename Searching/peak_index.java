/*
 * Peak Index in a Mountain Array
 
 An array arr a mountain if the following properties hold:

arr.length >= 3

There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i] 
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]


Given a mountain array arr, 
return the index i such that : 
arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].

You must solve it in O(log(arr.length)) time complexity.


Approach :

1. using binary search 
2. since peak > left_ele && peak > right_ele
3. based on this the condition is written

    if( mid < mid+1) {
        // its not a peak ele and need t0 move ahead in the arr
        s = mid + 1;
    }

    else : 1. mid > mid + 1
           2. mid > mid + 1 && mid > mid - 1
           
           in both of these cases , e = mid;

4. here e = mid and not mid -1 beacuse , we will loose the peak ele
   during the 2nd condition if is present.

5. so the ans / peak is always stored in the e variable.
6. return e;

 */

public class peak_index {
    class Solution {
        public int peakIndexInMountainArray(int[] arr) {
            int n = arr.length;
            int s = 0;
            int e = n - 1;
            while (s < e) {
                int m = s + (e - s) / 2;
                if (arr[m] < arr[m + 1])
                    s = m + 1;
                else
                    e = m;
            }
            return e;
        }
    }
}
