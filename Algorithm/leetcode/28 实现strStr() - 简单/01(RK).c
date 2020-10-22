int strStr(char * haystack, char * needle){
    if (*needle == '\0') return 0;
    int len1 = 0;
    int len2 = 0;
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
    //printf("%d %d \n", len1, len2);
    ch1 = haystack;
    ch2 = needle;
    int ch2Hash = hashcode(ch2, len2);
    for (int i = 0; i <= len1 - len2; i++)
    {
        if (hashcode (ch1 + i, len2) == ch2Hash)
        {
            int j = i; 
            while (j < i + len2)
            {
                if (*(ch1 + j) != *(ch2 + (j - i)))
                    break;
                j++;
            }
            if (j == i + len2) return i;
        }
    }
    return -1;
}

int hashcode(char* str, int len)
{
    char* ch = str;
    int hashcode = 0;
    while (len)
    {
        hashcode += (int)(*ch - 'a');
        ch++;
        len--;
    }
    return hashcode;
}