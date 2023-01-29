/*
Find cycle in a undirected , disconn graph
.................................................................................................

Approach :
1.  traverse the same dfs also using recursion
2.  if cycle detection condition occurs , change the ans stored
3.  CYCLE WILL ONLY BE DETECTED , IF A NODE IS VISITED FROM MORE THAN ONE PARENT NODE
    I.E A NODE IS HAVING MORE THAN 1 PARENT.

4.  So, cycle detection algo also works the same , if a node parent != node from which
    its called.

.................................................................................................

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfsCycleDetect(vector<int> adj[], unordered_map<int, bool> &vis, int src, bool &ans, int parent)
    {
        vis[src] = true;

        if (ans == true)
            return;

        // dont need queue ds to traverse, since using recursion
        for (auto neighbour : adj[src])
        {
            if (!vis[neighbour])
            {
                dfsCycleDetect(adj, vis, neighbour, ans, src);
            }
            else if (vis[neighbour] == true && parent != neighbour)
            {
                ans = true;
            }
        }
        return;
    }

    bool isCycle(int V, vector<int> adj[])
    {
        // Code here

        // using dfs
        int n = V;

        // 1. adj list already created
        // 2 . create vis
        unordered_map<int, bool> vis;

        for (int i = 0; i < n; i++)
        {
            vis[i] = false;
        }

        // 3. start dfs for diconn graph
        // store the ans fior every components
        bool ans = false;

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                int parent = -1;
                dfsCycleDetect(adj, vis, i, ans, parent);

                if (ans == true)
                    return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends