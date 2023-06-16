/*
Number of islands:

Given an m x n 2D binary grid grid which represents a map of '1's (land)
and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands
horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.


Approach:

1.  use dfs as a base for traversal
2.  for loop needed ; same as diconnected graph traversal
3.  when we find a 1 in any index , first we think we got an
    island , so we need to increment the count of islands
4.  now we call dfs only if we find a 1
5.  now inside the dfs function , we have to check all the 4 sides
    of the curr index if that is having a 1 or not and is conn to this
    curr index or not
6.  so for this we call dfs for those indexes also and make the 1s to 0s.


*/

lass Solution{
    public :
        void dfs(vector<vector<char>> & grid, int i, int j){
            // 2 base cases
            if (i < 0 || j < 0 || i > grid.size() - 1 || j > grid[0].size() - 1) return;
if (grid[i][j] == '0')
    return;

// make the curr index 0
grid[i][j] = '0';

// traverse in all 4 directions to check if 1 is present or not
dfs(grid, i + 1, j);
dfs(grid, i - 1, j);
dfs(grid, i, j - 1);
dfs(grid, i, j + 1);
}
int numIslands(vector<vector<char>> &grid)
{
    int n = grid.size();
    if (n == 0)
        return 0;

    int m = grid[0].size();

    int count = 0;

    // step1 : traverse the grid to find 1
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '1')
            {
                count++;
                dfs(grid, i, j);
            }
        }
    }
    return count;
}
}
;