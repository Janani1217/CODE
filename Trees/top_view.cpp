/*
Top view of a binary tree : print nodes visible from top view of a binary tree

https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1

Refer vertical order , for logic reference.
Print the nodes present in the map vector , only for the first node.

.................................................................................................

*/

class Solution
{
public:
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        // 2 main imp data structures :
        // map : first = distance ; second = vector of nodes for that dist
        map<int, vector<int>> mp;
        // level order : queue needed : first = node, second = dist
        queue<pair<Node *, int>> q;

        q.push(make_pair(root, 0));

        while (!q.empty())
        {
            pair<Node *, int> curr = q.front();
            q.pop();

            Node *node = curr.first;
            int dist = curr.second;

            // insert into map also:
            mp[dist].push_back(node->data);

            if (node->left)
            {
                q.push(make_pair(node->left, dist - 1));
            }
            if (node->right)
            {
                q.push(make_pair(node->right, dist + 1));
            }
        }

        // now collect ans from the map

        for (auto i : mp)
        {
            vector<int> temp = i.second;
            ans.push_back(temp[0]);
        }

        return ans;
    }
};
