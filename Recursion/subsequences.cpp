/*

Variations:
1. variations of LIS
2. Longest pallindromic subsequence
3. longest arithmetic subseq with difference given
4. distinct subsequences
---------------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------------
SUBSEQUENCE KEYWORD : INCLUDE / EXCLUDE
---------------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------------

Problem statement [checkSubsequence] : tell if a string A is a subsequence of B or not

Subsequence :  a character in a string can be taken or not , but the output should be in order.
So, a subseq of a string is a string which is formed by deleting some or none of the
characters in the original string , without disturbing its relative order of the remaining char.

eg :
S1 = "abc"
S2 = "ahbdueck"
result = true , since S1 is a subseq of S2.

Algo 1:
1. take indexes for both strings
2. take the count for every match
3. if the count == s1.length , then return true or else false

Algo 2:
1. base case would be , if the output matches S1 , retrun true
2. using recursion , either select the char in S2 or deselect it top form the output.
3. if nothing matches return false


---------------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------------

******* // very very imp
Problem Statement [Longest Increasing Subsequence] :
Find the STRICTLY INCREASING LONGEST SUBSEQUENCE , int the given array.

Eg:
[0, 3, 1, 6, 2, 2, 7]

There can be many subseq, but only STRICTLY incr subseq, we need to find out
[0 ,3, 6, 7]
[0, 1, 2, 7]
....

Here we cannot take 2,2 in one subseq, because we need strictly incr, meaning the
ele before curr ele should be strictly lesser than its next.

Algo :
1. we dont need every incr subseq to be stored , space mem waste, so we will
   store the last ele index which obeys the condition
2. same rule applies : include the curr ele , if it obeys the condition that it is
   greater than the previous ele, otherwise exclude and move forward.
3. terminating condition would be if the arr reaches its end.
4. initially the prev index would be -1.


---------------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------------

******* // very very imp
Problem Statement [Longest Common Subsequence] :
There are 2 strings , need to find LCS among it.

So, if we find all the subseq of both strings.
Then find the common subseq in them.
Among that the longest one we need to return.

Algo :
1. there are 2 strings s1 and s2.
2. there are 2 indexes pointing on both strings.
3. if the curr char matches , add 1 and then move ahead for both the indexes
4. if it donot match , then we have 2 options , either include in s1 and move ahead in s2 to compare
5. Or, move ahead in s1 i.e exclude in s1 and include in s2 and compare.
6. among them we need to find the max length.


---------------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------------

******* // very very imp
Problem Statement [Longest Arithmetic Subsequence] :
Find the longest AP
Arithmetic progression : difference btw 2 no.s is same in the sequence
eg: 1 3 5 7 9 11 13...  d = 2, a{first term} = 1

Brute force:
1. find all the AP's in the array
2. among them find the longest AP sequence
3. now to find the common diff = d, we need to take every 2 ele in the arr and
   calc the difference , for picking every two ele, we can use 2 for loops and it
   will give all the pairs in the arr.
4. so every pair will give us "d".
5. now for every pair we have 2 options, iy could be the starting of AP or the end of AP.
6. now if we take the pair as the last of AP, we find the diff and then look in the
   left part of the pair which satisfies the difference with the element.
7. so , for every pass, we find the length, and then find the longest length.

*/

#include <iostream>
using namespace std;

int longestArithmeticSubsequenceUtils(int arr[], int i, int diff)
{
    // backward check (left part in the arr from ith index) in the array
    // with the difference

    // base case
    if (i <= 0)
    {
        // first element index if stands in the 0th index , then no ele exist in left
        return 0;
    }

    // else if elements exist
    // move left part till 0
    int ans = 0;
    for (int k = i - 1; k >= 0; k--)
    {
        if (arr[i] - arr[k] == diff)
        {
            // ele found
            ans = max(ans, 1 + longestArithmeticSubsequenceUtils(arr, k, diff));
        }
    }
    return ans;
}

