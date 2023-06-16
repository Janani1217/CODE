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

class Solution {
    private ArrayList<Integer> findLeft(int[] heights, int n) {
        ArrayList<Integer> ans = new ArrayList<>();
        Stack<Integer> st = new Stack<>();
        st.push(0);
        ans.add(-1);

        // find the index of the smallest ele to its left
        for (int i = 1; i < n; i++) {
            int num = heights[i];
            if (!st.empty()) {
                if (num > heights[st.peek()]) {
                    ans.add(st.peek());
                    st.push(i);
                } else {
                    int flag = 0;
                    while (!st.empty() && num <= heights[st.peek()]) {
                        st.pop();
                        if (!st.empty() && num > heights[st.peek()]) {
                            ans.add(st.peek());
                            st.push(i);
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 0) {
                        ans.add(-1);
                        st.push(i);
                    }
                }
            } else {
                ans.add(-1);
                st.push(i);
            }
        }
        return ans;
    }

    private ArrayList<Integer> findRight(int[] heights, int n) {
        ArrayList<Integer> ans = new ArrayList<>();
        Stack<Integer> st = new Stack<>();
        st.push(n - 1);
        ans.add(n);

        // find the index of the smallest ele to its right
        for (int i = n - 2; i >= 0; i--) {
            int num = heights[i];

            if (!st.empty()) {
                if (num > heights[st.peek()]) {
                    ans.add(st.peek());
                    st.push(i);
                } else {
                    int flag = 0;
                    while (!st.empty() && num <= heights[st.peek()]) {
                        st.pop();
                        if (!st.empty() && num > heights[st.peek()]) {
                            ans.add(st.peek());
                            st.push(i);
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 0) {
                        ans.add(n);
                        st.push(i);
                    }
                }
            } else {
                st.push(i);
                ans.add(-1);
            }
        }
        Collections.reverse(ans);
        return ans;
    }

    public int largestRectangleArea(int[] heights) {
        int n = heights.length;
        ArrayList<Integer> left_Smallest = new ArrayList<>();
        ArrayList<Integer> right_Smallest = new ArrayList<>();
        int max_area = Integer.MIN_VALUE;

        left_Smallest = findLeft(heights, n);
        right_Smallest = findRight(heights, n);

        for (int i = 0; i < n; i++) {
            int curr_height = heights[i];
            int left = left_Smallest.get(i);
            int right = right_Smallest.get(i);

            int area = (right - left - 1) * curr_height;
            max_area = Math.max(max_area, area);
        }
        return max_area;
    }
}