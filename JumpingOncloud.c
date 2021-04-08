/*
There is a new mobile game that starts with consecutively numbered clouds. Some of the clouds are thunderheads and others are cumulus. The player can jump on any cumulus cloud having a number that is equal to the number of the current cloud plus  or . The player must avoid the thunderheads. Determine the minimum number of jumps it will take to jump from the starting postion to the last cloud. It is always possible to win the game.

For each game, you will get an array of clouds numbered  if they are safe or  if they must be avoided.

Example
c=[0,1,0,0,0,1,0]
Index the array from 0-6. The number on each cloud is its index in the list so the player must avoid the clouds at indices  1 and 5. They could follow these two paths:  0 2 4 6 or 0 2 3 4 6. The first path takes 3 jumps while the second takes 4. Return 3.

Function Description
Complete the jumpingOnClouds function in the editor below.

jumpingOnClouds has the following parameter(s):
int c[n]: an array of binary integers

Returns
int: the minimum number of jumps required

Sample Input 0
7
0 0 1 0 0 1 0
Sample Output 0
4
*/

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int c[50] = {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, \
                 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, \
                 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, \
                 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, \
                 0, 0, 1, 0, 0, 1, 0, 1, 0, 0};
    int c_count = 50;


    int i, min_jumps = 0, steps = -1;
    int flag_safe = 0;
    
    for (i = 0; i < c_count; i++)
    {
        if (c[i] == 0)
        {
            steps += 1;
            //((steps == 1) && (flag_safe == 1))，连续出现6个0的情况
            //(steps == 2), 连续出现3个0的情况
            if ((steps == 2) || ((steps == 1) && (flag_safe == 1)))
            {
                flag_safe = 1;
                min_jumps += 1;
                steps = -1;
            }
        }
        else {
            min_jumps += 1;
            if ((steps == 1) || ((steps == 0) && (flag_safe == 1)))
            {
                min_jumps += 1;
            }
            flag_safe = 0;
            steps = -1;
        }
    }
    //结尾连续出现0的情况
    if (((steps == 0) && (flag_safe == 1)) || ((steps == 1)))
    {
        min_jumps += 1;
    }

    printf("min_jumps = %d \n", min_jumps);  //28
    return min_jumps;
}