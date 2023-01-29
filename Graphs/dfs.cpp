/*

Depth first search : PRINT TILL DEPTH AND THEN COME BACK AND PRINT REMAINING

1.  given a  graph , print the root , go to its conn node , and then go to its conn node
    , continue untill it goes till the end of the graph level.

2.  Then come back and print the nodes present in its level and traverse reversal till all
    nodes in the graph got printed.

3.  So we are traversing back in the graph to print the rem adj nodes , so RECURSIVE CALLS
    are needed -> RECURSION

4.  So there can be case for the DISCONNECTED GRAPH , so same we need to keep a loop to
    ensure that all the nodes are traversed or not.

5.  DS :

    1.  map - vis : to keep track of already vis nodes
    2.  queue - to traverse
    3.  map <int , list> - adj list

..................................................................................................

Algo :

1.  start from src node , mark it vis as true

2.  check its adj node in the next level , if not visited , push in the queue and ans also,
    mark that node also as vis

3.  then move to the next level(with the help of adj list only) of its conn node, if not vis.
    Continue till the last level (last node in the adj list).

    If already vis node encountered , then move to the next node present in the list of
    conn nodes in the adj list of that particular src node.

4.  So , after we reach the end of the adj list , traverse back (recursion takes care of)
    and visit the nodes of the current src node , which is not already vis.

..................................................................................................

https://www.codingninjas.com/codestudio/problems/dfs-traversal_630462

TC : O(n+e)
SC : O(n+e)

.................................................................................................

PS :

1.  undirected
2.  disconnected
3.  sorted in traversal adj list

.................................................................................................

*/

#include <iostream>
using namespace std;

void prepareAdjList(unordered_map<int, set<int>> &adj, vector<vector<int>> &edges, int m)
{
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].insert(v);
        adj[v].insert(u);
    }
}

void dfs(unordered_map<int, set<int>> &adj, unordered_map<int, bool> &vis, int src, vector<int> &comp)
{
    comp.push_back(src);
    vis[src] = true;

    // for every conn node , make recr call
    for (auto i : adj[src])
    {
        if (!vis[i])
        {
            dfs(adj, vis, i, comp);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    int n = V;
    int m = E;

    vector<vector<int>> ans;

    // create all ds
    // 1. adj list
    unordered_map<int, set<int>> adj;
    prepareAdjList(adj, edges, m);

    // 2. prep vis ds
    unordered_map<int, bool> vis;
    for (int i = 0; i < n; i++)
    {
        vis[i] = false;
    }

    // 3. make dfs call , for disconn graph

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            // store each disconn compo of graph and then store it back into ans
            vector<int> component;
            dfs(adj, vis, i, component);
            ans.push_back(component);
        }
    }
    return ans;
}