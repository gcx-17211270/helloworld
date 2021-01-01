#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    int** returnNums = (int**)malloc(sizeof(int*));
    *returnNums = (int*)malloc(sizeof(int));
    returnSize = (int*)malloc(sizeof(int));
    *returnSize = 0;
    printf("%d %p", *returnSize, returnSize);
    for (int i = 0; i < numsSize; i++)
        for (int j = i + 1; j < numsSize; j++)
            for (int k = j + 1; k < numsSize; k++)
                for (int l = k + 1; l < numsSize; l++)
                {
                    if (nums[i] + nums[j] + nums[k] + nums[l] == target)
                    {
                        (*returnSize)++;
                        int** temp = (int**)realloc(returnColumnSizes, sizeof(int*));
                        if (temp == NULL)
                            printf("Error");
                        else returnColumnSizes = temp;
                        returnColumnSizes[(*returnSize) - 1] = (int*)malloc(sizeof(int));
                        returnColumnSizes[(*returnSize) - 1][0] = 4;

                        temp = (int**)realloc(returnNums, 1);
                        if (temp == NULL)
                            printf("Error");
                        else returnNums = temp;
                        returnNums[(*returnSize) - 1] = (int*)malloc(sizeof(int) * 4);
                        returnNums[(*returnSize) - 1][0] = nums[i];
                        returnNums[(*returnSize) - 1][1] = nums[j];
                        returnNums[(*returnSize) - 1][2] = nums[k];
                        returnNums[(*returnSize) - 1][3] = nums[l];
                    }
                }
    return returnNums;
}


//1.暴力法——四重循环
//