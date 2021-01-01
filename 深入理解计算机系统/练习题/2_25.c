#include <stdio.h>
/*WARNING : This is bugger code*/
float sum_elements(float a[], unsigned length) {
    int i;
    float result = 0;

    for (i = 0; i <= length - 1; i++)
    {
        result += a[i];
    }
    return result;
}

int main()
{
    float a[1];
    a[0] = 9;
    printf("sum_elements(a, 0)=");
    printf("%f\n", sum_elements(a, 0));
    return 0;
}