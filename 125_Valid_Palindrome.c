/*
Given a string s, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

Constraints:
1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef true
#define true 1
#endif

#ifndef false
#define false 0
#endif

int isPalindrome(char *s);
int isPalindrome2(char *s);

int main(void)
{
    char s1[] = "A man, a plan, a canal: Panama";
    char s2[] = "..,";
    char s3[] = "race a car";
    int result;

    result = isPalindrome(s1);
    printf("result = %d \n", result);  //true
    result = isPalindrome(s3);
    printf("result = %d \n", result);  //false
    result = isPalindrome(s2);
    printf("result = %d \n", result);  //true

    result = isPalindrome2(s1);
    printf("result = %d \n", result);  //true
    result = isPalindrome2(s3);
    printf("result = %d \n", result);  //false
    result = isPalindrome2(s2);
    printf("result = %d \n", result);  //true
}

int isPalindrome(char * s){
    int front, rear;
    int i, len, j=0;
    char *dest;

    len = strlen(s);
    if (len == 1)
        return true;
    
    dest = (char *)malloc((len+1)*sizeof(char));
    memset(dest, '\0', (len+1));

    for (i = 0; i < len; i++)
    {
        if (!isspace(s[i]) && !ispunct(s[i]))
        {
            dest[j] = tolower(s[i]);
            j++;
        }
    }
    //printf("%s \n", dest);
    len = strlen(dest);
    if (len == 0)
        return true;

    front = 0;
    rear = len - 1;
    while (front < rear)
    {
        if (dest[front] != dest[rear])
            break;
        
        front += 1;
        rear -= 1;
    }

    if (dest != NULL)
    {
        free(dest);
        dest = NULL;
    }

    return (front >= rear);
}

//pointer version
int isPalindrome2(char * s){
    char *front, *rear;
    int i, len, j=0;
    char *dest;

    len = strlen(s);
    if (len == 1)
        return true;
    
    dest = (char *)malloc((len+1)*sizeof(char));
    memset(dest, '\0', (len+1));

    for (i = 0; i < len; i++)
    {
        if (!isspace(s[i]) && !ispunct(s[i]))
        {
            dest[j] = tolower(s[i]);
            j++;
        }
    }
    //printf("%s \n", dest);
    len = strlen(dest);
    if (len == 0)
        return true;

    front = dest;
    rear = dest + (len - 1);
    while (front < rear)
    {
        if (*front != *rear)
            break;
        
        front++;
        rear--;
    }

    if (dest != NULL)
    {
        free(dest);
        dest = NULL;
    }

    return (front >= rear);
}