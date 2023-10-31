public class Solution {
    public static String solve(String s1, String s2, int n, int m) {
        // bc : 
        int[][] dp = new int [n+1][m+1];

        // form the dp matrix
        for(int i=n-1; i>=0; i--) {
            for(int j=m-1; j>=0; j--) {
                if(s1.charAt(i) == s2.charAt(j))
                    dp[i][j] = 1 + dp[i+1][j+1];
                else 
                    dp[i][j] = Math.max(dp[i+1][j] , dp[i][j+1]);
            }
        }
        int i=0 , j=0;
        StringBuilder lcs = new StringBuilder();

        while(i < n && j < m) {
            if(s1.charAt(i) == s2.charAt(j)) {
                lcs.append(s1.charAt(i));
                i++;
                j++;
            } else if(dp[i+1][j] > dp[i][j+1])
                i++;
            else 
                j++;
        }
        return lcs.toString();
        
    }
    public static String findLCS(int n, int m, String s1, String s2){
        // Write your code here.

        return solve(s1, s2, n, m);
        
    }
}
