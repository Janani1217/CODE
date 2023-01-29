/*
Variations :
1.  LIS with adj ele with diff 1
2.  longest arithmetic subseq
3.  LAS with diff
4.  russian dolls

etc...

....................................................................................


Problem statement :
Given 2 strings , find longest common subsequence (order should be same , include
any char, similarly find such common subseq among both str and find the longest
among those subsequences)

s1 = "abc"
s2 = "pbc"
op : "bc"

Subseq of s1 = [{}, a, b, c, ab, ac, bc, abc]
Subseq of s2 = [ {}, p, b, c, pb, bc ,pc, pbc]
common subseq = [ {}, b, c, bc]
longest subseq = [bc] = len = 2

Resolved in leetcode
....................................................................................

Approach :

1.  Take include - exclude approach
2.  Take 2 ptrs pointing to start of both str : i , j
3.  If curr char is match : add 1 and recr call by moving both i+1, j+1
4.  If no match , then 2 options we can get :
    4.1  one ans we can get by excluding i and including j
         make recr call for : i, j+1

    4.2  second by keeping i char and removing j char
         make recr call for : i+1 , j

    Then return the max of both options

5.  Base case , would be , if any of 2 indexes reaches 0, there will be no str
    to compare with the other, so if i==0 and j == 0

....................................................................................
*/

#include <iostream>
#include <vector>
using namespace std;

int solveRec(string s1, string s2, int i, int j)
{
    // base case :
    if (i >= s1.length() || j >= s2.length())
    {
        return 0;
    }

    // if a match
    if (s1[i] == s2[j])
    {
        return 1 + solveRec(s1, s2, i + 1, j + 1);
    }

    int op1 = solveRec(s1, s2, i + 1, j);
    int op2 = solveRec(s1, s2, i, j + 1);
    return max(op1, op2);
}

/*
rec + mem:
1.  type of dp = 2d -> i,j
2.  range of row = s1.length() + 1
    range of col = s2.length() + 1
3.  return if stored
4.  store final ans
*/

int solveMem(string s1, string s2, int i, int j, vector < vector<int> & dp)
{
    // base case
    if (i >= s1.length() || j >= j.length())
    {
        return 0;
    }

    int ans = 0;

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    if (s1[i] == s2[j])
    {
        return 1 + solve(s1, s2, i + 1, j + 1, dp)
    }
    else
    {
        int op1 = solve(s1, s2, i + 1, j, dp);
        int op2 = solve(s1, s2, i, j + 1, dp);
        ans = max(op1, op2);
    }

    return dp[i][j] = ans;
}

/*
tab :
1.  2d dp
2.  range of i -> n1 to 0
    range of j -> n2 to 0
3.  update bc
4.  insert nested for loop
5.  same conditions
6.  update final ans in dp
*/

int solveTab(string s1, string s2)
{
    int n1 = s1.length();
    int n2 = s2.length();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    int ans = 0;

    for (int i = n1 - 1; i >= 0; i--)
    {
        for (int j = n2 - 1; j >= 0; j--)
        {
            if (s1[i] == s2[j])
            {
                ans = 1 + dp[i + 1][j + 1];
            }
            else
            {
                int op1 = dp[i + 1][j];
                int op2 = dp[i][j + 1];
                ans = max(op1, op2);
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][0];

    /*
    TC : O(n2)
    SC : O(n2)
    */
}

/*
SO :
1.  we have to remove or reduce the 2d dp storage
2.  curr value depends on , curr row, row below itself
3.  match : takes from i +1, j+1
4.  else : takes max from i+1,j & i,j+1
5.  so we need only 2 rows (taking 2 vectors here) and n2 cols
6.  so after every iteration in the same for loop , move the rows up
*/

int solveTabSO(string s1, string s2)
{
    int ans = 0;

    vector<int> curr(s2.length() + 1, 0);
    vector<int> next(s2.length() + 1, 0);

    for (int i = n1.length() - 1; i >= 0; i--)
    {
        for (int j = n2.length() - 1; j >= 0; j--)
        {
            if (s1[i] == s2[j])
            {
                ans = 1 + next[j + 1];
            }
            else
            {
                int op1 = next[j];
                int op2 = curr[j + 1];
                ans = max(op1, op2);
            }
            curr[j] = ans;
        }
        next = curr;
    }
    return next[0];

    /*
    TC : O(n2)
    SC : O(n)
    */
}

int main()
{
    string s1 = "abc";
    string s2 = "pbc";

    int ansRec = solveRec(s1, s2, 0, 0);

    vector<vector<int>> dp;
    for (int i = 0; i < s1.length(); i++)
    {
        for (int j = 0; j < s2.length(); j++)
        {
            dp[i][j] = -1;
        }
    }
    int ansMem = solveMem(s1, s2, 0, 0, dp);
    cout << ansMem << endl;
}
