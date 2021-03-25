//
//  main.c
//  007_Reverse_Integer
//
//  Created by Ricky Who on 2020/10/23.
//

/*
 Given a 32-bit signed integer, reverse digits of an integer.

 Note:
 Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

 
 Example 1:
 Input: x = 123
 Output: 321
 
 Example 2:
 Input: x = -123
 Output: -321
 
 Example 3:
 Input: x = 120
 Output: 21
 
 Example 4:
 Input: x = 0
 Output: 0
  
 Constraints:
 -231 <= x <= 231 - 1
 */

#include <stdio.h>
#include <math.h>

int reverse(int x);
int main(int argc, const char * argv[])
{
    // insert code here...
    double x = -1534236468;  //1534236469
    printf("%d \n", reverse(x));
    return 0;
}

//need to address the issue of data overflow after reverse
int reverse(int x)
{
    double reNum=0;
    int nums[10], i=0, idx=0;
    
    //take out every single number from an unsigned integer
    while (x != 0)
    {
        nums[i] = x%10;
        i++;
        x /= 10;
    }

    //reverse data
    int j;
    idx = i-1;
    for (j=0;j<i;j++)
    {
        reNum += nums[j] * (pow(10,idx));
        idx--;
    }

    //address data overflow issue
    if ((reNum >= (pow(2, 31))) || (reNum < (pow(-2, 31))))
    {
        return 0;
    }
    else
    {
        return reNum;
    }

}
