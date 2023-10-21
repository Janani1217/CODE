/*
lowest common ancestor :
Given 2 nodes , and a binary tree.
But find the lowest common ancestor of both of these nodes.
Lowest =  ancestor which is nearest to these 2 nodes.
There can be more ancestors , present above this , but this will be
the lowest common one.

https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
*/

class Solution
{
public
    TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q)
    {

        // found any one of the node
        if (root == null || root == p || root == q)
            return root;

        TreeNode left = lowestCommonAncestor(root.left, p, q);
        TreeNode right = lowestCommonAncestor(root.right, p, q);

        if (left != null && right != null)
            return root;

        else if (left != null)
            return left;

        return right;
    }
}

/*
class Solution
{
public:
    TreeNode *solve(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // solved using recr
        // base cases:
        if (root == NULL)
            return NULL;

        if (root == p || root == q)
            return root;

        // rem cases
        TreeNode *leftAns = solve(root->left, p, q);
        TreeNode *rightAns = solve(root->right, p, q);

        // ans needed
        if (leftAns != NULL && rightAns != NULL)
            return root;

        if (leftAns != NULL)
            return leftAns;

        if (rightAns != NULL)
            return rightAns;

        return NULL;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
            return NULL;

        TreeNode *ans = solve(root, p, q);
        return ans;
    }
};
*/