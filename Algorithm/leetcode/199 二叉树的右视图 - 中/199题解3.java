
public class Solution {
    List<Integer> res = new ArrayList<>();

    public List<Integer> rightSideView(TreeNode root)
    {
        dfs(root, 0);
        return res;
    }

    private void dfs(TreeNode root, int depth)
    {
        if (root == null)
            return res;
        //先访问当前结点，再递归的访问右子树和左子树
        if (depth == res.size()){   // 如果当前节点所在深度还没有出现在res里，说明在该深度下当前节点是第一个被访问的节点，因此将当前节点加入res中。
            res.add(root.val);
        }
        depth++;
        dfs(root.right, depth);
        dfs(root.left, depth);
    }
}