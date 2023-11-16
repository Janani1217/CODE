A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).

For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) 
at odd positions are prime. However, "3245" is not good because 3 is at an even index but is not even.

Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 109 + 7.
A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.

 

Example 1:

Input: n = 1
Output: 5
Explanation: The good numbers of length 1 are "0", "2", "4", "6", "8".


Approach : 
Step by Step clear Explanation with Pictures | O(logN)



class Solution {

    public int mod = (int)1e9+7;

    public int countGoodNumbers(long n) {
        long firstpow = (n%2==0 ? n/2 : (n/2)+1);  // for 5
        long secpow = n/2; // for 4

        long multiply_1 = power(5, firstpow);
        long multiply_2 = power(4, secpow);

        long ans = 1;

        ans = (ans * multiply_1) % mod;
        ans = (secpow != 0) ? (ans * multiply_2) % mod : ans;
    
        return (int)(ans % mod);
    }

    public long power(long x, long y) {
        long temp;

        if(y==0)
            return 1;

        temp = power(x, y/2);

        if(y%2 == 0)
            return (temp*temp)%mod;
        return (x * temp * temp)%mod;
    }
}
