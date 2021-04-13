/*
Given a string, s, consisting of alphabets and digits, find the frequency of each digit in the given string.

Input Format
The first line contains a string,  num which is the given number.

Constraints
1<= len(num) <=1000
All the elements of num are made of english alphabets and digits.

Output Format
Print ten space-separated integers in a single line denoting the frequency of each digit from 0 to 9.
*/

#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

int main() {
    int occurs[10]={0};
    int i, j;
    char *s;

    s = (char *)malloc(1024*sizeof(char));
    if (s == NULL)
    {
        printf("memory malloc failed. \n");
        return -1;
    }
    memset(s, '\0', 1024);

    scanf("%s", s);
    s = (char *)realloc(s, (strlen(s)+1)*sizeof(char));
    if (s == NULL)
    {
        printf("memory remalloc failed. \n");
        return -1;
    }

    for (i = 0; i < strlen(s); i++)
    {
        if (isdigit(s[i]))
        {
            j = (s[i]-48);
            occurs[j] += 1;
            //printf("occ[%d]=%d \n", j, occurs[j]);
        }
    }
    
    //output result
    for (i = 0; i< 10; i++)
    {
        printf("%d ", occurs[i]);
    }
    
    if (s != NULL)
    {
        free(s);
        s = NULL;
    }
    return 0;
}
