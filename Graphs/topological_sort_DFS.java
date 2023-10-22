import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Stack;

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



class Solution {
    public boolean dfsTopo(List<List<Integer>> adj, int node, int[] vis) {
        if(vis[node] == 1) // encountered a curr exploring node -> so there is a deadlock -> this node is not completed and also the parent node is also not completed because it has a dep. on this node.
        
            return false;
        
        if(vis[node] == 2) // encountered already vis node fully -> already the prereq are been completed : so move ahead
            return true;

        vis[node] = 1; // the node is currently under exploring state and not yet fully completed.

        for(Integer neigh : adj.get(node)) {
            if(dfsTopo(adj, neigh, vis) == false)
                return false;
         
        }
        vis[node] = 2;
        return true;        
    }

    public void prepareAdjList(List<List<Integer>> adj, int[][] prerequisites, int n) {
        for(int i=0; i<n; i++) {
            adj.add(new ArrayList<>());
        }
        
        for (int[] prerequisite : prerequisites) {
            int from = prerequisite[1];
            int to = prerequisite[0];
            adj.get(from).add(to);
        }
    }

    public boolean canFinish(int numCourses, int[][] prerequisites) {
        int m = prerequisites.length;
        List<List<Integer>> adj = new ArrayList<>();
        prepareAdjList(adj, prerequisites, numCourses);
        int[] vis = new int[numCourses];
       
        for(int i=0; i<numCourses; i++) {
            if(vis[i] == 0) {
                if(dfsTopo(adj, i, vis) == false)
                    return false;
            }
        }
        return true;
    }
}
