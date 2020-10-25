//2020.04.23 高成鑫
//使用递归与迭代，没有考虑到例如【1，2，3，4】这类最后一个4能否被看到的问题
//package 
class solution {
    List<Integer> l = new ArrayList<>();
    public List<Integer> rightSideView(TreeNode root) {
        
        if (root == null) return l;
        else {
            l.add(root.val);
            if (root.right != null)
                rightSideView(root.right);
            else rightSideView(root.left);
        }
        return l;
    }
}