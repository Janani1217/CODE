
import java.io.*;

import java.util.*;

 

//User function Template for Java

class DisjointSet {

    List<Integer> rank = new ArrayList<>();

    List<Integer> parent = new ArrayList<>();

    List<Integer> size = new ArrayList<>();

    public DisjointSet(int n) {

        for (int i = 0; i <= n; i++) {

            rank.add(0);

            parent.add(i);

            size.add(1);

        }

    }

 

    public int findUPar(int node) {

        if (node == parent.get(node)) {

            return node;

        }

        int ulp = findUPar(parent.get(node));

        parent.set(node, ulp);

        return parent.get(node);

    }

 

    public void unionByRank(int u, int v) {

        int ulp_u = findUPar(u);

        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) return;

        if (rank.get(ulp_u) < rank.get(ulp_v)) {

            parent.set(ulp_u, ulp_v);

        } else if (rank.get(ulp_v) < rank.get(ulp_u)) {

            parent.set(ulp_v, ulp_u);

        } else {

            parent.set(ulp_v, ulp_u);

            int rankU = rank.get(ulp_u);

            rank.set(ulp_u, rankU + 1);

        }

    }

      public void unionBySize(int u, int v) {

        int ulp_u = findUPar(u);

        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) return;

        if (size.get(ulp_u) < size.get(ulp_v)) {

            parent.set(ulp_u, ulp_v);

            size.set(ulp_v, size.get(ulp_v) + size.get(ulp_u));

        } else {

            parent.set(ulp_v, ulp_u);

            size.set(ulp_u, size.get(ulp_u) + size.get(ulp_v));

        }

    }

}

public class Solution {

    public static boolean isValid(int adjr,int adjc,int n,int m){

        return adjr>=0 && adjr<n && adjc>=0 && adjc<m;

    }

    public static int[] numOfIslandsII(int n, int m, int[][] q) {

        // Write your code here.

        DisjointSet ds=new DisjointSet(n*m);

        int[][] vis=new int[n][m];

        int cnt=0;

        ArrayList<Integer> ans = new ArrayList<>();

        int len=q.length;

        for(int i=0;i<len;i++){

            int ro=q[i][0];

            int col=q[i][1];

            if(vis[ro][col]==1){

                ans.add(cnt);

                continue;

            }

            vis[ro][col]=1;

            cnt++;

            int dr[]={-1,0,1,0};

            int dc[]={0,1,0,-1};

            for(int ind=0;ind<4;ind++){

                int adjr=ro+dr[ind];

                int adjc=col+dc[ind];

                if(isValid(adjr, adjc, n, m)){

                    if(vis[adjr][adjc]==1){

                        int nodeNo=ro*m+col;

                        int adjNodeNo=adjr*m+adjc;

                        if(ds.findUPar(nodeNo)!=ds.findUPar(adjNodeNo)){

                            cnt--;

                            ds.unionBySize(nodeNo, adjNodeNo);

                        }

                    }

                }

            }

            ans.add(cnt);

        }

        int[] re=new int[ans.size()];

        for(int i=0;i<ans.size();i++){

            re[i]=ans.get(i);

        }

        return re;

    }

}
