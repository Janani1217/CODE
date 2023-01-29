/*
Graphs
............................................................................................................................................

Introduction :

Graphs : its a ds with nodes connected via edges
Directed graphs
Undirected graphs

Degree(node v) : from node v , how many edges are connected.
Directed graph :
Indegree - no. of edges coming inside
Outdegree - no. of edges going out

Weighted graph : edges have some value called weights
Directed graph - weighted directed graphs
Undirected graph - wg undirected graph

Path : traversing from one node to another without any node repeating

............................................................................................................................................

1.  Cyclic graphs : start node = end node after complete traversal , and
    it can be called as cyclic directed graphs . And if weight present ,
    then cyclic weighted graphs

2.  Non - cyclic graph : start node != end node , in case of directed
    graph only , where we cannot form a cycle after the traversal

............................................................................................................................................

Ways to Implement a graph:

1. Adjacency matrix:
Input of graph = no. edges(m) , nodes(n) , list of edges(0-1 , 1-3 , 2-3)

So to repr it , we create a 2D matrix with m * n
1 -> if 2 nodes connected or else 0 inside 2D matrix
SC : O(N*M)

2. Adjacency list :
Input of graph = no. edges(m) , nodes(n) , list of edges(0-1 , 1-3 , 2-3)

So in the list for each node , all its connected or adj conn nodes will be
present in the list

So in left , we will have the single entity and in its right , we will have
a list of numbers / nodes

So DS used : map <key , values>

Here key -> integer
Here Value -> list (Integer)

Map <int, list<int>>;

Here vector also can be used instead of list , but list comes with very
less limitations. So by using map, we create graph.

............................................................................................................................................




*/

#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class graph
{
public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, int direction)
    {
        /*
        directed = 0
        undirec graph = 1
        */

        // create an edge from u->v
        adj[u].push_back(v);

        if (direction == 0)
        {
            // its an undir graph , so from v->u will be present
            adj[v].push_back(u);
        }
    }

    void printAdjList()
    {
        for (auto i : adj)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << j << ", ";
            }
        }
    }
};

int main()
{
    int n;
    cout << "Enter no. of nodes";
    cin >> n;
    int m;
    cout << "Enter no. of edges";
    cin >> m;

    // create a new undirected graph
    graph g;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0);
    }

    // print graph
    g.printAdjList();
    return 0;
}