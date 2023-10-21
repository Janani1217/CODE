/*To find the least number of API calls using binary search*/

#include <bits/stdc++.h>
using namespace std;

int binarySearch(s, e, desired_res)
{
    int mid = (s + e) / 2;

    while (s < e)
    {
        int res = apiCall(mid);
        if (res == desired_res)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return e + 1;
}