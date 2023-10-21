package BinarySearchTree;

/*
 * BST Insertion :
 * 
 * 1. new key is alsways inserted at the leaf node of a tree.
 * 
 * 2. start searching from root until leaf is hit
 * 
 * 3. key_val > curr_node_val => move right
 * key_val < curr_node_val => move left
 * 
 * 4. once a leaf is hit => insert a new node with key val and return .
 * 
 * 
 */

import java.io.*;

public class insert {

    class Node {
        int key;
        Node left, right;

        Node(int item) {
            key = item;
            left = right = null;
        }
    }

    Node root;

    insert() {
        root = null;
    }

    insert(int key) {
        root = new Node(key);
    }

    void insertBST(int val) {
        root = insertBSTUtil(root, val);
    }

    Node insertBSTUtil(Node root, int key) {
        if (root == null) {
            root = new Node(key);
            return root;
        }

        if (root.key < key) {
            root.right = insertBSTUtil(root.right, key);
        } else {
            root.left = insertBSTUtil(root.left, key);
        }
        return root;
    }
}