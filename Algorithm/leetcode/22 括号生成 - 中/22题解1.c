/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void dfs(char** ans, char* a, int depth, int max_depth)
{
    int num1 = 0, k = 0, num2 = 0;
    if (depth == max_depth)
    {
        for (int i = 0; i < max_depth; i++)
            ans[k][i] = a[i];
        ans[k][max_depth] = '\0';
        k++;
        return;
    }
    if (num1 > num2)
    {
        num2++;
        a[depth] = ')';
        dfs(ans, a, depth + 1, max_depth);
        num2--;
    }
    if (num1 < max_depth / 2)
    {
        num1++;
        a[depth] = '(';
        dfs(ans, a, depth + 1, max_depth);
        num1--;
    }
    return;
}

char ** generateParenthesis(int n, int* returnSize){
    int a = 1, b = 1;
    for (int i = 2; i <= n; i++){
        b = a * (4 * i - 2) / (i + 1);
        a = b;
    }
    /*******************2020.04.13修改************************/
    *returnSize = (int*)malloc(sizeof(int));
    /*******************2020.04.13修改************************/
    *returnSize = a;
    char** ans = (char*)malloc(sizeof(char*) * a);
    char* k = (char*)malloc(sizeof(char) * (2 * n + 1));
    for (int i = 0; i < a; i++)
        ans[i] = (char*)malloc(sizeof(char) * (2 * n + 1));
    dfs(ans, k, 0, 2 * n);
    return ans;
}



/**
 * 报错信息             //2020.04.13 12:12 找到原因，returnSize未分配内存空间
 * =================================================================
==45==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x602000000017 at pc 0x00000040237d bp 0x7ffdd0171570 sp 0x7ffdd0171560
READ of size 1 at 0x602000000017 thread T0
    #3 0x7f3e2d5f282f in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2082f)
0x602000000017 is located 0 bytes to the right of 7-byte region [0x602000000010,0x602000000017)
allocated by thread T0 here:
    #0 0x7f3e2e60df88 in malloc (/usr/lib/x86_64-linux-gnu/libasan.so.5+0x10bf88)
    #3 0x7f3e2d5f282f in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2082f)
Shadow bytes around the buggy address:
  0x0c047fff7fb0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c047fff7fc0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c047fff7fd0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c047fff7fe0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c047fff7ff0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
=>0x0c047fff8000: fa fa[07]fa fa fa 07 fa fa fa 07 fa fa fa 07 fa
  0x0c047fff8010: fa fa 07 fa fa fa 04 fa fa fa fa fa fa fa fa fa
  0x0c047fff8020: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c047fff8030: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c047fff8040: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c047fff8050: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
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
==45==ABORTING
 * 
*/