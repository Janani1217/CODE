/*
Problem statement :
Rod Cutting :

Given a rod of length n
You can cut the rod in 3 sizes : A, B, C
Return Maximize the no. of cuts.
If no cuts possible : -1 return

Eg:
n = 17
A = 10
B = 11
C = 3

............................................................................................................

Approach :
1.  So we initially have n length and 3 options to cut
2.  So everytime , we check dor the 3 options , if possible to cut further
    or not.
3.  if we use A for the cut , rem = n-A . similarly for other cases too.

............................................................................................................

*/

#include <iostream>
#include <vector>
using namespace std;

int solveRec(int n, int a, int b, int c)
{
    // base case :
    if (n == 0)
        return 0;

    /*

    if the value of n goes below 0, then we cant return any ans : but if we return her -1
    the the situation was , returning -1 from suppose all 3 options

    in the last point , we take max of 3 options and add +1
    so output from this comes as 0 -> which shows that it forms an answer
    But actually ans should not be formed -> wrong calculation happened

    that is why we took INT_MIN , if we run out of the range where we
    cannot get ans in case if we go below 0.

    */
    if (n < 0)
        return INT_MIN;

    // select 3 options acc to condition:
    int op1 = solveRec(n - a, a, b, c);
    int op2 = solveRec(n - b, a, b, c);
    int op3 = solveRec(n - c, a, b, c);

    int ans1 = max(op1, op2);
    int ans2 = max(ans1, op3);

    return 1 + ans2;
}

/*
Rec + Mem :
1.  type of dp : 1D
2.  return stored val
3.  store final val
4.  return dp[n]
*/

int solveMem(int n, int a, int b, int c, vector<int> &dp)
{
    if (n == 0)
        return 0;

    if (n < 0)
        return INT_MIN;

    if (dp[n] != -1)
        return dp[n];

    int op1 = solveMem(n - a, a, b, c, dp);
    int op2 = solveMem(n - b, a, b, c, dp);
    int op3 = solveMem(n - c, a, b, c, dp);

    dp[n] = 1 + max(op1, max(op2, op3));
    return dp[n];
}

/*
Bottom-up :
1.  1D dp arr
2.  update bc
3.  range of n : 0 -> n
4.  return dp[n]
*/

int solveTab(int n, int a, int b, int c, vector<int> &dp)
{
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        int op1 = (i - a >= 0) ? dp[i - a] : INT_MIN;
        int op2 = (i - b >= 0) ? dp[i - b] : INT_MIN;
        int op3 = (i - c >= 0) ? dp[i - c] : INT_MIN;

        dp[i] = 1 + max(op1, max(op2, op3));
    }
    return dp[n];
}

int main()
{
    int n = 17;
    int a = 10, b = 11, c = 3;
    int ansRec = solveRec(n, a, b, c);

    vector<int> dpMem(n + 1, -1);
    int ansMem = solveMem(n, a, b, c, dpMem);
    cout << ansMem << endl;

    vector<int> dpTab(n + 1, 0);
    int ansTab = solveTab(n, a, b, c, dpTab);
    cout << ansTab << endl;
}