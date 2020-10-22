//BM算法-坏字符

int strStr(char * haystack, char * needle){
    if (*needle == '\0') return 0;
    int len1 = 0, len2 = 0, num = 0;
    char* ch1 = haystack;
    char* ch2 = needle;
    while (*ch1 != '\0')
    {
        len1++;
        ch1++;
    }
    while (*ch2 != '\0')
    {
        len2++;
        ch2++;
    }
    ch1 = haystack;
    ch2 = needle;

    while(*ch1 != '\0' && *ch1 != *ch2)
    {
        ch1++;
        num++;
    }
    //printf("%d %d %d\n", len1, len2, num);
    if (*ch1 == '\0') return -1;
    while(*ch1 != '\0')
    {
        int false_num = -1;
        for (int i = len2 - 1; i >= 0; i--)
        {
            if (num + i > len1 - 1)
                return -1;
            if (*(ch1 + i) != (*(ch2 + i)))
            { 
                false_num = i;
                break;
            }
        }
        //printf("*ch1 = %c false_num = %d", *ch1, false_num);
        if (false_num == -1) return num;
        if (false_num == 0){ ch1++; num++;}

        for (int i = false_num - 1; i > 0; i--)
        {
            if (*(ch2 + i) == *(ch1 + false_num))
            {
                false_num -= i;
                break;
            }
        }        
        num += false_num;
        ch1 += false_num;
        //printf(" %d %d\n", false_num, num);
    }    
    return 0;
}