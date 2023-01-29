/*
Boundary traversal :
print all left sided node + all leaf nodes + all right soded nodes from bottom to top

Approach :

1.  print left part of tree (except leaf node) ; stop wehn u reach leaf node
2.  print all leaf nodes from left to right
3.  print right part : (except leaf node) : bottom to top till root (dont print root)

Algorithm :

First insert the root node data in answer.

1. Print left : (root->left)

    1.  insert node data
    2.  travrse all left nodes till leaf encountered.
    3.  if there is no left node , go its right node and traverse left again.

2.  Print all leaf nodes present in left subtree (root->left)
3.  Print all leaf nodes present in right subtree (root -> right)

4.  Right : (root -> right)

    1.  dont print leaf nodes
    2.  first call the right part if present
    3.  if no right node , go to its left part
    4.  Now enter the node data. (after coming back of recr call)


.................................................................................................

TC : O(n)

https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

.................................................................................................

*/

class Solution
{
public:
    void leftTraversal(vector<int> &ans, Node *root)
    {
        if (root == NULL)
            return;

        if (root->left == NULL && root->right == NULL)
            return;

        ans.push_back(root->data);

        if (root->left)
        {
            leftTraversal(ans, root->left);
        }
        else
        {
            leftTraversal(ans, root->right);
        }
    }

    void rightTraversal(vector<int> &ans, Node *root)
    {
        if (root == NULL)
            return;

        if (root->left == NULL && root->right == NULL)
            return;

        if (root->right)
        {
            rightTraversal(ans, root->right);
        }
        else
        {
            rightTraversal(ans, root->left);
        }
        // ******* //
        ans.push_back(root->data);
    }

    void leafTraversal(vector<int> &ans, Node *root)
    {
        if (root == NULL)
            return;

        if (root->left == NULL && root->right == NULL)
        {
            ans.push_back(root->data);
            return;
        }

        leafTraversal(ans, root->left);
        leafTraversal(ans, root->right);
    }

    vector<int> boundary(Node *root)
    {
        vector<int> ans;

        if (root == NULL)
            return ans;

        ans.push_back(root->data);
        // print the left part
        leftTraversal(ans, root->left);

        // ******* //

        // print all left leaf nodes
        leafTraversal(ans, root->left);

        // ******* //

        // print all right leaf nodes
        leafTraversal(ans, root->right);

        // print right nodes
        rightTraversal(ans, root->right);

        return ans;
    }
};
