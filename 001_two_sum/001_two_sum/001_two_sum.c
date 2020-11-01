//
//  main.c
//  001_two_sum
//
//  Created by Ricky Who on 2020/10/23.
//

/*
 Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

 You may assume that each input would have exactly one solution, and you may not use the same element twice.

 You can return the answer in any order.

 Example 1:

 Input: nums = [2,7,11,15], target = 9
 Output: [0,1]
 Output: Because nums[0] + nums[1] == 9, we return [0, 1].
 Example 2:

 Input: nums = [3,2,4], target = 6
 Output: [1,2]
 Example 3:

 Input: nums = [3,3], target = 6
 Output: [0,1]
 
 Constraints:
 2 <= nums.length <= 105
 -109 <= nums[i] <= 109
 -109 <= target <= 109
 Only one valid answer exists.
 */


#include <stdio.h>
#include <stdlib.h>

int* twoSum1(int* nums, int numsSize, int target, int* returnSize);
int* twoSum2(int* nums, int numsSize, int target, int* returnSize);


int main(int argc, const char * argv[])
{
    int numsSize = 4;
    int nums[4] = {15, 7, 11, 2};
    int target = 9;
    
    int * returnSize;
    returnSize=(int*)malloc(sizeof(int)*2);
    
    twoSum1(nums, numsSize, target, returnSize);
    //twoSum2(nums, numsSize, target, returnSize);
    printf("%d %d\n", returnSize[0], returnSize[1]);
    
    return 0;
}

// #1
int* twoSum1(int* nums, int numsSize, int target, int* returnSize)
{
    int i,j;
    //*returnSize=2;
    for (i=0; i<numsSize-1; i++)
    {
        for (j=i+1; j<numsSize; j++)
        {
            if ((nums[i]+nums[j])==target)
            {
                //returnSize=(int*)malloc(sizeof(int)*2);
                returnSize[0]=i;
                returnSize[1]=j;
                return returnSize;
            }
        }
    }
    return returnSize;
}

// #2
int* twoSum2(int* nums, int numsSize, int target, int* returnSize)
{
    int i, j, tmp;
    //*returnSize=2;

    for (i=0; i<numsSize-1; i++)
    {
        tmp = target - nums[i];
        for (j=i+1; j<numsSize; j++)
        {
            if (tmp == nums[j])
            {
                //returnSize=(int*)malloc(sizeof(int)*2);
                returnSize[0]=i;
                returnSize[1]=j;
                break;
            }
        }
    }

    return returnSize;
}
