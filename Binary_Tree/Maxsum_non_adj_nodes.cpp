/*
MAX sum of non- adj nodes in a tree :
Given a tree , select those nodes which can give the max sum.
But these nodes should not be adj to one another.

Refer notes for logic and explaination !!!

https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1
*/

class Solution
{
public:
    pair<int, int> solve(Node *root)
    {
        if (root == NULL)
        {
            return make_pair(0, 0);
        }

        // make recr call for child nodes
        pair<int, int> leftAns = solve(root->left);
        pair<int, int> rightAns = solve(root->right);

        // calc options
        // include curr node
        int op1 = root->data + leftAns.second + rightAns.second;

        // excluded curr node
        int op2 = 0 + max(leftAns.first, leftAns.second) + max(rightAns.first, rightAns.second);

        // cout<<"root = "<<root->data<<" op1 = " <<op1 << " op2 = " <<op2 << endl;

        return make_pair(op1, op2);
    }
    int getMaxSum(Node *root)
    {
        // DS to store the 2 option answers
        // first=included sum ; second=excluded sum
        pair<int, int> ans = solve(root);
        return max(ans.first, ans.second);
    }
};