/*
PS : Articulation points in Graphs:

Check notes for complete explaination
.................................................................................................

*/

import java.util.*;

class Solution1 {
    public void DFS(int u, ArrayList<ArrayList<Integer>> adj, ArrayList<Integer> res,
            int[] visited, int[] parent, int[] disc, int[] low, int time) {
        int children = 0;
        visited[u] = 1;
        low[u] = disc[u] = time;
        for (int v : adj.get(u)) {
            if (visited[v] == 0) {
                children++;
                parent[v] = u;
                DFS(v, adj, res, visited, parent, disc, low, time + 1);
                low[u] = Math.min(low[u], low[v]);

                if (parent[u] == -1 && children > 1 && !res.contains(u)) {
                    res.add(u);
                }
                if (parent[u] != -1 && disc[u] <= low[v] && !res.contains(u)) {
                    res.add(u);
                }
            } else if (parent[v] != u) {
                low[u] = Math.min(low[u], disc[v]);
            }
        }
    }

    // Function to return Breadth First Traversal of given graph.
    public ArrayList<Integer> articulationPoints(int V, ArrayList<ArrayList<Integer>> adj) {
        int[] low = new int[V];
        int[] disc = new int[V];
        int[] visited = new int[V];
        int[] parent = new int[V];
        parent[0] = -1;
        ArrayList<Integer> res = new ArrayList<Integer>();

        DFS(0, adj, res, visited, parent, disc, low, 0);

        if (res.size() == 0) {
            res.add(-1);
            return res;
        }

        Collections.sort(res);
        return res;
    }
}

/*
 * #include <bits/stdc++.h>
 * using namespace std;
 * 
 * class Solution
 * {
 * public:
 * void dfsAP(int &node, int &timer, int &par, unordered_map<int, bool> &vis,
 * vector<int> &disc, vector<int> &low, vector<int> adj[], vector<bool> &res)
 * {
 * vis[node] = true;
 * disc[node] = low[node] = timer++;
 * int child = 0;
 * 
 * for (auto neigh : adj[node])
 * {
 * // check for parent
 * if (par == neigh)
 * {
 * continue;
 * }
 * 
 * // rem part
 * if (!vis[neigh])
 * {
 * 
 * dfsAP(neigh, timer, node, vis, disc, low, adj, res);
 * 
 * // 1. check if BE:
 * low[node] = min(low[node], low[neigh]);
 * 
 * // 2. check for AP :
 * if (low[neigh] >= disc[node] && par != -1)
 * res[node] = true;
 * 
 * child++;
 * }
 * else
 * {
 * // back edge is present : update low
 * low[node] = min(low[node], low[neigh]);
 * }
 * 
 * if (par == -1 && child > 1)
 * res[node] = true;
 * }
 * }
 * 
 * vector<int> articulationPoints(int V, vector<int> adj[])
 * {
 * // Code here
 * // make all the Ds : adj list already made
 * // other Ds :
 * vector<int> disc(V);
 * vector<int> low(V);
 * 
 * for (int i = 0; i < V; i++)
 * {
 * disc[i] = low[i] = -1;
 * }
 * 
 * int parent = -1;
 * unordered_map<int, bool> vis(V);
 * int timer = 0;
 * 
 * // to store AP
 * vector<bool> res(V);
 * for (int i = 0; i < V; i++)
 * res[i] = false;
 * 
 * // need to run bfs for disc G
 * for (int i = 0; i < V; i++)
 * {
 * if (!vis[i])
 * {
 * dfsAP(i, timer, parent, vis, disc, low, adj, res);
 * }
 * }
 * 
 * vector<int> ans;
 * // needed ans in order of traversal
 * for (int i = 0; i < V; i++)
 * {
 * if (res[i] == true)
 * ans.push_back(i);
 * }
 * 
 * if (ans.size() == 0)
 * ans.push_back(-1);
 * 
 * return ans;
 * }
 * };
 */