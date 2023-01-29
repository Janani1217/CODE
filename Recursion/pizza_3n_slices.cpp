/*
Problem statement :
There is a pizza with 3n slices.
You and your frnds have to pick the slices as follows:
1. u will pick any pizza slice
2. alice will pick slice in anti clockwise direction of your pick
3. bob will next pick in clockwise direction of ur pick
4. repeat untill there are no more slices of pizzas

Gn an array which repr the sizes of the slices of pixaas in clockwise direction.
Return max sum of slices that you can pick in teh game.



Approach:
2.  Now given 3n slices are there, so you can pick only n slices : 3n = n + n + n
    2n will be picked by frnds and remaining 1n will be picked by you.
3.  Here we see the pattern of either include the slice or exclude it and find the
    max in both the options
4.  Here the catch is handling the circular motion of the game.
5.  If we eat/pick 1st slice in the arr , the last slice of the arr will be picked by another
    since clock-wise movement is happening
6.  If we dont pick , then it will be present in the game. So this case has to be handled
7.  So we have taken 2 options for the above case and find the max in both of them
8.  In actual function, we normally write the include/exclude cases for each of the slice
    and find the max in both.
9.  If we include the curr slice , then we move by 2 indexes forward by adding the score
10. Else we move only by 1 index forward with no addition to the score

*/

#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> slices, int start, int end, int n)
{
    /*
    Base case :
    if the range is invalid : s > e
    (or)
    if , total slices are already eaten : termination condition reached
    */
    if (start > end || n == 0)
        return 0;

    int include = slices[start] + solve(slices, start + 2, end, n - 1);
    int exclude = 0 + solve(slices, start + 1, end, n - 1);
    return max(include, exclude);
}

int selectSlices(vector<int> slices, int n)
{
    /* we are calculating total slices which are actually for us in total pizza given
       in that case, we have total n/3 slices overall in the entire game which is the
       actual size of array in which we have to play the game.
    */

    /* The below calls are only for include and exclude of the first slice present in
       the array , because its circular clockwise movement, so this has to be handled.
    */

    // if we are including the first slice in arr, then the last slice will not be include
    // because it will be picked up by other. So total slices will be n-2 and index = 0
    int option1 = solve(slices, 0, n - 2, n / 3);

    // if we exclude 1st slice, then remaining 2nd slice till last will be there for the game
    // so only 1 slice is excluded = n-1 , and index = 1
    int option2 = solve(slices, 1, n - 1, n / 3);

    return max(option1, option2);
}

int main()
{
    vector<int> slices;
    slices.push_back(1);
    slices.push_back(2);
    slices.push_back(3);
    slices.push_back(4);
    slices.push_back(5);
    slices.push_back(6);

    // this will have total 3n slices provided in input
    int n = slices.size();
    int score = selectSlices(slices, n);
    cout << score << endl;
}