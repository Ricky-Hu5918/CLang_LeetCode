/*
将一个无符号整型值的二进制位模式倒序输出
*/

#include <stdlib.h>
#include <stdio.h>

unsigned int reverse_bits(unsigned int value);

int main(void)
{
    unsigned int value = 25;
    unsigned int ret;

    ret = reverse_bits(value);
    printf("ret = %u\n", ret);

    return 0;
}

unsigned int reverse_bits(unsigned int value)
{
    unsigned int ans = 0;
    unsigned int i;
    printf("value = %d\n", value);

    //此处使用i的左移次数来控制循环，i的左移次数就是unsigned int的位数，这样的话就不依赖于机器到底是16位还是32位了
    for (i = 1; i != 0; i <<= 1)
    {

        ans <<= 1;
        if (value & 1)
        {
            ans |= 1;
            printf("i=%d, ans=%d\n", i, ans);
        }

        value >>= 1;
    }

    printf("befre return i=%d, ans=%u\n", i, ans); //必须使用%u来输出，使用%d会overflow
    return ans;
}