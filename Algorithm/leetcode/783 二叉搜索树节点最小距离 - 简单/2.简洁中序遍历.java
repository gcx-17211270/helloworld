/index.html
public class 2.简洁中序遍历 {
    
}
/*
 * @Descripttion: 
 * @version: 
 * @Author: 32353
 * @Date: 2021-04-13 20:48:15
 * @LastEditors: 32353
 * @LastEditTime: 2021-04-13 20:58:51
 */

class Solution {
    private TreeNode pre = null;   //pre记录前一节点
    private int res = Integer.MAX_VALUE;
    public int minDiffInBST(TreeNode root) {
        dfs(root);
        return res;
    }
    private void dfs(TreeNode root){
        if(root == null) return;
        dfs(root.left);
        if(pre != null){
            res = Math.min(root.val-pre.val,res);   //记录最小
        }
        pre = root;
        dfs(root.right);
    }
}
