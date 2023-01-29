/*
Problem Statement : Given an array of N integers, and an integer K, find the number of pairs of elements in
the array whose sum is equal to K.

here the elements could repeat -> lead to double counting of the pairs sometimes.

there are chances that sum = number + number -> here same number will be found , so should be taken
care of that

Algorithm:
1. take a hashmap which stores the frequency of each element
2. take var "count" , everytime for each ele in the given array , add the remainder's freq
3. if (sum - num = num) -> if this is the case , then decrease the count -> must have wrongly added ->
   since that case is not acceptable
4. since after ending the loop, we must have counted each pair twice , so divide the count by 2.


TC : O(n)
SC : O(n)

*/

int find(int arr[], int n, int k)
{
    int count = 0;
    unordered_map<int, int> freq;

    // store the freq
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    // traverse to incr count
    for (int i = 0; i < n; i++)
    {
        count += freq[arr[i]];
        if (k - arr[i] == arr[i])
            count--;
    }
    count = count / 2;
    return count;
}