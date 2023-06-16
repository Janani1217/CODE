/*
Spiral Matrix :

Given a positive integer n, generate an n x n matrix filled with
elements from 1 to n2 in spiral order.

Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]

Approach :

1.  take 2 variables : l = left col ; r = right col
2.  take 2 variables : t = top row ; b = bottom row
3.  take 1 var : d = indicated direction : [0 = top , 1 = right , 2 = bottom , 3 = left]

4.  initialize all var : l = 0 ; r = n-1 ; t = 0 ; b = n-1

5.  when the l > r or t > b , then we need to stop the processing
6.  for this while loop : while(l<=r && t<=b)
7.  inside while loop , process acc to the direc d

8.  if d == 0 : move from top left to top right corner :
                for (i=l -> i<=r) { arr[t][i] ..}
                make : d = 1
                t++; // since top row got processed

9.  if d == 1 : move from right top to right bottom :
                for(i=t -> i<=b) { arr[i][r] ..}
                d = 2
                r--; // right col got processed

10. if d == 2 : move from bottom right to left corner
                for(i=r -> i>=l) { arr[b][i] ..}
                d = 3
                b--; // bottom row got processes

11. if d == 3 : move from left bottom corner to top
                for(i=b -> i>=t) { arr[i][l] ..}
                d = 0
                l++; // left col got processed

12. return the matrix

*/

class Solution
{
public
    int[][] generateMatrix(int n)
    {
        int count = 1;
        int[][] arr = new int[n][n];

        int l = 0, r = n - 1, t = 0, b = n - 1;
        int d = 0;

        while (l <= r && t <= b)
        {
            // direct 1 = left to right
            for (int i = l; i <= r; i++)
            {
                arr[t][i] = count++;
            }
            d = 1;
            t++;

            // direct 2 : top to bottom
            for (int i = t; i <= b; i++)
            {
                arr[i][r] = count++;
            }
            d = 2;
            r--;

            // direct 3 : right to left
            for (int i = r; i >= l; i--)
            {
                arr[b][i] = count++;
            }
            d = 3;
            b--;

            // direct 4 : bottom to top
            for (int i = b; i >= t; i--)
            {
                arr[i][l] = count++;
            }
            d = 0;
            l++;
        }

        return arr;
    }
} Console
