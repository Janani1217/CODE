/*
 * Given an unsorted array of integers, 
 * find the number of continuous subarrays having 
 * sum exactly equal to a given number k.
 * 
 *  N = 5
    Arr = {10 , 2, -2, -20, 10}
    k = -10
    Output: 3

 */

public class subarr_with_sum_k {
    //{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

import Maths.Solution;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            int N = Integer.parseInt(read.readLine());
            String input_line[] = read.readLine().trim().split("\\s+");
            int Arr[] = new int[N];
            for (int i = 0; i < N; i++)
                Arr[i] = Integer.parseInt(input_line[i]);
            int k = Integer.parseInt(read.readLine());

            Solution ob = new Solution();
            System.out.println(ob.findSubArraySum(Arr, N, k));
        }
    }
}
// } Driver Code Ends

// User function Template for Java

class Solution {
    static int findSubArraySum(int Arr[], int N, int k) {
        // key = prefix, val = cnt
        HashMap<Integer, Integer> hm = new HashMap<>();

        // entry for 0
        hm.put(0, 1);

        int prefix = 0;
        int count = 0;

        for (int i = 0; i < N; i++) {
            // add the curr ele to the prefix
            prefix += Arr[i];

            // check whether k - ps is in hm or not
            if (hm.containsKey(prefix - k)) {
                count += hm.get(prefix - k);
            }

            // put the ele into the hm
            if (hm.containsKey(prefix)) {
                hm.put(prefix, hm.get(prefix) + 1);
            } else {
                hm.put(prefix, 1);
            }

        }
        return count;
    }
}}