int longestArithmeticSubsequence(int arr[], int n)
{

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // catch here : add 2 , because we are considering 2 ele, arr[i] , arr[j]
            int diff = arr[j] - arr[i];
            ans = max(ans, 2 + longestArithmeticSubsequenceUtils(arr, i, diff));
        }
    }
    return ans;
}

int longestCommonSubsequence(string s1, int i, string s2, int j)
{
    // base : if both or any one string is zero length
    if (s1.length() == 0 || s2.length() == 0)
    {
        return 0;
    }
    if (i == s1.length() || j == s2.length())
    {
        return 0;
    }

    // if there is a match
    int ans = 0;
    if (s1[i] == s2[j])
    {
        ans = 1 + longestCommonSubsequence(s1, i + 1, s2, j + 1);
    }

    // not a match
    // include in s1 or include in s2
    else
    {
        ans = max(longestCommonSubsequence(s1, i, s2, j + 1),
                  longestCommonSubsequence(s1, i + 1, s2, j));
    }
    return ans;
}

int longestIncreasingSubsequence(int arr[], int size, int prev_index, int curr_index)
{
    // base case : if the index reaches the end of arr
    if (curr_index == size)
    {
        // here alwaysvthink of the smallest case , like if n==0
        return 0;
    }

    /*
    Here one element has 2 options that has to followed , one is by checking the subseq
    by selecting the ele -> pick flag is used for that.
    Now we have to check the subseq also if its not picked, so notPicked flag is used
    to indicate that.
    Now in the final stage both pick and notPick will store the subseq length in it, so
    return the max length.
    */

    // include the curr ele based on the condition
    int pick = 0;
    if (prev_index == -1 || arr[curr_index] > arr[prev_index])
    {
        // since we need the length , so if condition satisfied , incr the length
        pick = 1 + longestIncreasingSubsequence(arr, size, curr_index, curr_index + 1);
    }

    // exclude
    int notPick = 0 + longestIncreasingSubsequence(arr, size, prev_index, curr_index + 1);

    return max(pick, notPick);
}

int checkSubsequenceMethod1(string s1, int i, string s2, int j)
{
    // base case
    if (i >= s1.length() || j >= s2.length())
    {
        return 0;
    }

    // recursion case
    // if both char matches
    if (s1[i] == s2[j])
    {
        return (1 + checkSubsequenceMethod1(s1, i + 1, s2, j + 1));
    }
    else
    {
        return checkSubsequenceMethod1(s1, i, s2, j + 1);
    }
}

// this method might give TLE in long cases
bool checkSubsequenceMethod2(string s1, string s2, string op, int index)
{
    // cout << op << endl;
    //  base case
    if (op == s1)
        return true;

    if (index == s2.length())
        return false;

    // include the curr char
    if (checkSubsequenceMethod2(s1, s2, op + s2[index], index + 1))
        return true;

    // exclude the current char
    if (checkSubsequenceMethod2(s1, s2, op, index + 1))
        return true;

    return false;
}

int main()
{
    // string s1 = "axc";
    // string s2 = "ahbdgc";

    // find if string1 is a subseq of string2
    /*
    int result = checkSubsequenceMethod1(s1, 0, s2, 0);
    cout << "result = " << result << endl;
    if (result == s1.length())
    {
        cout << true << endl;
    }
    cout << false << endl;
    */

    // find the longest strictly incr subseq
    /*
    int arr[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = longestIncreasingSubsequence(arr, n, -1, 0);
    cout << result << endl;
    */

    // find longest common subsequence
    /*
    string s1 = "abcde";
    string s2 = "ae";

    int result = longestCommonSubsequence(s1, 0, s2, 0);
    cout << "result = " << result << endl;
    */

    int arr[] = {9, 4, 7, 2, 10};
    int n = 5;
    int result = longestArithmeticSubsequence(arr, n);
    cout << "result = " << result << endl;
}
