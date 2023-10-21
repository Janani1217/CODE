/*
This sort is based on divide and conquer approach.
Initially teh array is divided into half and then sorted and then merged.

Its a recursive algo which divides the arr into halves until it cannot be further
divided and invoke merge sorting in that half.

So if the arr will have 0 or 1 element it will stop (untill the atomic values are achieved).

Finally when both the halves are sorted, the merge operation is applied on it.
Merger operation is taking two sorted smaller halves of array and combining it into one.

.........................................................................................

Algorithm :
1. start
2. declare the array's left , right , mid positions
3. perform merge function :

    if(left > right) return;
    mid = (left + right)/2
    mergeSort(arr, left, mid);  // call func for first half
    mergeSort(arr, right, mid); // call func for the second half
    merge(arr,left,right);  // finally merge the sorted halves

4. stop

.........................................................................................

Algo explain :
1. divide() : it will recursively divide the arr into halves untill atomic

2. it will continue on both the halves : left->mid & mid+1->right

3. now will call the sortAndConquer() to sort the arr and merge into single arr

4. take a temp arr to store the sorted arr and later transfer to original arr

5. need to traverse on both halves so declare i and j accordingly

6. if the array has even elements , then only first while loop will be traversed

7. whichever is min ele will be pushed into temp arr.

8. now if the original arr is odd, then 2nd or 3rd while loop will execute till their ele are inserted into temp

9. now temp will be having all the ele sorted whichever is present from left to right indexes

10. final loop will copy those sorted elements back to the original array

.........................................................................................
*/

#include <iostream>
using namespace std;

// pass the pointer to the array as the reference to the arr is not correct
void sortAndConquer(int *arr, int left, int mid, int right)
{
    // left to mid and mid+1 to right is already sorted
    int i = left;
    int j = mid + 1;
    int k = left;               // to keep track of index in temp
    int temp[right - left + 1]; // to store the temp sorted array

    // need to merge the two sorted halves
    while (i <= mid && j <= right)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }

    // insert remaining values from i to mid into temp
    while (i <= mid)
    {
        temp[k] = arr[i];
        k++;
        i++;
    }

    // insert remaining values from j to right into temp
    while (j <= right)
    {
        temp[k] = arr[j];
        k++;
        j++;
    }

    // Put the values stored in temp back to arr
    for (int i = left; i <= right; i++)
    {
        arr[i] = temp[i];
    }
}

void divide(int *arr, int left, int right)
{
    // base case
    if (left >= right)
        return;

    // remaining process
    int mid = (left + right) / 2;
    // dividing the arr till atomic values reached
    divide(arr, left, mid);
    divide(arr, mid + 1, right);

    // sort and merge
    sortAndConquer(arr, left, mid, right);
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
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    divide(arr, 0, arr_size - 1);
    printArray(arr, arr_size);
}