/**
**@author : Gao Chengxin
**@data : 2020-03-29
**@time : 10 : 43
**@描述： 通过了17/35个测试用例，然后超时了
*/

int maxDistance(int** grid, int gridSize, int* gridColSize){
    int distance = 0, min = 0;
    int colSize = gridColSize[0];
    int maxdistance[gridSize * colSize];
    int flag = 0;
    int minLength = 0;
    int min1[gridSize * colSize];

    for (int i = 0; i < gridSize; i++)
        {
            for (int j = 0; j < colSize; j++)
            {
                if (grid[i][j] == 1) flag++;
            } 
        }
    if(flag == 0 || flag == gridSize * colSize) return -1;   

    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            if (grid[i][j] == 0) 
            {
                min1[minLength++] = minManhattan(grid, gridSize, gridColSize, i, j);
                //printf("i=%d j=%d min=%d\n",i,j,min);
            }
        }
    }
    return maxOfArray(min1,minLength);
}

int minManhattan(int** grid, int gridSize, int* gridColSize,int i, int j)
{
    int md[gridSize * gridColSize[0]];
    int mdLength = 0;
    //return ManhattanDistance(i, j, 1, 1);
    for (int m = 0; m < gridSize; m++)
    {
        for (int n = 0; n < gridColSize[0]; n++)
        {
            if(grid[m][n] == 1)
            {
                //printf("42 %d %d\n",m,n);
                md[mdLength++] = ManhattanDistance(i, j, m, n);
            }
        }
    }
    int distance = minOfArray(md, mdLength);
    return distance;
}

int ManhattanDistance(int i, int j, int m, int n)
{
    return abs(i - m) + abs(j - n);
}

int maxOfArray(int* maxdistance, int length)
{
    int max = maxdistance[0];
    for(int i = 1; i < length; i++)
    {
        if (maxdistance[i] > max) max = maxdistance[i];
    }
    return max;
}
int minOfArray(int* mindistance, int length)
{
    int min = mindistance[0];
    //printf("min = %d,length = %d\n",min,length);
    for(int i = 1; i < length; i++)
    {
        //printf("a[%d] = %d ",i,min);
        if (mindistance[i] < min) min = mindistance[i];
        //printf("min = %d\n",min);
    }
    //printf("\nminArray is %d\n", min);
    return min;
}