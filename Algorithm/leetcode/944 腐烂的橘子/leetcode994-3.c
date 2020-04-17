typedef struct Node
{
    int x[9];
    int y[9];
    int time[9];
}coordinate;

int orangesRotting(int** grid, int gridSize, int* gridColSize){
    coordinate a;
    int N = 0;
    for(int i = 0; i < gridSize; i++)
    {
        for(int j = 0; j < gridColSize[0]; j++)
        {
            if(grid[i][j] == 2) 
            {
                a.x[N] = i;
                a.y[N] = j;
				a.time[N++] = 0;
            }
        }
    }
    int time = 0;
    for(int i = 0 ; i < N; i++)
    {
        int xx, yy, b, c;
        b = a.x[i];
        c = a.y[i];
        int x_list[] = {1, -1, 0, 0};
        int y_list[] = {0, 0, 1, -1};
        for(int j = 0; j < 4; j++)
        {
            xx = b + x_list[j];
            yy = c + y_list[j];
            if(xx < 0 || yy < 0 || xx > 2 || yy > 2) 
            {
                continue;
            }
            if(grid[xx][yy] == 1) 
            {
                grid[xx][yy] = 2;
                a.x[N] = xx;
                a.y[N] = yy;
                if(i == 0) {a.time[N]++; time = a.time[N++];}
                else if(a.time[i] != a.time[i-1]) {a.time[N]++; time = a.time[N++];}
                else;
                
            }
        }
    }
    for(int i = 0; i < gridSize; i++)
    {
        for(int j = 0; j < gridColSize[0]; j++)
        {
            if(grid[i][j] == 1) return -1;
        }
    }
    return time;
}

