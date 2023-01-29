/*
Shortest Distance in Acyclic Directed graphs:

1.  Directed = weighted edges : DAG
2.  Acyclic graph

.................................................................................................

Approach : USING DFS

1.  Use TOPO SORT : we get to know which node comes before a given node

2.  So if the topo sort : a->b->c->d ;

3.  Now we need to find the shortest path :
    a -> b : find shortest path among these 2
    b -> c : //
    c -> d : //

4.  So we get a LINEAR ORDERING and utilize it to find the SHORTEST PATH

5.  Now we have a topo sort order in the stack ds which was used to store
    nodes once its recr got completed

6.  dist vector initially filled with infinity

7.  dist[src] = 0;

8.  now start poping from stack :

    node = stack.top();
    stack.pop();

    if(dist[node] == infinite)
        skip & continue ..

    if(dist[node] == some num)
    {
        // check its adj node with distance -> update in dist vector

        dist[adj_node] = distance_adj + distance_node;

        continue next pop;
    }

9.  so if the dist is not infinite then process the node wrt adj nodes and update
    the distance vector.

10. now during the updation of vector , if already a dist is present != infinity.
    compare the distance , if lesser then only update , otherwise neglect and
    continue.

11. so the final distance vector comes out to be the ans.

.................................................................................................

DS to be used :

1.  adj list : will be updated
2.  STACK : DFS : node's recr call ends, push into stack
3.  vis array
4.  distance array : to store shortest path

.................................................................................................

Modification in adj list :

1.  since its a directed graph with weights , so we have to store the weight of
    each edge also along with the adj nodes

2.  1 -> ( {4, 2} , {3, 5} )

    node 1 is conn to node 4 with the edge weight = 2;
    node 1 is conn to node 3 with the edge weight = 5;

3.  unordered_map <int , list<pair<int, int>> >;

.................................................................................................

https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1

*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    void prepareAdjList(unordered_map<int, list<pair<int, int>>> &adj, vector<vector<int>> &edges, int m)
    {
        for (int i = 0; i < m; i++)
        {
            vector<int> curr = edges[i];
            int u = curr[0];
            int v = curr[1];
            int d = curr[2];

            pair<int, int> p;
            p.first = v;
            p.second = d;
            adj[u].push_back(p);
        }
    }

    void dfsTopoSort(unordered_map<int, list<pair<int, int>>> adj, stack<int> &s, unordered_map<int, bool> &vis, int src)
    {
        // find the topo sort using dfs , recrs , stack insertion
        vis[src] = true;

        for (auto neigh : adj[src])
        {
            if (!vis[neigh.first])
            {
                dfsTopoSort(adj, s, vis, neigh.first);
            }
        }
        s.push(src);
    }

    void getShortestPath(unordered_map<int, list<pair<int, int>>> adj, stack<int> &s, vector<int> &dist, int src)
    {
        dist[src] = 0;

        while (!s.empty())
        {
            int top = s.top();
            s.pop();

            // check its dist
            if (dist[top] != INT_MAX)
            {
                int actualDist = dist[top];
                for (auto i : adj[top])
                {
                    if (actualDist + i.second < dist[i.first])
                    {
                        // update the dist
                        dist[i.first] = actualDist + i.second;
                    }
                }
            }
            else
            {
                dist[top] = -1;
            }
        }
    }

    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        // code here
        // make the ds :
        // 1. adj list
        unordered_map<int, list<pair<int, int>>> adj;
        prepareAdjList(adj, edges, M);

        // 2. need to find topo sort , using dfs , so push into stack after recr completes
        stack<int> s;

        // 3. visited Ds
        unordered_map<int, bool> vis;

        // 4. start dfs for topo sort
        for (int i = 0; i < N; i++)
        {
            if (!vis[i])
            {
                dfsTopoSort(adj, s, vis, i);
            }
        }

        // declare the size of vector if you are init : *******
        vector<int> dist(N);

        // fill teh dist vector with infinity
        for (int i = 0; i < N; i++)
        {
            dist[i] = INT_MAX;
        }

        // update for the rem nodes
        int src = 0;
        getShortestPath(adj, s, dist, src);

        return dist;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 3; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends