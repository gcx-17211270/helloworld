/**
 * 递归
 **/ 
#define MAX_SIZE 10240
void visit(struct Node* root, int* result, int* returnSize) {
  if (root)
    for (int i = 0; i < root->numChildren; i++) {
      result[(*returnSize)++] = root->children[i]->val;
      visit(root->children[i], result, returnSize);
    }
}
int* preorder(struct Node* root, int* returnSize) {
  int i, *result = (int*)calloc(MAX_SIZE, sizeof(int));
  *returnSize = 0;
  if (root == NULL) return result;
  result[(*returnSize)++] = root->val;
  visit(root, result, returnSize);
  return result;
}
/*
作者：dingjinyang
链接：https://leetcode-cn.com/problems/n-ary-tree-preorder-traversal/solution/cyu-yan-di-gui-die-dai-by-dingjinyang/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/