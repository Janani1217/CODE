import java.util.LinkedList;
import java.util.List;
/*
You are given a square grid with some cells open (.) and some blocked (X). 
Your playing piece can move along any row or column until it reaches the 
edge of the grid or a blocked cell. Given a grid, a start and a goal, 
determine the minimum number of moves to get to the goal.

grid = ["...", ".x.", "..."]
startX = 0
startY = 0
goalX = 1
goalY = 2

The grid is shown below:

...
.x.
...


The starting position (startX, startY) = (0, 0) so start in the top left corner. 
The goal is (goalX, goalY) = (1, 2). The path is (0, 0) → (0, 2) → (1, 2). 
It takes 2 moves to reach the goal.

Function Description
Complete the minimumMoves function in the editor.

minimumMoves has the following parameter(s):

string grid[n]: an array of strings that represent the rows of the grid
int startX: starting X coordinate
int startY: starting Y coordinate
int goalX: ending X coordinate
int goalY: ending Y coordinate
Returns

int: the minimum moves to reach the goal

...................................................................................................
 
Approach :
 
1. this is a bfs graph prblm which internally uses a queue DS
2. note vis nodes , using vis matrix
3. and a backtracking matrix



*/

public class castle_on_grid {

    static class Node {
        int x;
        int y;

        Node(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static int[] xMove = { -1, 0, 1, 0 };
    static int[] yMove = { 0, 1, 0, -1 };

    // return true if the below cond agrees
    private static boolean isSafe(int n, int x, int y, char[][] mat) {
        return (x >= 0 && y >= 0 && x < n && y < n && mat[x][y] == '.');
    }

    public static int minimumMoves(List<String> grid, int startX, int startY, int goalX, int goalY) {
        if (grid == null || grid.size() < 1)
            return -1;

        int n = grid.size();
        char[][] matrix = new char[n][n];

        // copy all the char present int the origianl grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = grid.get(i).charAt(j);
            }
        }

        // using queues for bfs
        LinkedList<Node> queue = new LinkedList<>();

        int[][] step = new int[n][n];
        boolean[][] vis = new boolean[n][n];

        // in the que add the starting index
        queue.add(new Node(startX, startY));
        vis[startX][startY] = true;

        while (!queue.isEmpty()) {
            Node node = queue.poll();
            int currX = node.x;
            int currY = node.y;

            // move in all the 4 directions
            for (int i = 0; i < 4; i++) {
                int index = 1; // no. of steps we can move in that direc

                // move in the direc untill is safe
                while (isSafe(n, currX + xMove[i] * index, currY + yMove[i] * index, matrix) &&
                        !vis[currX + xMove[i] * index][currY + yMove[i] * index]) {

                    int nextX = currX + xMove[i] * index;
                    int nextY = currY + yMove[i] * index;

                    vis[nextX][nextY] = true;

                    queue.add(new Node(nextX, nextY));

                    step[nextX][nextY] = step[currX][currY] + 1;

                    // if u reached the goal
                    if (nextX == goalX && nextY == goalY)
                        return step[nextX][nextY];

                    index++;
                }
            }
        }
        return -1;
    }
}
