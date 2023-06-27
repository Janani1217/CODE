/*
 * https://www.codingninjas.com/studio/problems/allocate-books_1090540?leftPanelTab=0
 */

import java.util.ArrayList;

public class max_allocation_books {
    public static boolean isPossible(ArrayList<Integer> arr, int target, int m, int n) {
        int count = 1;
        int page_sum = 0;

        for (int i = 0; i < n; i++) {
            if (page_sum + arr.get(i) <= target) {
                page_sum += arr.get(i);
            } else {
                count++;
                if (count > m || arr.get(i) > target) {
                    return false;
                }
                page_sum = arr.get(i);
            }
        }
        return true;
    }

    public static int findPages(ArrayList<Integer> arr, int n, int m) {
        // Write your code here.
        int s = 0;
        int sum = 0;
        int ans = -1;

        // find the search space
        for (int i = 0; i < n; i++) {
            sum += arr.get(i);
        }

        int e = sum;
        int mid = s + (e - s) / 2;

        if (m > n)
            return -1;

        while (s <= e) {
            // System.out.println( "mid = " + mid);
            if (isPossible(arr, mid, m, n)) {
                // System.out.println( "poss");
                ans = mid;
                e = mid - 1;
            } else {
                // System.out.println( "not poss");
                s = mid + 1;
            }
            mid = s + (e - s) / 2;
        }

        return ans;
    }
}