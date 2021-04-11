/*
Given a 6X6 2D Array, arr:

1 1 1 0 0 0
0 1 0 0 0 0
1 1 1 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
An hourglass in A is a subset of values with indices falling in this pattern in arry's graphical representation:

a b c
  d
e f g
There are  hourglasses in . An hourglass sum is the sum of an hourglass' values. 
Calculate the hourglass sum for every hourglass in , then print the maximum hourglass sum. 
The array will always be .
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define ARRAY_VERSION

#ifdef ARRAY_VERSION
int hourglassSum(int arr_rows, int arr_columns, int (*arr)[arr_columns]);  //array version
#else
int hourglassSum(int arr_rows, int arr_columns, int **arr);  //pointer version
#endif


int main(void)
{
    int max_sum;
    int arr[6][6] = {
        {-9, -9, -9, 1, 1, 1},
        {0, -9, 0, 4, 3, 2},
        {-9, -9, -9, 1, 2, 3},
        {0, 0, 8, 6, 6, 0},
        {0, 0, 0, -2, 0, 0},
        {0, 0, 1, 2, 4, 0}
    };

    max_sum = hourglassSum(6, 6, arr);
    printf("max_sum = %d \n", max_sum);

    return 0;
}

#ifdef ARRAY_VERSION
//二维数组通过指针传递后，仍然想以二维数组的方式读取的话，要通过数组指针的方式传递
int hourglassSum(int arr_rows, int arr_columns, int (*arr)[arr_columns]) //array version
#else
int hourglassSum(int arr_rows, int arr_columns, int** arr)  //pointer version
#endif
{
    int i, j, k=0;
    #ifndef ARRAY_VERSION
    int *p;
    #endif
    int sum[16]={0};
    int max_sum;

    for (i = 0; i<=3; i++)
    {
        #ifndef ARRAY_VERSION
        p=&(arr[i]);
        #endif

        for (j=0; j<=3; j++)
        {               
            #ifdef ARRAY_VERSION
            sum[k] = (arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+1] + arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2]);
            #else
            //pointer version
            sum[k] = (*p + *(p + 1) + *(p + 2) + *(p + 7) + *(p + 12) + *(p + 13) + *(p + 14));
            #endif
            //printf("%d \n", sum[k]);
            k++;

            #ifndef ARRAY_VERSION
            p++;
            #endif
        }        
    }

    max_sum = sum[0];
    for (i = 1; i < k; i++)
    {
        if (max_sum < sum[i])
            max_sum = sum[i];
    }

    return max_sum;
}