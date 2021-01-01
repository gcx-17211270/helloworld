#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char* byte_pointer;

void show_bytes(byte_pointer start, int len)
{
    int i; 
    for (i = 0; i < len; i++)
        printf("%.2x", start[i]);
    printf("\n");
}

void show_int(int x)
{
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x)
{
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void* x)
{
    show_bytes((byte_pointer) &x, sizeof(void*));
}

void test_show_bytes(int val)
{
    int ival = val;
    float fval = (float)ival;
    int* pval = &ival;
    show_int(val);
    show_float(fval);
    show_pointer(pval);
}

int main(int argc, int* argv[])
{
    //12345=0x00003039
    //12345.0 = 0x4640E400
    //test_show_bytes(12345);
    //3510593 = 00359141
    //3510593.0 = 4a564504
    //test_show_bytes(3510593);
    // const char* s = "abcdef";
    // show_bytes((byte_pointer)s, strlen(s));

    //***************P43 2.2.3节补码表示 有符号数的不同表示*********************
    // short x = 12345;            
    // short mx = -x;

    // printf("x = 12345, mx = -x B2Tw(Binary to Two's-complement)\n");
    // printf("x = B2Tw([0011 0000 0011 1001])\n");
    // printf("mx = B2Tw([1100 1111 1100 0111])\n");
    // printf("This is the storage of x and mx in memory.\n");
    // show_bytes((byte_pointer) &x, sizeof(short));
    // show_bytes((byte_pointer) &mx, sizeof(short));
    //***************P43 2.2.3节补码表示 有符号数的不同表示*********************

    //***************P44 2.2.4节有符号数和无符号数之间的转换*********************
    short int v = -12345;
    unsigned short uv = (unsigned short) v;
    printf("short int v = -12345, unsigned short uv = (unsigned short) v\n");
    printf("The Number v and uv in mermory is as follows.\n");
    show_bytes((byte_pointer)&v, sizeof(short));
    show_bytes((byte_pointer)&uv, sizeof(short));

    printf("The Number will be transformed as:\n");
    printf("v = %d, uv = %u\n\n", v, uv);

    unsigned int u = 4294967295;
    int tu = (int)u;
    printf("unsigned int u = 4294967295;int tu = (int)u \n");
    printf("The Number u and tu in mermory is as follows.\n");
    show_bytes((byte_pointer)&u, sizeof(unsigned int));
    show_bytes((byte_pointer)&tu, sizeof(int));

    printf("The Number will be transformed as:\n");
    printf("u = %u, tu = %d\n\n", u, tu);
    //***************P44 2.2.4节有符号数和无符号数之间的转换*********************
    
    // system("pause");
    return 0;
}