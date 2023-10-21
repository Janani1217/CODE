/*  Count of Smaller Numbers After Self :
 Given an integer array nums, return an integer
 array counts where counts[i] is the number of smaller elements 
 to the right of nums[i].

 Solution explaination : + Notes
 * https://www.youtube.com/watch?v=dw-tlJYjzco
 */

package segment_trees;

import java.util.ArrayList;
import java.util.List;

public class cout_small_after_self {
    class SegTN {
        int s, e;
        SegTN left, rt;
        int sum;

        public SegTN(int s, int e) {
            this.s = s;
            this.e = e;
            this.left = null;
            this.rt = null;
            this.sum = 0;
        }
    }

    class Solution {
        public SegTN buildTree(int s, int e) {
            if (s > e)
                return null;
            SegTN node = new SegTN(s, e);

            if (s == e)
                return node;

            int m = s + (e - s) / 2;
            node.left = buildTree(s, m);
            node.rt = buildTree(m + 1, e);
            node.sum = node.left.sum + node.rt.sum;
            return node;
        }

        public void updateTree(SegTN root, int val) {
            if (root == null)
                return;

            if (root.s == val && root.e == val) {
                root.sum += 1;
                return;
            }

            int m = root.s + (root.e - root.s) / 2;

            if (val <= m) {
                // left part update
                updateTree(root.left, val);
            } else {
                updateTree(root.rt, val);
            }

            // if(root.left!=null && root.rt!=null)
            root.sum = root.left.sum + root.rt.sum;

        }

        public int countCalcRange(SegTN root, int s, int e) {
            if (s > e)
                return 0;
            if (s == root.s && e == root.e)
                return root.sum;

            int m = root.s + (root.e - root.s) / 2;

            if (m >= e) {
                // left part completly
                return countCalcRange(root.left, s, e);
            } else if (m < s) {
                // right part completly
                return countCalcRange(root.rt, s, e);
            } else {
                // both parts need to move
                return countCalcRange(root.left, s, m) + countCalcRange(root.rt, m + 1, e);
            }
        }

        public List<Integer> countSmaller(int[] nums) {
            int n = nums.length;
            if (n == 0)
                return new ArrayList<>();

            List<Integer> ans = new ArrayList<>();
            int[] count = new int[n];
            int min = Integer.MAX_VALUE;
            int max = Integer.MIN_VALUE;

            for (int i = 0; i < n; i++) {
                min = Math.min(min, nums[i]);
                max = Math.max(max, nums[i]);
            }

            SegTN root = buildTree(min, max);

            for (int i = n - 1; i >= 0; i--) {
                updateTree(root, nums[i]);
                count[i] = countCalcRange(root, min, nums[i] - 1);
            }

            for (int i = 0; i < n; i++) {
                ans.add(count[i]);
            }
            return ans;
        }
    }
}
