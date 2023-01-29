/*
Problem statement : given an array which denotes the heights of towers . So there are n towers.
There is a number k given.
For each tower either you should +k or -k
find out the minimum difference between the shortest and the longest tower.

so here its minimize the max difference problem

TC: O(nlogn)
SC: O(n)


Algorithm :
1. if we see here it deals with min the difference between 2 numbers which are the shortest and tallest
   so it becomes easier to find if we sort the array.
2. initial maximim difference becomes when we add k with first number and subtract k with the last number
3. now traverse the whole arr and compare the curr num - k with min and update
4. max = curr num+1 - k , with max number obtained
5. if the curr min number goes to be -ve , then we should ignore that and move on
6. else we need to find the min(initial difference, curr_max - curr_min);

*/

{
    int findDifference(int arr[], int n, int k)
    {
        // sort the arr
        sort(arr, arr + n);

        // init max difference
        int answer = arr[n - 1] - arr[0];

        int curr_max = arr[n - 1] - k;
        int curr_min = arr[0] + k;

        int ma = 0, mi = 0;

        for (int i = 0; i < n; i++)
        {
            // curr number always subtract from k
            // next number always add up k and then compare
            ma = max(curr_max, arr[i + 1] - k);
            mi = min(curr_min, arr[i] + k);

            if (mi < 0)
                continue;

            answer = min(answer, ma - mi);
            return answer;
        }
    }