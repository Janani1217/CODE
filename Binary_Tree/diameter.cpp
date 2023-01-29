/*
Diameter of tree :
Take any 2 nodes in the tree, find the longest path between any 2 nodes in a tree.

Approach :

Diameter can be found in 3 ways :

1.  the ans can be in left subtree only
2.  the ans can be in right subtree only
3.  the ans can be in both trees combined also

So for :
1.  solve(leftChild);
2.  solve(rightChild);

3.  solve(height(left) + 1 + height(right));

Here if both left and right subtrees and combined, then the tallest of left and tallest
of right will form the longest path and plus the root node so adding 1 in middle of it
while traversing.

4. Taking the max of all the 3 options will return the ans.
.................................................................................................

https://leetcode.com/problems/diameter-of-binary-tree/

.................................................................................................


*/

class Solution
{
public:
    int height(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        return 1 + max(height(root->left), height(root->right));
    }

    /*
    TC : O(n2)
    SC : O(n)
    */

    int solve(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int leftAns = solve(root->left);
        int rtAns = solve(root->right);
        int combined = height(root->left) + height(root->right);

        return max(leftAns, max(rtAns, combined));
    }

    /*
        TC : O(n)
        SC : O(n)
    */
    pair<int, int> solveOptimize(TreeNode *root)
    {
        if (root == NULL)
        {
            pair<int, int> p = make_pair(0, 0);
            return p;
        }

        pair<int, int> leftAns = solveOptimize(root->left);
        pair<int, int> rtAns = solveOptimize(root->left);

        int combined = leftAns.second + rtAns.second;
        int op1 = leftAns.first;
        int op2 = rtAns.first;
        int op3 = combined;

        pair<int, int> ans;

        ans.first = max(op1, max(op2, op3));
        ans.second = max(leftAns.second, rtAns.second) + 1;

        return ans;
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        int ans1 = solve(root);

        // optimized solution : removal of height calculation every time
        pair<int, int> ans;
        ans = solveOptimize(root);
        return ans.first;
    }
};