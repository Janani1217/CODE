You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.

Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7.

https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/







import java.util.*;

class Pair {
    int fir;
    long sec;

    Pair(int fir, long sec) {
        this.fir = fir;
        this.sec = sec;
    }
}

/* COMBINATION OF DP AND DIJKRISTR'S' */

class Solution {
    public int countPaths(int n, int[][] roads) {
        // Create an adjacency list to represent the graph
        List<List<Pair>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }

        for (int i = 0; i < roads.length; i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];
            adj.get(u).add(new Pair(v, w));
            adj.get(v).add(new Pair(u, w));
        }

        // Initialize distance array and count array
        long[] dist = new long[n];
        int[] count = new int[n]; /****** VVII *****/

        Arrays.fill(dist, Long.MAX_VALUE);

        // Dijkstra's algorithm to calculate the shortest path
        dist[0] = 0;
        count[0] = 1;

        PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> Long.compare(a.sec, b.sec));
        pq.offer(new Pair(0, 0));

        while (!pq.isEmpty()) {
            Pair p = pq.poll();
            int node = p.fir;
            long cost = p.sec;

            /***  VVIII ***/
            // if u found a cost / edge wg which is greater than the curr dist itself : no need to proceed further
            if (cost > dist[node]) {
                continue;
            }

            for (Pair neighbor : adj.get(node)) {
                int nextNode = neighbor.fir;
                long nextCost = neighbor.sec;

                if (dist[nextNode] > cost + nextCost) {
                    dist[nextNode] = cost + nextCost;
                    pq.offer(new Pair(nextNode, dist[nextNode]));
                    count[nextNode] = count[node];
                } else if (dist[nextNode] == cost + nextCost) {
                    count[nextNode] = (count[nextNode] + count[node]) % 1_000_000_007;
                }
            }
        }

        return count[n - 1];
    }
}
