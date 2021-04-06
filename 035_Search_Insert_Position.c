/*
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2

Example 2:
Input: nums = [1,3,5,6], target = 2
Output: 1

Example 3:
Input: nums = [1,3,5,6], target = 7
Output: 4

Example 4:
Input: nums = [1,3,5,6], target = 0
Output: 0

Example 5:
Input: nums = [1], target = 0
Output: 0

Constraints:
1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int searchInsert(int *nums, int numsSize, int target);

int main(void)
{
    int nums[] = {1, 3, 5, 9};
    int target = 4;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int idx=-1;

    idx = searchInsert(nums, numsSize, target);
    printf("idx = %d \n", idx);

    return 0;
}


int searchInsert(int* nums, int numsSize, int target){
    int i, idx=-1;

    if (target<nums[0])
        return 0;
    
    if (numsSize == 1)
    {
        return (target <= nums[0]) ? 0 : 1;
    }

    if (target>nums[numsSize-1])
        return numsSize;

    for (i=0; i<(numsSize-1); i++)
    {
        if (nums[i] == target)
        {
            idx = i;
            break;
        }
            
        if ((nums[i] < target) && (nums[i+1]>=target))
        {
            idx = (i+1);
            break;
        }            
    }
    
    return idx;
}