//You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

//Return the size of the largest island in grid after applying this operation.

//An island is a 4-directionally connected group of 1s.

// https://leetcode.com/problems/making-a-large-island/

class DisjointSet {
    List<Integer> par = new ArrayList<>();
    List<Integer> size = new ArrayList<>();

    DisjointSet(int n) {
        for(int i=0; i<=n; i++) {
            par.add(i);
            size.add(1);
        }
    }

    public int find(int node) {
        if(node == par.get(node))
            return node;
        int p = find(par.get(node));
        par.set(node, p);
        return par.get(node);
    }

    public void unionBySize(int u, int v) {
        int ulp_u = find(u);
        int ulp_v = find(v);
        if (ulp_u == ulp_v) return;
        if (size.get(ulp_u) < size.get(ulp_v)) {
            par.set(ulp_u, ulp_v);
            size.set(ulp_v, size.get(ulp_v) + size.get(ulp_u));
        } else {
            par.set(ulp_v, ulp_u);
            size.set(ulp_u, size.get(ulp_u) + size.get(ulp_v));
        }
    }
}


class Solution {
    public boolean isValid(int x, int y, int n) {
        if(x>=0 && y>=0 && x<n && y<n)
            return true;
        return false;
    }
    public int largestIsland(int[][] grid) {
        int n = grid.length;
        DisjointSet ds = new DisjointSet(n * n); // create. a 2D matrix

        int[] dr = {-1, 0, 1, 0};
        int[] dc = {0, -1, 0, 1};

        // step 1 :find the conn components
        for(int r=0; r<n; r++) {
            for(int c=0; c<n; c++) {
                if(grid[r][c] == 1) {
                    // traverse in 4 directions
                    for(int i=0; i<4; i++){
                        int newr = r+dr[i];
                        int newc = c+dc[i];

                        if(isValid(newr, newc, n) && grid[newr][newc]==1) {
                            // find the cell numbers for both to combine
                            int cell_num = r*n+c;
                            int new_cell_num = newr*n+newc;

                            // merge these 2 cells
                            ds.unionBySize(cell_num, new_cell_num);
                        }
                    }
                }
            }
        }

        // step 2 : identify 0 and try to merge if poss
        int maxArea = 0;

        for(int r=0; r<n; r++) {
            for(int c=0; c<n; c++) { 
                
                if(grid[r][c] == 0) {
                    HashSet<Integer> hs = new HashSet<>(); // store the cells in same island

                    // convertt to 1 first and traverse in all 4 direc to see compo
                    for(int i=0; i<4; i++) {
                        int newr = r+dr[i];
                        int newc = c+dc[i];

                        if(isValid(newr, newc, n) && grid[newr][newc]==1) {

                            // add the ultimate par of the whole compo in the hs
                            hs.add(ds.find(newr * n + newc)); 
                        }
                    }

                    // after traversing in all 4 direc and combining if poss , then find the size of the new compo : if its more thn the max size

                    int sizeTotal = 0;
                    for(Integer par : hs) {
                        sizeTotal += ds.size.get(par);
                    }

                    maxArea = Math.max(maxArea, sizeTotal+1);
                }
            }
        }

      /*** VVI : To count the sz of compo which is not a part of cell for which we processed in step 2  ****/
        for(int c=0; c<n*n; c++) {
            maxArea = Math.max(maxArea, ds.size.get(ds.find(c)));
        }
        return maxArea;
    }
}
