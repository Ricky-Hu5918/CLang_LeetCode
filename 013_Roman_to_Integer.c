/*
13. Roman to Integer
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.

Example 1:
Input: s = "III"
Output: 3

Example 2:
Input: s = "IV"
Output: 4

Example 3:
Input: s = "IX"
Output: 9

Example 4:
Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.

Example 5:
Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

Constraints:
1 <= s.length <= 15
s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
It is guaranteed that s is a valid roman numeral in the range [1, 3999].
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int romanToInt(char * s);
int romanToInt2(char *s);
int romanToInt3(char *s);

int main(void)
{
    int res1 = 0, res2 = 0, res3 = 0;
    char *s1 = "IXIXIX";
    char *s2 = "LVIII";
    char *s3 = "MCMXCIV";

    res1 = romanToInt(s1);
    res2 = romanToInt(s2);
    res3 = romanToInt(s3);
    printf("res1 = %d, res2 = %d, res3 = %d \n", res1, res2, res3);  //9, 58, 1994

    res1 = romanToInt2(s1);
    res2 = romanToInt2(s2);
    res3 = romanToInt2(s3);
    printf("res1 = %d, res2 = %d, res3 = %d \n", res1, res2, res3);  //9, 58, 1994

    res1 = romanToInt3(s1);
    res2 = romanToInt3(s2);
    res3 = romanToInt3(s3);
    printf("res1 = %d, res2 = %d, res3 = %d \n", res1, res2, res3);  //9, 58, 1994

    return 0;
}

int romanToInt(char * s)
{
    int i, result=0;
    int len = strlen(s);
    printf("len = %d \n", len);

    for (i = 0; i < len; i++)
    {
        switch (s[i])
        {
        case 'I':
            if (s[i+1] == 'V')
            {
                result += 4;
                i += 1;
            }
            else if (s[i+1] == 'X')
            {
                result += 9;
                i += 1;
            }
            else
                result += 1;
            break;
        case 'V':
            result += 5;
            break;
        case 'X':
            if (s[i+1] == 'L')
            {
                result += 40;
                i += 1;
            }
            else if (s[i+1] == 'C')
            {
                result += 90;
                i += 1;
            }
            else
                result += 10;
            break;
        case 'L':
            result += 50;
            break;
        case 'C':
            if (s[i+1] == 'D')
            {
                result += 400;
                i += 1;
            }
            else if (s[i+1] == 'M')
            {
                result += 900;
                i += 1;
            }
            else
                result += 100;
            break;
        case 'D':
            result += 500;
            break;
        case 'M':
            result += 1000;
            break;
        default:
            break;
        }
    }

    return result;
}

//try to optimize 2
int romanToInt2(char * s)
{
    int i, result=0;
    int flag_I = 0, flag_X = 0, flag_C = 0;
    int len = strlen(s);
    printf("len = %d \n", len);

    for (i = 0; i < len; i++)
    {
        switch (s[i])
        {
        case 'I':
            flag_I = 1;
            result += 1;
            break;
        case 'V':
            result += 5;
            if (flag_I == 1)
            {
                result -= 2*flag_I;
                flag_I = 0;
            }           
            break;
        case 'X':
            flag_X = 10;
            result += 10;
            if (flag_I == 1)
            {
                result -= 2*flag_I;
                flag_I = 0;                
            }
            break;
        case 'L':
            result += 50;
            if (flag_X == 10)
            {
                result -= 2*flag_X;
                flag_X = 0;
            }
            break;
        case 'C':
            flag_C = 100;
            result += 100;
            if (flag_X == 10)
            {
                result -= 2*flag_X;
                flag_X = 0;                
            }
            break;
        case 'D':
            result += 500;
            if (flag_C == 100)
            {               
                result -= 2*flag_C;
                flag_C = 0;
            }
            break;
        case 'M':
            result += 1000;
            if (flag_C == 100)
            {               
                result -= 2*flag_C;
                flag_C = 0;
            }
            break;
        default:
            break;
        }
    }

    return result;
}

//try to optimize 3
int getValue(char s)
{
    switch (s)
    {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    } 
}

//prenum < num则减，否则加
int romanToInt3(char *s)
{
    int prenum = 0, num = 0;
    int result = 0;
    int i;

    prenum = getValue(s[0]);
    for (i = 1; i < strlen(s); i++)
    {
        num = getValue(s[i]);
        if (prenum < num)
            result -= prenum;
        else
            result += prenum;

        prenum = num;
    }
    result += prenum; //最后剩余一个要加上

    return result;
}