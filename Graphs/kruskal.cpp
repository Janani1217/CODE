/*
Minimum Spanning tree using Kruskal algorithm :

Given : graph is :
undirected
connected
weighted

Find and print total weight of MST using Kruskal algo.
*/

#include <bits/stdc++.h>
#include <algorithm>
void makeSet(vector<int> &parent, vector<int> &rank, int n)
{
    for (int i = 0; i <= n; i++)
    {
        rank[i] = 0;
        parent[i] = i;
    }
}

// first operation : find the actual parent
int findParent(vector<int> &parent, int node)
{
    // root node will have its par as the root node itself
    // and it will be the terminating point
    if (parent[node] == node)
        return node;

    /* now move to the upper top in the graph to reach the root
      node to get actual parent : so recr call back to its parent
      to do path compression , we have to know the par of current node to be
      ans ret from the recr call made.
    */
    parent[node] = findParent(parent, parent[node]);
    return parent[node];
}

// second operation : find union of 2 nodes
void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
{
    // first find parent
    int par1 = findParent(parent, u);
    int par2 = findParent(parent, v);
    if (rank[par1] == rank[par2])
    {
        // follow algo 1:
        parent[par1] = par2;
        rank[par1]++;
    }
    else if (rank[par1] > rank[par2])
    {
        parent[par2] = par1;
    }
    else if (rank[par1] < rank[par2])
    {
        parent[par1] = par2;
    }
}

bool cmp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}
int kruskalMST(int n, int m, vector<vector<int>> &graph)
{
    // assign all Ds needed :
    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent, rank, n);

    // we dont need adj list , linear DS is already given : graph
    // need to sort based on edges weights
    sort(graph.begin(), graph.end(), cmp);

    int min_wg = 0;
    // start iterating in the linear DS :
    for (int i = 0; i < graph.size(); i++)
    {
        // find parent
        int u = findParent(parent, graph[i][0]);
        int v = findParent(parent, graph[i][1]);

        // compare if both par are same or not : same components or not
        if (u != v)
        {
            // will be added into the tree.
            min_wg += graph[i][2];
            // belongs to diff components : so merge/union both
            unionSet(u, v, parent, rank);
        }
    }
    return min_wg;
}