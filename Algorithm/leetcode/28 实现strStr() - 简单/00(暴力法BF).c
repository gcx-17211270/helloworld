int strStr(char * haystack, char * needle){
    char* ch1 = haystack;
    char* ch2 = needle;
    int num = 0;
    while(*ch1 != '\0')
    {
        int temp = 0;
        while (*(ch1+temp) == *ch2)
        {
            temp++;
            ch2++;
            if (*ch2 == '\0')
                return num;
            if (*(ch1+temp) == '\0')
                break;
        }
        num++;
        ch1++;
        ch2 = needle;
    }
    return *ch2 == '\0' ? 0:-1;
}