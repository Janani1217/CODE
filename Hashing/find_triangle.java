/*
 * Given an array arr[] of N distinct integers points on the 2D Plane. 
 * The task is to count the number of Right-Angled Triangle 
 * from N points such that the base or perpendicular is parallel 
 * to the X or Y-axis.
 *
 * Input: arr[][] = {{1, 2}, {2, 1}, {2, 2}, {2, 3}, {3, 2}} 
 * Output: 4
 * 
 * .............................................................................
 * 
 * Approach :
 * At every point , to find right angled triangle formula = (m-1)*(n-1)
 * 
 * m = no. of points present on the same x axis where the curr pt exist
 * n = no. of points present on the same y axis where the curr pt exist
 *  
 * .............................................................................
 * 
 * 
 * https://www.geeksforgeeks.org/count-of-right-angled-triangle-formed-from-given-n-points-whose-base-or-perpendicular-are-parallel-to-x-or-y-axis/
 */

public class find_triangle {
    public int solve(int[][2] points, int n) {

        // first = x axis value , second = count
        Map<Integer, Integer> x_map = new HashMap<>();
        Map<Integer, Integer> y_map = new HashMap<>();
        

        // store the x and y points with its count : to find how many points
        // lie in the same lane
        for(int i=0; i<n; i++) {
            x_map.put(points[i][0] , x_map.get(points[i][0]) + 1);
            x_map.put(points[i][1] , x_map.get(points[i][1]) + 1);
        }

        int count = 0;

        // check tringles possible (m-1)*(n-1)
        for(int i=0; i<n; i++) {
            int x = points[i][0];
            int y = points[i][1];

            if(x_map.get(x) > 0 && y_map.get(y) > 0){
                count += (x_map.get(x) - 1 ) * (y_map.get(y) - 1);
            }  
        }

        return count;
    }
}
