import java.util.*;

// https://leetcode.com/problems/rotting-oranges/

public class rotting_oranges {
    public void dfs(int i, int j, int[][] grid, int n, int m, int rot) {
        // boundary checks
        if (i < 0 || j < 0 || i >= n || j >= m)
            return;

        /*
         * 1. cell has 0
         * 2. cell was already rotten by some other rotten oranges
         * hence its in the range of : 1 to the curr rot number
         */
        if (grid[i][j] == 0 || (grid[i][j] > 1 && grid[i][j] > rot))
            return;

        grid[i][j] = rot;

        // traverse in all 4 directions , by incr the rot val (done to maintain rotting
        // numbers )
        dfs(i + 1, j, grid, n, m, rot + 1);
        dfs(i - 1, j, grid, n, m, rot + 1);
        dfs(i, j + 1, grid, n, m, rot + 1);
        dfs(i, j - 1, grid, n, m, rot + 1);
    }

    public int orangesRotting(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;

        int started_rot = 2;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    // found a rotten orange
                    dfs(i, j, grid, n, m, started_rot);
                }
            }
        }

        // traverse the grid to know if all oranges got rotten or not
        started_rot = 2;

        for (int[] row : grid) {
            for (int cell : row) {
                if (cell == 1)
                    return -1;
                started_rot = Math.max(started_rot, cell);
            }
        }

        return started_rot;
    }
}
