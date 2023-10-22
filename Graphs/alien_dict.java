//{ Driver Code Starts
/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;
import java.math.*;

class Solution {
    public void prepareAdjList(String[] dict, int n, List<List<Character>> adj) {
        /* add the list for 26 char *****/
        for (int i = 0; i < 26; i++) {
            adj.add(new ArrayList<>());
        }

        for (int i = 0; i < n - 1; i++) {
            String s1 = dict[i];
            String s2 = dict[i + 1];

            int j = 0;
            int minLength = Math.min(s1.length(), s2.length());   /******* VVI */

            while (j < minLength && s1.charAt(j) == s2.charAt(j)) {
                j++;
            }

            if (j < s1.length() && j < s2.length()) {
                char from = s1.charAt(j);
                char to = s2.charAt(j);
                adj.get(from - 'a').add(to);  /******* VVI */
            }
        }
    }

    public void dfsTopo(List<List<Character> > adj, Stack<Character> st, Map<Character, Integer> vis, char ch) {
        if (vis.get(ch) == 1 || vis.get(ch) == 2) return;

        vis.put(ch, 1);

        for (char neigh : adj.get(ch - 'a')) {. /******* VVI */
            if (vis.get(neigh) == 0) dfsTopo(adj, st, vis, neigh);
        }

        st.push(ch);
        vis.put(ch, 2);
    }

    public String findOrder(String[] dict, int N, int K) {
        List<List<Character>> adj = new ArrayList<>();
        prepareAdjList(dict, N, adj);

        Map<Character, Integer> vis = new HashMap<>();
        for (char ch = 'a'; ch <= 'z'; ch++) {
            vis.put(ch, 0);
        }

        Stack<Character> st = new Stack<>();
        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (vis.get(ch) == 0) {
                dfsTopo(adj, st, vis, ch);
            }
        }

        StringBuilder res = new StringBuilder();

        while (!st.isEmpty()) {
            char c = st.pop();
            res.append(c);
        }

        return res.toString();
    }
}
