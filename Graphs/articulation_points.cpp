/*
PS : Articulation points in Graphs:

Check notes for complete explaination
.................................................................................................

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfsAP(int &node, int &timer, int &par, unordered_map<int, bool> &vis, vector<int> &disc, vector<int> &low, vector<int> adj[], vector<bool> &res)
    {
        vis[node] = true;
        disc[node] = low[node] = timer++;
        int child = 0;

        for (auto neigh : adj[node])
        {
            // check for parent
            if (par == neigh)
            {
                continue;
            }

            // rem part
            if (!vis[neigh])
            {

                dfsAP(neigh, timer, node, vis, disc, low, adj, res);

                // 1. check if BE:
                low[node] = min(low[node], low[neigh]);

                // 2. check for AP :
                if (low[neigh] >= disc[node] && par != -1)
                    res[node] = true;

                child++;
            }
            else
            {
                // back edge is present : update low
                low[node] = min(low[node], low[neigh]);
            }

            if (par == -1 && child > 1)
                res[node] = true;
        }
    }

    vector<int> articulationPoints(int V, vector<int> adj[])
    {
        // Code here
        // make all the Ds : adj list already made
        // other Ds :
        vector<int> disc(V);
        vector<int> low(V);

        for (int i = 0; i < V; i++)
        {
            disc[i] = low[i] = -1;
        }

        int parent = -1;
        unordered_map<int, bool> vis(V);
        int timer = 0;

        // to store AP
        vector<bool> res(V);
        for (int i = 0; i < V; i++)
            res[i] = false;

        // need to run bfs for disc G
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfsAP(i, timer, parent, vis, disc, low, adj, res);
            }
        }

        vector<int> ans;
        // needed ans in order of traversal
        for (int i = 0; i < V; i++)
        {
            if (res[i] == true)
                ans.push_back(i);
        }

        if (ans.size() == 0)
            ans.push_back(-1);

        return ans;
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
        vector<int> ans = obj.articulationPoints(V, adj);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends