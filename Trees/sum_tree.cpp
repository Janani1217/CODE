/*

PS :
Sum Tree = For every node , X in the tree other than the leaves , its value is equal
to the sum of its left subtree and its right subtree value . Then return true.
Else return false;

Empty tree is also a sum tre.
A leaf node is also a sum tree.

.................................................................................................

https://practice.geeksforgeeks.org/problems/sum-tree/1

.................................................................................................

*/
class Solution
{
    boolean solve(Node root)
    {
        if (root == null || (root.left == null && root.right == null))
            return true;

        int ls = 0;
        int rs = 0;

        // non leaf node checks
        if (solve(root.left) == true && solve(root.right) == true)
        {
            if (root.left == null)
                ls = 0;
            else if (root.left.left == null && root.left.right == null)
                ls = root.left.data;
            else
                ls = 2 * (root.left.data); // assuming its a sum tree

            if (root.right == null)
                rs = 0;
            else if (root.right.left == null && root.right.right == null)
                rs = root.right.data;
            else
                rs = 2 * (root.right.data);

            if (root.data == ls + rs)
                return true;
        }
        return false;
    }
    boolean isSumTree(Node root)
    {
        // Your code here
        return solve(root);
    }
}
/*
class Solution
{
public:
    // first = if sum tree or not ; second = actual sum of tree
    pair<bool, int>
    solve(Node *root)
    {
        // bc :
        if (root == NULL)
        {
            pair<bool, int> p;
            p = make_pair(true, 0);
            return p;
        }

        // leaf : sum = value
        if (root->left == NULL && root->right == NULL)
        {
            pair<bool, int> p;
            p = make_pair(true, root->data);
            return p;
        }

        pair<bool, int> leftAns = solve(root->left);
        pair<bool, int> rightAns = solve(root->right);

        bool op1 = (leftAns.first && rightAns.first);
        int op2 = leftAns.second + rightAns.second;

        pair<bool, int> ans;

        ans.first = (op1 && (op2 == root->data));
        ans.second = op2 + root->data;

        return ans;
    }
    bool isSumTree(Node *root)
    {
        pair<bool, int> ans;
        ans = solve(root);
        return ans.first;
    }
};
*/