/*
 * Given an array having both positive and negative integers. 
 * The task is to compute the length of the largest subarray with sum 0.
 * 
 * Input:
    N = 8
    A[] = {15,-2,2,-8,1,7,10,23}
    Output: 5
    Explanation: The largest subarray with
    sum 0 will be -2 2 -8 1 7.    
    
    
 */

public class longest_subarr_with_sum_0 {
    // given subarray and sum = use prefix sum
    int maxLen(int arr[], int n) {
        int maxlen = 0;

        // first val = ps ele
        // sec val = ps index
        Map<Integer, Integer> mp = new HashMap<>();

        // cal the prefix sum
        int ps[] = new int[n];
        ps[0] = arr[0];

        for (int i = 1; i < n; i++) {
            ps[i] = ps[i - 1] + arr[i];
        }
        /*
         * for(int i=0; i<ps.length; i++) {
         * System.out.println("ps = " + ps[i]);
         * }
         */

        // traverse through ps and find if we have a ps. = 0
        // cal the length = curr index - ps[0]

        mp.put(0, -1);

        // System.out.println("mp.get(0) =" +mp.get(0));

        for (int i = 0; i < ps.length; i++) {
            int currVal = ps[i];

            if (mp.containsKey(currVal)) {
                maxlen = Math.max(maxlen, i - mp.get(currVal));
                // System.out.println("i =" + i);
                // System.out.println("mp.get(currVal) =" +mp.get(currVal));
            } else {
                mp.put(currVal, i);
            }
        }
        return maxlen;
    }
}
