/*
We have a 2D room with infinite points and we are given a list of points
of motion sensors (x, y, r) where x and y represent the location and r
represent the radius in which the motion sensor is capable of detection.
We have to find whether it is possible to start from one end of the room
and reach the other end without being detected by the motion sensor.



Approach :
1. create the graph , using coordinates as the node of the graph
2. create edges btw nodes : by using radius if they overlap , then theres a edge
3. traverse from the starte point till the end point and everytime taking care not
    to be detected my motion graph
4. if there is a path then return true.

*/

#include <bits/stdc++.h>
using namespace std;

int squaredDistace(int x1, int x2, int y1, int y2)
{
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

bool dfs(int s, int e, vis, graph)
{
    vis.insert(s);

    // path reached / found
    if (s == e)
        return true;

    for (auto &neigh : graph.at(s))
    {
        if (vis.find(neigh) == vis.end())
        {
            if (dfs(neigh, e, vis, graph))
            {
                return true;
            }
        }
    }
    return false;
}

bool canTraverseUndetected(const vector<pair<int, int, int>> &motionSensors,
                           const pair<int, int> &start, const pair<int, int> &end)
{

    // create a graph : key = (x,y) coord , value = neigh of this coord node
    unordered_map<pair<int, int>, unordered_set<pair<int, int>>> graph;

    for (auto sensor : motionSensors)
    {
        // initially add empty neigh to each node in graph
        graph[make_pair(sensor.first, sensor.second)] = {};
    }

    // add edges based on detection ranges
    // iterate over all pairs of motion sensors
    for (auto sensor1 : graph)
    {
        for (auto sensor2 : graph)
        {
            if (sensor1 == sensor2)
                continue;

            int x1 = sensor1.first.first;
            int y1 = sensor1.first.second;
            int r1 = sensor1.second;

            int x2 = sensor2.first.first;
            int y2 = sensor2.first.second;
            int r2 = sensor2.second;
            

            // using squared dist to avoid floating point arithmetic
            int dist = squaredDist(x1, y1, x2, y2);

            if (dist <= (r1 + r2) * (r1 + r2))
            {
                graph[sensor1.first].insert(sensor2.first);
                graph[sensor2.first].insert(sensor1.first);
            }
        }
    }

    // add start and end nodes in the graph
    graph[start] = {};
    graph[end] = {};

    // dfs traversal
    unordered_set<pair<int, int>> vis;
    return dfs(start, end, vis, graph);
}

int main()
{
    vector<pair<int, int, int>> motionSensors = {{1, 1, 2}, {5, 5, 3}, {10, 10, 4}};
    pair<int, int> start = {0, 0};
    pair<int, int> end = {15, 15};

    bool result = canTraverseUndetected(motionSensors, start, end);
    return result;
}