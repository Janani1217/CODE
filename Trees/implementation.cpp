/*

Tree :
Its a non - linear data structure which holds information.
Every node in a tree is actually present in different memory addreses when created.


Binary Tree :
Its a tree with less than or equal to 2 child nodes.

Node {
    int data;
    Node *left;
    Node *right;
}

Ancestor : all the nodes present above a node.
Descendor : all nodes present below a node in tree.

.................................................................................................


Multiple children -> non - binary tree

Node_multi {
    int data;
    list<Node *> children;
}

.................................................................................................

*/

#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// create a function to create a tree
Node *buildTree(Node *root)
{
    int ip;
    cout << "enter the data" << endl;
    cin >> ip;
    root = new Node(ip);

    // terminating condition
    if (ip == -1)
        return NULL;

    cout << "enter data for left" << endl;
    root->left = buildTree(root->left);

    cout << "enter data for right" << endl;
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(Node *root)
{
    // print the tree in level order :
    // level order -> kind of  -> BFS
    queue<Node *> q;
    q.push(root);
    // acts as a seperator for level printing
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            // comes under seperate level
            cout << endl;
            // check if q has some child nodes or not
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
}

void inorder(Node *root)
{
    // bc :
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data;
    inorder(root->right);
}

void preOrder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data;
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root)
{
    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 1 2 3 4 5 6 7 8 9 -1 -1 -1 -1 -1 -1 -1 -1 -1
    // print level order in the form of tree levels only
    levelOrderTraversal(root);

    // L N R
    inorderPrint(root);

    // L R N
    preOrder(root);

    // N L R
    postOrder(root);
}