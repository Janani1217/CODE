/*

TOPOLOGICAL Sort : using BFS : KAHN'S ALGORITHM

ordering of graph , for every node u if appears before v node in adj
list , then in the topo ordering also u should come in front of v.

Topo can applied only in directed graphs only , since we are checking
ordering

And Topo sort cant be applied in cyclic graphs

............................................................................................................................................

ALGORITHM ;

1.  Find Indegree of all nodes

2.  DS : queue (we create in BFS) :  first push nodes with indegree = 0

3.  Do BFS same -> take front_node -> pop q -> include in ans -> loop neighbours

4.  so when we pop a node from queue , and move to its neigh, then the
    indegree of the neigh should definetly be reduced by 1.

5.  And those neigh node whose indegree got reduced , push it to queue.

6. same continues till queue gets empty.

............................................................................................................................................

TC : O(N+E)
SC : O(N)

............................................................................................................................................

*/

#include <bits/stdc++.h>

void prepareAdjList(unordered_map<int, list<int>> &adj, vector<vector<int>> &edges, int m, vector<int> &indegree)
{
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        // directed graph
        adj[u].push_back(v);
        indegree[v]++;
    }
}

void bfs(unordered_map<int, list<int>> adj, vector<int> &indegree, int src, vector<int> &ans, queue<int> &q)
{
    while (!q.empty())
    {
        int first_node = q.front();
        q.pop();
        // cout <<">> " <<first_node << endl;
        ans.push_back(first_node);

        for (auto neighbours : adj[first_node])
        {
            indegree[neighbours]--;
            if (indegree[neighbours] == 0)
                q.push(neighbours);
        }
    }
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    // solve topo order using bfs : using queu : kahn algo
    // req DS : adj list + indegree

    // init indegree with size v and init values with 0's
    vector<int> indegree(v, 0);
    unordered_map<int, list<int>> adj;
    prepareAdjList(adj, edges, e, indegree);

    // print indegree
    //     cout << "print indegree : " << endl;
    //     for(int i=0; i<v; i++)
    //     {
    //         cout <<i<<" -> "<< indegree[i] << endl;
    //     }

    // 2. push node with 0 indegree
    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // 3. call bfs
    vector<int> ans;

    // dont need for disconn components
    bfs(adj, indegree, i, ans, q);

    return ans;
}