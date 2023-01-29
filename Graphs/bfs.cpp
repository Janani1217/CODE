/*

Breadth first search : PRINT ALL ADJ NODES AND THEN MOVE AHEAD

1.  its a traversal technique

2.  print the ele starting from root , and PRINT ALL OF ITS ADJACENT NODES , if it was
    not printed or not yet visited.

3.  so we need a ds , which keeps the track of a particular node is already
    visited or not.

    unordered_map<node, bool> vis;

4.  we need another ds = queue , to keep a FIFO ordering of nodes to process it
    and also its neighbours. : its used for storing all nodes inorder to process
    them and traverse the graph

5.  so init we take the vis map , false for every node

6.  we create a adj list for the graph
    we also create a queue , which has the src node.

        q. push_back(src_node);

7.  DS created init : adj list of graph , queue with src node , vis map with false val

    7.1 check if( ! node->visited )
            bfs () ;

    7.2 we also have a var : front_node ,

            q . popback()
            front_node = src_node ;

            print (front_node) ;
            vis [front_node] = true ;

            if(adj nodes -> front_node = !vis )
            {
            q. push_back(all adj nodes of front_node)
            }

            repeat this untill all nodes in adj list gets completed ...

    7.3 so all the nodes in the BFS traversal gets printed.
        Also the queue gets empty


*******

8.  There is a case , where a graph is given with multiple components.
    Multiple components are not conn with one another -> DISCONNECTED GRAPHS

    So to handle this disconn graph BFS Traversal case :

    JUST ADD A LOOP TO ENSURE ALL THE NODES IN A GRAPH IS TRAVERSED.

    n -> no. of all nodes present in the graph

    for( int i=0; i<n; i++)
    {
        if( adj_nodes -> front_node != vis )
        {
            contd.. as above
        }
    }

*******
.................................................................................................


https://www.codingninjas.com/codestudio/problems/bfs-in-graph_973002

UNDIRECTED GRAPH : A graph where atleast 2 vertices are NOT CONNECTED by a path.

.................................................................................................

PS :

1.  given undirected graph
2.  disconnected graph
3.  op should be in traversed sorted order

TC : O(n + e)
SC : O(n + e)

.................................................................................................

*/

#include <bits/stdc++.h>
using namespace std;

void prepareAdjList(vector<pair<int, int>> edges, unordered_map<int, set<int>> &adj)
{
    int m = edges.size();
    for (int i = 0; i < m; i++)
    {
        pair<int, int> edge = edges[i];
        int u = edge.first;
        int v = edge.second;

        adj[u].insert(v);
        adj[v].insert(u);
    }
    return;
}

void bfs(unordered_map<int, set<int>> &adj, unordered_map<int, bool> &vis, vector<int> &ans, int src)
{
    // create a q ds
    queue<int> q;
    q.push(src);
    vis[src] = true;

    // loop till the conn graph from src
    while (!q.empty())
    {
        int front_node = q.front();
        q.pop();
        ans.push_back(front_node);

        // traverse thr adj list
        for (auto i : adj[front_node])
        {
            if (!vis[i])
            {
                q.push(i);
                vis[i] = true;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    int n = vertex;
    int m = edges.size();

    vector<int> ans;

    // ds needed
    // 1. adj list
    // we need in sorted order of traversal , so use set instead of list
    unordered_map<int, set<int>> adj;
    prepareAdjList(edges, adj);

    // 2. vis -> all false
    unordered_map<int, bool> vis;
    for (int i = 0; i < n; i++)
    {
        vis[i] = false;
    }

    // start looping through all nodes in graph
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            int src = i;
            bfs(adj, vis, ans, src);
        }
    }
    return ans;
}