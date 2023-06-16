/*
Sum of longest bloodline of a tree = sum of all nodes present in longest path of tree
from root to leaf.
If 2 or more paths compete for longest path , then sum of nodes max will be the op.
https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1
*/

class Solution
{
public:
    void traverse(Node *root, map<int, vector<int>> &mp, int &ht, int &sum)
    {
        if (root == NULL)
            return;

        if (root->left == NULL && root->right == NULL)
        {
            // push path into mp
            mp[ht].push_back(sum);
            return;
        }

        // rem case traverse
        if (root->left)
        {
            sum = sum + root->left->data;
            ht = ht + 1;
            traverse(root->left, mp, ht, sum);
            ht = ht - 1;
            sum = sum - root->left->data;
        }

        if (root->right)
        {
            sum = sum + root->right->data;
            ht = ht + 1;
            traverse(root->right, mp, ht, sum);
            ht = ht - 1;
            sum = sum - root->right->data;
        }
    }

    int sumOfLongRootToLeafPath(Node *root)
    {
        int ans = 0;
        if (root == NULL)
            return ans;

        // 1- ht, 2-sum
        map<int, vector<int>> mp;
        mp[0].push_back(root->data);
        int sum = root->data;
        int ht = 0;
        traverse(root, mp, ht, sum);

        // get ans
        int max_ht = 0;

        for (auto i : mp)
        {
            max_ht = max(max_ht, i.first);
        }

        // get vector wrt height
        vector<int> temp = mp[max_ht];
        sort(temp.begin(), temp.end(), greater<int>());

        ans = temp[0];

        return ans;
    }
};