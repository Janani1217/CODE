/*
PS : Implement phone directory :
Given a list of strings -> contacts that exists
Search for string str -> this has to display all words with prefix as the str
NOTE : after we enter each char , the recommendations has to be shown.

If no suggestions found, return empty array.


.................................................................................................

https://www.codingninjas.com/codestudio/problems/implement-a-phone-directory_1062666

.................................................................................................

Approach :

1. prefix = ""
2. prev node = root node
3. given string str = ninja

Loop through str each char :

4. lastChar = n (taking the ch in str)

5. check in prev node , if any child of it is having char == lastChar
6. if found ->
    a. curr node = child with ch
    b. print all suggestions till all terminal nodes

7. prev = curr
8. continue till str is traversed.
........................

printSuggestions (curr node , temp arr of strings, prefix)

1. its a recursive call , so base case :
        a. bc : if we reach a terminal node , put in temp storage
        b. we arent returning after that because it may continue and can have another
           terminal node below in the path which will form another word with prefix.

2.


.................................................................................................

TC : O(n * m2)
n = length of given target string to compare
k = 26 times the loop runs
m = average length of all strings



SC : O(n * m)
n = total no. strings in trie
m = avg length of all strings
*/

#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = false;
        }
        isTerminal = false;
    }
};

class Trie
{
    TrieNode *root;

    Trie(char ch)
    {
        root = new TrieNode(ch);
    }

    void insertUtil(TrieNode *root, string word)
    {
        // recr call : bc :
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }
        // rem cases
        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        insertUtil(child, word.substr(1));
    }

    void insert(string word)
    {
        insertUtil(root, word);
    }

    void printSuggestions(string &prefix, TrieNode *root, vector<int> &temp)
    {
        // recr call
        if (root->isTerminal == true)
        {
            // insert string collected till now into temp
            temp.push_back(prefix);
            // dont return , because further strings in trie could be present
        }

        // rem cases
        // for all the child nodes of root , store them in temp
        for (char i = 'a'; i < 'z'; i++)
        {
            TrieNode *child = root->children[i - 'a'];

            if (child != NULL)
            {
                // got the child - insert char
                prefix.push_back(i);
                // call further
                printSuggestions(prefix, child, temp);
                // after coming back , remove char from prefix, to traverse in some other paths
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getSuggestions(string queryStr)
    {
        // loop through all the char of this string
        TrieNode *prev = root;
        string prefix = "";
        vector<vector<string>> ans;

        for (int i = 0; i < queryStr.length(); i++)
        {
            char ch = queryStr[i];

            // push the current ch in prefix
            prefix.push_back(ch);

            // need to know if the root has this in its child or not
            TrieNode *curr = prev->children[ch - 'a'];

            if (curr == NULL)
            {
                break;
            }

            // else start storing the suggestions
            vector<string> temp; // temp storage of strings with prefix
            printSuggestions(prefix, temp, curr);

            ans.push_back(temp);
            prefix.clear();
            prev = curr;
        }
        return ans;
    }
};

vector<vector<string>> solve(vector<string> &contactList, string &queryStr)
{
    // create trie
    Trie *root = new Trie('\0');

    // insert all strings into it
    int n = contactList.size();
    for (int i = 0; i < n; i++)
    {
        insert(contactList[i]);
    }

    // get all suggestions for query string
    root->getSuggestions(queryStr);
}