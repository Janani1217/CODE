/*

Zig-Zag Traversal :
Move the tree is a zig zag way in every level.
Ans print the traversing nodes.

.................................................................................................

Approach :

1.  using level order traversal -> queue -> init with root data.
2.  first we go from L -> R , and then R -> L

3.  bool left_to_right = true -> flag to indicate the direction of movement in every traversal.

4.  pop from queue and inert its child.
5.  before pushing its child , need to check the flag -> make it false -> then push in that order.

6.  when we pop, store in ans and return.


.................................................................................................

https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

*/

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        // not a recr call , so impl here :
        vector<vector<int>> ans;

        if (root == NULL)
            return ans;

        // iterative - level order - use queue DS
        queue<TreeNode *> q;
        q.push(root);

        // create flag for direction
        bool left_to_right = true;

        while (!q.empty())
        {
            // process every level
            // first get the size of every level = no. of nodes present in taht level
            int size = q.size();

            // temp storage
            vector<int> temp(size);

            // process this level
            for (int i = 0; i < size; i++)
            {
                TreeNode *front = q.front();
                q.pop();

                // push the node val into temp based on the flag value
                // if left_to_right is true , it means push the data from left to right order = starting from i only
                // if the flag is false , the push / insert from the index which will be in reverse order = size-i-1 in the temp array.

                int index = left_to_right ? i : size - i - 1;
                temp[index] = front->val;

                // consider the left and right child
                if (front->left != NULL)
                    q.push(front->left);

                if (front->right != NULL)
                    q.push(front->right);
            }

            // level isprocessed , so reverse the direction
            left_to_right = !left_to_right;

            ans.push_back(temp);
        }
        return ans;
    }
};
