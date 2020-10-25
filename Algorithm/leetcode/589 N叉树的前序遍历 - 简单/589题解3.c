/**
 * 迭代
 **/ 
#define MAX_SIZE 10240
int* preorder(struct Node* root, int* returnSize) {
  int i, top = -1, *result = (int*)calloc(MAX_SIZE, sizeof(int));
  struct Node *p, **stack = (char**)malloc(sizeof(struct Node*) * MAX_SIZE);
  *returnSize = 0;
  if (root == NULL) return result;
  stack[++top] = root;
  while (top != -1) {
    p = stack[top--];
    result[(*returnSize)++] = p->val;
    // 从最后一个孩子开始入栈
    for (i = p->numChildren - 1; i >= 0; i--)
      stack[++top] = p->children[i];
  }
  return result;
}
/*
作者：dingjinyang
链接：https://leetcode-cn.com/problems/n-ary-tree-preorder-traversal/solution/cyu-yan-di-gui-die-dai-by-dingjinyang/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/