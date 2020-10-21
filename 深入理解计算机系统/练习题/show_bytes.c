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
    const char* s = "abcdef";
    show_bytes((byte_pointer)s, strlen(s));
    
    system("pause");
    return 0;
}