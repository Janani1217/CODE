/*
Similar to merge sort , quick sort is also conquer and divide approach based.
It will have a pivot element , around which the arr will be divided and then conquered after sorting.

There are diff ways to select the pivot element:
1. pick 1st ele as pivot
2. pick last ele as pivot
3. pick median
4. pick random ele as pivot

The key process in quick sort is partion() process.
It will recieve an arr and an ele of that arr as the pivot.
It has to put the pivot ele in its correct position in the arr as in sorted arr.
Then place all the smaller ele before pivot and greater ele after the pivot to form sorted arr.
This all has to be done in linear time = O(n).
 */

#include <iostream>
using namespace std;

int partition(int *arr, int start, int end)
{
    // selecting first ele as pivot
    int pivot = arr[start];

    /* leaving the pivot ele count the no. of ele greater than pivot
       in the entre arr to find correct pos of the pivot */
    int count = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= pivot)
            count++;
    }

    // giving pivot element its correct index
    int pivotIndex = start + count;
    swap(arr[start], arr[pivotIndex]);

    // Now pivot ele is placed in correct pos
    // Sort the left and right parts of pivot ele

    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= arr[pivotIndex])
            i++;

        while (arr[j] > arr[pivotIndex])
            j++;

        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(int *arr, int start, int end)
{
    if (start >= end)
        return;

    // partition array
    int pivot = partition(arr, start, end);

    quickSort(arr, start, pivot - 1);
    quickSort(arr, pivot + 1, end);
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\n";
    }
}

#include <iostream>
using namespace std;

int main()
{
    int arr[] = {2, 5, 3, 6, 7, 1, 4, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    printArray(arr, n);
    return 0;
}