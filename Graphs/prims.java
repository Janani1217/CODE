/*
Prims Algorithm :
This algo is used to get minimum spanning tree = MST

.................................................................................................

Spanning Tree : CONDITION :

1.  If a graph is converted into a tree which has N NODES and N-1 EDGES.
2.  Every node is REACHABLE from every other node
3.  Now TREE NEVER CONTAINS A CYCLE
4.  So its a acyclic graph

.................................................................................................

Minimum Spanning Tree :

1.  THE TOTAL COST OF THE TREE SHOULD BE MINIMUM OF ALL THE OTHER SPANNING TREES
    WHICH CAN BE OBTAINED.

2.  So it means that , there can be many no. of spanning trees which can be obtained

3.  So to get a MST we can use PRIM'S ALGO
.................................................................................................

PRIM'S ALGORITHM :

1.  DS Needed : 3 DS ; indexes indicate the node
    1.  key : init with infinity
    2.  mst : init with false : to inidcate which node is in mst
    3.  parent : init with -1

2.  src_node = 0
    key[src_node] = 0;
    parent[src_node] = -1;

3.  From the key DS , get the min value among all, whose mst is FALSE ONLY ,
    Because its already included in the spanning tree ,

    key[u] = 0;
    mst[u] = true;

4.  Find all the neigh of u ->
    Update the dist of the neigh nodes in the key DS ;
    Update the parent[neigh] = u;

5.  Same repeat from 3 -> 5 points above and update the DS

6.  During update of Key DS, if already the value is present, compare it with the
    current edge wg value , and update the Key DS, only if current val is lesser

7.  Now finally after the mst DS fills with all true, we stop

8.  Take the parent[] , make the edges between the child = index and parent = value
    present in that parent[index]

    Weights will be the same in the edges.
    Cal the entire sum of wg of edges.

.................................................................................................

*/

import java.util.*;

class Pair {
    int first;
    int sec;

    public Pair(int first, int sec) {
        this.first = first;
        this.sec = sec;
    }

    public int getFirst() {
        return first;
    }

    public int getSec() {
        return sec;
    }
}

class Solution {

    static int[] key;
    static int[] parent;
    static boolean[] isInMST;

    static void prepareAdjList(Map<Integer, List<Pair>> adjList, int edges[][]) {
        for (int i = 0; i < edges.length; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wg = edges[i][2];

            adjList.computeIfAbsent(u, k -> new ArrayList<>()).add(new Pair(v, wg));
            adjList.computeIfAbsent(v, k -> new ArrayList<>()).add(new Pair(u, wg));
        }
    }

    static void fillDS(int V) {
        key = new int[V];
        parent = new int[V];
        isInMST = new boolean[V];

        for (int i = 0; i < V; i++) {
            key[i] = Integer.MAX_VALUE;
            parent[i] = -1;
            isInMST[i] = false;
        }
    }

    static void primsAlgo(Map<Integer, List<Pair>> adj, int v) {

        for (int i = 0; i < v; i++) {
            int mini = Integer.MAX_VALUE;
            int node = 0;

            // take out the min value among the key
            for (int j = 0; j < v; j++) {
                if (isInMST[j] == false && key[j] < mini) {
                    mini = key[j];
                    node = j;
                }
            }

            // update mst only for the min node which is taken out
            isInMST[node] = true;

            // traverse through its adj nodes and update mst
            List<Pair> ll = adj.get(node);

            for (Pair p : ll) {
                int neighNode = p.getFirst();
                int dist = p.getSec();

                if (isInMST[neighNode] == false && dist < key[neighNode]) {
                    key[neighNode] = dist;
                    parent[neighNode] = node;
                }
            }
        }
    }

    static int findEdgeWeight(Map<Integer, List<Pair>> adj, int u, int v) {
        if (adj.containsKey(u)) {
            List<Pair> neighbors = adj.get(u);
            for (Pair pair : neighbors) {
                if (pair.getFirst() == v) {
                    return pair.getSec();
                }
            }
        }
        // Edge not found, return a default value or throw an exception as needed.
        return -1;
    }

