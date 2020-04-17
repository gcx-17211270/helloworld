#include<stdio.h>
void merge(int* A, int ASize, int m, int* B, int BSize, int n);
void shellSort(int* A, int ASize);
int main()
{ 
	int a[6] = {4, 5, 6, 0, 0, 0};
	int b[3] = {1, 2, 3};
	for(int i = 0; i < 6; i++)
		printf("%d", a[i]);
	printf("\n\n");
	merge(a,6,3,b,3,3);
	return 0;
}


void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int i = m;
    for(int i = m; i < m + n; i++)
    {
        A[i] = B[i-m];
    }
    for(int i = 0; i < 6; i++)
		printf("%d", A[i]);
	printf("\n\n");
    shellSort (A, m+n);
    for(int i = 0; i < 6; i++)
		printf("%d", A[i]);
	printf("\n\n");
}

void shellSort(int *A, int ASize)
{
    int h = 1;
    while(h < ASize/3) h =3 * h + 1;
    while(h >= 1)
    {
        for(int i = h; i < ASize; i++)
        {
            for(int j = i; j > 0 && A[j] < A[j-h]; j = j - h)
            {
                int temp = A[j];
                A[j] = A[j-h];
                A[j-h] = temp;
            }
        }
        h = h / 3; 
    }
}
