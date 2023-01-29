/*
Trie : Implementation :

Suppose we need to implement a dictionary.
We have many words in it. We can have 3 operations in it.
1. insert word
2. delete word
3. search word

What could be the DS to handle these operations in a dictionary?
We will get the idea of HASHMAP.
map<string, bool> dict;

insert , search, remove => O(1) time - constant time.

BUT !!!
The TC will be O(1) using hashmap for these oper, only in AVERAGE CASE.
But in WORST CASE it will be different.

  Suppose a word = "absndkcn......ewdwf" of length = l.
  dict.insert("absndkcn......ewdwf") ;  -> actually will take O(l) time to insert operation in
  hashmap
  O(l) - insert , search , remove in hashmap for worst case.

.................................................................................................

Trie :
Its a DS just a tree with multiple child nodes.

Refer Note book for further clarification !!!

https://www.codingninjas.com/codestudio/problems/implement-trie_631356?leftPanelTab=1

*/

class TrieNode
{
public:
  char data;
  TrieNode *children[26];
  bool isTerminal;

  TrieNode(char w)
  {
    data = w;
    for (int i = 0; i < 26; i++)
    {
      children[i] = NULL;
    }
    isTerminal = false;
  }
};

class Trie
{
  TrieNode *root;

public:
  Trie()
  {
    // null char as in root node
    root = new TrieNode('\0');
  }
  /** Inserts a word into the trie. */

  // recursive function
  void insertUtil(TrieNode *root, string word)
  {
    // base case:
    if (word.length() == 0)
    {
      // reached end
      root->isTerminal = true;
      return;
    }

    // rem case
    // 1. find the index of curr char in the word
    int index = word[0] - 'a';

    // traversal temp node
    TrieNode *child;

    // 2. check if char present in trie
    if (root->children[index] != NULL)
    {
      // already present -> move ahead
      child = root->children[index];
    }
    else
    {
      // char not present, then insert node with char present in word:
      child = new TrieNode(word[0]);
      root->children[index] = child;
    }
    insertUtil(child, word.substr(1));
  }

  void insert(string word)
  {
    insertUtil(root, word);
  }

  bool searchutil(TrieNode *root, string word)
  {
    // base case:
    if (word.length() == 0)
    {
      if (root->isTerminal == true)
      {
        return true;
      }
    }

    // rem case
    // node for traversal:
    TrieNode *child;

    int index = word[0] - 'a';

    // if word present
    if (root->children[index] != NULL)
    {
      // word is present - move ahead
      child = root->children[index];
    }
    else
    {
      // word not present
      return false;
    }
    return searchutil(child, word.substr(1));
  }

  /** Returns if the word is in the trie. */
  bool search(string word)
  {
    return searchutil(root, word);
  }

  bool startsWithUtil(TrieNode *root, string word)
  {
    // bc :
    if (word.length() == 0)
    {
      return true;
    }

    // rem case;
    TrieNode *child;

    int index = word[0] - 'a';

    if (root->children[index] != NULL)
    {
      // word is present , move ahead
      child = root->children[index];
    }
    else
    {
      return false;
    }
    return startsWithUtil(child, word.substr(1));
  }

  /** Returns if there is any word in the trie that starts with the given prefix. */
  bool startsWith(string prefix)
  {
    return startsWithUtil(root, prefix);
  }
};