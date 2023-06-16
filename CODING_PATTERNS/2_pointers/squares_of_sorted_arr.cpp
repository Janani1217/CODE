/*
Squares of a Sorted Array

Given an integer array nums sorted in non-decreasing order,
return an array of the squares of each number sorted in non-decreasing order.

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]

Approach : Using 2 pointers.

1.  p1 = 0
    p2 = n-1

2.  create a new arr : result
    index = n-1

    This index is for entering the values into the result vector

3.  for loop : index : n-1 -> 0

    3.1 if (abs(nums[p1]) > abs(nums[p2]))
            then definitly , the square of p1 will be bigger than p2 square
            so it will be placed in the right part of the result

        result[index] = sq(nums[p1]);
        p1++;

    3.2 else {
        result[index] = sq(nums[p2]);
        p2--;
    }

4. return result;

TC : O(n)
SC : O(n)

*/

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int n = nums.size();

        // take 2 pointers
        int p1 = 0;
        int p2 = n - 1;

        // take a new arr and loop over the arr from back
        vector<int> result(n, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            if (abs(nums[p1]) > abs(nums[p2]))
            {
                // their suqres will also be greater
                result[i] = nums[p1] * nums[p1];
                p1++;
            }
            else
            {
                result[i] = nums[p2] * nums[p2];
                p2--;
            }
        }
        return result;
    }
};