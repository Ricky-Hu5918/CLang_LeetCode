/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 
Constraints:
0 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lower-case English letters.
*/

/*
conside strs[0] as a benchmark, using strncmp to find the number of common prefix, then save the number 
into arry, then find the minimum value in arry, and using strncpy to copy the minimum common prefix to 
the deststr, and return the deststr
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *longestCommonPrefix(char **strs, int strsSize);
int min(int *arry, int len);

int main(void)
{
    char *strs[] = {"flower", "flow", "flight", "fucky"};
    //char *strs[] = { "dog", "racecar", "car" };
    //char *strs[] = { "pig", "", "dog" };
    //char *strs[] = {};
    char *common_prefix;
    int i, j;
    int len = sizeof(strs) / sizeof(strs[0]);
    

    common_prefix = longestCommonPrefix(strs, len);
    printf("common prefix = %s \n", common_prefix);

    return 0;
}

char *longestCommonPrefix(char **strs, int strsSize)
{
    int common[200]={};
    int i, j, k = 0;
    int maxLen, len, cmpLen;
    char *pre_str[200]={};
    
    if ((strsSize == 0) || (strs == NULL) || (strlen(strs[0]) == 0))
        return "";

    for (i = 1; i < strsSize; i++)
    {
        
        len = strlen(strs[0]) > strlen(strs[i]) ? strlen(strs[i]) : strlen(strs[0]);
        //printf("len = %d \n", len);
        if (len == 0)
            return "";

        for (j = len; j > 0; j--)
        {
            cmpLen = strncmp(strs[0], strs[i], j);
            //printf("cmpLen = %d j = %d \n", cmpLen,  j);
            if (cmpLen == 0)  //cmplen==0 means that the two string have the same number of j characters
            {
                common[k] = j;
                k++;
                break;
            }

            if ((cmpLen != 0) && (j == 1))
            {
                return "";
            }
        }        
    }

    maxLen = min(common, k);
    // printf("maxlen = %d \n", maxLen);

    strncpy(pre_str, strs[0], maxLen);
    // printf("pre_str = %s \n", pre_str);
    return pre_str;
}

//find the minimun number in a arry
int min(int *arry, int len)
{
    int minValue;
    int i;

    minValue = arry[0];
    for (i = 1; i < len; i++)
    {
        minValue = arry[i] < minValue ? arry[i] : minValue;
    }

    return minValue;
}
