
typedef struct queue
{
    struct TreeNode* data;
    int front;
    int rear;
}Myqueue;

void initqueue(Myqueue* queue, int maxsize)
{
    queue->data = (struct TreeNode*)malloc(sizeof(struct TreeNode*) * maxsize);
    queue->front = 0;
    queue->rear = 0;
}

void enqueue(Myqueue* obj, struct TreeNode* root)
{
    obj->data[obj->rear++] = *root;
}

struct TreeNode* dequeue(Myqueue* obj, struct TreeNode* root)
{
    struct TreeNode* temp = obj->data;
    return &obj->data[obj->front++];
    free(temp);
}

int isqueueEmpty(Myqueue* obj)
{
    return obj->front == obj->rear;
}

int height(struct TreeNode* root)
{
    int HL, HR, MaxH;
    if (root)
    {
        HL = height(root->left);
        HR = height(root->right);
        MaxH = (HL > HR) ? HL : HR;
        return (MaxH + 1);
    }
    else return 0;
}

int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int** ret = (int**)malloc(sizeof(int*) * 1000);
    int count = 0, i = 0, depth;
    depth = height(root);
    *returnSize = depth;
    Myqueue* queue = (Myqueue*)malloc(sizeof(Myqueue));
    returnColumnSizes[0] = (int*)malloc(sizeof(int) * 1000);
    initqueue(queue, 10000);
    if(!root) return NULL;
    enqueue(queue, root);
    depth = 0;
    while (!isqueueEmpty(queue))
    {
        count = queue->rear - queue->front;
        ret[depth] = (int*)malloc(sizeof(int) * count);
        returnColumnSizes[0][depth] = count;
        while(i != count)
        {
            root = dequeue(queue, root);
            if(depth%2 == 0) ret[depth][i++] = root->val;
            else 
            {
                ret[depth][count - i - 1] = root->val;
                i++;
            }
            if (root->left) enqueue(queue, root->left);
            if (root->right) enqueue(queue, root->right);
        }
        i = 0;
        depth++;
    }
    return ret;
}

