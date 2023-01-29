/*
Problem statement :
Max Sum of Non-Adj elements:

Given : input array of elements
[2,1,4,9]
Take always non-adj ele , but the sum should be max
Return that max sum of non-adj elements in the arr.

Op :
6(2,4) ; 10(1,9) ; 11(2,9) ;
So max = 11 : (2,9)
....................................................................................

Approach :
Can solve by include- exclude : find sum in both case , and return max
Include only when immediate previous is not included.

....................................................................................

*/

#include <iostream>
#include <vector>
using namespace std;

int solveRec(vector<int> arr, int currI)
{
    // base case
    if (currI >= arr.size())
        return 0;

    int op1 = arr[currI] + solveRec(arr, currI + 2);
    int op2 = solveRec(arr, currI + 1);

    return max(op1, op2);
}

/*
Top down : add dp arr :
1.  type of dp : 1d : currI changed
    currI range : 0 -> n
2.  return saved ans
3.  copy rem cases
4.  store final ans
*/

int solveMem(vector<int> arr, int currI, vector<int> &dp)
{
    if (currI >= arr.size())
        return 0;

    if (dp[currI] != -1)
        return dp[currI];

    int op1 = arr[currI] + solveRec(arr, currI + 2);
    int op2 = solveRec(arr, currI + 1);

    return dp[currI] = max(op1, op2);
}

/*
Bottom up approach : remove recr call
1.  dp arr
2.  update dp arr with BC : but the bc is >=0 , so index not possible
    so no need of bc updation in dp arr
2.  value of currI = n -> 0

*/

int solveTab(vector<int> arr, vector<int> &dp)
{

    int n = arr.size();

    for (int i = n - 1; i >= 0; i--)
    {
        int op1 = arr[i] + dp[i + 2];
        int op2 = dp[i + 1];
        dp[i] = max(op1, op2);
    }
    // get it from the recr main call
    return dp[0];
}

/*
    SO :
1.  here the op1 depens on dp[i+2]
2.  and op2 depends on dp[i+1]
3.  so if we store both of them in var , then we can exclude dp arr

*/

int solveTabSO(vector<int> arr)
{
    int n = arr.size();
    int prev1 = 0;
    int prev2 = 0;
    int curr = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        int op1 = arr[i] + prev2;
        int op2 = prev1;
        curr = max(op1, op2);
        prev2 = prev1;
        prev1 = curr;
    }
    // get it from the recr main call
    return curr;
}

int main()
{
    vector<int> arr;
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(4);
    arr.push_back(9);
    int currI = 0;

    int ansRec = solveRec(arr, currI);

    // top down : range of currI : n -> 0
    int n = arr.size();
    vector<int> dp(n, -1);
    int ansMem = solveMem(arr, currI, dp);

    // bottom up :
    /*
    in the for loop we are moving from n-1 -> 0 , but in op1
    we are accessing dp[i+2] -> if we are dp[n] , then it will be acessing
    dp[n+2] , so we need to make dp[n+2] size arr.
    */
    vector<int> dpTab(n + 2, 0);
    int ansTab = solveTab(arr, dpTab);

    int ansTabSO = solveTabSO(arr);
    cout << ansTabSO << endl;
}