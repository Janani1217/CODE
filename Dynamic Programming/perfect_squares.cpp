/*
Problem statement :
Perfect squares :
Given n , return least number of perfect square numbers which sums up to n.
Perfect square - its a square of an integer / its a product of a number with itself
Eg of perfect sq : 1 ,4, 9, 16, 25 ...

Eg1:
n = 12
4 + 4 + 4 = 12
OP : 3

Eg2:
n = 13
4 + 9 = 13
OP : 2

.....................................................................................

Analysis :

1.  Suppose n = 27 , lets check what are the perfect sq no.s which exists below
    27 : 1, 4, 9, 16, 25

2.  So to make 27 , we now have 5 ways : so 5 recr calls for every ele : so when
    there is MULTIPLE RECR CALLS exists , then we need to use FOR LOOP PATTERN

3.  With the help of for loop, take all the ans , and store the min no. ways

.....................................................................................

Approach :

1.  Suppose n = 13 , take root(13) = 3 , so it means that for loop will run
    from 1 till 3.

    Because we need to run a loop whose square(i*i)is lesser than 13.
    We cant use any number whose square is greater than 13 -> NO , so that means
    we have to run loop from 1 till that number , whose square is less than 13.

    And root(13) & (i*i) both means the same.

2.  So now we will have i = 1 , 2 , 3
    And the perfect sqaures will be  = 1, 4, 9
    So we are having 3 options to reach a sum of 13.

3.  So in the for loop, run recr call for each perfect sq and get the ans.
    Take the min of all the 3 options rec call ans and return it.

.....................................................................................

*/

#include <iostream>
#include <vector>
using namespace std;

// range of n : starts from n and ends when bc 0 is reached
int solveRec(int n)
{
    // base case
    if (n <= 0)
    {
        return 0;
    }

    int ans = INT_MAX;
    // loop for perfect square
    for (int i = 1; i * i <= n; i++)
    {
        ans = min(ans, 1 + solveRec(n - (i * i)));
    }
    return ans;
}

/*
1.  Update dp with bc
2.  return stored ans
3.  range of n : 0 -> n : for outer loop
4.  copy the remaining part in the above solution and paste in the below soln
*/

int solveTab(int N, vector<int> &dp)
{
    dp[0] = 0;

    for (int n = 1; n <= N; n++)
    {
        int ans = INT_MAX;
        for (int i = 1; i * i <= n; i++)
        {
            ans = min(ans, 1 + dp[n - (i * i)]);
        }
        dp[n] = ans;
    }
    return dp[N];

    /*
    TC : n * root(n) = nrootn
    SC : O(n)
    */
}

/*
Check SO :
1.  dp[n] depends on ans = dp[n - i*i] , and i -> 1 to n
2.  here is i would have been a fix number , then we could have tried to remove
    the inner for loop. But i here is variable
3.  So , this is input dependent. So SO is NOT POSSIBLE.
*/

int main()
{
    int n = 27;
    int ansRec = solveRec(n);

    vector<int> dp(n + 1, -1);
    int ansTab = solveTab(n, dp);
    cout << ansTab << endl;
}