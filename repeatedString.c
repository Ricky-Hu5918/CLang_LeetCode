#include <stdlib.h>
#include <stdio.h>
//字符串s无限重复，从无限重复的字符串的前n个字符中查找字符a出现的次数
int main(void)
{
    char *s = "udjlitpopjhipmwgvggazhuzvcmzhulowmveqyktlakdufzcefrxufssqdslyfuiahtzjjdeaxqeiarcjpponoclynbtraaawrps";
    long n = 872514961806;  //69801196944
    int len;
    int i = 0;
    long result=0;
    char *p;

    for (p = s; *p != '\0'; p++)
        len += 1;

    printf("len = %d \n", len);
    if (len == 1)
    {
        if (s[0] == 'a')
            return n;
        else {
            return 0;
        }
    }
        
    // if (!strchr(s, 'a'))
    //     return 0;
    
    //find the number of occurences of a in string s
    for (i = 0; i<len; i++)
    {
        //printf("%c \n", s[i]);
        if (s[i] == 'a')
        {
            printf("== \n");
            result += 1;
        }
            
    }
    printf("result 1 = %ld \n", result);

    //check the number of repeats of string s in number n
    result *= (n/len);
    printf("result 2 = %ld \n", result);
    printf("n//f = %ld %d \n", (n / len), (n%len));
    //n%len等于字符串s最后剩余的长度，看a在其中重复出现几次
    for (i = 0; i < (n % len); i++)
    {
        if (s[i] == 'a')
            result += 1;
    }

    printf("resutl = %ld \n", result);
    return 0;
}