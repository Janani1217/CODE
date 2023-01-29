/*
Problem statement :

Given a dictionary of words , and a string s .
Need to find if we can make this s with using words in dict , we can repeatedly
use the words to make S.
Return true if yes or else false.

Eg:
s = "catsandog"
wordDict = ["cats","dog","sand","and","cat"]

Approach :

1.  take substr from S and check in dict if present or not

    "c" -> ? -> no
    "ca" -> ? -> no
    "cat" -> ? -> no
    "cats" -> ? -> TRUE

    "a"
    "an"
    "and" -> TRUE

    "o"
    "og" -> no -> FALSE

    S ended -> BASE CASE -> return

    op : return false

2.  Data structures to be used -> we can pass substr or the index for the
    start and end of the str to be checked.

3.  We can use map<string,bool> to store the wordDict to check if the str
    is present of not.

    or else since vector , we can use find() to get whether the substr is present
    or not in the dict.

4.  base case : if we have reached till end successfully , then return true.
    if we could not have reached till end , in between it would have returned false




*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string.h>
using namespace std;

bool isWord(string s, unordered_map<string, bool> &present, int start)
{

    // base case
    if (s.length() == 0)
        return true;

    // remaining cases
    for (int i = start + 1; i < s.length() + 1; i++)
    {
        string left = s.substr(0, i);
        string newS = s.substr(i, s.length() - 1);
        if (present[left] && isWord(newS, present, 1))
            return true;
    }
    return false;
}

int main()
{
    string s = "catsandog";
    vector<string> wordDict;
    wordDict.push_back("cats");
    wordDict.push_back("dog");
    wordDict.push_back("sand");
    wordDict.push_back("and");
    wordDict.push_back("cat");

    // map all the words in dict to map
    unordered_map<string, bool> present;
    for (auto i : wordDict)
    {
        present[i] = true;
    }

    cout << "result = " << isWord(s, present, 0) << endl;
}