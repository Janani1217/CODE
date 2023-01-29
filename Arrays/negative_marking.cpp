/*
Problem statement  :
find one repeated element in the arr, in place and no extra space.

here in such prblms we go with the marking the number in first visit negative and again if the sam number
is re visited then it is caught to be the duplicate

TC: O(n)
SC: O(1)

*/
int findRepeated(vector<int> nums, int n)
{
    if (n == 0)
        return -1;
    if (n == 1)
        return 0;

    for (int i = 0; i < n; i++)
    {
        int curr = abs(nums[i]);
        if (nums[curr] < 0)
        {
            return curr;
        }
        nums[curr] *= -1;
    }

    for (int i = 0; i < n; i++)
    {
        nums[i] = abs(nums[i]);
    }
    return -1;
}
