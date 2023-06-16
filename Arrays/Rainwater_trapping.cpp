/*
Trapping Rainwater  :
Given n non-negative integers representing an elevation map where the
width of each bar is 1, compute how much water it can trap after raining.


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6

Explanation:
In this case, 6 units of rain water (blue section) are being trapped.

https://leetcode.com/problems/trapping-rain-water/


.................................................................................................

Approach :

ARRAY PREPROCESSING : process the given arr and store the results into an auxiliary arr.

1.  we need to see at each index , whether on its any left if there is a block
    with greater height and also in its any right if there is a block with
    greater height.

2.  so first take a arr : left = store the tallest left block if present or else the curr height
3.  similarly another arr : right = store the tallest right block if present or else the curr ht

4.  now , apply the formula for each index : min(left,right) - index

    since the water will be stored till the smallest block of the left and rt block
    And secondly, the curr index block is also present as a standing block for which
    there will wont be water counted.

.................................................................................................

*/

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        int left[n];
        int right[n];
        int res = 0;

        left[0] = height[0];
        right[n - 1] = height[n - 1];

        for (int i = 1; i < n; i++)
        {
            left[i] = max(left[i - 1], height[i]);
        }

        for (int i = n - 2; i >= 0; i--)
        {
            right[i] = max(right[i + 1], height[i]);
        }

        // calc the result
        for (int i = 0; i < n; i++)
        {
            res += min(left[i], right[i]) - height[i];
        }
        return res;
    }
};