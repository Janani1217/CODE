#include <iostream>
using namespace std;

// output : 345, 34, 3
void printHalf(int arr[], int size)
{
    // base case
    if (size < 1)
    {
        return;
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    printHalf(arr, size / 2);
}

void printHalfMethodTwo(int arr[], int start, int end)
{
    // base
    if (start >= end)
    {
        cout << arr[start] << endl;
        return;
    }

    for (int i = start; i <= end; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    /*
    The max number in int = 2^32 - 1.
    If start = 2^32 - 1 and end = 2^32 - 1, then the sum = start+end, will create a problem
    The register memory cant store the summation value in CPU.
    So we should always avoid calculating mid = (start + end) / 2
    */

    int mid = start + ((end - start) / 2);
    printHalfMethodTwo(arr, start, mid);
}

int main()
{
    int arr[] = {3, 4, 5, 1, 2, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    printHalfMethodTwo(arr, 0, n - 1);
}