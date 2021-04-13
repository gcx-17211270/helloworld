/*
 * @Descripttion: 
 * @version: 
 * @Author: 32353
 * @Date: 2021-04-13 20:39:26
 * @LastEditors: 32353
 * @LastEditTime: 2021-04-13 20:39:28
 */
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
    public int minDiffInBST(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int result = traverse(root, -1, Integer.MAX_VALUE).min;
        return result;
    }
    private Node traverse(TreeNode root, int lastVal, int minNum) {
        if (root == null) {
            return new Node(lastVal, minNum);
        }
        //-1表示从根节点进入
        if (lastVal == -1) lastVal = root.val;
        if (root.left != null) {
            Node node = traverse(root.left, lastVal, minNum);
            lastVal = node.val;
            minNum = node.min;
        }
        minNum = minAbs(root.val, lastVal, minNum);
        lastVal = root.val;
        if (root.right != null) {
            Node node = traverse(root.right, lastVal, minNum);
            lastVal = node.val;
            minNum = node.min;
        }
        return new Node(lastVal, minNum);
    }
    private int minAbs(int rootVal, int lastVal, int min) {
        int temp = rootVal > lastVal ? rootVal - lastVal : lastVal - rootVal;
        //防止和“自身相减”、相同值
        if (temp == 0) return min;
        return temp < min ? temp : min;
    }
}

class Node {
    int val;
    int min;
    public Node(int val, int min) {
        this.val = val;
        this.min = min;
    }
}/index.html
public class 1.中序遍历 {
    
}
