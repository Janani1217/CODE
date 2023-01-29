/*
********** VVImportant **********

Problem statement: Edit distance :

Given 2 words : word1 , word 2

Convert word1 to word2 with min number of below operations:
1. insert a char
2. delete a char
3. replace a char

Eg:
word1 = "horse"
word2 = "ros"

WAY1 :
del h
del o
r is match -> mov forward
repl s with o -> match
replace e with s -> match
TOTAL = 4 OPERTIONS = del ,del ,repl, repl

WAY2:
repl h -> r -> match
o is match -> move forward
del r
s -> match -> move forward
del e
TOTAL = 3 OPERTIONS = repl ,del ,del


Approach:
1. include if there is a match and call forward by moving both pointers ahead
2. if no match , then perform 3 operations and move forward if matched
3. find the min among them and then return that.
4. *** BASE condition : if any of the pointer(i or j) has reached its size of the word ,
   then there will be few situations :

        Situation 1 :

        a.  if suppose i is at 3rd index = word1
        b.  if j = word2 has reached its end
        c.  then now we have to convert word1 to word2, so anyhow we need to delete the
            remaing present in word1 after the i index, which is also an operation that
            has to be counted.
        d.  So once this situation arrives , then [ word1.length() - i ] will be added to
            answer.


        Situation 2 :

        a.  if suppose i has reached its end = word1.length()
        b.  if j has not reached yet. So here to convert word1 to word2, remaining ele in
            word2 has to be added to word1 to convert it complelety.
            So those are alos operations to be counted
        c.  Now [ word2.length() - j ] will be added to the answer
*/

#include <iostream>
using namespace std;

int minDistance(string word1, string word2, int i, int j)
{
    // base cases
    //  if i has reached word1 length
    if (i == word1.length())
    {
        return (word2.length() - j);
    }

    // if j has reached word2 length
    if (j == word2.length())
    {
        return (word1.length() - i);
    }

    // if there is a match
    if (word1[i] == word2[j])
    {
        return minDistance(word1, word2, i + 1, j + 1);
    }
    else
    {
        int insert_option = minDistance(word1, word2, i, j + 1);
        int delete_operation = minDistance(word1, word2, i + 1, j);
        int replace_operation = minDistance(word1, word2, i + 1, j + 1);
        return min(insert_option, min(delete_operation, replace_operation)) + 1;
    }
}
int main()
{
    string word1 = "horse";
    string word2 = "ros";
    int min_operations = minDistance(word1, word2, 0, 0);
    cout << min_operations << endl;
}