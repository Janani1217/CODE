/*
Find all possible FBT : one node will have either 0 or 2 child.
Given n, find all the poss FBT from that number n.

https://leetcode.com/problems/all-possible-full-binary-trees/description/

Approach:

This is find all poss combinations ~ recursive solution can be applied
Here , in the output , we need a vector<node> which will hav ethe root pointer of the trees poss

In this we will have :
left_ans = <list of all subtrees forming FBT with that "i" passed in the function as no. of nodes>
right_ans = <list of all subtrees forming FBT with "n-i" passed as no. of nodes in function>

Once we get them , at the current node , we need to permute the total no. of trees we can get
with these left and right subroots in the vector<node>.

So we run a nested loop on these two ans vector and form a root node , everytime and push
that in the answer.

We also use memoization to simplify recr if already a particular n value is processed.
*/

// map : first = n , second = no. of FBT that could be formed

vector<Node *> solve(int n, unordered_map<int, vector<Node *>> memo)
{
    vector<Node *> ans;
    // base cases :
    if (n == 0)
        return ans;

    if (n % 2 == 0)
    {
        // cant form a FBT if we are left with only 2 nodes or multiple of 2 nodes
        return ans;
    }

    // if only 1 node is present then just that node forms the tree
    if (n == 1)
    {
        Node *node = new Node(0);
        ans.push_back(node);
        memo[1] = node;
        return ans;
    }

    // use memo
    if (memo.find(n) != memo.end())
        return memo[n];

    // loop over n
    for (int i = 1; i < n; i++)
    {
        // get the left and right FBT with the nodes combinations
        vector<Node *> left_ans = solve(i, memo);
        vector<Node *> right_ans = solve(n - 1 - i, memo);

        // once we get the subtrees, permute over it to get all the tree combinations with diff roots
        for (int j = 0; j < left_ans.size(); j++)
        {
            for (int k = 0; k < right_ans.size(); k++)
            {
                // form the root for this current combination
                Node *node = new Node(0);
                node->left = left_ans[j];
                node->right = right_ans[k];
                ans.push_back(node);
            }
        }
    }
    memo[n] = ans;
    return ans;
}