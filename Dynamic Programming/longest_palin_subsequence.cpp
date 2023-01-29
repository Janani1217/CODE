/*
Problem statement :
Longest palindromic subsequence
Given string s , find the longest pallindromic subseq
Eg : s = bbbab
Op : 3

palindromes :
bab
bbb
3 is the longest palindrome seq

....................................................................................

Approach :

1.  let s1 = "amomb" and s2 = "bmoma"

    Now palin in s1 = mom
    If we rev the string then also the palin will be mom only

    So we are taking rev of s1 and stroring in s2

    Now this mom is a subseq in s1 , and we have to find it in s2 , so we do that by
    finding longest common subseq method

    The palin wont change because we are just finding the common subseq which is the
    longest of the same string in rev order, which will be the common subseq among
    both the strings and that will be equal to a palin

2.  So rev and do lcs
....................................................................................

*/

#include <iostream>
#include <vector>
using namespace std;

int solveTabSO(string s1, string s2)
{
    int ans = 0;
    vector<int> curr(s2.length() + 1, 0);
    vector<int> next(s2.length() + 1, 0);

    int n1 = s1.length();
    int n2 = n1;

    for (int i = n1 - 1; i >= 0; i--)
    {
        for (int j = n2 - 1; j >= 0; j--)
        {
            if (s1[i] == s2[j])
            {
                ans = 1 + next[j + 1];
            }
            else
            {
                int op1 = curr[j + 1];
                int op2 = next[j];
                ans = max(op1, op2);
            }
            curr[j] = ans;
        }
        next = curr;
    }
    return next[0];
}

int main()
{
    string s1 = "bbbab";
    string s2 = s1;
    reverse(s1.begin(), s1.end());

    int ansRec = solveTabSO(s1, s2);
    cout << ansRec << endl;
}