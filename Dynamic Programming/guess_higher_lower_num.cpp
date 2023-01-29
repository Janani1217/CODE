/*
PS : Guess number higher or lower

There are 2 players :

P1 picks a no. between 1 -> n
P2 guesses a number.

Here p2 can guess correct or incorrect no.
If p2 gueses incorrect no. then that could be greater than correct
no. or it could be less than correct no which will be informed by p1.

Now if p2 guess(x) which is incorrect no., then p2 has to give x
amount of dollars.

If p2 runs out of money , then it has lost his game.

OP : Return the min amount of money p2 need to gaurantee a win regardless
of what no. p1 picks

....................................................................................

Analysis of question:

1.  If p1 picks a no.

2.  P2 guess the no. as = x

3.  Right guess by P2 -> no money given and P2 WINS THE GAME

4.  Wrong guess by P2 : worst case :
    Pay x dollars
    P1 informs : correct ans falls in higher or lower range
    And P2 continues to guess.

    If money with p2 <= 0 -> p2 LOST
    And p2 didnt reach till correct ans

5.  So p1 will pick the no. only once, and p2 will also guess till correct ans ->
    so the game is not infinite if correct ans guess
    Else p2 will keep on guessing until money <= 0 || the range has completed

6.  So for every wrong guess, p2 has to search in the range said by p1.

7.  Now if we reach a range where only 1 element is present , then that is the correct ans

    Which will form the base case in this problem

    Now in this , sometimes the range can go out as start > end -> invalid range
    return 0;

....................................................................................

Explained in notes visual -> please study that !!

....................................................................................

Approach :

1.  p2 guess is irrespective of p1 selection

2.  we have to consider all the values present in 1 -> n range to get sub ans and
    finally find the min amount p2 has to spend to reach that atomic range among
    all the sub answers

3.  So for this we take a for loop. Select a number in the range : i
    Then we consider worst case : incorrect guess everytime
    So we add that i into the sub answer
    Then we go with finding sub ans for left range and right range

4.  Among those two ranges ans , we get the max value , becuase we need to consider
    the worst case.

5.  Now we add this subans with i and for the overall sub ans that we recive in the
    for loop, we find the min and return that ans.

....................................................................................

*/

#include <iostream>
#include <vector>
using namespace std;

int solveRec(int s, int e)
{
    // base case :
    if (s >= e)
        return 0;

    // remaining case : run loop
    int ans = INT_MAX;
    for (int i = s; i <= e; i++)
    {
        // to consider worst case , we take max : MIN-MAX Coding pattern
        int subAns = i + max(solveRec(s, i - 1), solveRec(i + 1, e));
        ans = min(ans, subAns);
    }
    return ans;
}

/*
1.  type of dp : 2d
2.
*/

int solveMem(int s, int e, vector<vector<int>> &dp)
{
    // bc:
    if (s >= e)
        return 0;

    if (dp[s][e] != -1)
        return dp[s][e];

    // remaining cases:
    int ans = INT_MAX;
    for (int i = s; i <= e; i++)
    {
        int sub = i + max(solveMem(s, i - 1, dp), solveMem(i + 1, e, dp));
        ans = min(ans, sub);
    }
    dp[s][e] = ans;
    return ans;
}

/*
1.  type = 2d
2.  update bc : no need , already 0 init in dp
3.  since 2d dp , so 2 for loops , so find range of both variables
    s : n -> 0
    e : 0 -> n
*/

int solveTab(int n)
{
    /*
    dp size  = n+2 : because in the 3rd for loop, i = s init, and s starts
    from n.

    now if i++ means n++ -> go out of bound -> will throw error, so init with
    n + 2 as the size of the dp

    Anyhow previously we had init dp(n+1) , because we start from 0.
    Now we need to increase 1 index more for the above situation.
    */
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    // rem cases : insert tab loop
    for (int s = n; s >= 1; s--)
    {
        // to consider the bc : if(s >= e) return 0; so we are checking only
        // if e starts after s only.
        for (int e = s + 1; e <= n; e++)
        {
            int ans = INT_MAX;
            for (int i = s; i <= e; i++)
            {
                int sub = i + max(dp[s][i - 1], dp[i + 1][e]);
                ans = min(ans, sub);
            }
            dp[s][e] = ans;
        }
    }
    return dp[1][n];
}

int main()
{
    int n = 10;
    int ans = solveRec(0, n);

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    int ansMem = solveMem(0, n, dp);
    cout << ans << endl;
}