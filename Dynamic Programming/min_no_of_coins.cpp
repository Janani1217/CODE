/*
******* NEW PATTERN *********
Problem statement : INCOMPLETE - REFER DP 2 VIDEO LAST
Min no. of coins :

Given an input arr and a target
Return min. no. of elements you have to take to reach the target

Eg:
arr = [1,2,3]
target = 7

....................................................................................

Approach :

1.  Here also either include one ele or exclude it

2.  But there is a set of arr ele given, so multiple no. of recr calls will be
    made, but we cannot write it manually
    So create a loop for it.

3.  In other prblms, we were having fixed no. of options for each element
    But here , we dont have fixed no. of options, we have to try for how
    many no. of ele present in the arr : which could vary from 0 - 1000
    also
    =>
    so whichever ele we are currently standing on reg the target
    pending , we are trying on with all the ele present in the loop to get
    the remaining target amount.

4.  Hence for that purpose need to create a for loop to get the ans for
    each element.

5.  Now , for every recr call made , we will get the ans which could be ->
    valid or invalid

6.  So for valid (>= 0) -> 0 or +ve number
    For invalid (<0) -> -1 if supose we return

7.  Now suppose we get an invalid ans in the recr call, and we didnt have
    any check on that , then it will return -1 + 1  = 0 which turns out to be a
    valid ans which is wrong op.

    So we are not keeping -1 for negative targets, we are return INT_MAX,
    becoz we need to find the min ans

8.  So in the for loop, for every ele we will get a ans, and we have to get
    the min of those ans , so we created mini var

9.  Adding +1 -> bcoz we need to find # of ways to reach target , so when we
    are using an ele , we are adding +1 to the ans.

....................................................................................

*/

#include <iostream>
#include <vector>
using namespace std;

int solveRec(int arr[], int n, int target)
{
    // base case
    if (target == 0)
        return 0;
    if (target < 0)
        return INT_MAX;

    int ans = INT_MAX;
    int mini = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        /*
        if final ans we didnt find the correct one and it crossed 0
        then it will return INT_MAX only , so need to keep a check
        for this
        */
        ans = solveRec(arr, n, target - arr[i]);
        if (ans != INT_MAX)
        {
            mini = min(ans + 1, mini);
        }
    }
    return mini;

    /*
    TC : expo
    SC : O(1)
    */
}

/*
1.  type of dp = 1d -> target val getting changed
2.  store the final ans in dp
3.  return if already present in dp
*/

int solveMem(int arr[], int n, vector<int> &dp, int target)
{
    if (target == 0)
        return 0;

    if (target < 0)
        return INT_MAX;

    // whatever var is changing , that will only format the dp
    if (dp[target] != -1)
        return dp[target];

    int mini = INT_MAX;

    for (int i = 1; i < n; i++)
    {
        int ans = solveMem(arr, n, dp, target - arr[i]);
        if (ans != INT_MAX)
        {
            mini = min(mini, ans + 1);
        }
    }
    dp[target] = mini;
    return mini;
}

/*
1.  update base case
2.
*/

int solveTab(int arr[], int n, vector<int> &dp, int target)
{
    // base case
    dp[0] = 0;

    for (int t = 1; t <= target; t++)
    {
        int mini = INT_MAX;
        for (int i = 1; i < n; i++)
        {
            if (dp[t - arr[i]] > 0 && dp[t - arr[i]] != -1)
            {
                mini = min(mini, dp[t - arr[i]]);
            }
        }
        dp[t] = (mini == INT_MAX) ? -1 : mini;
    }
    return dp[t];
}

int main()
{
    int arr[3] = {1, 2, 3};
    int target = 7;

    int ansRec = solveRec(arr, 3, target);
    int n = 3;
    cout << ansRec << endl;

    vector<int> dp(n, -1);
    int ansMem = solveMem(arr, n, dp, target);

    vector<int> dpTab(target + 1, -1);
    int ansTab = solveTab(arr, n, dpTab, target);

    cout << ansTab << endl;
}