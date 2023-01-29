/*
Problem statement :
Generate Parentheses :
Given n , which repr the pair of parenthesis with opn-closed brackets
Return total number of combinations well formed with those parenthesis

Eg :
n = 3 :() () ()
OP :
((())) , (())() , ()(()) , ()()() , (()())

Eg :
n = 1 :()
OP :
()

....................................................................................................
....................................................................................................

Analysis :

1.  Here same as include-exclude pattern : either include the brace or exclude
    it -> based on conditions.
2.  Given if n=3 , then total braces will be n*2 = 6 position -> so for each pos
    check for include - exclude

Conditions :

n = 3 :
total open braces = 3
total close braces = 3

1.  In any expression, the first pos will always have open brace : (
    So remaining open brace = 2 , closed rem = 3

    currOpen = 1
    currClose = 0
    remOpen = 2 : n-1
    remClose = 3 : n

2.  Valid combination conditions : base case
    currOpen = n && currClose = n
    or
    remOpen = 0 && remClose = 0

    store the result and return

3.  Valid open bracket placement : check whether it is present or not
    Then insert and call for the next pos
    Then after completing the recr call, pop back the inserted char
    so that the next combination it can try for.

4.  Valid close bracket placement :
    First : it should be available
    Second : CURR OPEN BRACES > CURR CLOSED BRACES : ****************************
    Then only there is a valid requirement for the another closed brace to be
    inserted.
    So then make the recr call.
    Backtrack and pop out.

 ....................................................................................................
 ....................................................................................................

*/

#include <iostream>
#include <vector>
using namespace std;

void getParenthesis(string &temp, int currOpen,
                    int currClose, int remOpen, int remClose, vector<string> &result)
{
    // base case
    if (remOpen == 0 && remClose == 0)
    {
        result.push_back(temp);
        return;
    }

    /*
    open brace recr call : with condition :
    1. rem open braces should be available
    */

    if (remOpen > 0)
    {
        temp.push_back('(');
        getParenthesis(temp, currOpen + 1, currClose, remOpen - 1, remClose, result);
        // backtrack : for moving to try for next combination
        temp.pop_back();
    }

    /*
    close brace recr call : with conditions :
    1. close brace must be available
    2. count of currOpen > cuurClose
    */

    if (remClose > 0 && currOpen > currClose)
    {
        temp.push_back(')');
        getParenthesis(temp, currOpen, currClose + 1, remOpen, remClose - 1, result);
        temp.pop_back();
    }
}

int main()
{
    int n = 3;
    vector<string> result;
    string temp = "(";

    int currOpen = 1;
    int currClose = 0;
    int remOpen = n - 1;
    int remClose = n;

    getParenthesis(temp, currOpen, currClose, remOpen, remClose, result);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }
}