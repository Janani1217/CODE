/*
PS :
Check a binary tree is balanced or not.

Balanced tree = height balanced tree = if difference of left and right subtrees height is
not more than 1 FOR ALL NODES !!


Approach :

abs[height_left_subtree] - abs[height_right_subtree] <= 1

1.  op1 = check for left -> balanced or not
2.  op2 = check for rt -> balanced or not
3.  ans1 = ht_left
4.  ans2 = ht_right

5.  if(op1 && op2) && (abs[ans1] - abs[ans2] <= 1)
    return TRUE !!

.................................................................................................

https://leetcode.com/problems/balanced-binary-tree/

.................................................................................................

*/

#include <bits/stdc++.h>
class Solution
{
public:
    int height(TreeNode *root)
    {
        // recr call : bc
        if (root == NULL)
            return 0;

        return max(height(root->left), height(root->right)) + 1;
    }

    /*
    TC : O(N2)
    */
    bool isBalancedUtil(TreeNode *root)
    {
        // recr call : bc : null node always balanced
        if (root == NULL)
            return true;

        // leaf node is always balanced
        if (root->left == NULL && root->right == NULL)
            return true;

        bool op1 = isBalancedUtil(root->left);
        bool op2 = isBalancedUtil(root->right);

        int ht1 = height(root->left);
        int ht2 = height(root->right);

        /* ************** */
        if ((op1 && op2) && (abs(abs(ht1) - abs(ht2)) <= 1))
            return true;

        return false;
    }

    /*
    TC : O(N)
    */
    // first = balanaced or not ; second = height ;
    pair<bool, int> solveOP(TreeNode *root)
    {
        // bc :
        if (root == NULL)
        {
            pair<bool, int> p;
            p = make_pair(true, 0);
            return p;
        }

        // rem cases
        pair<bool, int> op1 = solveOP(root->left);
        pair<bool, int> op2 = solveOP(root->right);

        int leftHt = op1.second;
        int rightHt = op2.second;

        bool leftBal = op1.first;
        bool rightBal = op2.first;

        int height = max(leftHt, rightHt) + 1;

        bool balanced = false;
        if ((leftBal && rightBal) && (abs(abs(leftHt) - abs(rightHt)) <= 1))
            balanced = true;

        pair<bool, int> answer;
        answer.first = balanced;
        answer.second = height;

        return answer;
    }

    bool isBalanced(TreeNode *root)
    {
        int ans1 = isBalancedUtil(root);

        pair<bool, int> ans;
        ans = solveOP(root);
        return ans.first;
    }
};