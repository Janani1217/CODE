import java.util.Stack;

class Solution {
    public int longestValidParentheses(String s) {
        int len = 0;
        // PUSH THE INDEX OF BRACES
        Stack<Integer> st = new Stack<>();
        st.push(-1);

        for (int i = 0; i < s.length(); i++) {
            Character curr = s.charAt(i);

            System.out.println("curr = " + curr);

            if (curr == '(') {
                st.push(i);
            }

            else if (curr == ')') {
                if (!st.empty())
                    st.pop();

                if (!st.empty()) {
                    len = Math.max(len, i - st.peek());
                    System.out.println("peek = " + st.peek());
                    System.out.println("len = " + len);
                } else {
                    System.out.println("2nd push = " + i);
                    st.push(i);
                }
            }
        }

        return len;
    }
}