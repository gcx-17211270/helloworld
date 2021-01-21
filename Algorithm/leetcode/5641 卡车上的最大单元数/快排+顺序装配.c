/*
 * @Descripttion: 
 * @version: 
 * @Author: 32353
 * @Date: 2021-01-03 11:30:39
 * @LastEditors: 32353
 * @LastEditTime: 2021-01-03 11:30:48
 */
void quickSort(int** boxTypes, int* boxTypesColSize, int lo, int hi);
int partition(int** boxTpyes, int* boxTYpesColSize, int lo, int hi);

int maximumUnits(int** boxTypes, int boxTypesSize, int* boxTypesColSize, int truckSize){
    quickSort(boxTypes, boxTypesColSize, 0, truckSize - 1);
    int truckSum = truckSize;
    int maxUnits = 0, i = 0;
    while (truckSum > 0)
    {
        if (i >= boxTypesSize) break;
        int truckLeft = truckSum - boxTypes[i][0] > 0 ? boxTypes[i][0] : truckSum;
        maxUnits += truckLeft * boxTypes[i][1];     //默认了boxTypesColSize的内容是2，所以直接使用了0和1，没有用它表示，对于代码可能的扩展性有影响
        i++;
        truckSum -= boxTypes[i][0];
    }
    return maxUnits;
}

void quickSort(int** boxTypes, int* boxTypesColSize, int lo, int hi)
{
    if (lo >= hi) return;
    int j = partition(boxTypes, boxTypesColSize, lo, hi);
    quickSort(boxTypes, boxTypesColSize, lo, j - 1);
    quickSort(boxTypes, boxTypesColSize, j + 1, hi);
}

int partition(int** boxTypes, int* boxTypesColSize, int lo, int hi)
{
    int* temp2Units = (int*)malloc(sizeof(int) * boxTypesColSize[0]);
    temp2Units[0] = boxTypes[lo][0];
    temp2Units[1] = boxTypes[lo][1];
    int i = lo, j = hi + 1;
    while(1)
    {
        while(boxTypes[++i][1] < temp2Units[1]) if (i == hi) break;
        while(boxTypes[--j][1] > temp2Units[1]) if (j == lo) break;
        if (i >= j) break;
        int* temp = (int*)malloc(sizeof(int) * boxTypesColSize[0]);
        temp[0] = boxTypes[i][0]; temp[1] = boxTypes[i][1];
        boxTypes[i][0] = boxTypes[j][0]; boxTypes[i][1] = boxTypes[j][1];
        boxTypes[j][0] = temp[0]; boxTypes[j][1] = temp[1];
        free(temp);
    }
    boxTypes[lo][0] = boxTypes[j][0]; boxTypes[lo][1] = boxTypes[j][1];
    boxTypes[j][0] = temp2Units[0]; boxTypes[j][1] = temp2Units[1];
    free(temp2Units);
    return j;
}

执行结果：

=================================================================
==42==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x603000000028 at pc 0x5640d2d37927 bp 0x7ffc7bc65fa0 sp 0x7ffc7bc65f90
READ of size 8 at 0x603000000028 thread T0
    #4 0x7fc0a6ea60b2 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x270b2)
0x603000000028 is located 0 bytes to the right of 24-byte region [0x603000000010,0x603000000028)
allocated by thread T0 here:
    #0 0x7fc0a7aebbc8 in malloc (/lib/x86_64-linux-gnu/libasan.so.5+0x10dbc8)
    #3 0x7fc0a6ea60b2 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x270b2)
Shadow bytes around the buggy address:
  0x0c067fff7fb0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c067fff7fc0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c067fff7fd0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c067fff7fe0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c067fff7ff0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
=>0x0c067fff8000: fa fa 00 00 00[fa]fa fa fa fa fa fa fa fa fa fa
  0x0c067fff8010: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c067fff8020: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c067fff8030: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c067fff8040: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c067fff8050: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
Shadow byte legend (one shadow byte represents 8 application bytes):
  Addressable:           00
  Partially addressable: 01 02 03 04 05 06 07 
  Heap left redzone:       fa
  Freed heap region:       fd
  Stack left redzone:      f1
  Stack mid redzone:       f2
  Stack right redzone:     f3
  Stack after return:      f5
  Stack use after scope:   f8
  Global redzone:          f9
  Global init order:       f6
  Poisoned by user:        f7
  Container overflow:      fc
  Array cookie:            ac
  Intra object redzone:    bb
  ASan internal:           fe
  Left alloca redzone:     ca
  Right alloca redzone:    cb
  Shadow gap:              cc
==42==ABORTING