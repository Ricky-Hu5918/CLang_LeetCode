/*
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Clarification:
What should we return when needle is an empty string? This is a great question to ask during an interview.
For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

Example 1:
Input: haystack = "hello", needle = "ll"
Output: 2

Example 2:
Input: haystack = "aaaaa", needle = "bba"
Output: -1

Example 3:
Input: haystack = "", needle = ""
Output: 0

Constraints:
0 <= haystack.length, needle.length <= 5 * 104
haystack and needle consist of only lower-case English characters.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_strStr(char *haystack, char *needle);

int main(void)
{
    char haystack[] = "hlliolllllllooot";
    char needel[] = "lllo";
    int idx;

    idx = my_strStr(haystack, needel);
    printf("idx = %d \n", idx);

    return 0;
}

//should use KMP algorithm, but I can't
int my_strStr(char * haystack, char * needle){
    int len_haystack = strlen(haystack);
    int len_needle = strlen(needle);
    int i=0, j=0;
    int flag=0; //to indicate if we find the same character
    int idx = -1;
    
    if (len_needle == 0)
        return 0;
    if ((len_haystack == 0) && (len_needle > len_haystack))
        return -1;

    while ((i <= (len_haystack-1)) || (j <= (len_needle - 1)))
    {
        if (haystack[i] != needle[j])
        {
            //printf("!= %d %d %d \n", flag, i, j);
            if (flag == 1)  //the last character is the same but the current character is not
            {
                flag = 0;  //clear flag
                idx = -1;  //clear idx

                //have found j numbers of same character
                //step back to numbers of same characters(i and j have to step back to the same number)
                i -= (j-1);  //step back to (j-1)
                j = 0;
            }
            else
                i++;
        }
        else{
            //printf("== %d %d %d \n", flag, i, j);
            if (flag == 0)
            {
                flag = 1;
                idx = i;
            }

            //find all same characters
            if (j == (len_needle-1))
                return idx;

            i++;
            j++;
        }
    }

    return -1;
}