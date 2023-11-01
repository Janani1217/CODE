
Best Time to Buy and Sell Stock III
  
You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete at most two transactions.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).



  

class Solution {
    public int solvemem(int[] prices, int dp[][][], int n, int ind, int buy, int cap) {
        // base case :
        if(ind == n || cap == 0)
            return 0;

        if(dp[ind][buy][cap] != -1)
            return dp[ind][buy][cap];
        
        int profit = 0;

        // cap will only decrese when transaction completed after sell
        if(buy == 0) {
            // we can buy the stock on this day :
            profit = Math.max(-prices[ind] + solvemem(prices, dp, n, ind+1, 1, cap) , solvemem(prices, dp, n, ind+1, 0, cap));
        } else {
            // we can sell the stock on this day :
            profit = Math.max(+prices[ind] + solvemem(prices, dp, n, ind+1, 0, cap-1) , solvemem(prices, dp, n, ind+1, 1, cap));
        }

        return dp[ind][buy][cap] = profit;
    }

    public int solveTab(int[] prices, int dp[][][], int n) {
        
        // if ind has reached n : put 0
        /* bc understanding : 
        for(int buy=0; buy<=1; buy++) {
            for(int cap=0; cap<=2; cap++) {
                dp[n][buy][cap] = 0;
            }
        }

        for(int buy=0; buy<=1; buy++) {
            for(int ind=0; ind<n; ind++) {
                dp[ind][buy][0] = 0;
            }
        }
        */

        int profit = 0;

        for(int ind=n-1; ind>=0; ind--) {
            for(int buy=0; buy<=1; buy++) {
                for(int cap=1; cap<=2; cap++) {
                    if(buy == 0) {
                        // we can buy on this day
                        profit = Math.max(-prices[ind] + dp[ind+1][1][cap] , dp[ind+1][0][cap]);
                    }
                    if (buy == 1){
                        // we can sell stocks on this day 
                        profit = Math.max(prices[ind] + dp[ind+1][0][cap-1] , dp[ind+1][1][cap]);
                    }
                    dp[ind][buy][cap] = profit;
                }
            }
        }
        return dp[0][0][2];  /****/
    }
    public int maxProfit(int[] prices) {
        int n = prices.length;

        // 3d DP 
        // 1 : index of the days = n values
        // 2 : should buy or not : 0 = buy , 1 = sell = 2 values
        // 3 : no. transactions = 3 values : 0, 1, 2

        int[][][] dp = new int[n+1][2][3];
        return solveTab(prices, dp, n);
    }
}
