
/*
Strongly connected components : from one node , u can reach to any node in that
connected component of the Graph.

Kosaraju's Algorithm :

1.  Prepare adj list

2.  Topo sort , using dfs , using stack insertion after recr call returns

3.  tranpose graph : make u insert back in v

4.  do dfs calling on the stack formed in step 2, loop till stack gets empty,
    increment count of SCC , for no. times the dfs call is made in that loop.

5.  return count;

REFER TO NOTEBOOK FOR DETAILS !!

.................................................................................................

*/
import java.util.*;

class Solution {
    int[] vis;

    public void prepareAdjList(int v, ArrayList<ArrayList<Integer>> adj, HashMap<Integer, List<Integer>> adjL) {
        for (int i = 0; i < v; i++) {
            ArrayList<Integer> arr = adj.get(i);
            adjL.put(i, arr);
        }
    }

    public void topoSorting(Stack<Integer> st, HashMap<Integer, List<Integer>> adjL, int src) {
        vis[src] = 1;
        List<Integer> ll = adjL.get(src);

        for (Integer neigh : ll) {
            if (vis[neigh] == 0) {
                topoSorting(st, adjL, neigh);
            }
        }

        st.push(src);
    }

    public void fillDS(int V) {
        for (int i = 0; i < V; i++) {
            vis[i] = 0;
        }
    }

    public void transposeGraph(HashMap<Integer, List<Integer>> trans, HashMap<Integer, List<Integer>> adj, int v) {
        for (int i = 0; i < v; i++) {
            for (int neigh : adj.getOrDefault(i, new ArrayList<>())) {
                trans.computeIfAbsent(neigh, k -> new ArrayList<>()).add(i);
            }
        }
    }

    public void dfs(HashMap<Integer, List<Integer>> adjTransL, int src) {
        vis[src] = 1;

        List<Integer> ll = adjTransL.getOrDefault(src, new ArrayList<>());

        for (Integer neigh : ll) {
            if (vis[neigh] == 0) {
                dfs(adjTransL, neigh);
            }
        }
    }

    public int kosaraju(int V, ArrayList<ArrayList<Integer>> adj) {
        // prepare adj list
        HashMap<Integer, List<Integer>> adjL = new HashMap<>();
        prepareAdjList(V, adj, adjL);

        vis = new int[V];
        fillDS(V);

        // get the topo sorting
        Stack<Integer> st = new Stack<>();
        for (int i = 0; i < V; i++) {
            if (vis[i] == 0) {
                topoSorting(st, adjL, i);
            }
        }

        // clear the vis ds
        fillDS(V);

        // transpose graph
        HashMap<Integer, List<Integer>> adjTransL = new HashMap<>();
        transposeGraph(adjTransL, adjL, V);

        // // print transpose graph
        // for(HashMap.Entry<Integer, List<Integer>> entry : adjTransL.entrySet()) {
        // System.out.println(entry.getKey());
        // List<Integer> ll = entry.getValue();

        // for(Integer i : ll) {
        // System.out.println(i);
        // }
        // System.out.println("next");
        // }

        // traverse on dfs
        int count = 0;
        while (!st.isEmpty()) {
            int top = st.peek();
            st.pop();
            if (vis[top] == 0) {
                count++;
                dfs(adjTransL, top);
            }
        }
        return count;
    }
}

/*
 * #include <bits/stdc++.h>
 * 
 * void prepAdjList(unordered_map<int, list<int>> &adj, vector<vector<int>>
 * &edges)
 * {
 * for (int i = 0; i < edges.size(); i++)
 * {
 * int u = edges[i][0];
 * int v = edges[i][1];
 * 
 * // directed
 * adj[u].push_back(v);
 * }
 * }
 * 
 * void dfs(int src, unordered_map<int, list<int>> &adj, unordered_map<int,
 * bool> &vis, stack<int> &s)
 * {
 * vis[src] = true;
 * for (auto neigh : adj[src])
 * {
 * if (!vis[neigh])
 * {
 * dfs(neigh, adj, vis, s);
 * }
 * }
 * s.push(src);
 * }
 * 
 * void prepTranspose(int v, unordered_map<int, list<int>> &trans,
 * unordered_map<int, list<int>> &adj, unordered_map<int, bool> &vis)
 * {
 * for (int i = 0; i < v; i++)
 * {
 * vis[i] = false;
 * for (auto neigh : adj[i])
 * {
 * trans[neigh].push_back(i);
 * }
 * }
 * }
 * 
 * int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
 * {
 * // Write your code here.
 * // prep adj list
 * unordered_map<int, list<int>> adj;
 * prepAdjList(adj, edges);
 * int count = 0;
 * 
 * // step 1 : topo sort : dfs
 * unordered_map<int, bool> vis;
 * stack<int> s;
 * 
 * for (int i = 0; i < v; i++)
 * {
 * if (!vis[i])
 * {
 * dfs(i, adj, vis, s);
 * }
 * }
 * 
 * // step 2: graph transpose :
 * unordered_map<int, list<int>> trans;
 * prepTranspose(v, trans, adj, vis);
 * 
 * // step 3 : dfs on topo sort
 * while (!s.empty())
 * {
 * int top = s.top();
 * s.pop();
 * if (!vis[top])
 * {
 * count++;
 * dfs(top, trans, vis, s);
 * }
 * }
 * 
 * return count;
 * }
 * 
 */