You are given an integer array bloomDay, an integer m and an integer k.

You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.





class Solution {
    public boolean verifyDay(int day, int[]arr, int m, int k) {
        int cnt_flowers = 0;
        int cnt_boq = 0;
        int n = arr.length;

        for(int i=0; i<n; i++) {
            if(arr[i] <= day)
                cnt_flowers++;
            else{
                // got a bigger day , so incr the boq count:
                cnt_boq += (cnt_flowers/k);
                cnt_flowers = 0;
            }
        }
        cnt_boq += (cnt_flowers/k);
        return cnt_boq >= m;
    }

    public int minDays(int[] bloomDay, int m, int k) {
        int l = bloomDay[0];
        int h = bloomDay[0];
        int n = bloomDay.length;

        if(n < (long)m*k) //**** long  */
            return -1;

        for(int i=0; i<n; i++){
            l = Math.min(l, bloomDay[i]);
            h = Math.max(h, bloomDay[i]);
        }

        while(l <= h) {
            int mid = l + (h-l)/2;
            if(verifyDay(mid, bloomDay, m, k)){
                // this day is satisfying : 
                h = mid - 1;
            }else{
                l = mid+1;
            }
        }
        return l;
    }
}
