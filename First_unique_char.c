/*
Given a string s, return the first non-repeating character in it and return its index. 
If it does not exist, return -1.

Example 1:
Input: s = "leetcode"
Output: 0

Example 2:
Input: s = "loveleetcode"
Output: 2

Example 3:
Input: s = "aabb"
Output: -1
 
Constraints:
1 <= s.length <= 105
s consists of only lowercase English letters.
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int firstUniqChar1(char *s); //two pointers method
int firstUniqChar2(char *s); //hash table method

int main(void)
{
    char *s = "lovelveetcode";
    int rtIdx;

    rtIdx = firstUniqChar1(s);
    printf("rtIdx-1 = %d\n", rtIdx);

    rtIdx = firstUniqChar2(s);
    printf("rtIdx-2 = %d\n", rtIdx);

    return 0;
}

//two pointers, cur is the base, pos will keep moving from head to tail to check if there is a repeating char
int firstUniqChar1(char *s)
{
    char *cur = s;
    int idx_cur = 0, idx_pos = 0;

    while (*cur != '\0')
    {
        char *pos = s;
        while (*pos != '\0')
        {
            if ((*cur == *pos) && (idx_cur != idx_pos))
            {
                idx_pos = 0;
                break;
            }
            pos++;
            idx_pos += 1;
        }

        if (idx_pos != 0)
        {
            return idx_cur;
        }

        cur++;
        idx_cur += 1;
    }

    return -1;
}

//hasd tabel
typedef struct
{
    char curEle;
    int idx;
    int occurTimes;
} firstUniqChar;

int firstUniqChar2(char *s)
{
    int hashNum = 0;
    int rtIdx = -1;
    int i, j, len = strlen(s);
    firstUniqChar *hash = (firstUniqChar *)calloc(sizeof(firstUniqChar), len);
    if (hash == NULL)
    {
        printf("hash calloc failed. \n");
        return 0;
    }

    //build the hash table and count the occur times
    for (i = 0; i < len; i++)
    {
        int hashFind = 0;
        for (j = 0; j < hashNum; j++)
        {
            if (hash[j].curEle == s[i])
            {
                hash[j].idx = i;
                hash[j].occurTimes += 1;
                hashFind = 1;
            }
        }

        if (hashFind == 0)
        {
            hash[hashNum].curEle = s[i];
            hash[hashNum].idx = i;
            hash[hashNum].occurTimes += 1;
            hashNum += 1;
        }
    }

    //return the index of the first element who occurs only once
    for (i = 0; i < hashNum; i++)
    {
        if (hash[i].occurTimes == 1)
        {
            rtIdx = hash[i].idx;
            break;
        }
    }

    if (hash != NULL)
    {
        free(hash);
        hash = NULL;
    }

    return rtIdx;
}