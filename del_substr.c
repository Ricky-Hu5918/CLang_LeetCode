/*
删除一个字符串的一部分
*/

#include <stdlib.h>
#include <stdio.h>

#define true 1
#define false 0

int del_substr(char *str, char const *substr);

int main(void)
{
    int ret;
    char str[] = "abcdefgh";
    //char *substr = "cde";  //test case 1
    char *substr = "fgh"; //test case 2
    //char *substr = "fph"; //test case 3

    ret = del_substr(str, substr);
    printf("delete substr success? = %d, str = %s \n", ret, str);

    return 0;
}

int del_substr(char *str, char const *substr)
{
    char *s_str = str;
    char *start;

    if (substr == NULL)
        return true;

    while (*s_str++ != '\0')
    {
        if (*s_str == *substr)
        {
            start = s_str;
            //printf("*start = %c\n", *start);
            while ((*substr != '\0') && (*(++s_str) == *(++substr)))
                ;
            break;
        }
    }

    //printf("*s_str = %c, *substr = %c \n", *s_str, *substr);
    //didn't find the whole substr
    if (*substr != '\0')
        return false;

    //found the whole substr, then replace the substr to delete it
    while (*s_str != '\0')
    {
        *start++ = *s_str++;
    }
    *start = '\0';
    printf("str = %s\n", str);

    return true;
}