/*
 * @Descripttion: 
 * @version: 
 * @Author: LeetCode-Solution
 * @Date: 2021-01-02 21:38:36
 * @LastEditors: 32353
 * @LastEditTime: 2021-01-02 21:38:36
 */
void swap(int** a, int** b) {
    int* tmp = *a;
    *a = *b, *b = tmp;
}

int cmp(int* a, int* b) {
    return a[0] == b[0] ? a[1] - b[1] : a[0] - b[0];
}

struct Heap {
    int** heap;
    int size;
    int capacity;
};

void init(struct Heap* obj, int capacity) {
    obj->size = 0;
    obj->heap = NULL;
    obj->capacity = capacity;
    obj->heap = malloc(sizeof(int*) * (obj->capacity + 1));
    for (int i = 1; i <= obj->capacity; i++) {
        obj->heap[i] = malloc(sizeof(int) * 2);
    }
}

void setFree(struct Heap* obj) {
    for (int i = 1; i <= obj->capacity; i++) {
        free(obj->heap[i]);
    }
    free(obj->heap);
    free(obj);
}

void push(struct Heap* obj, int num0, int num1) {
    int sub1 = ++(obj->size), sub2 = sub1 >> 1;
    (obj->heap[sub1])[0] = num0, (obj->heap[sub1])[1] = num1;
    while (sub2 > 0 && cmp(obj->heap[sub2], obj->heap[sub1]) < 0) {
        swap(&(obj->heap[sub1]), &(obj->heap[sub2]));
        sub1 = sub2, sub2 = sub1 >> 1;
    }
}

void pop(struct Heap* obj) {
    int sub = 1;
    swap(&(obj->heap[sub]), &(obj->heap[(obj->size)--]));
    while (sub <= obj->size) {
        int sub1 = sub << 1, sub2 = sub << 1 | 1;
        int maxSub = sub;
        if (sub1 <= obj->size && cmp(obj->heap[maxSub], obj->heap[sub1]) < 0) {
            maxSub = sub1;
        }
        if (sub2 <= obj->size && cmp(obj->heap[maxSub], obj->heap[sub2]) < 0) {
            maxSub = sub2;
        }
        if (sub == maxSub) {
            break;
        }
        swap(&(obj->heap[sub]), &(obj->heap[maxSub]));
        sub = maxSub;
    }
}

int* top(struct Heap* obj) {
    return obj->heap[1];
}

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    struct Heap* q = malloc(sizeof(struct Heap));
    init(q, numsSize);
    for (int i = 0; i < k; i++) {
        push(q, nums[i], i);
    }
    int* ans = malloc(sizeof(int) * (numsSize - k + 1));
    *returnSize = 0;
    ans[(*returnSize)++] = top(q)[0];

    for (int i = k; i < numsSize; ++i) {
        push(q, nums[i], i);
        while (top(q)[1] <= i - k) {
            pop(q);
        }
        ans[(*returnSize)++] = top(q)[0];
    }
    setFree(q);
    return ans;
}

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/sliding-window-maximum/solution/hua-dong-chuang-kou-zui-da-zhi-by-leetco-ki6m/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

// 执行用时：1072 ms, 在所有 C 提交中击败了5.23%的用户
// 内存消耗：122.9 MB, 在所有 C 提交中击败了5.11%的用户