    static int spanningTree(int V, int E, int edges[][]) {
        // prep adj list
        Map<Integer, List<Pair>> adjList = new HashMap<>();
        prepareAdjList(adjList, edges);

        // prep other ds :
        fillDS(V);

        int src = edges[0][0];
        key[src] = 0;
        parent[src] = -1;

        primsAlgo(adjList, V);

        // now for the mst with the parent ds
        int wg = 0;

        for (int i = 0; i < V; i++) {
            if (parent[i] != -1) {
                int u = i;
                int v = parent[i];

                int w = findEdgeWeight(adjList, u, v);

                if (w != -1)
                    wg += w;

                // for(int j=0; j<edges.length; j++) {
                // if((edges[j][0] == u && edges[j][1]==v) || (edges[j][0] == v && edges[j][1]
                // == u)) {
                // wg += edges[j][2];
                // }
                // }
            }
        }

        return wg;
    }
}

/*
 * #include <bits/stdc++.h>
 * void prepareAdjList(unordered_map<int, list<pair<int, int>>> &adj,
 * vector<pair<pair<int, int>, int>> g, int m)
 * {
 * for (int i = 0; i < m; i++)
 * {
 * pair<pair<int, int>, int> p = g[i];
 * auto curr = p.first;
 * int wg = p.second;
 * 
 * int u = curr.first;
 * int v = curr.second;
 * 
 * adj[u].push_back(make_pair(v, wg));
 * adj[v].push_back(make_pair(u, wg));
 * }
 * }
 * 
 * void prims(unordered_map<int, list<pair<int, int>>> adj, vector<int> &key,
 * vector<bool> &mst, vector<int> &parent, int n)
 * {
 * // source node = 1
 * key[1] = 0;
 * parent[1] = -1;
 * 
 * // start the algo
 * for (int i = 1; i < n; i++)
 * {
 * // 1. get the min ele in key with prioirty queue
 * int mini = INT_MAX;
 * int u; // to find the min node
 * 
 * for (int v = 1; v <= n; v++)
 * {
 * if (!mst[v] && key[v] < mini)
 * {
 * mini = key[v];
 * u = v;
 * }
 * }
 * 
 * // 2. update mst of u
 * mst[u] = true;
 * 
 * // 3. find its adj nodes
 * for (auto neigh : adj[u])
 * {
 * int node = neigh.first;
 * int dist = neigh.second;
 * 
 * // 4. check condition if not in mst
 * if (mst[node] == false && dist < key[node])
 * {
 * key[node] = dist;
 * parent[node] = u;
 * }
 * }
 * }
 * }
 * 
 * vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m,
 * vector<pair<pair<int, int>, int>> &g)
 * {
 * // 1. create all ds : adj list
 * unordered_map<int, list<pair<int, int>>> adj;
 * prepareAdjList(adj, g, m);
 * 
 * // 2. create ans
 * vector<pair<pair<int, int>, int>> ans;
 * 
 * // 3. prim's algo other DS : key
 * vector<int> key(n + 1, INT_MAX);
 * 
 * // 4. DS for MST nodes
 * vector<bool> mst(n + 1, false);
 * 
 * // 5. DS for storing parent
 * vector<int> parent(n + 1, -1);
 * // this parent will give the ans
 * 
 * // 6. start the process of creating mst
 * prims(adj, key, mst, parent, n);
 * 
 * // 7. parent DS is ready , construct the mst
 * for (int i = 1; i <= n; i++)
 * {
 * int node = i;
 * int par = parent[i];
 * if (par != -1)
 * {
 * // not a source node
 * int wg = key[node];
 * ans.push_back({{par, node}, wg});
 * }
 * }
 * 
 * return ans;
 * }
 * 
 */