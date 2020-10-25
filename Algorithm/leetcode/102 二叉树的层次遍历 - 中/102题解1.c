/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define MAX_RETURN_NUM 1000
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
// 整理输入输出
    int **ret = (int**)calloc(MAX_RETURN_NUM , sizeof(int*));
    *returnColumnSizes = (int*)calloc(MAX_RETURN_NUM, sizeof(int));
    *returnSize = 0;
// 建立指向节点的指针队列和两个索引
    struct TreeNode *queue[10000];
    int outIndex = 0;
    int inIndex = 0;
// 判断异常输入，进入while循环之前初始化
    if (root == NULL){return NULL;}
    queue[inIndex++] = root;
    int levelcount = inIndex - outIndex;
    int count = 0;
// BFS
    while (levelcount > 0){
        count++;
        ret[*returnSize] = (int*)calloc(levelcount,sizeof(int));
        (*returnColumnSizes)[*returnSize] = levelcount;
// 每一层的动作
        for (int i = 0; i < levelcount; i++){
            if (queue[outIndex]->left != NULL){
                queue[inIndex++] = queue[outIndex]->left;
            }
            if (queue[outIndex]->right != NULL){
                queue[inIndex++] = queue[outIndex]->right;
            }
            ret[*returnSize][i] = queue[outIndex]->val;
            outIndex++;
        }
// 进入下一层之前的动作
        (*returnSize)++;
        levelcount = inIndex - outIndex;
    }
    return ret;
}
/*
作者：dong-bei-zhang-da-shuai
链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal/solution/cyu-yan-bfsshuang-bai-by-dong-bei-zhang-da-shuai/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/