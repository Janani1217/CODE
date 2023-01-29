/*
Problem statement :
Sum of nodes withinh k distance from the target;

Given a tree with root, value of the target node, and a value of k.

Return the sum of all the nodes present in the k distance to the target
including the target node itself.


--> leetcode :
All Nodes Distance K in Binary Tree

--> Explaination in notebook : since a repr of tree


....................................................................................................................
....................................................................................................................

Approach:

1.  create a node-parent mapping to go above the node for k distances also : TC = O(n)

    1.1     To make a recr call from node back to its parent node, we need to create this.

    1.2     For that DS : unordered map <int, node*> : if given data is unique
                            (OR)
                          unordered map <node*, node*> : if given data is not unique

            For the root node , create a dummy node as parent and insert :
                    Node *node = new Node(-1);
                    mapping[root] = node;

    1.3     To fill the data , do a tree traversal : create a new function(mapping, root):

            1.3.1   if root is null - return
            1.3.2   if(root->left != NULL) {
                        mapping[root->left] = root;
                        func(mapping, root->left);
                    }
            1.3.3   if(root->right != NULL) {
                        mapping[root->right] = root;
                        func(mapping, root->right);
                    }



2.  find target node -> O(n) : create a function(root, target) for the search :

    2.1     if root is null -> return null;
    2.2     if (root->data) == target -> return root;

    2.3     Node *left = function (root->left , target);
            if (left != NULL) -> return left ;

    2.4     Node *right = function (root->right , target);
            if (right != NULL) -> return right ;


3.  traverse in each directions for k steps from the target node :
    3.1 recr call 1 : goto left part
    3.2 recr call 2 : goto right part
    3.3 recr call 3 : goto parent

    TC : O(n) : create a function (target, k , &sum, map <node* , bool> visited , mapping) for this :

    3.1     if (k < 0) return;
    3.2     if (visited[target] == true) {
                return ;
            }

    3.3     if (target == NULL) return;

    3.4     visited[target] = true;

    3.4     sum = sum + root->data + func( target->left , k-1 , sum , visited )
                                   + func( target->right , k-1 , sum , visited)
                                   + funct( mapping[taregt] , k-1 , sum , visited) ;

4.  Total TC : O(n)

....................................................................................................................
....................................................................................................................

*/

#include <iostream>
#include <unordered_map>
#include <iterator>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void printCurrentLevel(Node *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";

    else if (level > 1)
    {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

int height(Node *root)
{
    if (root == NULL)
        return 0;

    int left = height(root->left);
    int right = height(root->right);
    return 1 + max(left, right);
}

void printLevelOrder(Node *root)
{
    int h = height(root);
    for (int i = 1; i <= h; i++)
    {
        // print wrt height/level of tree
        printCurrentLevel(root, i);
    }
}

void fillMapping(Node *root, unordered_map<Node *, Node *> &parent)
{
    if (root == NULL)
        return;

    if (root->left != NULL)
    {
        parent[root->left] = root;
        fillMapping(root->left, parent);
    }
    if (root->right != NULL)
    {
        parent[root->right] = root;
        fillMapping(root->right, parent);
    }
}

Node *searchTarget(Node *root, int target)
{
    if (root == NULL)
        return NULL;

    if (root->data == target)
        return root;

    Node *left = searchTarget(root->left, target);
    if (left != NULL)
        return left;

    Node *right = searchTarget(root->right, target);
    if (right != NULL)
        return right;

    return NULL;
}

void findSum(int k, Node *target, unordered_map<Node *, Node *> parent,
             int &ans, unordered_map<Node *, bool> vis)
{
    if (k < 0)
        return;

    if (target == NULL)
        return;

    if (vis[target] == true)
        return;

    vis[target] = true;
    ans = ans + target->data;

    cout << ans << endl;

    findSum(k - 1, target->left, parent, ans, vis);
    findSum(k - 1, target->right, parent, ans, vis);
    findSum(k - 1, parent[target], parent, ans, vis);
}

int solve(Node *root, int k, int target)
{

    if (root == NULL)
        return 0;

    // step 1 : create node - parent mapping and fill it
    unordered_map<Node *, Node *> parent;

    Node *dummy = new Node(-1);
    parent[root] = dummy;
    fillMapping(root, parent);

    // step 2 : search target : do traversal
    Node *targetNode = searchTarget(root, target);

    // step 3 : find total sum from k distance from target
    int ans = 0;
    unordered_map<Node *, bool> visited;
    findSum(k, targetNode, parent, ans, visited);

    return ans;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);
    root->left->right->right->right = new Node(8);

    // printLevelOrder(root);

    // solution to problem :
    int k = 1;
    int target = 5;
    int sum = solve(root, k, target);
    cout << "sum = " << sum << endl;
    return 0;
}