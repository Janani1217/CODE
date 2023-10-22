class Solution {
    public boolean dfs(List<List<Integer>> adj, int color[], int col, int node) {
        color[node] = col;
        // traverse its neighbours
        for(Integer neigh : adj.get(node)) {
            if(color[neigh] == -1) {
                if(dfs(adj, color, 1 - col, neigh) == false)
                    return false;
            }
            else if(color[neigh] == col) 
                    return false; // same col as the curr node
        }
        return true;
    }
    public void prepareAdjList(List<List<Integer>> adj, int[][] graph, int n) {
        for(int i=0; i<n; i++) {
            List<Integer> list = new ArrayList<>();
            for(int j=0; j<graph[i].length; j++) {
                list.add(graph[i][j]);
            }
            adj.add(list);
        }
    }
    public boolean isBipartite(int[][] graph) {
        int n = graph.length;

        // 1. make adj list
        List<List<Integer>> adj = new ArrayList<>();
        prepareAdjList(adj, graph, n);

        // 2. DS for color : 
        int color[] = new int[n];
        for(int i=0; i<n; i++) {
            color[i] = -1; // init colored with -1
        }

        // 3. run dfs with start color = 0
        for(int i=0; i<n; i++) {
            if(color[i] == -1) {
                if(dfs(adj, color, 0, i) == false)
                    return false;
            }
        }

        return true;
    }
}
