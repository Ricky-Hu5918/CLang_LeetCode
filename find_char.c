/*
查找source字符串中匹配chars字符串中任何字符的第一个字符
*/
#include <stdio.h>
#include <stdlib.h>

char *find_char(char const *source, char const *chars);

int main(void)
{
    char *source = "abcdef";
    char *chars = "xrcqef";
    char *ret;

    ret = find_char(source, chars);
    printf("The first char we found is %c \n", *ret);

    return 0;
}

char *find_char(char const *source, char const *chars)
{
    if ((source == NULL) || (chars == NULL))
    {
        return NULL;
    }

    char *s = source;
    char *c = chars;

    while (*s++ != '\0')
    {
        while (*c++ != '\0')
        {
            if (*s == *c)
            {
                return s;
            }
        }
    }

    return NULL;
}