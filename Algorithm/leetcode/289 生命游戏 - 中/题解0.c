void gameOfLife(int** board, int boardSize, int* boardColSize){
    int colSize = boardColSize[0];
    loc a[colSize * boardSize];
    int m[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int n[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            int total = 0;
            for (int k = 0; k < 8; k++)
            {
                if (i + m[k] < 0 || i + m[k] > boardSize || j + n[k] < 0 || j + n[k] > colSize)
                    continue;
                if (board[i + m[k]][j + n[k]] == 1) total++;
            }
            if (board[i][j] == 1) 
            {
                switch(total)
                {
                    case 2: board[i][j] = 1;break;
                    case 3: board[i][j] = 1;break;
                    default: board[i][j] = 0;break;
                }
            }
            else
            {
                if (total == 3) board[i][j] = 1;
            }
        }
    }
}

typedef struct location
{
    int i;
    int j;
    bool change;
}loc;