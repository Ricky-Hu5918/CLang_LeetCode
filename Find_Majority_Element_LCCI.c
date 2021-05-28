/*
A majority element is an element that makes up more than half of the items in an array. 
Given a positive integers array, find the majority element. 
If there is no majority element, return -1. Do this in O(N) time and O(1) space.

Example 1:
Input: [1,2,5,9,5,9,5,5,5]
Output: 5
 
Example 2:
Input: [3,2]
Output: -1
 
Example 3:
Input: [2,2,1,1,1,2,2]
Output: 2
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    /* data */
    int curNum;
    int totalCnt;
} MajorityHash;

int majorityElement(int *nums, int numsSize)
{
    int hashNum = 0;
    int i, j;
    int majorityEle = -1;

    MajorityHash *hash = (MajorityHash *)calloc(sizeof(MajorityHash), numsSize);
    if (hash == NULL)
    {
        printf("hash calloc failed.\n");
        return 0;
    }

    //create hash table
    for (i = 0; i < numsSize; i++)
    {
        int hashFind = 0;

        //find element in hash table
        for (j = 0; j < hashNum; j++)
        {
            if (hash[j].curNum == nums[i])
            {
                hash[j].totalCnt += 1;
                hashFind = 1;
                break;
            }
        }

        //current element does not exist in hash table, then add it
        if (hashFind == 0)
        {
            hash[hashNum].curNum = nums[i];
            hash[hashNum].totalCnt += 1;
            hashNum += 1;
        }
    }

    //return the majority element
    for (i = 0; i < hashNum; i++)
    {
        if (hash[i].totalCnt > (numsSize / 2))
        {
            majorityEle = hash[i].curNum;
        }
    }

    if (hash != NULL)
    {
        free(hash);
        hash = NULL;
    }

    return majorityEle;
}

int main(void)
{
    int nums[] = {1, 2, 5, 9, 5, 9, 5, 5, 5};
    int majorityEle;
    int numsSize = (sizeof(nums) / sizeof(nums[0]));

    majorityEle = majorityElement(nums, numsSize);
    printf("Majority element = %d \n", majorityEle);

    return 0;
}