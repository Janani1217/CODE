/*
Kth ancestor of tree node :

1. when node is found , then return the node value
2. make left and right calls
3. if any of the left or right ans != -1
    3.1 it means , we have found the node , now need to find the ancestor
    3.2 so , decrement k first
    3.3 after decr k , check the vslue of k if 0 or less than 0
    3.4 if zero means , we found the ancestor node
    3.5 if we go above the ancestor node in the tree , then also this decr of k will happen
    3.6 but as per our logic only k=0, that node will be the ancestor node.
    So we are setting a very high value

4. Now after we get the ans in the main call
    4.1 if ans == -1  -> no ancestor found
    4.2 if ans == node -> node found , but ancestor not found
        this will happen when there are lesser than k nodes present above the
        node found in the tree.

    4.3 so in these 2 cases, return -1
        else return the ans;

https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab
*/

int solve(Node *root, int &k, int node)
{
    if (root == NULL)
        return -1;

    if (root->data == node)
    {
        return root->data;
    }

    int left = -1;
    int right = -1;

    left = solve(root->left, k, node);
    right = solve(root->right, k, node);

    if (left != -1 && right == -1)
    {
        k = k - 1;
        if (k <= 0)
        {
            k = INT_MAX;
            return root->data;
        }
        return left;
    }

    if (left == -1 && right != -1)
    {
        k = k - 1;
        if (k <= 0)
        {
            k = INT_MAX;
            return root->data;
        }
        return right;
    }

    return -1;
}

int kthAncestor(Node *root, int k, int node)
{
    // Code here
    int ans = solve(root, k, node);

    // because if no ancestor found, then the node found will be returned from top of tree
    // ********* ans == node //
    if (ans == -1 || ans == node)
        return -1;

    return ans;
}