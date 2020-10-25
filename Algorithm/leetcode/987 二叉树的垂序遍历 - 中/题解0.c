//思路：使用一个结构数组，记录值与横坐标，再将横坐标相同的放在同一列输出
typedef struct Node{
    int val;
    int xpos;
    int ypos;
};

int** chuixubianli(TreeNode* root, int* returnSize, int** returnColSize)
{
    struct Node node[5000];
    if (root == NULL) return NULL;
    int* min = (int*)malloc(sizeof(int)); 
    int* max = (int*)malloc(sizeof(int)); 
    int* len = (int*)malloc(sizeof(int)); 
    *min = 0, *max = 0, *len = 0;
    preOrder(root, node, min, max, len, 0, 0);
    //怎么把*len个数根据坐标分类
    int length = *max - *min;
    *returnSize = length;
    int** res = (int**)malloc(sizeof(int*) * length);
    int** returnColumnSize = (int**)malloc(sizeof(int*) * length)
    for (int i = 0; i < length; i++)
    {
        *res[i] = (int*)malloc(sizeof(int) * (5000 / length));
    }
    for (int i = 0; i < length; i++)
    {
        *returnColumnSize[i] = (int*)malloc(sizeof(int));
        *returnColumnSize[i] = 0;
        for (int j = 0; j < *len; j++)
        {
            if(node[j]->xpos = i + *min) res[i][(*returnColumnSize[i])++] = node->val;
        }
    }
}

void preOrder(TreeNode* root, struct Node* node, int* min, int* max, int* len, int x, int y)
{
    if(root = NULL) return ;
    node[(*len)]->val = root->val;
    node[(*len)]->xpos = x;
    node[(*len)++]->ypos = y;
    if (root->left != NULL) 
    {
        (*len)++;
        if (x - 1 < *min) *min = x - 1;
        preOrder(root->left, node, min, max, len, x - 1, y - 1);
    }
    if (root->right != NULL)
    {
        (*len)++;
        if(x + 1 > *max) *max = x + 1;
        preOrder(root->right, node, min, max, len, x + 1, y - 1);
    }
}