package BinarySearchTree;

class Node {
    int val;
    Node left, rt;

    Node(int key) {
        val = key;
        left = rt = null;
    }
}

class BST_Delete {
    Node root;

    Node deleteNode(Node root, int key) {
        if (root == null)
            return null;

        // when the actual root has to be deleted
        if (root.val == key) {
            return deleteHelper(root);
        }

        Node dummy = root;

        // middle nodes have to be deleted
        while (root != null) {
            if (root.val > key) {
                // key will be on left part
                if (root.left != null && root.left.val == key) {
                    root.left = deleteHelper(root.left);
                    break;
                } else {
                    root = root.left;
                }
            } else {
                // key will be on right part
                if (root.rt != null && root.rt.val == key) {
                    root.rt = deleteHelper(root.rt);
                    break;
                } else {
                    root = root.rt;
                }
            }
        }

        return dummy;
    }

    Node deleteHelper(Node root) {
        // if one of the child is not present return the other one
        if (root.left == null)
            return root.rt;
        else if (root.rt == null)
            return root.rt;

        Node rightChild = root.rt;
        Node lastRight = findLastRight(root.left);
        lastRight.rt = rightChild;

        return root.left;
    }

    Node findLastRight(Node root) {
        if (root.rt == null)
            return root;
        return findLastRight(root.rt);
    }
}
