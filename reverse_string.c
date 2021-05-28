/*
把参数字符串中的字符反向排列
*/

#include <stdio.h>
#include <stdlib.h>

void reverse_string(char *string);

int main(void)
{
    char string[] = "abcdefg";

    reverse_string(string);
    printf("after reverse, string = %s \n", string);
}

void reverse_string(char *string)
{
    char *start = string;
    if (string == NULL)
        return;

//把end指向最后一个字符
#if 0
    int len = sizeof(string) / sizeof(string[0]); //字符数组长度中包含'\0'，而strlen()中不包含'\0'
    //printf("%d, %d \n", sizeof(string), sizeof(string[0]));
    //printf("len = %d \n", len);
    char *end = &string[len - 2]; //把end指向最后一个字符
#else
    char *end;
    for (end = string; *end != '\0'; end++)
        ;
    end--;
#endif

    char tmp;
    while (start <= end)
    {
        tmp = *start;
        *start = *end;
        *end = tmp;
        start++;
        end--;
    }
}