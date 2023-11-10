import java.util.ArrayList;
import java.util.Collections;
import java.util.Stack;

/*  Largest Rectangle in Histogram
 * 
 *  Given an array of integers heights representing the histogram's bar height where the width 
 *  of each bar is 1, return the area of the largest rectangle in the histogram.
 * 
 * 
 * Input: heights = [2,1,5,6,2,3]
 * Output: 10
 * 
 * Explanation: The above is a histogram where width of each bar is 1.
 * The largest rectangle is shown in the red area, which has an area = 10 units.
 * 
 *    https://leetcode.com/problems/largest-rectangle-in-histogram/description/
 * 
 */

import java.util.Stack;

class Solution {
    public int largestRectangleArea(int[] heights) {
        int n = heights.length;
        int[] left = new int[n];
        int[] right = new int[n];
        Stack<Integer> stack = new Stack<>();
        
        // Find nearest smaller element to the left
        for (int i = 0; i < n; i++) {
            while (!stack.isEmpty() && heights[stack.peek()] >= heights[i]) {
                stack.pop();
            }
            left[i] = stack.isEmpty() ? -1 : stack.peek();
            stack.push(i);
        }

        // Clear the stack for finding nearest smaller element to the right
        stack.clear();

        // Find nearest smaller element to the right
        for (int i = n - 1; i >= 0; i--) {
            while (!stack.isEmpty() && heights[stack.peek()] >= heights[i]) {
                stack.pop();
            }
            right[i] = stack.isEmpty() ? n : stack.peek();
            stack.push(i);
        }

        // Calculate the maximum area
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            int area = width * heights[i];
            maxArea = Math.max(maxArea, area);
        }

        return maxArea;
    }
}
