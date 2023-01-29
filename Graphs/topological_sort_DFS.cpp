/*

TOPOLOGICAL SORT :

PS : find TS for a DAG

DAG (DIRECTED ACYCLIC GRAPH)

TS : Linear ordering of vertices such that for every edge , u-> , u always appears
     before v everytime of that ordering.

.................................................................................................

Logic : WHY TOPO SORT NOT APPLICABLE ON DIRECTED CYCLIC GRAPH ??

Suppose a graph :
1->2
2->3
3->1

we write a linear ordering : 1 2 3

check topo :

in adj list : 1 comes before 2
in ordering : 1 comes before 2

in adj list : 2 comes before 3
order : 2 comes before 3

adj list : 3 comes before 1
order :  3 comes after 1    ---->> NOT A TOPOLOGICAL SORT !!

SO THERE IS A CYCLE
HENCE A LINEAR ORDERING CANNOT BE OBTAINED

CANT APPLY TOPO SORT IN : CYCLIC DIRECTED GRAPH

SO IF WE ARENT ABLE TO GET A TOPO SORT , THEN THE GRAPH MIGHT BE CYCLIC
.................................................................................................

USING DFS :

DS Needed :

1.   adj list
2.   visited map
3.   New DS stack : To get LIFO : When we COME BACK in a RECURSION call ->
     its adj node callings gets completed in the adj list , and it returns back to
     its parent node in the recr tree, -> INSERT IN STACK

Logic :

1.   we keep on storing the nodes , whose recr call gets completed in the recr
     call and its not possible to propagate further .

2.   And finally we print the ele from top to bottom in the stack , this will
     give the order of ele , in the same way , it was called from the adj list.

3.   so the ordering should match the ordering in adj list calling.
.................................................................................................

https://www.codingninjas.com/codestudio/problems/topological-sort_985252

TC : O(N+E)
SC : O(N)

.................................................................................................

*/

#include <bits/stdc++.h>
void prepareAdjList(unordered_map<int, list<int>> &adj, vector<pair<int, int>> &edges, int m)
{
     for (int i = 0; i < m; i++)
     {
          pair<int, int> p = edges[i];
          int u = p.first;
          int v = p.second;
          adj[u].push_back(v);
     }
}

void printList(unordered_map<int, list<int>> &adj, int n, int m)
{
     for (auto i : adj)
     {
          cout << adj.begin()->first << "->";
          for (auto j : adj.begin()->second)
          {
               cout << j << " , ";
          }
          cout << endl;
     }
}

void dfsTopo(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &vis, stack<int> &dfsComplete, int src)
{
     // recr call : no queue needed
     vis[src] = true;
     for (auto node : adj[src])
     {
          if (!vis[node])
          {
               dfsTopo(adj, vis, dfsComplete, node);
          }
     }
     dfsComplete.push(src);
}

vector<int> topologicalSort(vector<pair<int, int>> &edges, int N, int M)
{
     // topo sort only in : DIRECTED AND ACYCLIC GRAPH
     // form all ds
     // 1. adj list
     unordered_map<int, list<int>> adj;
     prepareAdjList(adj, edges, M);
     printList(adj, N, M);

     // 2. vis map
     unordered_map<int, bool> vis;
     for (int i = 0; i < N; i++)
     {
          vis[i] = false;
     }

     // 3. since dfs : create another ds : stack
     stack<int> dfsComplete;
     // ans -> traverse stack after dfs call
     // for loop for disconn graph
     vector<int> ans;
     for (int i = 0; i < N; i++)
     {
          dfsTopo(adj, vis, dfsComplete, i);
     }

     // get the ordering
     while (!dfsComplete.empty())
     {
          // cout << dfsComplete.top() << " , ";
          ans.push_back(dfsComplete.top());
          dfsComplete.pop();
     }
     return ans;
}
