#define INT_MAX (int)pow(2,31)-1
#define INT_MIN (int)pow(2,31)*(-1) - 1
//#define INT_MIN -2147483647
int myAtoi(char * str){
    char* s = str;
    int count = 0;
    int flag = 1;
    while(*s)
    {
        if (*str != ' ' && *str != '-' && (*str < '0' || *str > '9')) return 0;
        if (*s == ' ' && (*(s+1) != ' ' && *(s+1) != '-' && *(s+1) != "+")) return 0;
        if(*s == " ")
        {
            s = s + 1;
            continue;
        }
        if (*s == '-')
        {
            s = s + 1;
            count = -1 * (int)(*s - '0');
            s = s + 1;
            flag = 0;
            continue;
        }
        if (flag)
        {
        	if ( *s >= '0' && *s <= '9' )
	        {
                if (count > INT_MAX / 10) return INT_MAX;
	            count = 10 * count + (int)(*s - '0');
	        }
	        if (*s >= '0' && *s <= '9' && ( *(s+1) < '0' || *(s+1) > '9'))
	            break;
	        s = s + 1;
		}
        else
        {
        	if ( *s >= '0' && *s <= '9' )
	        {
                if (count < INT_MIN / 10) return INT_MIN;
	            count = 10 * count - (int)(*s - '0');
	        }
	        if (*s >= '0' && *s <= '9' && ( *(s+1) < '0' || *(s+1) > '9'))
	            break;
	        s = s + 1;
		}
    }
    return count;
}