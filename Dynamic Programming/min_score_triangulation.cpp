/*
PS : Min score triangulation of polygon

Given n sided polygon , where each vertex has some value
Given an integer array with vertex values

You have to triangulate the polygon into n-2 triangles
For each triangle , the val of that tria is product of its vertices
And total score of triangulation = sum of these val over n-2 trai in the triangulation

Return the smallest poss total score that you can get with some triangulation
of the given polygon

Eg : n = 3 , [1,2,3]
OP : 6 , already a tria shape , no

....................................................................................

Explained in note book diagramatically

....................................................................................

Approach :

1.  i + 1 -> j : then it forms  a str line , so cant connect to form a tria
    So these are 2 end points in the given arr

    NOW WE SEE THE PATTERN = NEED MIN OF MULTIPLE ANSWERS : FOR LOOP APPLY

2.  Now we select a mid point in btw these i and j as k and join i with k
    which forms a tria - i->k->j

3.  rem parts of ploygon after this tria formed in sent to recr for further
    repeating the same process of traingulation

4.  So the base case could be i+1==j , which means so middle vertexes are
    present btw them
*/

#include <iostream>
#include <vector>
using namespace std;

int solveRec(vector<int> &val, int i, int j)
{
    // base case : if str line
    if (i + 1 == j)
        return 0;

    // rem cases : need to loop from i till j
    int ans = INT_MAX;
    // mid no. should be greater than i and lesser than j
    for (int k = i + 1; k < j; k++)
    {
        // selected a node = k
        int currSum = (val[i] * val[k] * val[j]) + solveRec(val, i, k) +
                      solveRec(val, k, j);
        ans = min(ans, currSum);
    }
    return ans;
}

/*
Mem:
1.  TYPE OF DP = 2D DP
2.  Range of i = 0 -> n
3.  Range of j = n -> 0
*/

int solveMem(vector<int> &val, int i, int j, vector<vector<int>> &dp)
{
    // bc:
    if (i + 1 == j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    // rem cases :
    int mini = INT_MAX;
    for (int k = i + 1; k < j; k++)
    {
        int currSum = (val[i] * val[k] * val[j]) +
                      solveMem(val, i, k, dp) +
                      solveMem(val, k, j, dp);

        mini = min(mini, currSum);
    }
    return mini;
}

/*
Tab:
1.  2d dp
2.  update bc
3.  range of i : n ->0
4.  range of j : 0->n
5.  2 for loops + rem for loop
6.  return dp[0][n-1]
*/

int solveTab(vector<int> &val)
{
    int n = val.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // bc : update not needed already init with 0
    // rem cases : 2 for loops + 1 already for loop

    for (int i = n - 1; i >= 0; i--)
    {
        /*
        1.  j is dep on i for bc condition that i+1 != j ,
            so j is init with i+2

        2.  if j > i at some point then it becomes an invalid
            range, so j init with i+2
        */

        for (int j = i + 2; j < n; j++)
        {
            int mini = INT_MAX;
            for (int k = i + 1; k < j; k++)
            {
                int currSum = (val[i] * val[k] * val[j]) +
                              dp[i][k] +
                              dp[k][j];

                mini = min(mini, currSum);
            }
            dp[i][j] = mini;
        }
    }
    return dp[0][n - 1];
}

int main()
{
    vector<int> val;
    val.push_back(3);
    val.push_back(7);
    val.push_back(4);
    val.push_back(5);

    int ans = solveRec(val, 0, val.size() - 1);

    int n = val.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    int ansMem = solveMem(val, 0, n - 1, dp);
    cout << ansMem << endl;
}