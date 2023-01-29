/*
Bridges in graph :

The edge if on removal which will increase the conn components , or make the
graph disconnected.

Brute force : pick every edge and check if on removal , get the no. conn compo
in the graph.

NOTES Refer..

.................................................................................................

*/

#include <bits/stdc++.h>
void prepareAdjList(unordered_map<int, list<int>> &adj, vector<vector<int>> edges, int m)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void bfs(int src, int par, int &timer, vector<int> &disc, vector<int> &low, vector<vector<int>> &result, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &vis)
{
    // strt bfs : recursion
    vis[src] = true;
    disc[src] = low[src] = timer++;

    for (auto neigh : adj[src])
    {
        // if its a parent of the neigh - ignore
        if (neigh == par)
        {
            continue;
        }

        if (!vis[neigh])
        {
            bfs(neigh, src, timer, disc, low, result, adj, vis);
            // coming back after recr to parent node
            // check 1 : low update, if it was a back edge
            low[src] = min(low[src], low[neigh]);

            // check 2 : edge is a bridge
            if (low[neigh] > disc[src])
            {
                // its a bridge
                vector<int> v;
                v.push_back(src);
                v.push_back(neigh);
                result.push_back(v);
            }
        }
        else
        {
            // already visited , its a back edge **
            low[src] = min(disc[neigh], low[src]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e)
{
    // Write your code here
    // create all Ds : 1. adj list
    unordered_map<int, list<int>> adj;
    prepareAdjList(adj, edges, e);

    // 2. disc Ds
    vector<int> disc(v);

    // 3. low Ds
    vector<int> low(v);

    // 4. parent
    int parent = -1;
    unordered_map<int, bool> vis;
    int timer = 0;

    for (int i = 0; i < v; i++)
    {
        disc[i] = -1;
        low[i] = -1;
    }

    // traversing the graph using BFS :
    // cover if any disc compo is present:
    vector<vector<int>> result; // store the bridge edges
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            bfs(i, parent, timer, disc, low, result, adj, vis);
        }
    }
    return result;
}