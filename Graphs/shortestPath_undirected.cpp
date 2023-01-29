/*

Shortest path in undirected graph :

1.  undirected = unweighted graph
2.  USING BFS : traverse LEVEL BY LEVEL
3.  So , we can get the shortest level path using bfs easily
4.  Because bfs works over shortest distance only

.................................................................................................

Data structers used :
1.  adj list
2.  queue : bfs
3.  vis ds
3.  PARENT DS : to store parent

.................................................................................................

Parent Ds :

This is used to get the final ans of shortest path found.
Since we traversed by using BFS, we will store the parent in the same way.

So we get the src node and dest node also in the question.

Now in the parent array , traverse back from dest node in parent -> src node
in parent array.

This will give us the shortest path. We have to finnaly reverse the final
output array to get the actual ans path.

.................................................................................................

LOGIC : BACKTRACT FROM DEST NODE TILL SRC NODE IN PARENT ARRAY STORES USING BFS

Use the src node given in question (if) to pass into the bfs call !!

.................................................................................................

TC : O(N+E)
SC : O(N + N + N) = O(N)

.................................................................................................

*/

#include <bits/stdc++.h>
using namespace std;

void prepareAdjList(unordered_map<int, list<int>> &adj, vector<pair<int, int>> edges, int m)
{
    pair<int, int> p;
    for (int i = 0; i < m; i++)
    {
        p = edges[i];
        int u = p.first;
        int v = p.second;

        // undirected graph:
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void bfs(unordered_map<int, list<int>> adj, unordered_map<int, bool> &vis, unordered_map<int, int> &parent, int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    parent[src] = -1;

    while (!q.empty())
    {
        int first_node = q.front();
        q.pop();

        for (auto neigh : adj[first_node])
        {
            if (!vis[neigh])
            {
                vis[neigh] = true;
                parent[neigh] = first_node;
                q.push(neigh);
            }
        }
    }
}
vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t)
{

    // find the shortest path using bfs using parent array
    // make all ds
    // 1. adj list
    unordered_map<int, list<int>> adj;
    prepareAdjList(adj, edges, m);

    // 3. ds. = vis
    unordered_map<int, bool> vis;

    // 4. parent array
    unordered_map<int, int> parent;

    // 5. call bfs for shortest path with the src node given
    bfs(adj, vis, parent, s);

    // 6. get the final path
    vector<int> path;

    while (t != s)
    {
        path.push_back(t);
        int par = parent[t];
        t = par;
    }
    path.push_back(t);

    // reverse the path vector
    reverse(path.begin(), path.end());
    return path;
}
