
public class count_of_target {
    public class Solution {
        public static int solveFirst(int arr[], int n, int x) {
            int s = 0, e = n - 1;
            int ans = -1;

            while (s <= e) {
                int m = s + (e - s) / 2;
                if (arr[m] == x) {
                    // got some occurance
                    ans = m;
                    e = m - 1;
                } else if (arr[m] > x) {
                    e = m - 1;
                } else
                    s = m + 1;
            }
            return ans;
        }

        public static int solveLast(int arr[], int n, int x) {
            int s = 0, e = n - 1;
            int ans = -1;

            while (s <= e) {
                int m = s + (e - s) / 2;
                if (arr[m] == x) {
                    // got some occurance
                    ans = m;
                    s = m + 1;
                } else if (arr[m] > x) {
                    e = m - 1;
                } else
                    s = m + 1;
            }
            return ans;
        }

        public static int count(int arr[], int n, int x) {
            // Your code goes here
            int first = solveFirst(arr, n, x);
            int last = solveLast(arr, n, x);
            if (first == -1 || last == -1)
                return 0;
            return last - first + 1;
        }
    }
}
