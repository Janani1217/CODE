/*
PS : Longest common prefix:

Given list of strings :
coding , code , codeninja , coder

Find the longest prefix in this
OP = "cod" = 3

....................................................................................................

Approach 1 :

1.  for loop 1 for 1st word
2.  for loop 2 : nested : compare every char od word_1 with the remaining chars present
    in the other words in the list.

3. TC = O(n * m)  // n = no. of words , m = max length of word
4. SC = O(1)


....................................................................................................

Approach 2 :

1.  form a trie ;
2.  take every node and insert into trie -> insertWord(root, word);  -> O(l)
3.  traverse in trie:

    if(child_count == 1)
    {
        ans ++;
    }
    else {
        return;
    }

    return ans;


Here the TC will ve equal to above approach
SC = O(n*m)

We can follow first approach also , but this is for understanding of trie usage.
....................................................................................................


https://www.codingninjas.com/codestudio/problems/longest-common-prefix_2090383?leftPanelTab=1

...................................................................................................

*/

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;
    int childCount;

    TrieNode(char w)
    {
        data = w;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};

class Trie
{
public:
    TrieNode *root;
    Trie(char ch)
    {
        root = new TrieNode(ch);
    }

    void insertWord(TrieNode *root, string word)
    {
        // bc:
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        // rem case
        //  traversal temp node :
        TrieNode *child;
        int index = word[0] - 'a';

        // if already present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // add the node
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childCount++;
        }
        insertWord(child, word.substr(1));
    }

    void insert(string word)
    {
        insertWord(root, word);
    }

    void solve(string str, string &ans)
    {
        // loop throu the entire word
        for (int i = 0; i < str.length(); i++)
        {
            char curr = str[i];

            if (root->childCount == 1)
            {
                // move ahead
                ans.push_back(curr);
                int index = curr - 'a';
                root = root->children[index];
            }
            else
            {
                // no need to move forward from here
                break;
            }
            if (root->isTerminal == true)
                break;
        }
    }
};

string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    Trie *root = new Trie('\0');

    // insert all the strings in the trie
    for (int i = 0; i < n; i++)
    {
        string word = arr[i];
        root->insert(word);
    }

    // all words got inserted into the trie
    // traverse till child is 1 only

    string ans = "";
    root->solve(arr[0], ans);

    return ans;
}
