/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private int sucessor(TreeNode root) {
        root = root.right;
        while(root.left != null){
            root = root.left;
        }
        return root.val;
    }

    private int predecessor(TreeNode root) {
        root = root.left;
        while(root.right != null){
            root = root.right;
        }
        return root.val;
    }

    public TreeNode deleteNode(TreeNode root, int key) {
        if(root == null) return null;

        if(key > root.val)
            root.right = deleteNode(root.right, key);
        else if(key < root.val)
            root.left = deleteNode(root.left, key);
        else{
            // key == root
            // u have to delete the current root

            // 1. check if the root is a leaf node:
            if(root!=null && root.left==null && root.right==null)
                root = null;
            
            // 2. check if right exists and bring the lowest left child
            if(root!=null && root.right != null) {
                root.val = sucessor(root);
                root.right = deleteNode(root.right, root.val); // since the val will be duplicated and has to be deleted 
            } else if (root!=null && root.left != null) {
                root.val = predecessor(root);
                root.left = deleteNode(root.left, root.val); // del the copy of this which is present in left
            }
        }

        return root;
    }
}
