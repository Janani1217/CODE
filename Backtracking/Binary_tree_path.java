/*
Problem statement :
Given a binary tree, return all root to leaf path in any order.

OP : Return a vector<string>, so here string is the path.
< "1->2->3->4" , "1->5->6" , "1->5->->7->8" >

Explained with diagrams in note.

......................................................................................................
......................................................................................................

Algorithm :

1.  Base case : reaching leaf node :
    push the data into curr str
    Then push the str into vector ans
    then pop the root data
    pop the arrow inserted
    return.

2.  Remaining case :
    Check for both left and right node of root
    add the root data to curr str
    add the arrow ->
    move forward/call recr to child whoever present

......................................................................................................
......................................................................................................

Pass the answer vector as the reference.

We cant backtrack at the leaf node , because it will go up only 1 level.
But there might be cases , where we need to go 2 times , or more towards
the root.

So we have to do the backtracking in the remaining cases section after
the recr call has been made.

......................................................................................................
......................................................................................................

*/

import java.util.ArrayList;
import java.util.List;

class Node {
    int data;
    Node left, right;

    public Node(int d) {
        data = d;
        left = right = null;
    }
}

public class BinaryTreePaths {
    public static int height(Node root) {
        if (root == null)
            return 0;

        int left = height(root.left);
        int right = height(root.right);
        return 1 + Math.max(left, right);
    }

    public static void printCurrentLevel(Node root, int height) {
        if (root == null)
            return;

        if (height == 1)
            System.out.print(root.data + " ");
        else if (height > 1) {
            printCurrentLevel(root.left, height - 1);
            printCurrentLevel(root.right, height - 1);
        }
    }

    public static void printLevelOrderBinaryTree(Node root) {
        if (root == null)
            return;

        int h = height(root);

        for (int i = 1; i <= h; i++) {
            printCurrentLevel(root, i);
            System.out.println();
        }
    }

    public static void printAllPaths(Node root, List<String> ans, String str) {
        if (root == null)
            return;

        if (root.left == null && root.right == null) {
            str = str + root.data;
            ans.add(str);
            return;
        }

        String oldStr = str;
        str = str + root.data + "->";

        printAllPaths(root.left, ans, str);
        printAllPaths(root.right, ans, str);

        str = oldStr;
    }

    public static void main(String[] args) {
        Node root = new Node(1);

        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);

        // printLevelOrderBinaryTree(root);
        List<String> ans = new ArrayList<>();
        String str = "";
        printAllPaths(root, ans, str);

        for (String path : ans) {
            System.out.println(path);
        }
    }
}
