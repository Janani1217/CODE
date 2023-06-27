/*
 *  Next Smaller Element :
 * 
 * Given an array, print the Next Smaller Element (NSE) for every element. 
 * The NSE for an element x is the first smaller element on the right side 
 * of x in the array. 
 * 
 * Elements for which no smaller element exist (on the right side), 
 * consider NSE as -1. 
 * 
 * 
 * Element         NSE
   4      -->    2
   8      -->    5
   5      -->    2
   2      -->   -1
   25     -->   -1
   
 */

import java.util.*;

public class next_smallest {
    static ArrayList<Integer> nextSmallerElement(ArrayList<Integer> arr, int n) {
        // Write your code here.

        ArrayList<Integer> ans = new ArrayList<>();
        ans.add(-1); // for the first ele
        Stack<Integer> st = new Stack<>();
        st.push(arr.get(n - 1));

        for (int i = n - 2; i >= 0; i--) {
            int num = arr.get(i);
            if (num > st.peek()) {
                ans.add(st.peek());
                st.push(num);
            } else {
                // find the smallest ele
                int flag = 0;
                while (!st.empty()) {
                    if (num > st.peek()) {
                        ans.add(st.peek());
                        st.push(num);
                        flag = 1;
                        break;
                    }
                    st.pop();
                }
                if (flag == 0) {
                    ans.add(-1);
                    st.push(num);
                }
            }
        }
        Collections.reverse(ans);
        return ans;
    }
}