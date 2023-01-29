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

#include <bits/stdc++.h>

void prepAdjList(unordered_map<int, list<int>> &adj, vector<vector<int>> &edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        // directed
        adj[u].push_back(v);
    }
}

void dfs(int src, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &vis, stack<int> &s)
{
    vis[src] = true;
    for (auto neigh : adj[src])
    {
        if (!vis[neigh])
        {
            dfs(neigh, adj, vis, s);
        }
    }
    s.push(src);
}

void prepTranspose(int v, unordered_map<int, list<int>> &trans, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &vis)
{
    for (int i = 0; i < v; i++)
    {
        vis[i] = false;
        for (auto neigh : adj[i])
        {
            trans[neigh].push_back(i);
        }
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
    // Write your code here.
    // prep adj list
    unordered_map<int, list<int>> adj;
    prepAdjList(adj, edges);
    int count = 0;

    // step 1 : topo sort : dfs
    unordered_map<int, bool> vis;
    stack<int> s;

    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, vis, s);
        }
    }

    // step 2: graph transpose :
    unordered_map<int, list<int>> trans;
    prepTranspose(v, trans, adj, vis);

    // step 3 : dfs on topo sort
    while (!s.empty())
    {
        int top = s.top();
        s.pop();
        if (!vis[top])
        {
            count++;
            dfs(top, trans, vis, s);
        }
    }

    return count;
}