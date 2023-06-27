/*

Aggresive cows :

https://www.codingninjas.com/studio/problems/aggressive-cows_1082559?leftPanelTab=0import java.util.Arrays;
*/
public class aggresive_cows {
    public static boolean isPoss(int[] stalls, int k, int mid) {
        int count_cows = 1;
        int last_pos = stalls[0]; // first cow is placed here

        for (int i = 0; i < stalls.length; i++) {
            if (stalls[i] - last_pos >= mid) {
                count_cows++;
                if (count_cows == k) {
                    return true;
                }
                last_pos = stalls[i];
            }
        }
        return false;
    }

    public static int bs(int[] stalls, int k, int s, int e) {
        int m = s + (e - s) / 2;
        int ans = -1;

        while (s <= e) {
            if (isPoss(stalls, k, m) == true) {
                // need to find the max number
                ans = m;
                s = m + 1;
            } else {
                e = m - 1;
            }
            m = s + (e - s) / 2;
        }
        return ans;
    }

    public static int aggressiveCows(int[] stalls, int k) {
        // Write your code here.
        int n = stalls.length;
        Arrays.sort(stalls);

        // search space found
        int s = 0;
        int e = -1;

        for (int i = 0; i < n; i++) {
            e = Math.max(e, stalls[i]);
        }

        // find the possible number with bs
        int ans = bs(stalls, k, s, e);
        return ans;

    }
}
