/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        LinkedList<List<Integer>> res = new LinkedList<>();
        LinkedList<TreeNode> queue = new LinkedList<TreeNode>();

        if (root == null)
            return res;

        queue.add(root);

        while(queue.size() > 0)
        {
            int size = queue.size();
            List<Integer> tmp = new ArrayList<>();
            for (int i = 0; i < size; i++)
            {
                TreeNode t = queue.remove();
                tmp.add(t.val);
                if (t.left != null)
                {
                    queue.add(t.left);
                }
                if (t.right != null)
                {
                    queue.add(t.right);
                }
            }
            res.addFirst(tmp);
        } 
        return res;
    }    
}