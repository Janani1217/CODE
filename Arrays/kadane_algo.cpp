/*
Problem Statement : Given an array Arr[] of N integers. Find the contiguous sub-array(containing at
least one number) which has the maximum sum and return its sum.

* It can contain whole negative values or positive or both values
* This algo works for all

TC : O(n)
SC : O(1)

* When we receive a negative currSum by adding the curr number , then make the currSum = 0
and start the same process from there.

* max_sum = 0 : it will not process the arr with all -ve values
so max_sum = INT_MIN;

*/

int maxContinousArraySum(int arr[], int n)
{
    int max_sum = INT_MIN;
    int curr_sum = 0;

    for (int i = 0; i < n; i++)
    {
        curr_sum += arr[i];
        if (curr_sum > max_sum)
            max_sum = curr_sum;
        if (curr_sum < 0)
            curr_sum = 0;
    }
    return max_sum;
}