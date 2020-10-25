int maxDistance(int **grid, int gridSize, int *gridColSize)
{
    int i, j, m, x, y, find;
    int max = -1;
    if (grid == 0 || gridSize == 0 || gridColSize == 0) {
        return 0;
    }
    // 遍历每个海洋，找到与其曼哈顿距离最近的陆地，如果该距离超过当前的最近距离，更新到最大距离
    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == 0) {
                find = 0;
                // 从距离为1开始BFS，直到找到最近的陆地，或者遍历完整个地图
                for (m = 1; m <= ((gridSize - 1) * 2); m++) {
                    for (x = 0; x <= m; x++) {
                        y = m - x;
                        if (i + x >= 0 && i + x < gridSize && j + y >= 0 && j + y < gridSize) {
                            if (grid[i + x][j + y] == 1) {
                                if (m > max) {
                                    max = m;
                                }
                                find = 1;
                                break;
                            }
                        }

                        if (i - x >= 0 && i - x < gridSize && j + y >= 0 && j + y < gridSize) {
                            if (grid[i - x][j + y] == 1) {
                                if (m > max) {
                                    max = m;
                                }
                               find = 1;
                               break;
                            }
                        }

                        if (i + x >= 0 && i + x < gridSize && j - y >= 0 && j - y < gridSize) {
                            if (grid[i + x][j - y] == 1) {
                                if (m > max) {
                                    max = m;
                                }
                                find = 1;
                                break;
                            }
                        }

                        if (i - x >= 0 && i - x < gridSize && j - y >= 0 && j - y < gridSize) {
                            if (grid[i - x][j - y] == 1) {
                                if (m > max) {
                                    max = m;
                                }
                                find = 1;
                              break;
                            }
                        }

                    }
                    if (find) {
                        break;
                    }
                }
            }
        }
    }
    return max;
}

/*
执行用时 :92 ms, 在所有 C 提交中击败了54.23%的用户
内存消耗 :7.4 MB, 在所有 C 提交中击败了100.00%的用户

遍历每个海洋，找到与其曼哈顿距离最近的陆地，如果该距离超过当前的最近距离，更新到最大距离
如何遍历：从距离为1开始BFS，针对 【delatx + deltay = 当前距离】 的所有x和y的组合进行遍历，直到找到最近的陆地，或者遍历完整个地图,

作者：theemptysea
链接：https://leetcode-cn.com/problems/as-far-from-land-as-possible/solution/bfs-by-theemptysea/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。



作者：theemptysea
链接：https://leetcode-cn.com/problems/as-far-from-land-as-possible/solution/bfs-by-theemptysea/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/