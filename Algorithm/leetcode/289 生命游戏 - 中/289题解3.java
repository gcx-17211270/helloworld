    public void gameOfLife(int[][] board) {
        int sum = 0;

        int[][] boardTmp = new int[board.length + 2][board[0].length + 2];

        for (int i = 0; i < boardTmp.length - 2; i++) {
            for (int j = 0; j < boardTmp[0].length - 2; j++) {
                boardTmp[i + 1][j + 1] = board[i][j];
            }
        }

        for (int i = 0; i < boardTmp.length - 2; i++) {
            for (int j = 0; j < boardTmp[0].length - 2; j++) {
                sum += boardTmp[i][j] + boardTmp[i][j + 1] + boardTmp[i][j + 2] + boardTmp[i + 1][j]
                        + boardTmp[i + 1][j + 2] + boardTmp[i + 2][j] + boardTmp[i + 2][j + 1] + boardTmp[i + 2][j + 2];
                int n = boardTmp[i + 1][j + 1];
                if (n == 1) {
                    if (sum < 2 || sum > 3) {
                        board[i][j] = 0;
                    }
                }
                if (n == 0) {
                    if (sum == 3) {
                        board[i][j] = 1;
                    }
                }
                sum = 0;
            }
        }
    }
/*
执行用时0ms，添加首行首列、末行末列
Nice Tesla
发布于 10 小时前
626
image.png
时间复杂度O(mn)
添加首行首列、末行末列为0值。只需判断八个位置之和即可。
[0, 0, 0, 0, 0]
[0, 0, 1, 0, 0]
[0, 0, 0, 1, 0]
[0, 1, 1, 1, 0]
[0, 0, 0, 0, 0]
[0, 0, 0, 0, 0]

作者：nice-tesla
链接：https://leetcode-cn.com/problems/game-of-life/solution/zhi-xing-yong-shi-0mstian-jia-shou-xing-shou-lie-m/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/