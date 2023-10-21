/*
 *  Path With Minimum Effort

You are a hiker preparing for an upcoming hike. 
You are given heights, a 2D array of size rows x columns, 
where heights[row][col] represents the height of cell (row, col). 
You are situated in the top-left cell, (0, 0), and you hope to travel 
to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). 
You can move up, down, left, or right, and you wish to find a route 
that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between 
two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell 
to the bottom-right cell.

*/

import java.util.*;

class Solution {
    public int minimumEffortPath(int[][] heights) {
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        int m = heights.length;
        int n = heights[0].length;

        // create dist ds and fill with max values
        int[][] dist = new int[m][n];
        for (int i = 0; i < m; i++) {
            Arrays.fill(dist[i], Integer.MAX_VALUE);
        }

        // update for source node
        dist[0][0] = 0;
        pq.offer(new int[] { 0, 0, 0 });

        // loop through pq :
        while (!pq.isEmpty()) {

            // take out front node from pq
            int[] node = pq.poll();
            int front_node_dist = node[0];
            int x = node[1];
            int y = node[2];

            // check if we have reached teh dest or not
            if (x == m - 1 && y == n - 1)
                return dist[x][y];

            // traverse thr all 4 directions
            int[] dx = { -1, 0, 1, 0 };
            int[] dy = { 0, 1, 0, -1 };

            for (int i = 0; i < 4; i++) {

                int newX = x + dx[i];
                int newY = y + dy[i];

                // check for boundaries
                if (newX >= 0 && newY >= 0 && newX < m && newY < n) {

                    // if within boundary -> update the dist
                    int curr_node_dist = Math.abs(heights[newX][newY] - heights[x][y]);
                    int new_node_dist = Math.max(front_node_dist, curr_node_dist);

                    // update the dist if its smaller
                    if (dist[newX][newY] > new_node_dist) {
                        dist[newX][newY] = new_node_dist;
                        pq.offer(new int[] { new_node_dist, newX, newY });
                    }
                }
            }
        }
        return 0;
    }
}