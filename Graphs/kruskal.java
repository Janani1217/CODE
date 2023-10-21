/*
Minimum Spanning tree using Kruskal algorithm :

Given : graph is :
undirected
connected
weighted

Find and print total weight of MST using Kruskal algo.
*/

/*
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

int findParent(vector<int> &parent, int node)
{
    if (parent[node] == node)
        return node;
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


*/

//{ Driver Code Starts

import java.util.*;

class Solution {
    static int[] parent, rank;

    static void makeSet(int v) {
        parent[v] = v;
        rank[v] = 0;
    }

    static int findSet(int v) {
        if (v == parent[v])
            return v;

        return parent[v] = findSet(parent[v]);
    }

    static void unionSets(int a, int b) {
        a = findSet(a);
        b = findSet(b);

        if (a != b) {
            if (rank[a] < rank[b]) {
                int temp = a;
                a = b;
                b = temp;
            }
            parent[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;
        }
    }

    static int spanningTree(int V, int E, int edges[][]) {
        parent = new int[V];
        rank = new int[V];

        Arrays.sort(edges, (a, b) -> a[2] - b[2]);

        for (int i = 0; i < V; i++) {
            makeSet(i);
        }

        int cost = 0;

        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if (findSet(u) != findSet(v)) {
                cost += w;
                unionSets(u, v);
            }
        }

        return cost;
    }
}