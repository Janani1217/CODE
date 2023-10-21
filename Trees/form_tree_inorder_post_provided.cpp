/*
Construct tree from inorder and preorder :

Given 2 Arrays of Inorder and preorder traversal.
The tree can contain duplicate elements.
Construct a tree and print the Postorder traversal.

**** Take care of duplicate elements *****

https://practice.geeksforgeeks.org/problems/construct-tree-1/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab
*/

class Solution
{
public:
    void createMapping(int in[], unordered_map<int, vector<pair<bool, int>>> &nodeToIndex, int n)
    {
        for (int i = 0; i < n; i++)
        {
            int ele = in[i];
            nodeToIndex[ele].push_back(make_pair(false, i));
        }
    }

    int findPosInInorder(int in[], int ele, int n, unordered_map<int, vector<pair<bool, int>>> &nodeToIndex)
    {
        vector<pair<bool, int>> curr = nodeToIndex[ele];
        int ans = -1;
        for (int i = 0; i < curr.size(); i++)
        {
            pair<bool, int> temp = curr[i];
            if (temp.first == false)
            {
                nodeToIndex[ele][i].first = true;
                ans = temp.second;
                return ans;
            }
        }
        return -1;
    }

    Node *solve(int in[], int pre[], int &index, int inOrderStart, int inOrderEnd, int n, unordered_map<int, vector<pair<bool, int>>> &nodeToIndex)
    {
        if (index >= n || inOrderStart > inOrderEnd)
            return NULL;

        // get the root ele and incr the index
        int ele = pre[index++];

        // create node for root
        Node *root = new Node(ele);

        // find the pos of this ele in in[]
        int pos = findPosInInorder(in, ele, n, nodeToIndex);
        // cout<<"ele = "<<ele<<" pos = "<<pos<< endl;

        // now call the left and right recr passing the nodes in inorder and pre order
        root->left = solve(in, pre, index, inOrderStart, pos - 1, n, nodeToIndex);
        root->right = solve(in, pre, index, pos + 1, inOrderEnd, n, nodeToIndex);

        return root;
    }
    Node *buildTree(int in[], int pre[], int n)
    {
        // make a var for index in pre order
        int preOrderIndex = 0;

        // ******** Duplicate elements ********
        // first - element , second - already vis , third - index of ele
        unordered_map<int, vector<pair<bool, int>>> nodeToIndex;
        createMapping(in, nodeToIndex, n);

        Node *ans = solve(in, pre, preOrderIndex, 0, n - 1, n, nodeToIndex);
        return ans;
    }
};