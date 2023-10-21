/*
Bottom view of BT :

Approach :
Last nodes in the distance map , is produced as the output.

https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab
.................................................................................................

*/

class Solution
{
public:
    vector<int> bottomView(Node *root)
    {
        // DS needed
        // map : 1-Dist , 2 - level , 3 - vector of nodes
        map<int, vector<int>> mp;

        // queue : travel level order : 1-Node , 2-level , 3-dist
        queue<pair<Node *, int>> q;

        vector<int> ans;
        if (root == NULL)
            return ans;

        q.push(make_pair(root, 0));

        while (!q.empty())
        {
            pair<Node *, int> curr = q.front();
            q.pop();

            Node *node = curr.first;
            int dist = curr.second;

            // insert into map
            mp[dist].push_back(node->data);

            if (node->left)
                q.push(make_pair(node->left, dist - 1));

            if (node->right)
                q.push(make_pair(node->right, dist + 1));
        }

        // get the ans
        for (auto i : mp)
        {
            vector<int> temp = i.second;
            ans.push_back(temp.back());
        }

        return ans;
    }
};