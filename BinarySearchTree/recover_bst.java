You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. 
Recover the tree without changing its structure.


class Solution {
    private TreeNode firstIncorrectNode = null;
    private TreeNode secondIncorrectNode = null;
    private TreeNode prevNode = null;

    public void recoverTree(TreeNode root) {
        // Initialize variables for tracking incorrect nodes and previous node
        firstIncorrectNode = null;
        secondIncorrectNode = null;
        prevNode = null;

        // Perform in-order traversal
        inOrderTraversal(root);

        // Swap the values of the incorrect nodes
        if (firstIncorrectNode != null && secondIncorrectNode != null) {
            int temp = firstIncorrectNode.val;
            firstIncorrectNode.val = secondIncorrectNode.val;
            secondIncorrectNode.val = temp;
        }
    }

    private void inOrderTraversal(TreeNode root) {
        if (root == null)
            return;

        // Traverse left subtree
        inOrderTraversal(root.left);

        // Check the current node
        if (prevNode != null && root.val < prevNode.val) {
            // Found an incorrect node
            if (firstIncorrectNode == null) {
                firstIncorrectNode = prevNode;
                secondIncorrectNode = root;
            } else {
                // Update the second incorrect node
                secondIncorrectNode = root;
            }
        }

        // Update previous node
        prevNode = root;

        // Traverse right subtree
        inOrderTraversal(root.right);
    }
}
