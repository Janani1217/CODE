void sortColors(vector<int> &nums)
{
    int a = 0, b = nums.size() - 1, i = 0;
    // Three varibale one to track last pos , another to track 2's pos and other is to iterate.
    // The 1's will get inline automatically if 0's and 2's are kept properly
    while (i <= b)
    {
        if (nums[i] == 2)
        {
            swap(nums[i], nums[b]);
            b--;
        }
        else if (nums[i] == 0)
        {
            swap(nums[i], nums[a]);
            i = a + 1;
            a++;
        }
        else
            i++;
    }
}