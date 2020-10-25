typedef struct {
    int x;
    int y;
    int lev;
} Queue;

/* 标准BFS框架, 队列实现广度优先遍历 */
/* 坏橘子入队列, 出队列时, 将周边的好橘子染坏, 坏橘子再入队, 依次循环 */
/* 当队列为空时, 说明没有好橘子了, 此时判断如果还有好橘子, 返回-1, 否则返回level */
int orangesRotting(int** grid, int gridSize, int* gridColSize){
    int m = gridSize;
    int n = gridColSize[0];
    int i, j;
    int x_shift[] = {-1, 1,  0, 0};
    int y_shift[] = { 0, 0, -1, 1};

    Queue *Q = (Queue*)malloc(sizeof(Queue) * m * n);
    int front = 0;
    int rear  = 0;
    int x, y, xx, yy;
    int lev = 0;
    /* 坏橘子入队列, 记录x/y坐标, 标记lev为0 */
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (grid[i][j] == 2) {
                Q[rear].x = i;
                Q[rear].y = j;
                Q[rear++].lev = 0;
            }
        }
    }
    /* BFS广度优先遍历, 坏橘子出队列x/y, 与之相邻的好橘子进队列, 依次处理 */
    while (front != rear) {
        x = Q[front].x;
        y = Q[front].y;
        lev = Q[front++].lev;
        /* 上下左右寻找坏橘子周边的好橘子 */
        for (i = 0; i < 4; i++) {
            xx = x + x_shift[i];
            yy = y + y_shift[i];
            if (xx < 0 || xx >= m || yy < 0 || yy >= n || grid[xx][yy] != 1) {
                continue;
            }
            grid[xx][yy] = 2; /* 好橘子被染坏 */
            Q[rear].x = xx;   /* 入队列操作 */
            Q[rear].y = yy;
            Q[rear++].lev = lev + 1;
        }
    }
    /* 队列为空时, 如果还有好橘子, 返回-1 */
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                return -1;
            }
        }
    }
    return lev;
}
