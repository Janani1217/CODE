#include <iostream>
using namespace std;

/*
1. build tree
2. print inorder
3. check mirror
4. height/max depth of tree
*/

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *buildTree(node *root)
{
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
        return NULL;

    root->left = buildTree(root->left);
    root->right = buildTree(root->right);

    return root;
}

void printInOrder(node *root)
{
    if (root == NULL)
        return;

    cout << root->data << "\n";
    printInOrder(root->left);
    printInOrder(root->right);

    return;
}

// treat as 2 different trees and has 2 pointers
bool checkBothSides(node *r1, node *r2)
{
    // base cases
    // 1.if both node is null
    if (r1 == NULL && r2 == NULL)
        return true;

    // 2. if one is null and other is not null, then not mirror
    if (r1 == NULL && r2 != NULL)
        return false;

    if (r1 != NULL && r2 == NULL)
        return false;

    // 3. now both nodes are present , so check the data contained , it should be same if mirror
    if (r1->data != r2->data)
        return false;

    /* r1's left node will be the r2's right node if seen in mirror, and they both should be
       same if they are mirror , and vice versa , so need to check like this and in both
       conditions it should return true
    */

    bool op1 = checkBothSides(r1->left, r2->right);
    bool op2 = checkBothSides(r1->right, r2->left);
    bool bothSameOrNot = op1 && op2;

    return bothSameOrNot;
}

// check whether left and right of the tree is mirror or not
bool checkMirror(node *root)
{
    if (root == NULL)
        return true;
    return checkBothSides(root->left, root->right);
}

/* max depth = no. of nodes in the longest path from root down to farthest leaf node
   Find the max depth or height of tree
*/

int findHeight(node *root)
{
    // base case
    if (root == NULL)
        return 0;

    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    return max(leftHeight, rightHeight) + 1;
}

int main()
{
    node *root = NULL;
    root = buildTree(root);
    // 3 4 -1 -1 4 -1 -1
    //  printInOrder(root);

    // bool isMirror = checkMirror(root);
    // cout << isMirror << "\n";

    int depth = findHeight(root);
    cout << depth << "\n";

    return 0;
}