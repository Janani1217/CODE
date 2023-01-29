/*
Problem Stataement : Given an array, rotate the array to the right by k steps, where k is non-negative.
Take care of the end cases in this question especially.

Algorithm:
1. base case : if (n==1 || k==0) then no need to rotate , return the entire arr as it is.
2. if(k>n), then rotate only n-k no. of times only , for that: k=k%n;
3. reverse whole arr
4. reverse 1st k elements
5. reverse last rem elements
*/

void rotateArray(vector<int> &nums, int k)
{
    int n = nums.size();
    if (n == 1 || k == 0)
        return;
    k = k % n;

    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());

    return;
}