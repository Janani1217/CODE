/*
problem statement : Given an array of integers nums and an integer target, return indices of the two
numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.
Constrains :
Solve it lesser than O(n^2).

Should not do :
Since it asks about the index in the answer , so we cannot go for Binary search for the remaining element
as we normally do.
So whenever index is asked in the answer , cant use binary search or sorting of elements should be done.
Go worst case to increase the space complexity , as here its O(n).

TC : O(N)
SC : O(N)

*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums{2, 3, 4, 5};
    vector<int> result = twoSum(nums, 8);
    return 0;
}
vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> ans;
    unordered_map<int, int> store;

    for (int i = 0; i < nums.size(); i++)
    {
        int remaining = target - nums[i];
        if (store.find(remaining) != store.end())
        {
            ans.push_back(i);
            ans.push_back(store[remaining]);
            return ans;
        }
        store[nums[i]] = i;
    }
    return ans;
}