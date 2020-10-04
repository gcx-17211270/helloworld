int specialArray(int* nums, int numsSize){
    int count = 0;
    selectSort(nums, numsSize);
    if (nums[numsSize - 1] >= numsSize) return numsSize;
    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i - 1] >= i && nums[i] < i)
            return i;
    }
    return -1;
}

void selectSort(int* nums, int numsSize)
{
    int temp = nums[0];
    for (int i = 0; i < numsSize - 1; i++)
    {
        for(int j = i + 1; j < numsSize; j++)
        {
            if (nums[j] > nums[i]) 
            {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }
        
}