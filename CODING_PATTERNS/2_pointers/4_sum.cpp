/*
4Sum :
Given an array nums of n integers, return an array of all the unique
quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

.................................................................................................

Approach :

1.  its same as 3 sum , using 2 for loops and 2 inner ptrs
2.  check the same conditions for the inner ptrs and move
3.  run time err comes in case of huge negative no.s so it can be handled by using :

    long long sum = nums[i];
    sum += nums[j];
    sum += nums[k];
    sum += nums[l];

.................................................................................................

*/

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> res;
    int n = nums.size();
    set<vector<int>> s;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int k = j + 1;
            int l = n - 1;

            while (k < l)
            {
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];

                if (sum == target)
                {
                    s.insert({nums[i], nums[j], nums[k], nums[l]});
                    k++;
                    l--;
                }
                else if (sum > target)
                    l--;
                else
                    k++;
            }
        }
    }

    // copy back the vectors:
    for (auto quad : s)
    {
        res.push_back(quad);
    }
    return res;
}