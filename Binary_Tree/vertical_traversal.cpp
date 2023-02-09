/*
Vertical order Traversal :

Draw vertical lines from top to bottom moving from left to right
Print all the nodes present in those vertical lines fron start to end.
So the nodes which overlap in the line , printed as they are in line from left to right.
lines are made : top to bottom = vertical lines.

.................................................................................................

PLEASE REFER NOTES for clear explaination !!!

.................................................................................................

Approach :

1.  there is a number line.

.................................................................................................

https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

.................................................................................................

*/

class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        // create the DS needed :
        map<int, map<int, vector<int>>> list;
        queue<pair<TreeNode *, pair<int, int>>> q;

        vector<vector<int>> ans;

        if (root == NULL)
            return ans;

        // 1. do level order traversal
        // push the root node in the queue

        // dist = 0 , level = 0
        q.push(make_pair(root, make_pair(0, 0)));

        while (!q.empty())
        {
            pair<TreeNode *, pair<int, int>> curr = q.front();
            q.pop();

            TreeNode *node = curr.first;
            int dist = curr.second.first;
            int level = curr.second.second;

            // push into map
            // first - dist ; second - lvel ; third - list of nodes data
            list[dist][level].push_back(node->val);

            if (node->left != NULL)
            {
                q.push(make_pair(node->left, make_pair(dist - 1, level + 1)));
            }
            if (node->right != NULL)
            {
                q.push(make_pair(node->right, make_pair(dist + 1, level + 1)));
            }
        }

        // form the ans
        for (auto i : list)
        {
            vector<int> temp;
            for (auto j : i.second)
            {
                sort(j.second.begin(), j.second.end());
                for (auto k : j.second)
                {
                    temp.push_back(k);
                }
            }
            ans.push_back(temp);
        }

        return ans;
    }
};