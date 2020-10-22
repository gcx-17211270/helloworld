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
        if (target == inorder[i])
            return i;
    }
    return -1;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    if (inorderSize <= 0) return NULL;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = preorder[0];
    int k = find(inorder, inorderSize, root->val);
    if (k != -1)
    {
        root->left = buildTree(preorder + 1, k, inorder, k);
        root->right = buildTree(preorder + k + 1, preorderSize - k - 1, inorder + k + 1, preorderSize - k - 1);
    }
    else return NULL;
    return root;
}