/*

Shortest path algorithm :
Bellman Ford Algo :

Given :

Directed graph : 1 -> N
Weighted graph
G may contain negative weights.

Find the shortest path between src and dest node given.

.................................................................................................

REFER TO NOTEBOOK FOR DETAILS !!

TC: (N-1) * M
SC: O(N)
*/

#include <bits/stdc++.h>
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges)
{
    // Write your code here.
    // make all the Ds:
    // no traversal needed , so no adj list

    // fill it with a big no. = 1e9
    vector<int> dist(n + 1, 1e9);
    dist[src] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            int u = edges[j][0];
            int v = edges[j][1];

            // imp to check if the distance is not infinity and then add , otherwise seg err
            if (dist[u] != 1e9 && dist[u] + edges[j][2] < dist[v])
            {
                // new dist got
                dist[v] = dist[u] + edges[j][2];
            }
        }
    }

    // check negative cycles
    for (int j = 0; j < m; j++)
    {
        vector<int> edge = edges[j];
        int u = edge[0];
        int v = edge[1];

        if (dist[u] != 1e9 && dist[u] + edge[2] < dist[v])
        {
            // negative cycle present
            return -1;
        }
    }
    return dist[dest];
}
