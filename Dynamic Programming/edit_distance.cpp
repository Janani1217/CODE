/*
Problem statement :
Given 2 strings : w1, w2
find min no. of operations to convert w1 to w2
Operations :
1.   insert a char
2.  del a char
3.  replace a char

Eg:
w1 = "intention"
w2 = "execution"

....................................................................................

Approach :

1.  take 2 indexes for i1 -> w1 and i2 -> w2 , we have to convert w1 to w2
    so we have to make changes in w1 onlty
    traversing from back
    can do it in forward direction also

2.  if char match , move forward with i-1, j-1

3.  else we have 3 options
    insert in w1 = 1 + solve(i, j-1) ;
    delete in w1 = 1 + solve(i-1, j); // no need to del the char , just ignore that an move
    replace in w1 = 1 + solve(i-1, j-1);

    Now take max among 3 ans;

....................................................................................

*/

#include <iostream>
#include <vector>
using namespace std;

int solveRec(string s1, string s2, int i, int j)
{
    // base case
    if (i == s1.length())
    {
        return s2.length() - j;
    }

    if (j == s2.length())
    {
        return s1.length() - i;
    }

    int ans = 0;
    // if matched
    if (s1[i] == s2[j])
    {
        ans = solveRec(s1, s2, i + 1, j + 1);
    }
    else
    {
        int ins = solveRec(s1, s2, i, j + 1);
        int del = solveRec(s1, s2, i + 1, j);
        int rep = solveRec(s1, s2, i + 1, j + 1);

        ans = min(ins, min(del, rep)) + 1;
    }
    return ans;
}

int solveTab(string s1, string s2, int i, int j)
{

    vector<vector<int>> &dp(s1.length() + 1, vector<int>(s2.length() + 1, 0));
    int n1 = s1.length();
    int n2 = s2.length();

    for (int m = 0; m <= n1; m++)
    {
        for (int n = 0; n <= n2; n++)
        {
            if (m == n1)
                dp[m][n] = n2 - n;

            if (n == n2)
                dp[m][n] = n1 - m;
        }
    }

    for (int w1 = n1 - 1; w1 >= 0; w1--)
    {
        int ans = 0;
        for (int w2 = n2 - 1; w2 >= 0; w2--)
        {
            if (s1[w1] == s2[w2])
                ans = dp[w1 + 1][w2 + 1];

            else
            {
                int ins = dp[w1][w2 + 1];
                int del = dp[w1 + 1][w2];
                int rep = dp[w1 + 1][w2 + 1];
                ans = min(ins, min(del, rep)) + 1;
            }
            dp[w1][w2] = ans;
        }
    }
    return dp[0][0];
}

int main()
{
    string s1 = "horse";
    string s2 = "ros";

    int ansRec = solveRec(s1, s2, 0, 0);

    int ansTab = solveTab(s1, s2, 0, 0);
    cout << ansTab << endl;
}