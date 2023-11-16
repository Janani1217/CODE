Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000


Binary Exponentiation (Recursive)

1. x^n = x is multiplied n times to get the answer.
2. so if 2^100 => 2 is multiplied 100 times to get ans => 100 multiplications are needed.
3. this is linear approach ~ O(N) time.
4. With binary expo , we can get using logN.

Approach : 

at each step , this x^n is divided into : 
-> (x * x) ^ n/2;  (if n is even)
-> (x * (x*x) ^ (n-1)/2);  (if n is odd : removed one x in the beginning)

Observation : 

1. so with this , if 2^100 is given , linear approach = 100 multiplications
2. binary expo -> 10 multiplications, at each step : n / 2.




CODE : recursive

class Solution {
    private double binaryExpo(double x, long n) {
        // base case :
        if(n == 0)
            return 1;
        
        if(n < 0)
            return 1.0/binaryExpo(x, -1*n);

        // for even power : 
        if(n%2 == 0){
            return binaryExpo(x*x , n/2);
        }else {
            return x * binaryExpo(x*x, (n-1)/2);
        }
    }
    public double myPow(double x, int n) {
        return binaryExpo(x, n);
    }
}


CODE : iterative  :

class Solution {
    private double binaryExpo(double x, long n) {
        // base case :
        if(n == 0)
            return 1;
        
        if(n < 0){ // if power is negative
            n = -1 * n; //(making n positive)
            x = 1.0/x;
        }
        
        double ans = 1;

        // for even power : 
        while(n != 0) {
            if(n%2 == 1) { // it has to come to this point at any point in the mult.
                ans = ans * x;
                n = n-1;
            }
            x = x*x;
            n = n/2; 
        }
        return ans;
    }
    public double myPow(double x, int n) {
        return binaryExpo(x, n);
    }
}
