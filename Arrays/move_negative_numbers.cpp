/*
Move all the negative no.s to right of arr and positive ele to left
of the same arr, without changing the order.

Space : O(n)
Time : O(n)

Since space n is given , we can do it using temp arr
Push all poitive into temp
push all negative into temp
copy temp into arr.
retun arr.
https://practice.geeksforgeeks.org/problems/move-all-negative-elements-to-end1813/1
*/

void segregateElements(int arr[], int n)
{
    // store all positive nos in a temp arr
    vector<int> temp;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
        {
            temp.push_back(arr[i]);
        }
    }

    if (temp.size() == n)
    {
        // it means all are negative or all are positive
        return;
    }

    // push all negative ele into temp
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            temp.push_back(arr[i]);
        }
    }

    // copy all temp ele into original arr
    for (int i = 0; i < temp.size(); i++)
    {
        arr[i] = temp[i];
    }

    return;
}