/*
***************************
Problem statememt :
0/1 Knapsack problem :

Given n items
1st array : repr the weight of n items
2nd array : repr the value of each item

Given total capacity of the bag, and 0/1 means : either fully keep the item
in the bag or donot keep it.

Op : give the max value of the knapsack , in which we have to store the items

Eg1 :
n = 3 , W = 4
val[] = [1,2,3]
weight[] = [4,5,1]
Op : 3

Here , total cap = 4, so we cant include item with wg = 5 , if we include item
with wg = 4 , then val = 1 added, and total val of bag = 1
Now if we include wg = 1, val = 3, then total val of bag = 3 -> max val
So op = 3 : mac val of bag

....................................................................................

Analysis :
1.  include the wg if lesser than remaining capacity of the bag , so if included,
    then add its value to the total sum

2.  if wg of curr item > rem capacity -> donot include it and no val added

3.  so either include item or eclude it and add up the val to the sum and finnaly
    find the max out of those values

....................................................................................

*/

#include <iostream>
#include <vector>
using namespace std;

int solveRec(int n, int w, vector<int> val, vector<int> wg, int index)
{
    // bc:
    if (n == 0 || w == 0 || index > n)
        return 0;

    int op1 = INT_MIN;
    int op2 = INT_MIN;
    // include item
    if (wg[index] <= w)
    {
        op1 = val[index] + solveRec(n, w - wg[index], val, wg, index + 1);
    }
    op2 = solveRec(n, w, val, wg, index + 1);

    return max(op1, op2);
}

/*
Mem + Rec :
1.  Type of dp -> recr variable = w and index -> 2D Dp

2.  Range of those var :
    w -> w till 0
    index -> 0 till n

3.  In 2D dp, row -> index ; col -> w ;
    vector<vector<int>> dp( n , vector<int> (w, -1));

    This is another way of init 2d vector
    First dp(n) repr : since index value ranges till n , so we init with that val

    Second -> vector<int>(w,-1) : this is the second param of table : col :
    so here we have the value of w in the ip, so init with that value and default
    values filled with -1 initially

    So these params values / ranges can be changed once we start to code acc.
    Like n+1 or w+1 etc

4.  And we can also interchange , i.e rows with cols , i.e put w in rows and
    n in cols , the ans will be same ; need to process in the code with them
    accordingly.
*/

int solveMem(int n, int w, vector<int> val, vector<int> wg, int index, vector<vector<int>> &dp)
{
    // bc:
    if (n == 0 || w == 0 || index > n)
        return 0;

    if (dp[index][w] != -1)
        return dp[index][w];

    int op1 = INT_MIN;
    int op2 = INT_MIN;

    if (wg[index] <= w)
    {
        op1 = val[index] + solveRec(n, w - wg[index], val, wg, index + 1, dp);
    }
    op2 = solveRec(n, w, val, wg, index + 1, dp);

    return dp[index][w] = max(op1, op2);
}

/*
Bottom up approach :
1.  update bc
2.  range of var :
    index : rev of above : n till 0
    w : rev : 0 till w
3.  create for loop to move through all combinations
4.  replace recr call with dp
*/

int solveTab(int n, int w, vector<int> val, vector<int> wg, int index)
{
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));

    /*
    base case analysis :
    if n=0, w=0, n>index -> put 0 in dp
    But dp is already init with 0 only , so no updations needed
    */

    int op1 = INT_MIN;
    int op2 = INT_MIN;

    // include - exclude
    for (int index = n - 1; index >= 0; index--)
    {
        for (int C = 1; C <= w; C++)
        {
            if (wg[index] <= C)
            {
                op1 = val[index] + dp[index + 1][C - wg[index]];
            }
            op2 = dp[index + 1][C];
            dp[index][C] = max(op1, op2);
        }
    }
    // return those var value which are sent in the initial main() recr function
    // In solveRec() : index = 0; capacity = w
    return dp[0][w];
}

/*
SO : shown in youtube
*/

int main()
{
    int n = 3;
    int w = 3;
    vector<int> val;
    val.push_back(1);
    val.push_back(2);
    val.push_back(3);

    vector<int> wg;
    wg.push_back(4);
    wg.push_back(5);
    wg.push_back(1);

    int ansRec = solveRec(n, w, val, wg, 0);
    cout << ansRec << endl;

    vector<vector<int>> dp(n + 1, vector<int>(w + 1, -1));
    int ansMem = solveMem(n, w, val, wg, 0, dp);

    int ansTab = solveTab(n, w, val, wg, 0);
    cout << ansTab << endl;
}