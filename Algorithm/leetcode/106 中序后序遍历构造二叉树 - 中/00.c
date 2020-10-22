/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int find(int* inorder, int inorderSize, int target)
{
    for (int i = 0; i < inorderSize; i++)
    {
        if (inorder[i] == target)
            return i;
    }
    return -1;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
    if (postorderSize <= 0) return NULL;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = postorder[postorderSize - 1];
    int k = find(inorder, inorderSize, root->val);
    if (k != -1)
    {
        root->left = buildTree(inorder, k, postorder, k);
        root->right = buildTree(inorder + k + 1, inorderSize - k - 1, postorder + k, postorderSize - k - 1);
    }
    else return NULL;
    return root;
}