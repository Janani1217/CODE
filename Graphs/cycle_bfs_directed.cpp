/*
Cycle detection in directed graphs using BFS :

.................................................................................................

Using Kahn's algo :

1.  we use this algo to find the topo sort in ACYCLIC DIRECTED GRAPHS only by using
    indegree of each node.

2.  if we see , if the graph is cyclic, we DON'T get a VALID TOPO SORT.

3.  So if we dont get a valid topo sort in a directed graph , then it means
    that we are having a cyclic graph.

4.  FINAL CHECK IF VALID TOPO ORDER ->
    COUNT OF NODES IN TOPO ORDER == TOTAL NODES IN ACTUAL GRAPH

.................................................................................................
https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1


*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void bfs(vector<int> adj[], vector<int> &indegree, int &cnt, int src, queue<int> &q)
    {

        while (!q.empty())
        {
            int first_node = q.front();
            q.pop();

            cnt++;

            for (auto neigh : adj[first_node])
            {
                indegree[neigh]--;
                if (indegree[neigh] == 0)
                {
                    q.push(neigh);
                }
            }
        }
    }

    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        /*
        here we are using kahn algo for topo sort to get a invalid order to get a cyclic graph identification
        1,  DS new = indegree vector
        2.  queue
        3.  function to get valid topo sort check

        DS : for adj list already made;
        */

        vector<int> indegree(V, 0);
        // fill the indegrees for each node
        for (int i = 0; i < V; i++)
        {
            for (auto j : adj[i])
            {
                indegree[j]++;
            }
        }

        // *******
        // push into queue whose indegree is 0 :
        queue<int> q;

        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        // start bfs
        int count = 0;
        bfs(adj, indegree, count, 0, q);

        // check if valid topo or not:
        if (count == V)
        {
            // no cycle exists : we got valid topo sort
            return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
