/*
Number of closed islands :

Given a 2D grid consists of 0s (land) and 1s (water).
An island is a maximal 4-directionally connected group of 0s and a
closed island is an island totally (all left, top, right, bottom)
surrounded by 1s.

Return the number of closed islands.


Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],
              [1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
Output: 2

Explanation:
Islands in gray are closed because they are completely surrounded
by water (group of 1s).

..................................................................................................

Approach : CONCEPT = BOUNDARY DFS !!

1.  given 1 = water and 0 = land
2.  If land is attached to boundary , that cannot be considered as ans
    since it has to be surrounded by water.

    so for that first convert all the land attached to boundary as 0.
    And also the land attached to it is also converted to 0 as well.

    this can be done by traversing dfs on all the 4 boundaries.

3.  second time dfs is traversed in the inside part
4.  when it encounters a 0 = land , it starts traversing the area which is
    surrounded by 1 and returns back

5.  incr the count
6.  similarly other lands which are 4 directionally covered
    with 0 are found through the dfs traversal.

..................................................................................................

*/

class Solution
{
public:
    void dfs(vector<vector<int>> &grid, int i, int j, int n, int m)
    {
        // base condition :
        if (i < 0 || j < 0 || i > n - 1 || j > m - 1)
            return;

        if (grid[i][j] == 1)
            return;

        // convert the curr into 1
        grid[i][j] = 1;

        // traverse 4 directions
        dfs(grid, i + 1, j, n, m);
        dfs(grid, i - 1, j, n, m);
        dfs(grid, i, j + 1, n, m);
        dfs(grid, i, j - 1, n, m);
    }
    int closedIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        if (n == 0)
            return 0;
        int m = grid[0].size();

        int count = 0;

        // dfs on boundary first
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // identify boundary
                if (i * j == 0 || i == n - 1 || j == m - 1)
                {
                    // traverse dfs if we find a land = 0
                    if (grid[i][j] == 0)
                    {
                        dfs(grid, i, j, n, m);
                    }
                }
            }
        }

        // traverse dfs in the middle portion
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                // traverse dfs if found 0
                if (grid[i][j] == 0)
                {
                    count++;
                    dfs(grid, i, j, n, m);
                }
            }
        }
        return count;
    }
};