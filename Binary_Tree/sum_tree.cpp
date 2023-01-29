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