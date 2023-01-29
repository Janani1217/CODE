/*
Find the height of Binary tree

Height : Depth of tree : longest path between root node and a leaf node

.................................................................................................

https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1

.................................................................................................

TC : O(n) : skewed tree then recr stack will contain all nodes
SC : O(n) : skewed tree then recr stack will contain all nodes

.................................................................................................

*/

class Solution
{
public:
    // Function to find the height of a binary tree.
    int heightUtil(Node *node)
    {
        if (node == NULL)
            return 0;

        int leftHeight = 1 + heightUtil(node->left);
        int rightHeight = 1 + heightUtil(node->right);

        int ans = max(leftHeight, rightHeight);
        return ans;
    }
    int height(struct Node *node)
    {
        // code here
        return heightUtil(node);
    }
};
