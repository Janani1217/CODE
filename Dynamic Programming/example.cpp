/*
Convert below recr function to Dp
*/

#include <iostream>
#include <vector>
using namespace stad;

// given a recr solution
int solveRec(vector<int> nums, int x)
{
    if (x == 0)
        return 0;
    if (x < 0)
        return INT_MAX;

    int mini = INT_MAX;
    for (int i = 0; i < nums.size(); i++)
    {
        int ans = solve(nums, x - nums[i]);
        if (ans != INT_MAX)
        {
            mini = min(mini, ans);
        }
    }
    return mini;
}

/*
Following the top up approach : jjust store the values obtained :
1.  Type of dp arr : 1D : only 1 var x is changed in recr func
2.  range of x : value sent for x till 0(bc) : x->0
3.  currently create dp arr : vector<int>dp(x,-1)
4.  check if solution exist : return if yes
*/

int solveMem(vector<int> nums, int x, vector<int> &dp)
{
    if (x == 0)
        return 0;
    if (x < 0)
        return INT_MAX;

    if (dp[x] != -1)
        return dp[x];

    int mini = INT_MAX;
    for (int i = 0; i < nums.size(); i++)
    {
        int ans = solve(nums, x - nums[i], dp);
        if (ans != INT_MAX)
        {
            mini = min(mini, ans);
        }
    }
    return dp[x] = mini;
}

/*
Following the bottom up approach : remove recr and put for loop :
1.  put dp arr as it is
2.  update base cases
3.  range of loop : val of x : 0->x : reverse of top-down
4.  in the loop copy the mem logic and change values acc in recr call
*/

int solveTab(vector<int> nums, int x, vector<int> &dp)
{
    // we dont ahve negative indexs in dp arr : so no need to do anything
    dp[0] = 0;

    int mini = INT_MAX;
    for (int i = 1; i < x; i++)
    {
        int ans = dp[x - nums[i]];
        if (ans != INT_MAX)
        {
            mini = min(mini, ans);
        }
    }
    dp[x] = mini;
    return dp[x];
}

/*
Optimize SC :
1.  can we remove dp arr : curr ans depends on : dp[x - nums[i]]
here we cant.
*/

int main()
{
    int x = 4;
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(9);
    nums.push_back(7);

    int ansRec = solveRec(nums, x);

    vector<int> dp(x + 1, -1);
    int ansMem = solveMem(nums, x, dp);

    // value to be filled for dp arr : question dependent : here INT_MAX

    vector<int> dpTab(x + 1, INT_MAX);
    int ansTab = solveTab(nums, x, dpTab);
}