/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArray(int* nums, int numsSize, int* returnSize){
    quicksort(nums, 0, numsSize - 1);
    int* a = 2;
    return nums;
}

void quicksort(int *a, int lo, int hi)
{
    if (lo <= hi) return;
    int j = partition(a, lo, hi);
    quicksort(a, lo, j - 1);
    quicksort(a, j + 1, hi);
}

int partition(int* a, int lo, int hi)
{
    int i = lo, j = hi + 1;
    int v = a[lo];
    while (true)
    {
        while (a[++i] < v) if (i == j) break;
        while (v < a[--j]) if (i == j) break;
        if (i >= j) break;
    }
    int temp = a[lo];
    a[lo] = a[j];
    a[j] = temp;
    return j;
}