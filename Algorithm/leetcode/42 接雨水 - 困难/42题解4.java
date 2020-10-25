
public class Solution {
    int sum = 0;
    int[] max_left = new int[height.length];
    int[] max_right = new int[height.length];

    for (int i = 1; i < height.length - 1; i++)
        max_left[i] = Math.max(max_left[i - 1], height[i -1]);
    for (int i = height.length - 2; i >= 0; i--)
        max_right[i] = Math.max(max_right[i + 1], height[i + 1]);
    for (int i = 1; i < height.length - 1; i++)
    {
        int min = Math.min(max_left[i], max_right[i]);
        if (min > height[i])
            sum += min - height[i];
    }
    return sum;
}

/**
 * 我们注意到，解法二中。对于每一列，我们求它左边最高的墙和右边最高的墙，都是重新遍历一遍所有高度，这里我们可以优化一下。

首先用两个数组，max_left [i] 代表第 i 列左边最高的墙的高度，max_right[i] 代表第 i 列右边最高的墙的高度。（一定要注意下，第 i 列左（右）边最高的墙，是不包括自身的，和 leetcode 上边的讲的有些不同）

对于 max_left我们其实可以这样求。

max_left [i] = Max(max_left [i-1],height[i-1])。它前边的墙的左边的最高高度和它前边的墙的高度选一个较大的，就是当前列左边最高的墙了。

对于 max_right我们可以这样求。

max_right[i] = Max(max_right[i+1],height[i+1]) 。它后边的墙的右边的最高高度和它后边的墙的高度选一个较大的，就是当前列右边最高的墙了。

这样，我们再利用解法二的算法，就不用在 for 循环里每次重新遍历一次求 max_left 和 max_right 了。

作者：windliang
链接：https://leetcode-cn.com/problems/trapping-rain-water/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-8/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */