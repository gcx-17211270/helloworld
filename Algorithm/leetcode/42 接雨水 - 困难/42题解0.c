int trap(int* height, int heightSize){
    if (heightSize == 0) return 0;
    int highest = 0, higher = 0, high = 0;
    int count = 0;
    for (int i = 0; i < heightSize; i++)
        if (height[i] > height[highest]) highest = i;       //一次遍历，寻找最高
    //printf("highest = %d\n",highest);
    for (int i = 0; i <= highest; i++)          //在highest左边寻找左低右高的凹状体
    {
        if (height[i] >= height[high])
        {
            higher = i;
            if (higher > high + 1)
            {
                //printf("%d %d %d ",higher, high, higher - high);
                int uper = fillup(height, high, higher);
                count += uper;
                //printf("%d %d\n", uper, count);
            }
            high = i;
        }
    }
    
    high = heightSize - 1;
    for (int i = heightSize-1; i >= highest; i--)       //在highest右边计算右低左高的结构体
    {
        if (height[i] >= height[high])
        {
            higher = i;
            if (high > higher + 1)
            {
                //printf("higher - high = %d\n",higher - high);
                int uper = fillup2(height, higher, high);
                count += uper;
            }
            high = i;
        }
    }
    
    return count;
}
int fillup(int* height, int i, int j)       //fillup和fillup1是左右两边计算容积的公式
{                                           //他们的区别在于fillup是左低右高的凹状体
    int total = 0;                          //fillup1是右高左低的结构体
    for (int k = i + 1; k < j; k++)
        total += height[k];
    return height[i] * (j - i - 1) - total;
}

int fillup2(int* height, int i, int j)
{
    int total = 0;
    for (int k = i + 1; k < j; k++)
        total += height[k];
    return height[j] * (j - i - 1) - total;
}
/**
 * 解题思路
暴力求解
    1.能够容纳雨水，必然代表存在一个两边高中间低的凹状结构，那么我们的任务就变成了寻找凹状结构
    2.找到凹状结构之后，我们可以从它的低的一段开始，计算它的容积
    3.将所有的凹状结构容积求和，得出接雨水的容量

具体实现：
    1.寻找凹状结构
        1）我们对数组的大小，即结构的高度做一次遍历，寻找到最高的，标记为highest
        2）在highest左边，必然是左边低的凹状结构，从数组的第一位开始，将其标记为high，向右寻找 到更高的后标记为higher，在high和higher中间就是我们寻找的凹状结构，每找到一个凹状体结构，我们将high向后移为highest，便于寻找下一个凹状体。我们用fillup函数计算这个凹状结构的容积。
        3）在highest右边，必然是右边低的凹状结构，从数组的最后一位开始，将其标记为high，逐次向左遍历寻找higher，在high和higher之间的必然是右低左高的凹状体，使用fillup1计算容积并将high移到当前。
    2.计算容积
我们用fillup来计算凹状体的体积，fillup函数的数组左边必定是短板，因而容积=左高度凹状结构长度-已填充的，相对的，后面有一个fillup1函数，容积计算应该是右高度凹状结构-已填充
    3.复杂度：循环进行了2n次，比较进行了2n次，时间复杂度o(n)
没有使用额外的数组，空间复杂度o(1)

作者：32353
链接：https://leetcode-cn.com/problems/trapping-rain-water/solution/xun-zhao-ao-zhuang-yu-shui-rong-qi-ji-suan-rong-ji/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

//2020.0412.17:16 通过 8 ms击败59.55%的用户	6.1 MB击败100%	 在C的提交中