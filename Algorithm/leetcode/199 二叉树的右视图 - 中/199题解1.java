class Solution{
    public List<Integer> res = new ArrayList<>();
    if (root == null)
        return res;
    Queue<TreeNode> queue = new LinkedList<>();
    queue.offer(root);
    while(!queue.isEmpty()) {
        int size = queue.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode node = queue.poll();
            if (node.left != null) {
                queue.offer(node.left);
            }
            if (node.left != null) {
                queue.offer(node.right);
            }
            if (i == size - 1) {
                res.add(node.val);
            }
        }
    }
}