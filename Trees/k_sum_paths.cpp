/*
K Sum Path :
given root, int target sum.

Return total number of paths havinf the target sum

Path can start and end at any node having the sum.
.................................................................................................

Approach :
1.  For every path you move, push the root value in to a vector
2.  Compare in the vector formed , whether target sum can be achieved
3.  If yes, incr the count of ans.

https://leetcode.com/problems/path-sum-iii/
*/

class Solution
{
    int count = 0;
public
    void solve(TreeNode root, int sum, ArrayList<Long> path)
    {
        if (root == null)
            return;

        int value = root.val;
        path.add((long)value);

        solve(root.left, sum, path);
        solve(root.right, sum, path);

        // both are done so cal the path
        int size = path.size();
        long curr = 0;

        // System.out.println(size);

        for (int i = size - 1; i >= 0; i--)
        {
            curr += path.get(i);

            if (curr == sum)
            {
                // System.out.println("hi");
                count++;
            }
        }

        // backtrack : pop back
        path.remove(path.size() - 1);
    }

public
    int pathSum(TreeNode root, int targetSum)
    {
        ArrayList<Long> path = new ArrayList<>();
        solve(root, targetSum, path);
        return count;
    }
}

/*
class Solution
{
public:
    void solve(TreeNode *root, vector<long> path, int &count, int targetSum)
    {
        // using recr
        // bc
        if (root == NULL)
            return;

        // add the curr node into the path
        path.push_back(root->val);

        solve(root->left, path, count, targetSum);
        solve(root->right, path, count, targetSum);

        int size = path.size();
        long sum = 0;
        // if target sum is matched into the vector or not
        for (int i = size - 1; i >= 0; i--)
        {
            sum += path[i];
            if (sum == targetSum)
                count++;
        }

        // after recr comes back - remove the curr node
        path.pop_back();
    }

    int pathSum(TreeNode *root, int targetSum)
    {

        /***** Signed integer issue could happen , so put long */
/*       vector<long> path;
       int count = 0;

       solve(root, path, count, targetSum);
       return count;
   }
};

*/