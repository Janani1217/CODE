import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

/*
Dijkstra's Algorithm :
SHORTEST DISTANCE FROM SRC TO ALL OTHER NODES

Given :
undirected graph
edges with weights

.................................................................................................

Approach :

1.  DS :
    1.  distance vector : needed anyhow with size n and init with infinity
    2.  set = pair<int,int>  : always get the min distance : need of ordering

        p.first = distance
        p.second = node

        so sorting inside set happens wrt distance , so we kept it in first

2.  init the distance of src node = 0;
    update set -> (0, 0) : src = 0, dist[src] = 0

3.  now take the top from set -> (0 ,0)
    move to the neighbours of the top_node = 0

4.  update the dist_vector of the neigh_nodes wrt top_node
    &
    insert into set <neigh_dist , neigh_node>

5.  now again if we take the top_node from set , we get the min distance node
    and continue the same process and update the dist vector wrt its neigh
    nodes.

6.  update the distance , only if prev dist is greater than the current dist

7.  so the final dist vector gives the shortest distance from src node to all
    the other nodes which are indicated by the indexes of the dist vector

.................................................................................................

TC : O(E log V)
SC : O(V + E)

.................................................................................................

*/

class Solution {
    public int[] findMinDistance(ArrayList<ArrayList<Integer>> graph, int src, int n) {
        int[] minDist = new int[n];
        for (int i = 0; i < n; i++) {
            minDist[i] = (int) (1e9);
        }
        minDist[src] = 0;
        Queue<Integer> qu = new LinkedList<>();
        qu.add(src);
        while (qu.size() > 0) {
            int rm = qu.remove();
            for (Integer adjNode : graph.get(rm)) {
                int nwt = minDist[rm] + 1;
                if (nwt < minDist[adjNode]) {
                    minDist[adjNode] = nwt;
                    qu.add(adjNode);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (minDist[i] == (1e9)) {
                minDist[i] = -1;
            }
        }
        return minDist;
    }

    public int[] shortestPath(int[][] edges, int n, int m, int src) {
        ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }
        for (int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            graph.get(u).add(v);
            graph.get(v).add(u);
        }
        return findMinDistance(graph, src, n);
    }
}

/*
 * #include <bits/stdc++.h>
 * 
 * void djkistra(unordered_map<int, list<pair<int, int>>> adj, set<pair<int,
 * int>> &s, vector<int> &dist, int src)
 * {
 * while (!s.empty())
 * {
 * // fetch the top data from ordered set
 * auto top = *(s.begin());
 * int node_dist = top.first;
 * int node = top.second;
 * // erase the top data
 * s.erase(s.begin());
 * 
 * // traverse its neigh nodes
 * for (auto neigh : adj[node])
 * {
 * if (dist[neigh.first] > neigh.second + node_dist)
 * {
 * // first find if we already have a record for the neigh node
 * // in the set with SOME distance , so first delete that and then insert this
 * // It could have been vis by some other node and inserted into the set
 * previosly
 * auto record = s.find(make_pair(dist[neigh.first], neigh.first));
 * 
 * if (record != s.end())
 * {
 * s.erase(record);
 * }
 * 
 * dist[neigh.first] = node_dist + neigh.second;
 * s.insert(make_pair(dist[neigh.first], neigh.first));
 * }
 * }
 * }
 * }
 * 
 * vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int
 * source)
 * {
 * // 1. create adj list
 * unordered_map<int, list<pair<int, int>>> adj;
 * 
 * for (int i = 0; i < edges; i++)
 * {
 * int u = vec[i][0];
 * int v = vec[i][1];
 * int d = vec[i][2];
 * 
 * adj[u].push_back(make_pair(v, d));
 * adj[v].push_back(make_pair(u, d));
 * }
 * 
 * int n = vertices;
 * // 2. create and init dist vector with infinity
 * vector<int> dist(n);
 * for (int i = 0; i < n; i++)
 * {
 * dist[i] = INT_MAX;
 * }
 * dist[source] = 0;
 * 
 * // find the sp from src node given to all the other nodes
 * // 3. ordered set to get min distance for each node
 * set<pair<int, int>> s;
 * s.insert(make_pair(0, source));
 * 
 * djkistra(adj, s, dist, source);
 * 
 * return dist;
 * }
 */
