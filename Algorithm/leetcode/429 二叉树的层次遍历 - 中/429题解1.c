#define MAXCOL 5000
#define MAXROW 1000
struct Node* queue[MAXCOL] = {0};

int** levelOrder(struct Node* root, int* returnSize, int** returnColumnSizes)
{
    *returnSize = 0;
    if (root == NULL)
    {
        *returnColumnSizes = NULL;
        return NULL;
    }
    *returnColumnSizes = (int*)malloc(sizeof(int) * MAXCOL);
    int** res = (int**)malloc(sizeof(int*) * MAXROW);
    int front = 0, rear = 0;
    queue[rear++] = root;
    while(front != rear)
    {
        int capacity = (rear + MAXCOL - front) % MAXCOL;
        res[returnSize[0]] = (int*) malloc (sizeof(int) * capacity);
        returnColumnSizes[0][returnSize[0]] = capacity;
        for (int idx = 0; idx < capacity; idx++)
        {
            struct Node* node = queue[front];
            front = (front + 1) % MAXCOL;
            res[returnSize[0]][idx] = node->val;
            for (int j = 0; j < node->numChildren; j++)
            {
                if (node->children[j])
                {
                    queue[rear] = node->children[j];
                    rear = ( rear + 1 ) % MAXCOL;
                }
            }
        }
        returnSize[0]++;
    }
    return res;
}