class Solution {
    List<Integer> res = new ArrayList<>();
    int level = 0;
    public List<Integer> rightSideView(TreeNode root) {
        dfs(root, 0);
        return res;
    }

    public void dfs(TreeNode node, int num){
        if(node == null)
            return;
        if(level == num){
            level++;
            res.add(node.val);
        }
        dfs(node.right, num + 1);
        dfs(node.left, num + 1);
    }
}

//为什么题解2比题解3快？