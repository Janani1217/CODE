/*
Sort Colors :

Given an array nums with n objects colored red, white, or blue, sort them in-place
so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

.................................................................................................


Approach :

DUTCH NATIONAL FLAG ALGO :

1.  have 3 ptrs : s , m , e
2.  if 0 : swap with the inital ptr with current and incr both
3.  if 1 : inc the curr ptr
4.  if 2 : swap with the last ptr with curr and decr the last

.................................................................................................

*/

void solve(vector<int> &nums)
{
    int n = nums.size();
    int s = 0;
    int m = 0;
    int e = n - 1;

    while (m <= e)
    {
        switch (nums[m])
        {
        case 0:
            swap(nums[s++], nums[m++]);
            break;

        case 1:
            m++;
            break;

        case 2:
            swap(nums[m], nums[e--]);
            break;
        }
    }
}