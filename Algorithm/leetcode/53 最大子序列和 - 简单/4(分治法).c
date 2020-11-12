//浙大——陈越老师《数据结构》慕课代码

int maxSubArray(int* nums, int numsSize){
    return DivideAndConquer(nums, 0, numsSize - 1);
}

int DivideAndConquer(int List[], int left, int right)
{
    //分治法求List[left]到List[right]的最大子列和
    int MaxLeftSum, MaxRightSum;    //存放左右子问题的解
    int MaxLeftBorderSum, MaxRightBorderSum;    //存放跨分界线的结果
    int LeftBorderSum, RightBorderSum;
    int center, i;
    if (left == right)      //递归的终止条件，子列只有一个数字
    {
        return List[left];
        //上面是为了通过leetcode测试用例改变的，原代码没有上一句
        if (List[left] > 0) return List[left];
        else return 0;
    }
    //下面是分治的过程
    center = (left + right) / 2;    //找到中分点，递归求两边子列的最大和
    MaxLeftSum = DivideAndConquer(List, left, center);
    MaxRightSum = DivideAndConquer(List, center + 1, right);
    //下面是求跨分界线的最大子列和
    //从中线向左扫描
    LeftBorderSum = 0;
    MaxLeftBorderSum = List[center];
    for(i = center; i >= left; i--)
    {
        LeftBorderSum += List[i];
        if (LeftBorderSum > MaxLeftBorderSum)
            MaxLeftBorderSum = LeftBorderSum;
    }
    //从中线向右扫描
    RightBorderSum = 0;
    MaxRightBorderSum = List[center + 1];
    for (i = center + 1; i <= right; i++)
    {
        RightBorderSum += List[i];
        if (RightBorderSum > MaxRightBorderSum)
            MaxRightBorderSum = RightBorderSum;
    }

    return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}

int Max3(int a, int b, int c)
{
    int temp = a > b ? a : b;
    return  temp > c ? temp : c;
}