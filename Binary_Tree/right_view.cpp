/*
Right side view of binary tree:
Only level and vector of nodes needed !!

https://leetcode.com/problems/binary-tree-right-side-view/
*/

class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;
        // based on level order
        // DS needed : map : 1-level
        map<int, vector<int>> mp;
        queue<pair<TreeNode *, int>> q;

        // insert root
        q.push(make_pair(root, 0));

        while (!q.empty())
        {
            pair<TreeNode *, int> curr = q.front();
            q.pop();

            TreeNode *node = curr.first;
            int level = curr.second;

            // insert into map
            mp[level].push_back(node->val);

            if (node->left)
                q.push(make_pair(node->left, level + 1));

            if (node->right)
                q.push(make_pair(node->right, level + 1));
        }

        // get ans
        for (auto i : mp)
        {
            vector<int> temp = i.second;
            ans.push_back(temp.back());
        }
        return ans;
    }
};