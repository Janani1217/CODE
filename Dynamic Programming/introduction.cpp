/*
What is Dp ?

It a technique used to solve such problems where :

1.  overlapping subproblems :
    in recursive tree , we have same problems which we solve again and again , eg : in
    factorial problem, so repleated or overlapping sub problems to solve a big
    original problem.

2.  optimal sub structure :
    When our big prblm , optimal solution depends on small sub problem's optimal solutions
    Then that is called Optimal sub structure

............................................................................................................

Those who cannot remember the past are condemned to repeat it .
[When we find out optimal solution of any subproblem , we are going to store it for any future
 repeatable subproblem, that is DP , so that no need to re calculate it , just return the answer]
............................................................................................................

Types of Dp :

1.  Top-Down Approach :
    Recursion + memoization [store the ans for every sub problem]

2.  Bottom-Up Approach :
    Tabulation method : table filling method :
    Go from bottom to top of the solution.
    Eg: in tree : go from leaf to root to update or find the final ans

............................................................................................................

**********************************************
Life Cycle of DP Problem :

1.  Start to solve with the help of recursion
2.  Then add memoization with recursion
3.  Then form bottom up approach
4.  Check if Space Optimization is possible or not
**********************************************

............................................................................................................

*/

/*

Fibbonocci series eg : 0 1 1 2 3 5 8 13 21 34 .... (add prev 2 no.s in series)
Recr relation : f(n) = f(n-1) + f(n-2);

*/

#include <iostream>
#include <vector>
using namespace std;

int solve(int n)
{
    // base case :
    if (n <= 1)
    {
        return n;
    }

    int ans = solve(n - 1) + solve(n - 2);
    return ans;

    /*
    SC : recr depth = O(n)
    TC : R : O(2^n) :  exponential -> bad complexity
    */
}

/*

Here for the above solution the TC : exponential , if we solve using recr relation
for TC.
So its the worst TC.

............................................................................................................

Since we see in this problem , we see overlapping sub problems in the problem.
So we need to apply DP in such prblm.
So store the ans and then return it when again the sub prblm is encountered.

............................................................................................................

So how can we apply DP , on what params?

See in the recursive function , in those args , whose value changes in the recr
call, that will be the no. of Dp : 1D or 2D or 3D .. depends on the changing args
in the call.


So in this eg : we see the value of n is changed in the recr call :
we send (n-1) , (n-2) in the following recr calls, so only 1 arg value is getting
changed -> 1D will be applied

If suppose the actual call is : f(n-2, d+1) -> 2 parms are changed so make 2D

............................................................................................................

Apply DP : recr + mem :

1.  Create a DP array , where we call the recr function in the calling function (here main())
    + pass that arr in function
2.  Store the ans in DP arr
3.  Check if DP arr already has ans , if yes , then return -> has to be checked just after
    the base cases.

............................................................................................................


*/

int solveMem(int n, vector<int> &dp)
{
    // base case :
    if (n <= 1)
    {
        return n;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    int ans = solveMem(n - 1, dp) + solveMem(n - 2, dp);

    // step 2: before every return , just store the ans in dp arr
    dp[n] = ans;
    return ans;

    /*
    SC : dp arr + recr depth = O(n) + O(n)
    TC : R + M : O(n)
    */
}

/*
............................................................................................................

Apply bottom-up approach :

1.  create a dp array
2.  Recr -> base cases analyze -> make changes accordingly in dp array
3.  Look at the range of for loop for changing variables and copy the recr logic here

............................................................................................................
*/

int solveTab(int n)
{
    /*
    step 1 : create dp arr : init with 0 , here no need to check any
    solution availability , so we are init with 0 , since we will be anyhow updating all
    the values
    */
    vector<int> dp(n + 1, 0);

    // step 2 : update dp arr acc to base cases:
    dp[0] = 0;
    dp[1] = 1;

    /*
    step 3 : range for changing var in for loop

    in top down : value of n goes from n->0
    in bottom up : make it reverse for the range

    we already have the values of 0 and 1 in the dp arr as the base cases,
    so start from 2.
    */

    for (int i = 2; i <= n; i++)
    {
        // copy from recr function call and modify acc to dp arr
        int ans = dp[i - 1] + dp[i - 2];
        dp[i] = ans;
    }
    // return whatever value passed in the original function
    return dp[n];

    /*
    SC : dp arr = O(n)
    TC : for loop : O(n)
    */
}

/*
Now can we do space optimization ?
CHECK THE PARAM ON WHICH THE ANSWER OF DP DEPENDS.

Here :

1.  dp[n] depends on dp[n-1] and dp[n-2]
2.  it means the curr value depends on the back 2 values only
3.  so there is no need of creating and storing all the values in arr
4.  so we can have values stored in 3 var : curr, prev1, prev2

*/

int solveTabSO(int n)
{
    int prev1 = 1;
    int prev2 = 0;
    int curr = 0;

    for (int i = 2; i <= n; i++)
    {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;

    /*
    SC : O(1)
    TC : for loop : O(n)   --> HUGE DIFFERENCE IN BOTH -> BEST CASE
    */
}

int main()
{
    int n = 6;
    int ansRec = solve(n);

    // Top-down approach : R + M : step 1 :
    /*
       since we call the func from here , so add DP array here with size n and store -1
       here , if we pass n in the size , then it will create an arr from 0 -> n-1
       but in the solveMem(n) we pass the value of n , which wont exist in the dp arr
       so , how will we acess the ans of n from that dp arr.
       So we have to creat +1 size of dp arr.

       Initialize with -1 , since we are going to check whether the solution is available
       or not , so we have to init with a dummy value = -1

    */
    vector<int> dp(n + 1, -1);
    int ansRecAndMem = solveMem(n, dp);

    /*
    Bottom - up approach :
    Whatever params are present in recr solution , same will be passed , and nothing
    else.
    */
    int ansTabulation = solveTab(n);

    /*
    Do space optimization :
    no need to create an arr of values
    just store previous 2 val in 2 var and 1 curr val in a var
    */

    cout << n << endl;
    int ansTabSO = solveTabSO(n);
    cout << ansTabSO << endl;
}