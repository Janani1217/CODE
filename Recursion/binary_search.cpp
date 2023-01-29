/*
Binary Search :

This is a kind of algo which is used to find/search an ele/target in an array.
Condition : It should be a monotonic array : either in increasing or decreasing order ele

Algo (considering arr is in increasing order):
1.  First find mid of range
2.  compare if(target > mid)
3.  if yes -> target is in right side of mid -> so leftptr = mid+1
4.  else -> target is in left side of mid -> so rightptr = mid-1

So initial arr size = n , then it cuts down to n/2 size, then n/4, then n/6 untill atomic value reaches.
Much more faster than Linear Search.

*/

#include <iostream>
using namespace std;

// using recursion
int binarySearch(int arr[], int target_to_search, int start, int end)
{
    // base case : atomic value reaches
    if (start > end)
        return -1;

    int mid = start + ((end - start) / 2);
    if (arr[mid] == target_to_search)
        return mid;
    else if (arr[mid] > target_to_search)
        end = mid - 1;
    else
        start = mid + 1;
    return binarySearch(arr, target_to_search, start, end);
}

int main()
{
    int arr[] = {2, 4, 5, 6, 8, 10, 12, 15};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    int search_result = binarySearch(arr, 19, 0, arr_size);
    cout << search_result << endl;
}