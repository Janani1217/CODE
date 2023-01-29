/*
PS :
Given 2 trees, find if the trees are identical or not.

Identical : structurally identical and nodes have the same value.

Corner cases are very imp here !!!
.................................................................................................

https://leetcode.com/problems/same-tree/

.................................................................................................

*/

class Solution
{
public:
    bool solve(TreeNode *p1, TreeNode *p2)
    {
        // base cases :
        if ((p1 == NULL && p2 != NULL) || (p1 != NULL && p2 == NULL))
            return false;

        if (p1 == NULL && p2 == NULL)
            return true;

        if (p1->left == NULL && p2->left != NULL)
            return false;

        if (p1->right == NULL && p2->right != NULL)
            return false;

        if (p1->left != NULL && p2->left == NULL)
            return false;

        if (p1->right != NULL && p2->right == NULL)
            return false;

        bool leftAns = solve(p1->left, p2->left);
        bool rtAns = solve(p1->right, p2->right);

        if (leftAns && rtAns && (p1->val == p2->val))
            return true;

        return false;
    }
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        return solve(p, q);
    }
};