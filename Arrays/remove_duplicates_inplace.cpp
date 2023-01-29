/*
Problem Statement :
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that
each unique element appears only once.

The relative order of the elements should be kept the same.

Have the result be placed in the first part of the array.
If there are k elements after removing the duplicates, then the first k elements of nums should hold
the final result.
It does not matter what you leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.
Do not allocate extra space for another array.
You must do this by modifying the input array in-place with O(1) extra memory.

SC:O(1)
TC:O(n)
/*

/*
ALGORITHM :
1. take 2 pointers , 1st pointer(j) to iterate for unique elements and 2nd ptr(i) to iterate till last of
   original arr until find a unique element.
2. once i finds unique ele , replace j++ with that elements and then continue moving i til it finds next
3. move i till n-1.
*/

int removeDuplicates(vector<int> &nums)
{
    int n = nums.size();
    int j = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (nums[i] != nums[i + 1])
        {
            nums[j++] = nums[i];
        }
    }
    nums[j++] = nums[n - 1];
    return j++;
}