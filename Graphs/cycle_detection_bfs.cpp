/*
Cycle Deetction :

Given a graph with disconnected components.
undirected
have a cycle

.................................................................................................

Algo : USING BFS

1.  create adj list
2.  create vis DS
3.  create queue to store node for traversal

4.  now if a node is already vis , we used to ignore and move forward in bfs and dfs algo
    But now , we need to check its parent also.
    So create a DS to store PARENT .

    unordered_map<int,int> parent;

5.  src init node -> we start -> vis[src] = true -> parent[src] = -1; -> q.push(src)

6.  adj[src] -> check all its adj nodes, visit it if not visited and go in the 5th
    line process. contd..

7.  now if this process encounters a node in adj list which is :
    1.  already vis = true
    2.  encountered_node -> parent[curr_node]
        IGNORE

8.  Parent of a node -> the node in the adj list left side , right child nodes are child
    nodes if called from the node present in the left part of adj list

9.  SO NEGLECT A NODE CONDITION :
    1. VISTED TRUE
    2. PARENT NODE OF CALLING NODE ONLY

10. And when we jump to another compo in the graph , new src node will be created auto
    in the for loop that we write.

11.  CYCLE DETECTION CONDITION :
    1. VISITED TRUE
    2. PARENT OF CALLING NODE != ENCOUNTED_NODE IN ADJ LIST OF CALLING NODE

    CYCLE PRESENT
    LOOP BREAKS !!!

.................................................................................................

https://www.codingninjas.com/codestudio/problems/cycle-detection-in-undirected-graph_1062670

TC: O(n+m)
SC: O(n+m)

.................................................................................................

*/

#include <bits/stdc++.h>
using namespace std;

void prepareAdjList(unordered_map<int, list<int>> &adj, vector<vector<int>> &edges, int m)
{
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

bool bfsDetectCycle(unordered_map<int, list<int>> adj, unordered_map<int, bool> &vis, int src, unordered_map<int, int> &parent)
{
    // 1. queue ds to traverse
    queue<int> q;
    q.push(src);

    // 3. mark vis of src node and update parent traverse the graph wrt queue
    vis[src] = true;
    parent[src] = -1;

    while (!q.empty())
    {
        int curr_node = q.front();
        q.pop();

        for (auto neighbour : adj[curr_node])
        {
            if (vis[neighbour] == true && parent[curr_node] != neighbour)
            {
                return true;
            }
            else
            {
                // cycle detected
                if (!vis[neighbour])
                {
                    parent[neighbour] = curr_node;
                    q.push(neighbour);
                    vis[neighbour] = true;
                }
            }
        }
    }
    return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    // Write your code here.
    // create DS needed
    // 1. create adj list
    unordered_map<int, list<int>> adj;
    prepareAdjList(adj, edges, m);

    // 2. create vis ds
    unordered_map<int, bool> vis;
    for (int i = 0; i <= n; i++)
    {
        vis[i] = false;
    }

    // 3. loop for disconn components
    unordered_map<int, int> parent;
    bool ans = false;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            ans = bfsDetectCycle(adj, vis, i, parent);
            // check ans for every component in graph
            if (ans)
                return "Yes";
        }
    }
    return "No";
}
