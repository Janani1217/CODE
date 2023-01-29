/*
Problem statement :
Given a binary tree, return all root to leaf path in any order.

OP : Return a vector<string>, so here string is the path.
< "1->2->3->4" , "1->5->6" , "1->5->->7->8" >

Explained with diagrams in note.

......................................................................................................
......................................................................................................

Algorithm :

1.  Base case : reaching leaf node :
    push the data into curr str
    Then push the str into vector ans
    then pop the root data
    pop the arrow inserted
    return.

2.  Remaining case :
    Check for both left and right node of root
    add the root data to curr str
    add the arrow ->
    move forward/call recr to child whoever present

......................................................................................................
......................................................................................................

Pass the answer vector as the reference.

We cant backtrack at the leaf node , because it will go up only 1 level.
But there might be cases , where we need to go 2 times , or more towards
the root.

So we have to do the backtracking in the remaining cases section after
the recr call has been made.

......................................................................................................
......................................................................................................

*/

#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

int height(Node *root)
{
    if (root == NULL)
        return 0;

    int left = height(root->left);
    int right = height(root->right);
    return 1 + max(left, right);
}

void printCurrentLevel(Node *root, int height)
{
    if (root == NULL)
        return;

    if (height == 1)
        cout << root->data << " ";

    else if (height > 1)
    {
        printCurrentLevel(root->left, height - 1);
        printCurrentLevel(root->right, height - 1);
    }
}

void printLevelOrderBinaryTree(Node *root)
{
    if (root == NULL)
        return;
    // to print level order , get the height of tree first
    int h = height(root);

    // print for every height accordingly
    for (int i = 1; i <= h; i++)
    {
        printCurrentLevel(root, i);
        cout << endl;
    }
}

void printAllPaths(Node *root, vector<string> &ans, string str)
{
    // base cases:
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        str = str + to_string(root->data);
        ans.push_back(str);
        return;
    }

    string oldStr = str;
    // remaining cases :
    str = str + to_string(root->data);
    str.push_back('-');
    str.push_back('>');

    printAllPaths(root->left, ans, str);
    printAllPaths(root->right, ans, str);

    /*
     backtrack : no need to use pop multiple times to remove prev , just
     store the old str value and copy here.
    */

    str = oldStr;
}

int main()
{
    Node *root = new Node(1);

    // create a binary tree
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);

    // printLevelOrderBinaryTree(root);
    vector<string> ans;
    string str = "";
    printAllPaths(root, ans, str);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
}