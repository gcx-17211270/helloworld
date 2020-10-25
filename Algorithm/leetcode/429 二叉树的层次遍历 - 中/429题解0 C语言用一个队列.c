/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MaxSize 5000
int** levelOrder(struct Node* root, int* returnSize, int** returnColumnSizes) {
    int** res = (int**)malloc(sizeof(int*) * MaxSize);
    struct Node** Queue = (struct Node**)malloc(sizeof(struct Node*) * MaxSize);
    int front = -1, rear = -1;
    if (root != NULL) Queue[++rear] = root;
    *returnSize = 0;
    while(front != rear)
    {
        int* tmp = (int*)malloc(sizeof(int) * (rear-front));
        struct Node* temp = Queue[++front];
        int j = rear, i = front, length = rear - front;
        for(int i = front; i <= j; i++)
        {
            tmp[i] = temp->val;
            for(int i = 0; i < temp->numChildren; i++)
            {
                Queue[++rear] = temp->children[i];
            }
            temp = Queue[++front];
        }

        //这一句有问题，怎么返回列数啊,不知道怎么改
        *returnColumnSizes = (int**)malloc(sizeof(int*) * MaxSize);
        *returnColumnSizes[0] = (int*)malloc(sizeof(int));
        returnColumnSizes[0][*returnSize] = j-i;
        
        res[(*returnSize)++] = tmp;
    }
    return res;
}