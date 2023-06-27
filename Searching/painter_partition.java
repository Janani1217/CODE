/*
 * https://www.codingninjas.com/studio/problems/painter-s-partition-problem_1089557?leftPanelTab=0
 */

import java.util.ArrayList;

public class painter_partition {
    public static boolean isPartitionPoss(ArrayList<Integer> boards, int mid, int k) {
        int n = boards.size();
        int count = 1;
        int sum = 0;

        for (int i = 0; i < n; i++) {
            if (sum + boards.get(i) <= mid) {
                sum += boards.get(i);
            } else {
                count++;
                if (count > k || boards.get(i) > mid) {
                    return false;
                }
                sum = boards.get(i);
            }
        }
        return true;
    }

    public static int bs(ArrayList<Integer> boards, int k, int s, int e) {
        int ans = -1;
        int m = s + (e - s) / 2;
        while (s <= e) {
            if (isPartitionPoss(boards, m, k) == true) {
                ans = m;
                e = m - 1;
            } else {
                s = m + 1;
            }
            m = s + (e - s) / 2;
        }
        return ans;
    }

    public static int findLargestMinDistance(ArrayList<Integer> boards, int k) {
        // Write your code here.
        int n = boards.size();
        int s = 0;
        int e = 0;

        for (int i = 0; i < n; i++) {
            e += boards.get(i);
        }

        int ans = bs(boards, k, s, e);
        return ans;
    }
}
