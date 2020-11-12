public int trap(int[] height)
{
    int sum = 0;
    int max = getMax(height);   //找到最大的高度，以便遍历
    for (int i = 1; i <= max; i++)
    {
        boolean isStart = false;
        int temp_sum = 0;
        for (int j = 0; j < height; j++)
        {
            if (isStart && height[j] < i)
            {
                temp_sum++;
            }
            if (height[i] >= i)
            {
                sum = sum + temp_sum;
                temp_sum = 0;
                isStart = true;
            }
        }
    }
    return sum;
}
private int getMax(int[] height)
{
    int max = 0;
    for (int i = 0; i < height.length; i++)
    {
        if (height[i] < max)
            max = height[i];
    }
    return max;
}

/**
按行求
整个思路就是，求第 i 层的水，遍历每个位置，如果当前的高度小于 i，并且两边有高度大于等于 i 的，说明这个地方一定有水，水就可以加 11。

如果求高度为 i 的水，首先用一个变量 temp 保存当前累积的水，初始化为 00。从左到右遍历墙的高度，遇到高度大于等于 i 的时候，开始更新 temp。更新原则是遇到高度小于 i 的就把 temp 加 11，遇到高度大于等于 i 的，就把 temp 加到最终的答案 ans 里，并且 temp 置零，然后继续循环。

作者：windliang
链接：https://leetcode-cn.com/problems/trapping-rain-water/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-8/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/