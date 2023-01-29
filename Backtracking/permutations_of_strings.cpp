/*
******************

HW:
Find permutations of str if it has repeated chars

Problem statement :
Permutations of strings :
Given a string as input
Op : print all permutations of string given

Eg: s = abc
op :
abc
acb
bac
bca
cab
cba

No. of permuations = len(s)! = factorial of len of string

..................................................................................................

Approach :

1.  If we look at the op, "a" , "b", "c" comes in all the 3 positions in the string in op
2.  So we need to run a loop (j) for length of str to track the indexes for each
    char in the op
3.  To do this swap with that char with the char which was present in that index (j)
4.  So , we need to solve for one char in the str and remaining chars are solved by recr

..................................................................................................

Algorithm :

1.  Base case : when for every case , if we reach to the len of the str, then we have a
    particular output and that has to be stored and returned

    { n = len of ip str }
2.  For every char in ip str , we have total n options to be swapped with , so run a loop

    j = i ; j < n ; j++

    Here i repr the char index in the ip string

3.  Now within the for loop , we do the swapping of char on indexes i and j
    swap (str[i] , str[j])

4.  Then after the swap , next recr call goes for the next ele in ip str , with making i
    forward.

    solve (i+1, str);

    swap (str[i] , str[j]); ************  -> BACKTRACKING


    // The str sent in recr call , then it is sent BY REFERENCE
    So for the next recr call from parent for incremented i value , will have the
    swapped str values and the op with the next recr call from parent will give wrong
    ans
    So if we again swap the ele after the child recr call , then the recr call for the
    parent will be in its original state when it has made the curr recr call.

    Hence we do a re swap after we complete the child recr.
    This is called Backtracking.

    If we didnt do by byreference in function call , then backtrcking isnt needed
    But that function is depeneded on the question posed on us.



..................................................................................................
*/

#include <iostream>
#include <vector>
using namespace std;

void findPermutations(string &str, vector<string> &op, int index)
{
    // base case
    if (index == str.length())
    {
        op.push_back(str);
        return;
    }

    // for each char in ip , swap with all pos
    for (int j = index; j < str.length(); j++)
    {
        swap(str[index], str[j]);
        findPermutations(str, op, index + 1);
        // backtrack to original str
        swap(str[index], str[j]);
    }
}

int main()
{
    string str = "xyz";
    vector<string> output;
    int index = 0;

    findPermutations(str, output, index);

    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << endl;
    }
}