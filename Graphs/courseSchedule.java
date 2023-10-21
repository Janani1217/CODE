/* https://leetcode.com/problems/course-schedule-ii/description/*/

import java.util.*;

class Solution {
    public Boolean topoSort(HashMap<Integer, List<Integer>> adj, int n, List<Integer> ans) {
        HashMap<Integer, Integer> indegree = new HashMap<>();
        Queue<Integer> q = new LinkedList<>(); // to store indegree 0 nodes

        // calc indegree
        for (Map.Entry<Integer, List<Integer>> entry : adj.entrySet()) {
            List<Integer> ll = entry.getValue();
            for (Integer nbr : ll) {
                indegree.put(nbr, indegree.getOrDefault(nbr, 0) + 1);
            }
        }

        // add to the queue whose indegree is 0
        for (int i = 0; i < n; i++) {
            if (!indegree.containsKey(i) || indegree.get(i) == 0)
                q.add(i);
        }

        // traverse with indegree 0 from the queue
        while (!q.isEmpty()) {
            Integer node = q.poll();
            // add into the ans , since its visited
            ans.add(node);

            if (adj.containsKey(node)) {
                for (Integer nbr : adj.get(node)) {
                    indegree.put(nbr, indegree.get(nbr) - 1);
                    if (indegree.get(nbr) == 0)
                        q.add(nbr);
                }
            }
        }
        return ans.size() == n;
    }

    public int[] findOrder(int numCourses, int[][] prerequisites) {
        // create adj list :
        HashMap<Integer, List<Integer>> adj = new HashMap<>();
        for (int[] row : prerequisites) {
            int u = row[0];
            int v = row[1];
            if (!adj.containsKey(v))
                adj.put(v, new ArrayList<>());
            adj.get(v).add(u);
        }

        List<Integer> ans = new ArrayList<>();
        int[] arr = new int[numCourses];

        if (topoSort(adj, numCourses, ans) == true) {
            for (int i = 0; i < numCourses; i++) {
                arr[i] = ans.get(i);
            }
            return arr;
        }

        return new int[0];
    }
}