void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int i = m;
    if(m + n == ASize)
    {
        for(int i = m; i < m + n; i++)
        {
            A[i] = B[i-m];
        }
        shellSort (A, m+n);
    }
    else;
}

void shellSort(int *a, int ASize)
{
    int h = 1;
    while(h < ASize / 3) h =3 * h + 1;
    while(h >= 1)
    {
        for(int i = h; i < ASize; i++)
        {
            for(int j = i; j-h >= 0 && a[j] < a[j-h]; j = j - h)
            {
                int temp = a[j];
                a[j] = a[j-h];
                a[j-h] = temp;
            }
        }
        h = h / 3;
    }
}
