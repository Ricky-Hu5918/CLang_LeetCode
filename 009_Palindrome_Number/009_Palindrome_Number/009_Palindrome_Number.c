//
//  main.c
//  009_Palindrome_Number
//
//  Created by Ricky Who on 2020/10/26.
//
/*Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
 
 Follow up: Could you solve it without converting the integer to a string?

 Example 1:
 Input: x = 121
 Output: true
 
 Example 2:
 Input: x = -121
 Output: false
 Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
 
 Example 3:
 Input: x = 10
 Output: false
 Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 
 Example 4:
 Input: x = -101
 Output: false
 
 Constraints:
 -231 <= x <= 231 - 1
 */
#include <stdio.h>
#include <math.h>

typedef int bool;
#define true 1;
#define false 0;

bool isPalindrome(int x);

int main(int argc, const char * argv[]) {
    // insert code here...
    int x = 5225;
    printf("x is Palindrome, %d \n", isPalindrome(x));
    return 0;
}

bool isPalindrome(int x)
{
    int tmp = x;
    if (x<0)
    {
        return false;
    }
    
    int newX[20];
    int i=0, idx=0, j;

    while (x>0)
    {
        newX[i] = x%10;
        //printf("newx = %d \n", newX[i]);
        i++;
        x = x/10;
    }
    idx = i - 1;
    
    int reX = 0;
    for (j = 0; j < i; j++)
    {
        reX += newX[j] * (pow(10, idx));
        idx--;
    }
    //printf("reX = %d \n", reX);
    
    return reX==tmp?1:0;
}
