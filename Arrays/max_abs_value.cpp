/*
Given two arrays of integers with equal lengths, return the maximum value of:

|arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j|

where the maximum is taken over all 0 <= i, j < arr1.length.

EX :
Input: arr1 = [1,2,3,4], arr2 = [-1,4,5,6]
Output: 13

Approach :
Whenver the mod expression is given try to always open the mod and
solve it using diff combinations

If we expand 3 mods given in equation.
There will get eight equations overall.
Out of those 8 equations, 4 equations are negative version of other 4.
So, it means we need to calculate only 4 of these 8 equations.
As other 4 will give same values.


So, directly coming to final 4 eqautions:

arr1[i] - arr1[j] + arr2[i] - arr2[j] + i - j ---> (arr1[i] + arr2[i] + i) - (arr1[j] + arr2[j] + j)
arr1[i] - arr1[j] + arr2[i] - arr2[j] - i + j ---> (arr1[i] + arr2[i] - i) - (arr1[j] + arr2[j] - j)
arr1[i] - arr1[j] - arr2[i] + arr2[j] + i - j ---> (arr1[i] - arr2[i] + i) - (arr1[j] - arr2[j] + j)
arr1[i] - arr1[j] - arr2[i] + arr2[j] - i + j ---> (arr1[i] - arr2[i] - i) - (arr1[j] - arr2[j] - j)


Now, Lets looks at these simplified forms :

(arr1[i] + arr2[i] + i) - (arr1[j] + arr2[j] + j)
(arr1[i] + arr2[i] - i) - (arr1[j] + arr2[j] - j)
(arr1[i] - arr2[i] + i) - (arr1[j] - arr2[j] + j)
(arr1[i] - arr2[i] - i) - (arr1[j] - arr2[j] - j)


In each of these equation forms:
(first part) - (second part)
to make it maximum we need to maximize first part and minimize second part.

So, we are creating 4 max variables and 4 min variables.
Now substracting each max with its corresponding min will give us one possible value.
We will get 4 possible candidates.
Maximum of those 4 is right answer.

*/

class Solution
{
public
    int maxAbsValExpr(int[] arr1, int[] arr2)
    {
        int maxA1 = Integer.MIN_VALUE;
        int maxA2 = Integer.MIN_VALUE;
        int maxA3 = Integer.MIN_VALUE;
        int maxA4 = Integer.MIN_VALUE;

        int minA1 = Integer.MAX_VALUE;
        int minA2 = Integer.MAX_VALUE;
        int minA3 = Integer.MAX_VALUE;
        int minA4 = Integer.MAX_VALUE;

        int n1 = arr1.length;
        int n2 = arr2.length;

        for (int i = 0; i < n1; i++)
        {
            maxA1 = Math.max(maxA1, arr1[i] + arr2[i] + i);
            maxA2 = Math.max(maxA2, arr1[i] + arr2[i] - i);

            maxA3 = Math.max(maxA3, arr1[i] - arr2[i] + i);
            maxA4 = Math.max(maxA4, arr1[i] - arr2[i] - i);

            minA1 = Math.min(minA1, arr1[i] + arr2[i] + i);
            minA2 = Math.min(minA2, arr1[i] + arr2[i] - i);

            minA3 = Math.min(minA3, arr1[i] - arr2[i] + i);
            minA4 = Math.min(minA4, arr1[i] - arr2[i] - i);
        }

        int ans = maxA1 - minA1;

        ans = Math.max(ans, maxA2 - minA2);
        ans = Math.max(ans, maxA3 - minA3);
        ans = Math.max(ans, maxA4 - minA4);

        return ans;
    }
}