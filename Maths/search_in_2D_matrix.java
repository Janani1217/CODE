package Maths;
/*
Search in a 2D matrix : 

Write an efficient algorithm that searches for a value target in an m x n 
integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
 

Example 1:

Input: matrix = 
[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], 
target = 5
Output: true


*/

class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length;

        if (m == 0)
            return false;

        int n = matrix[0].length;

        if (n == 0)
            return false;

        int r = 0;
        int c = n - 1;

        while (c >= 0 && r < m) {
            if (target == matrix[r][c])
                return true;
            else if (target < matrix[r][c])
                c--;
            else if (target > matrix[r][c])
                r++;
        }
        return false;
    }
}