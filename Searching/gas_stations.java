You are given an integer array stations that represents the positions of the gas stations on the x-axis. 
You are also given an integer k.

You should add k new gas stations. You can add the stations anywhere on the x-axis, and not necessarily on an integer position.

Let penalty() be the maximum distance between adjacent gas stations after adding the k new stations.

Return the smallest possible value of penalty(). Answers within 10-6 of the actual answer will be accepted.

 

Example 1:

Input: stations = [1,2,3,4,5,6,7,8,9,10], k = 9
Output: 0.50000




class Solution {
    private boolean verify(double d, int[]arr, int k){
        int n = arr.length;
        int cnt = 0; // to cnt the total no. of new stations that can be added in btw 2 stations present

        for(int i=0; i<n-1; i++) { // iterating thr pair , so till n-1
            cnt += ((int)(arr[i+1] - arr[i])/d); // total number of possible stations which can come in between these 2 stations : so curr_dist / D.
        }

        return cnt <= k; // if the total number of stations are <= required : return true
    }
    public double minmaxGasDist(int[] stations, int k) {
        int n = stations.length;
        double l = 0;
        double h = 1e5;

        while(h-l > 1e-6) { // smallest positive number = 0.000001
            double m = l + (h-l)/2;
            if(verify(m, stations, k))
                h = m;
            else
                l = m; 
        }

        return l;
    }
}
