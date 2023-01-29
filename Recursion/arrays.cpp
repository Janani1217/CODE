#include <iostream>
using namespace std;

// void printArray(int arr[], int n, int k)
// {
//     cout << arr[k] << " ";
//     if (k == 0)
//         return;
//     printArray(arr, n, k - 1);
// }

// int fact(int n)
// {
//     if (n == 0)
//         return 1;
//     int res = n * fact(n - 1);
//     return res;
//     ;
// }

int findMax(int arr[], int n, int k, int maxN)
{
    if (k == n)
        return maxN;
    if (arr[k] > maxN)
        maxN = arr[k];
    int res = findMax(arr, n, k + 1, maxN);
    return res;
}

int main()
{
    int arr[6] = {3, 5, 6, 9, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int res = findMax(arr, n, 0, 0);
    cout << "\n"
         << res << "\n";
    return 0;
}