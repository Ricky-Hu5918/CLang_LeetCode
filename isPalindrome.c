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

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define true 1
#define false 0

//two pointers method
int isPalindrome(char *s)
{
    int i = 0, j = (strlen(s) - 1);

    while (i < j)
    {
        if (!isalnum(s[i]))
        {
            i++;
            continue;
        }

        if (!isalnum(s[j]))
        {
            j--;
            continue;
        }

        if (tolower(s[i]) != tolower(s[j]))
        {
            return false;
        }
        else
        {
            i++;
            j--;
        }
    }
    return true;
}

int main(void)
{
    char *s = "A man, a plan, a canal: Panama";
    int rt;

    rt = isPalindrome(s);
    printf("rt = %d \n", rt);

    return 0;
}