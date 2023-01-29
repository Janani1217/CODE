/*

Recursive solution :
1.  Base case
2.  Recr calls for rem cases
3.  return op if needed

Tc : exponential
Sc : depends on question

.....................................................................................

Recr + Memoization solution :
1.  know the type of dp arr : 1d, 2d, 3d etc
2.  form a dp arr and pass in function
3.  return stored ans
4.  after all recr call , final ans : store in dp[]
5.  return dp[n]

Tc : O(n)
Sc : O(n) + O(n)

....................................................................................

Bottom-up solution :
1.  keep the same dp arr
2.  update dp arr values acc to BC
3.  remove return for already stored values
4.  start a for loop : look for range of changing var : opp to top down
5.  copy entire for loop logic from above
6.  replace recr call with dp[] values accordingly
7.  return dp[n] at last

Tc : O(n)
Sc : O(n)

....................................................................................

Bottom-up Space Optimization solution :
1.  check dependency of curr value
2.  look if we can optimize by removing the dp arr
3.  if such solution exist , replace dp arr values with variables in for loop
4.  remove any extra code
5.  return the final variable value.

Tc : O(n)
Sc : 1

*/