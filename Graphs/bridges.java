/*
Bridges in graph :

The edge if on removal which will increase the conn components , or make the
graph disconnected.

Brute force : pick every edge and check if on removal , get the no. conn compo
in the graph.

NOTES Refer..

.................................................................................................

*/

import java.util.*;

class Solution {
    static int[] disc, low, parent, vis;
    static int[][] bridges;
    static int ptr;

    static void prepareAdjList(Map<Integer, List<Integer>> adjList, ArrayList<ArrayList<Integer>> adj, int v) {
        for (int i = 0; i < adj.size(); i++) {
            ArrayList<Integer> arr = adj.get(i);
            adjList.put(i, arr);
        }
    }

    static void formSet(int V) {
        disc = new int[V];
        low = new int[V];
        parent = new int[V];
        vis = new int[V];
        bridges = new int[V + 1][2];
        ptr = 0;

        for (int i = 0; i < V; i++) {
            disc[i] = 0;
            low[i] = 0;
            parent[i] = i;
            vis[i] = 0;
        }
    }

    static void dfsBridges(Map<Integer, List<Integer>> adjList, int src, int timer) {
        vis[src] = 1;
        disc[src] = timer;
        low[src] = timer++;

        List<Integer> ll = adjList.get(src);

        for (int i = 0; i < ll.size(); i++) {
            int neigh = ll.get(i);

            if (vis[neigh] == 0) {
                parent[neigh] = src;
                dfsBridges(adjList, neigh, timer);

                // coming back conditons to check if its a bridge

                if (low[neigh] > disc[src]) {
                    bridges[ptr][0] = neigh;
                    bridges[ptr][1] = src;
                    ptr++;
                }

                // update the low also
                low[src] = Math.min(low[src], low[neigh]);
            } else {
                // already vis by some other path : back edge conditions to check

                if (parent[src] != neigh) {
                    low[src] = Math.min(low[src], low[neigh]);
                }
            }
        }
    }

    // Function to find if the given edge is a bridge in graph.
    static int isBridge(int V, ArrayList<ArrayList<Integer>> adj, int c, int d) {
        Map<Integer, List<Integer>> adjList = new HashMap<>();
        prepareAdjList(adjList, adj, V);

        formSet(V);

        /*
         * for(Map.Entry<Integer, List<Integer>> mp : adjList.entrySet()) {
         * System.out.println(mp.getKey());
         * List<Integer> neigh = mp.getValue();
         * for(Integer i : neigh) {
         * System.out.println(i);
         * }
         * System.out.println("next");
         * }
         */

        int timer = 0;

        for (int i = 0; i < V; i++) {
            if (vis[i] == 0 && adjList.get(i).size() > 0) {
                dfsBridges(adjList, i, timer);
            }
        }

        for (int i = 0; i < bridges.length; i++) {
            if ((bridges[i][0] == c && bridges[i][1] == d) || (bridges[i][0] == d && bridges[i][1] == c))
                return 1;
        }

        return 0;
    }
}

/*
 * #include <bits/stdc++.h>
 * void prepareAdjList(unordered_map<int, list<int>> &adj, vector<vector<int>>
 * edges, int m)
 * {
 * for (int i = 0; i < edges.size(); i++)
 * {
 * int u = edges[i][0];
 * int v = edges[i][1];
 * adj[u].push_back(v);
 * adj[v].push_back(u);
 * }
 * }
 * 
 * void bfs(int src, int par, int &timer, vector<int> &disc, vector<int> &low,
 * vector<vector<int>> &result, unordered_map<int, list<int>> &adj,
 * unordered_map<int, bool> &vis)
 * {
 * // strt bfs : recursion
 * vis[src] = true;
 * disc[src] = low[src] = timer++;
 * 
 * for (auto neigh : adj[src])
 * {
 * // if its a parent of the neigh - ignore
 * if (neigh == par)
 * {
 * continue;
 * }
 * 
 * if (!vis[neigh])
 * {
 * bfs(neigh, src, timer, disc, low, result, adj, vis);
 * // coming back after recr to parent node
 * // check 1 : low update, if it was a back edge
 * low[src] = min(low[src], low[neigh]);
 * 
 * // check 2 : edge is a bridge
 * if (low[neigh] > disc[src])
 * {
 * // its a bridge
 * vector<int> v;
 * v.push_back(src);
 * v.push_back(neigh);
 * result.push_back(v);
 * }
 * }
 * else
 * {
 * // already visited , its a back edge **
 * low[src] = min(disc[neigh], low[src]);
 * }
 * }
 * }
 * 
 * vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e)
 * {
 * // Write your code here
 * // create all Ds : 1. adj list
 * unordered_map<int, list<int>> adj;
 * prepareAdjList(adj, edges, e);
 * 
 * // 2. disc Ds
 * vector<int> disc(v);
 * 
 * // 3. low Ds
 * vector<int> low(v);
 * 
 * // 4. parent
 * int parent = -1;
 * unordered_map<int, bool> vis;
 * int timer = 0;
 * 
 * for (int i = 0; i < v; i++)
 * {
 * disc[i] = -1;
 * low[i] = -1;
 * }
 * 
 * // traversing the graph using BFS :
 * // cover if any disc compo is present:
 * vector<vector<int>> result; // store the bridge edges
 * for (int i = 0; i < v; i++)
 * {
 * if (!vis[i])
 * {
 * bfs(i, parent, timer, disc, low, result, adj, vis);
 * }
 * }
 * return result;
 * }
 * 
 */