/* https://leetcode.com/problems/kth-ancestor-of-a-tree-node/description/ */

class TreeAncestor {
    int n;
    int[][] dp; // A 2D array to store ancestors at different heights

 
    public TreeAncestor(int n, int[] parent) {
        this.n = n;
        int maxDepth = (int) (Math.log(n) / Math.log(2)) + 1;
        dp = new int[n][maxDepth];

        // Fill the dp array with -1 to indicate no ancestor at that height
        for (int i = 0; i < n; i++) {
            Arrays.fill(dp[i], -1);
        }

        // Initialize the dp array with direct parents
        for (int i = 0; i < n; i++) {
            dp[i][0] = parent[i];
        }

        // Precompute ancestors for each node at different heights
        for (int j = 1; j < maxDepth; j++) {
            for (int i = 0; i < n; i++) {
                if (dp[i][j - 1] != -1) {
                    dp[i][j] = dp[dp[i][j - 1]][j - 1];
                }
            }
        }
    }

    public int getKthAncestor(int node, int k) {
        int depth = (int) (Math.log(n) / Math.log(2)) + 1;

        // Traverse through the ancestor levels using binary representation of k
        for (int i = 0; i < depth; i++) {
            if ((k & (1 << i)) != 0) {
                node = dp[node][i];
                if (node == -1) {
                    break; // No ancestor at this height
                }
            }
        }

        return node;
    }
}