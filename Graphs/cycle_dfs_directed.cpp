/*

PS :
Given DIRECTED GRAPH , so Connected graph only it will be.
Detect cycle in it.

.................................................................................................
*********
Why the logic of UNDIRECTED GRAPH CANNOT BE APPLIED IN DIRECTED GRAPH
CYCLE DETECT ?

Consider a directed graph :
1 - 2
2 - 3
3 - 7
3 - 8
8 - 7
2 - 4
4 - 5
5 - 6

so if we see subgraph and follow the undirected approach :
=> if already vis + not its parent => CYCLE

4 -> 5 -> 6 -> 4

here parent[5] = 4 , parent[6] = 5

6 -> 4 : but 4 is already vis && par[6] = 5 != 4
So this will give a cycle.

................................

Now 2nd subgraph :
3 -> 8 -> 7

In adj list :
3 -> 7, 8
8 -> 7

Now 1st 3 is encountered.
2nd 7 is visited. 7 doesnt have further , back to 3 -> 8
3rd 8 is encountered. make vis[8] = true.
4th 8-> 7 , already visited 7.
And condition for cycle is checked now :

vis[7] != true && par[8] != 7
THROW CYCLE DETECTED !!

But HERE WE DONT HAVE A CYCLE IN THE PATH : 3->8->7
So thats why sometimes , this logic wont work out in directed graphs.

.................................................................................................

SOLVED BY DFS :

APPROACH :

1.  Current DS : adjList map , queue , vis map

2.  NEED OF ANOTHER DS : dfsVis map :
    It keeps track of nodes for which DFS call is sent and also for those
    whose call has returned back after recr compltes for that node.

3.  Recr call of a node is sent = true
    Recr call of a node is returned back = false

4.  CYCLE CONDITION :

    vis[node] = true
    &&
    dfsVis[node] = true

    CYCLE PRESENT !!!

5.  Because if a cyclic node is called again , it forms a infinite recursion
    And dfsVis[node] = true, means its still present in the recr tree , and it has a child
    which has called this current node , and this child then calls back the src node /
    cyclic node.

.................................................................................................

https://www.codingninjas.com/codestudio/problems/detect-cycle-in-a-directed-graph_920545

TC : O(N+M)
SC : O(N+M)

*/

#include <bits/stdc++.h>
void prepAdjList(unordered_map<int, list<int>> &adj, vector<vector<int>> &edges, int m)
{
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        // *** only one edge insertion
        adj[u].push_back(v);
    }
}

bool dfsCycleDetect(unordered_map<int, list<int>> adj, unordered_map<int, bool> &vis, unordered_map<int, bool> &dfsVis, int src)
{
    // use DFS : use recursion, no queue
    vis[src] = true;
    dfsVis[src] = true;

    for (auto node : adj[src])
    {
        // ***** cycle condition check ****** //
        if (vis[node] == true && dfsVis[node] == true)
            return true;
        else if (!vis[node])
        {
            bool ans = dfsCycleDetect(adj, vis, dfsVis, node);
            dfsVis[node] = false;
            if (ans == true)
                return true;
        }
    }
    dfsVis[src] = false;

    return false;
}

bool isCyclic(vector<vector<int>> &edges, int v, int e)
{
    // build all necessary ds
    int n = v;
    int m = e;
    // 1. adj list
    unordered_map<int, list<int>> adj;
    prepAdjList(adj, edges, m);

    // 2. create visited map
    unordered_map<int, bool> vis;
    for (int i = 0; i < n; i++)
    {
        vis[i] = false;
    }

    // 3. create dfsVis map : track recr calls for nodes
    unordered_map<int, bool> dfsVis;
    for (int i = 0; i < n; i++)
    {
        dfsVis[i] = false;
    }

    // 4. loop for all conn components
    int ans = false;
    for (int i = 0; i < n; i++)
    {
        ans = dfsCycleDetect(adj, vis, dfsVis, i);
        if (ans == true)
            return true;
    }
    return false;
}