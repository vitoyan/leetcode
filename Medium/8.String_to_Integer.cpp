int myAtoi(char* str) {
    long long num = 0;
    if(str != NULL && *str != '\0')
    {
        int minus = 1;
        
        while(*str == ' ')
            str++;
            
        if(*str == '+')
            str++;
        else if(*str == '-')
        {
            str++;
            minus = -1;
        }
        
        while(*str != '\0')
        {
            if(*str >= '0' && *str <= '9')
            {
                num = num * 10 + minus * (*str - '0');
                if((minus == 1 && num > 0x7fffffff))
                {
                    num = 0x7fffffff;
                    break;
                }
                if((minus == -1 && num < (signed int) 0x80000000))
                {
                    num = (signed int)0x80000000;
                    break;
                }
                str++;
            }
            else
            {
                break;
            }
        }
    }
    
    return (int)num;
}