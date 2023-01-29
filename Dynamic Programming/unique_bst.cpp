/*
Problem statement :
Given an input n , return the number of structurally unique bst which has
exactly n nodes.

n = 3
Op: 5
Look at leetcode for examples
And Notebook for complete description visually

............................................................................................

Approach:

1.  If we have n = 0, then empty tree with root = null will be the poss
    structure BST , so ans = 0;
2.  If n = 1, only 1 comb poss, so ans = 1
3.  If n = 2, then 2 structurally unique BST poss , so ans = 2;

    These will form the bc

4.  Then every node within the range of 1 -> n is considered as root and the
    left and right tree ans are calc and then added up to get what is the ans
    for the current root node

5.  So if we take curr root node as 'i' which can vary from 1 -> n.
    For this we can take a loop
    And for every root i, we can apply the same formula to get its left and right ans

    f(i) = f(i-1) * f(n-i);

6.  This mult is done to get the entire range of combinations possible in the whole BST

............................................................................................

*/

#include <iostream>
#include <vector>
using namespace std;

int solveRec(int n)
{
    // base case
    if (n == 0 || n == 1)
        return 1;

    if (n == 2)
        return 2;

    // remaining case
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        // consider i as root
        int leftAns = solveRec(i - 1);
        int rightAns = solveRec(n - i);
        ans += leftAns * rightAns;
    }
    return ans;
}

// mem
int solveMem(int n, vector<int> &dp)
{
    // bc
    if (n <= 1)
        return 1;

    if (n == 2)
        return 2;

    // rem
    if (dp[n] != -1)
    {
        return dp[n];
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += solveMem(i - 1, dp) * solveMem(n - i, dp);
    }
    dp[n] = ans;
    return ans;
}

int solveTab(int N, vector<int> &dp)
{
    // update bc:
    dp[0] = dp[1] = 1;

    // take out range of N => 0 to n
    for (int n = 2; n <= N; n++)
    {
        // rem things copy paste
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans += dp[i - 1] * dp[n - i];
        }
        dp[n] = ans;
    }

    return dp[N];
}

int main()
{
    int n = 3;

    vector<int> dp(n + 1, 0);

    int ans = solveTab(n, dp);
    cout << ans << endl;
}