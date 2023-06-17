import java.util.HashMap;
import java.util.Map;

/*
 *  Max Points on a Line :
 *  
 * Given an array of points where points[i] = [xi, yi] represents 
 * a point on the X-Y plane, return the maximum number of points 
 * that lie on the same straight line.
 * 
 * Input: points = [[1,1],[2,2],[3,3]]
 * Output: 3
 * 
 * .............................................................................
 * 
 * https://leetcode.com/problems/max-points-on-a-line/
 * 
 * .............................................................................
 * 
 */

class Solution {
    public int maxPoints(int[][] points) {
        int n = points.length;
        double max_num = Integer.MAX_VALUE;
        int count = 0;

        for (int i = 0; i < n - 1; i++) {
            HashMap<Double, Integer> mp = new HashMap<>();

            for (int j = i + 1; j < n; j++) {
                if (points[i][0] == points[j][0]) {
                    // handling infinity case (x2 - x1)
                    mp.put(max_num, mp.getOrDefault(max_num, 0) + 1);
                } else {
                    double y = points[j][1] - points[i][1];
                    double x = points[j][0] - points[i][0];
                    double slope = (y == 0) ? 0 : y / x;

                    mp.put(slope, mp.getOrDefault(slope, 0) + 1);

                    System.out.println("slope = " + slope + "count = " + mp.get(slope));
                }
            }

            for (Map.Entry<Double, Integer> ele : mp.entrySet()) {
                count = Math.max(count, ele.getValue() + 1);
            }
        }

        return Math.max(1, count);
    }
}
