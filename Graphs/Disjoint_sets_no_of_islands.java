public class Disjoint {
    List<Integer> rank = new ArrayList<>();
    List<integer> parent = new ArrayList<>();
    List<Integer> size = new ArrayList<>();
    
    public Disjoint(int n) {
        for(int i=0; i<=n; i++) {
            rank.add(0);
            parent.add(i);
            size.add(1);
        }
    }

    public int findUltimateParent(int node) {
        if(node == parent.get(node))
            return node;
        int ultimate_parent = findUltimateParent(parent.get(node));
        parent.set(node, ultimate_parent);
        return parent.get(node);
    }

    public int findUnionByRank(int u, int v) {
        // 1. find ultimate par
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);

        // 2. if both the ranks are equal : nothing to do : both belongs to same compo
        if(ulp_u == ulp_v)
            return;

        // 3. if not same compo : compare the ranks of the par
        if(rank.get(ulp_u) < rank.get(ulp_v)) {
            parent.set(ulp_u, ulp_v);
        } else if(rank.get(ulp_u) > rank.get(ulp_v)) {
            parent.set(ulp_v, ulp_u);
        } else {
            // if equal : make any one as par of another
            parent.set(ulp_v, ulp_u);
            // incr the rank of par
            rank.set(ulp_u, rank.get(ulp_u)+1);
        }
    }

    public int findUnionBySize(int u, int v) {
        
        // find the ult parent
        int ulp_u = findUltimateParent(u);
        int ult_v = findUltimateParent(v);

        // compare its size :
        if(size(ulp_u) < size(ulp_v)) {
            parent.set(ulp_u, ulp_v);
        } else if (size(ulp_u) > size(ulp_v)) {
            parent.set(ulp_v , ulp_u);
        } else {
            // if size is equal : attach any one and incr teh size
            parent.set(ulp_v, ulp_u);
            size.set(ulp_u, size.get(ulp_u)+size.get(ulp_v));
        }
    }
}



public class Solution {
    public static boolean isValid(int r, int c, int n, int m) {
        if(r >= 0 && c >= 0 && r < n && c < m) 
            return true;
        return false;
    }
    public static int[] numOfIslandsII(int n, int m, int[][] q) {
        
        // using disjoint set to find the no. of componenets in const time
        // max no. of ele in the DS set = n * m
        Disjoint ds = new Disjoint(n*m);
        int[][] vis = new int[n][m];
        int cnt = 0; // total no. of islands found for each query returning
        
        List<Integer> ans = new ArrayList<>();

        int sz = q.length;
        
        for(int i=0; i<sz; i++) {
            int row = q[i][0];
            int col = q[i][1];

            if(vis[row][col] == 1) {
                ans.add(cnt); // got the connected island here
                continue; // move to next query
            } 

            // assuming this is a new island :
            vis[row][col] = 1;
            cnt++;

            // 4 direct
            int dr[] = {+1, 0, -1, 0};
            int dc[] = {0, +1, 0, -1};

            // traverse in 4 directions
            for(int ind=0; ind<4; ind++) {
                int adjr = row + dr[ind];
                int adjc = col + dc[ind];

                // validate new r and c
                if(isValid(adjr, adjc, n, m)) {
                    // check whether the new cell is a island or not : otherwise ther is no point in moving ahead.
                    // it has to be an island
                    if(vis[adjr][adjc] == 1) {
                        // okay now we need to connect these 2 islands
                        // for that : we need to find the cell numbers from the below formula 
                        // with this we can call disjointset methods 
                        int nodeNum = row * m + col;
                        int adjNodeNum = adjr * m + col;
                        
                        if(ds.findUltimateParent(nodeNum) != ds.findUltimateParent(adjNodeNum)) {
                            // it means : u got an adj island but they are not having same parent : we need 
                            // to connect these islands now : 
                            cnt--; // reduce the cnt because we are connecting 
                            ds.findUnionBySize(nodeNum, adjNodeNum);  // after connecting : change the size of the component
                        } 
                    }
                }
            }
            ans.add(cnt);
        }
        return ans;
    }
}
