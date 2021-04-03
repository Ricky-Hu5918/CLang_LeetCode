/*
Given a sorted array nums, remove the duplicates in-place such that each element appears only once and returns the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Clarification:

Confused why the returned value is an integer but your answer is an array?

Note that the input array is passed in by reference, which means a modification to the input array will be known to the caller as well.

Internally you can think of this:

// nums is passed in by reference. (i.e., without making a copy)
int len = removeDuplicates(nums);

// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
 
Example 1:
Input: nums = [1,1,2]
Output: 2, nums = [1,2]
Explanation: Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the returned length.

Example 2:
Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4]
Explanation: Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively. It doesn't matter what values are set beyond the returned length.

Constraints:
0 <= nums.length <= 3 * 104
-104 <= nums[i] <= 104
nums is sorted in ascending order.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int removeDuplicates(int *nums, int numsSize);
int removeDuplicates2(int *nums, int numsSize);

int main(void)
{
    int nums[] = {0,0,1,1,1,2,2,3,3,4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int len;
    //printf("numsSize = %d \n", numsSize);
    
    len = removeDuplicates2(nums, numsSize);
    printf("len 2 = %d \n", len);
    // len = removeDuplicates(nums, numsSize);
    // printf("len = %d \n", len);

    return 0;
}

//arry version
int removeDuplicates(int *nums, int numsSize)
{
    int i=0, j=1, count=0;

    if ((numsSize == 0) || (numsSize == 1))
        return numsSize;

    while (j <= numsSize-1)
    {
        if (nums[i] == nums[j])
        {
            j++;
        }
        else
        {
            if (j > (i+1))
            {
                nums[i+1] = nums[j];
            }
            i++;
            j++;
            count += 1;
        }
    }

    return (count+1);
}

//pointer version
int removeDuplicates2(int* nums, int numsSize)
{
    int count = 0;
    int *pre, *cur, *tail;

    if ((numsSize == 0) || (numsSize == 1))
    {
        return numsSize;
    }

    pre = nums;
    cur = nums + 1;
    tail = nums + (numsSize-1);

    while (cur <= tail)
    {
        if (*pre == *cur)
        {
            cur++;
        }
        else 
        {        
            if (cur > pre+1)
            {
                *(pre+1) = *cur;
            }

            pre++;
            cur++;
            count += 1;
        }
    }

    return (count+1);

}