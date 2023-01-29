/*
Problem statement : [ LIS VARIANT ]

Given n cuboids where the dimensions of the ith cuboid is cuboids[i] =
[width_i, length_i, height_i] (0-indexed).

Choose a subset of cuboids and place them on each other.

You can place cuboid i on cuboid j if width_i <= width_j and length_i <= length_j and
height_i <= height_j

You can place cuboid in ANY WAY upside down or by side to stack the other cuboids on it.
Need to find the MAX HEIGHT of the stacked cuboids.

........................
Given ip:
dimensions of cuboids :
{
    [50, 40, 20] ,
    [95, 37, 53] ,
    [45, 23, 12]
}

Op : 109

.........................
Approach :

1.  To find the max height , we will normally take the max dimension among the l,w,h for all
    the given cuboid. To select that we SORT the dimensions for each of them.

    [20, 40, 50],
    [37, 53, 95],
    [12, 23, 45]

    Now from this we see that height can be taken from the last column due to the max number.

2.  SORT ACC TO WIDTH (1st col) among the above three cuboids

    [12, 23, 45]
    [20, 40, 50],
    [37, 53, 95],

    we do this to get an increasing order of width among the cuboids
    So that we can consider the last row as the base cuboid and remaining we can check
    the condition.

3.  In LIS problem : we make the subseq , by including the next element if greater than
    the current ele , otherwise we exclude and move forward, to get the LIS.

    Similarly here, we take the last cuboid as the base , since its max and check the
    upper cuboids condition l,w,h lesser than its previous.

    If yes then include and add the height and if NOT then exclude it since its not mandatory
    to include all cuboids.

4.  First we sort among the dimensions to get the max height of the stack
    Then we sort wrt width among the cuboids to get the max base cuboid
    Then we check conditions and stack to get the max height of stack.

*/

#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>> &cuboids, int curr, int prev)
{
    // prev = base cuboid as it comes up and curr cuboid moves up
    // prev cuboid will be the bigger one than curr , as we move in decr order
    if (cuboids[curr][0] <= cuboids[prev][0] &&
        cuboids[curr][1] <= cuboids[prev][1] &&
        cuboids[curr][2] <= cuboids[prev][2])
        return true;
    else
        return false;
}

int solve(vector<vector<int>> &cuboids, int n, int curr, int prev)
{
    // base case : since we are moving from last to 1st index
    if (curr < 0)
        return 0;

    // include case for prev cuboid : it will only happen if condition satisfies
    int pick = 0;

    if (prev == -1 || isSafe(cuboids, curr, prev))
    {
        pick = cuboids[curr][2] + solve(cuboids, n, curr - 1, curr);
    }

    // exclude case : happens in all cases
    int not_pick = 0 + solve(cuboids, n - 1, curr - 1, curr);

    return max(pick, not_pick);
}

int stackCuboids(vector<vector<int>> &cuboids)
{
    // step 1: sort all dimensions : sort among one vector
    for (int i = 0; i < cuboids.size(); i++)
    {
        sort(cuboids[i].begin(), cuboids[i].end());
    }

    // step 2 : sort based on width : first parameter : sort all vectors wrt 1st param
    sort(cuboids.begin(), cuboids.end());

    // step 3 : follow LIS approach : solve(arr,n,current,prev)

    // current will be the base cuboid = last cuboid
    // prev will be the = first cuboid , init it will = -1

    int result = solve(cuboids, cuboids.size(), cuboids.size() - 1, -1);

    return 0;
}

int main()
{
    vector<vector<int>> cuboids{
        {50, 40, 20},
        {95, 37, 53},
        {45, 23, 12}};

    int max_height = stackCuboids(cuboids);
    cout << max_height << endl;

    return 0;
}