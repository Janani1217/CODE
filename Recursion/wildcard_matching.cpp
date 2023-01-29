/*

Problem statement:

Given input string : s
Given a pattern : p
Implement wildcard matching which has the following "?" and "*":
"?" : matches any SINGLE CHAR
"*" : matches any SEQUENCE OF CHAR (including the empty seq)

Expected op : matching should cover the entire ip string.

Eg 1 :
s = "aa"
p = "a"
op = FALSE

we cant match "a" to "aa"
if we would have "a?" , "?a" , "??" , "aa" , "?*" , "*?" , "*a" , "a*" , "*" ,
"**" , "***" , "a**", "?*?" etc.........

Here "a?" - match second "a" in ip string with "?" in pattern
And if "*" - it can match a seq of char which could be "aa" in given ip
And if "***" - first * can match aa , and remainng empty string

But "a" in P , cannot match anywhere to the given ip str = "aa".


Eg 2 :
s = "cb"
p = "?c"
op = FALSE

Since c will match with ? , but b will not match with c in pattern

APPROACH :

1.  There are 2 strings : s(abcd) and p(*cd) , so put 2 pointers i and j in the
    last of each string.
2.  If match = both move backward towards start, i-1 and j-1
3.  If j -> "*" , so here it can match an entire char seq or empty seq , 2 options,
    a.  empty seq -> i , j-1
    b.  char seq  -> i-1 , j

    Here if replaced with empty seq -> then i has not matched so will remain in the
    same place , but j will move backwards.

    Here if matched with char sequence -> then basically we are logically replacing
    the * with *b , we are not inserting but logically we are doing that in the code
    process, such that i matches with j , then i will move backward to the next char
    in ip and j will remain there itself.

4.  If j -> "?" , then only one single char will be replaced to be a match.
    And after that both i and j has to move forward : i-1 , j-1

5.  Base cases :

    a.  if both i and j has reached ends , return
        ( i < 0 && j < 0 ) , return TRUE
    b.  if i(s) has reached end , but j(p) still present ( i < 0 && j >= 0) ,
            i.  if only * present -> return TRUE
            ii. if other than * any other char present -> return FALSE
    c.  if i(s) is present , but j(p) has reached its end ,
         ( i>=0 && j<0 ) -> return FALSE


*/

#include <iostream>
using namespace std;

bool isMatch(string s, string p, int i, int j)
{
    // base cases :
    if (i == 0 && j == 0)
        return true;
    if (i > 0 && j == 0) // pattern has ended
        return false;
    if (i == 0 && j > 0) // ip str has ended
    {
        // run a loop to check if there are char other than *
        for (int k = j - 1; k >= 0; k--)
        {
            if (p[k] != '*')
                return false;
        }
        return true;
    }

    // recr cases :

    // 1. match case : both move to next
    // 2. if ? case in j : then also equal to a match : both move
    if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
        return isMatch(s, p, i - 1, j - 1);

    // 2. * case for j : if replace with seq of char || replace with empty str
    // we can get the ans in any of the 2 cases for ips.
    else if (p[j - 1] == '*')
    {
        return isMatch(s, p, i - 1, j) || isMatch(s, p, i, j - 1);
    }
    else
        return false;
}

int main()
{
    string s = "abcd";
    string p = "*cd";

    // i -> length of s
    // j -> length if j

    bool result = isMatch(s, p, s.length(), p.length());
    cout << result << endl;
}