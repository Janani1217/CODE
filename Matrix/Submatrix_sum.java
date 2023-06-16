/*
Problem : SUBMATRIX SUM ******

Given an `M × N` integer matrix and two coordinates (p, q) and (r, s) 
representing top-left and bottom-right coordinates of a submatrix of it, 
calculate the sum of all elements present in the submatrix.

Input:

mat =
[
	[0, 2, 5, 4, 1],
	[4, 8, 2, 3, 7],
	[6, 3, 4, 6, 2],
	[7, 3, 1, 8, 3],
	[1, 5, 7, 9, 4]
]

(p, q) = (1, 1)
(r, s) = (3, 3)

Output: 38

Explanation: The submatrix formed by coordinates (p, q), (p, s), (r, q), and (r, s) is 
shown below, having the sum of elements equal to 38.

 8  2  3
 3  4  6
 3  1  8

Assume that `m` lookup calls are made to the matrix; the task is to 
achieve constant time lookups.

EXPLAINED IN NOTES VERY CLEARLY !!! PLEASE LOOK IF NOT REMEMBERING !
*/

class Solution {
    public static int findSubmatrixSum(int[][] mat, int p, int q, int r, int s) {
        // Write your code here...
        int m = mat.length;
        if (m == 0)
            return 0;

        int n = mat[0].length;

        int[][] ps = new int[m][n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // row wise
                if (j == 0)
                    ps[i][j] = mat[i][j];
                else
                    ps[i][j] = mat[i][j] + ps[i][j - 1];
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // col wise
                if (i != 0)
                    ps[i][j] += ps[i - 1][j];
            }
        }
        // System.out.println("sum="+ps[r][s]);

        int sum = 0;
        if (p == 0 && q == 0) {
            sum = ps[r][s];
        } else if (p == 0) {
            // top row should not be deducted
            sum = ps[r][s] - ps[r][q - 1];
        } else if (q == 0) {
            // left is 0 :
            sum = ps[r][s] - ps[p - 1][s];
        } else {
            sum = ps[r][s] - ps[p - 1][s] - ps[r][q - 1] + ps[p - 1][q - 1];
        }
        return sum;
    }
}
