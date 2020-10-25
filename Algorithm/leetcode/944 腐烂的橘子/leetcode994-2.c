typedef struct {
    int x;
    int y;
    int lev;
} Queue;

/* ��׼BFS���, ����ʵ�ֹ�����ȱ��� */
/* �����������, ������ʱ, ���ܱߵĺ�����Ⱦ��, �����������, ����ѭ�� */
/* ������Ϊ��ʱ, ˵��û�к�������, ��ʱ�ж�������к�����, ����-1, ���򷵻�level */
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
    /* �����������, ��¼x/y����, ���levΪ0 */
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (grid[i][j] == 2) {
                Q[rear].x = i;
                Q[rear].y = j;
                Q[rear++].lev = 0;
            }
        }
    }
    /* BFS������ȱ���, �����ӳ�����x/y, ��֮���ڵĺ����ӽ�����, ���δ��� */
    while (front != rear) {
        x = Q[front].x;
        y = Q[front].y;
        lev = Q[front++].lev;
        /* ��������Ѱ�һ������ܱߵĺ����� */
        for (i = 0; i < 4; i++) {
            xx = x + x_shift[i];
            yy = y + y_shift[i];
            if (xx < 0 || xx >= m || yy < 0 || yy >= n || grid[xx][yy] != 1) {
                continue;
            }
            grid[xx][yy] = 2; /* �����ӱ�Ⱦ�� */
            Q[rear].x = xx;   /* ����в��� */
            Q[rear].y = yy;
            Q[rear++].lev = lev + 1;
        }
    }
    /* ����Ϊ��ʱ, ������к�����, ����-1 */
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                return -1;
            }
        }
    }
    return lev;
}
