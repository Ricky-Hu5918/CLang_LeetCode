/*
Print a pattern of numbers from 1 to n as shown below. Each of the numbers is separated by a single space.

                            4 4 4 4 4 4 4  
                            4 3 3 3 3 3 4   
                            4 3 2 2 2 3 4   
                            4 3 2 1 2 3 4   
                            4 3 2 2 2 3 4   
                            4 3 3 3 3 3 4   
                            4 4 4 4 4 4 4   
Input Format
The input will contain a single integer .

Constraints
1<= n <= 1000

Sample Input 0
2
Sample Output 0
2 2 2
2 1 2
2 2 2

Sample Input 1
5
Sample Output 1
5 5 5 5 5 5 5 5 5 
5 4 4 4 4 4 4 4 5 
5 4 3 3 3 3 3 4 5 
5 4 3 2 2 2 3 4 5 
5 4 3 2 1 2 3 4 5 
5 4 3 2 2 2 3 4 5 
5 4 3 3 3 3 3 4 5 
5 4 4 4 4 4 4 4 5 
5 5 5 5 5 5 5 5 5
*/

#include <stdlib.h>
#include <stdio.h>

//打印的值等于n减去水平方向（j)和垂直方向（i)这二者的最小值
int main(void){
    int i, j, n;
    int ver_min;  //min diff between vertical sizes
    int hor_min;  //min diff between horizontal sizes
    int min, len;

    n = 7;
    len = 2 * n - 1;
    for (i = 0; i < len; i++)
    {
        for (j = 0; j < len; j++)
        {
            ver_min = (i <= len - i) ? i : (len -1 - i);
            hor_min = (j <= len - j) ? j : (len -1 - j);
            min = (ver_min <= hor_min) ? ver_min : hor_min;
            printf("%d ", (n - min));
        }
        printf("\n");
    }
}