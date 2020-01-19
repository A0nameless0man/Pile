#include <cstdio>
#include <iostream>
#include <math.h>
static double easy(double a, double b, int way)
{
    //使用int指示运算符以使用for循环
    switch(way)
    {
        case 0:
            return (a + b);
        case 1:
            return (a - b);
        case 2:
            return (a * b);
        case 3:
            if(fabs(b) > 0)
            {
                return (a / b);
            }
            else
            {
                return 0;
            }
        default:
            return 0;
    }
}
static bool count(int *input, int *caculate)
{
    //超多for循环嵌套在此
    //此处决定运算符
    for(caculate[3] = 0; caculate[3] < 2; caculate[3]++)
    {
        for(caculate[0] = 0; caculate[0] < 4; caculate[0]++)
        {
            for(caculate[1] = 0; caculate[1] < 4; caculate[1]++)
            {
                for(caculate[2] = 0; caculate[2] < 4; caculate[2]++)
                {
                    if(caculate[3] == 0)
                    {

                        if(fabs(easy(easy(input[0], input[1], caculate[0]),
                                     easy(input[2], input[3], caculate[1]),
                                     caculate[2])
                                - 24)
                           <= 0.00005)
                        {

                            return true;
                        }
                    }
                    else
                    {
                        if(fabs(
                             easy(
                               easy(easy(input[0], input[1], caculate[0]), input[2], caculate[1]),
                               input[3],
                               caculate[2])
                             - 24)
                           <= 0.00005)
                        {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}
static bool trarange(int *input, int *output, int *caculate)
{
    //此处决定运算顺序
    for(size_t m = 0; m < 4; m++)
    {
        output[0] = input[m];
        for(size_t n = 0; n < 4; n++)
        {
            if(n != m)
            {
                output[1] = input[n];
                for(size_t p = 0; p < 4; p++)
                {
                    if(p != m && p != n)
                    {
                        output[2] = input[p];
                        for(size_t q = 0; q < 4; q++)
                        {
                            if(q != m && q != n && q != p)
                            {
                                output[3] = input[q];
                                if(count(output, caculate))
                                {
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

int main()
{
    printf("请输入四个数字，以“Enter”分隔。       \n");

    char sing[4]     = { '+', '-', '*', '/' };
    int  input[4]    = { 6, 6, 2, 3 };
    int  range[4]    = { 6, 6, 2, 3 };
    int  caculate[4] = { 0, 0, 0, 0 };
    //获取输入
    //计算并输出结果
    // for(input[0] = 0; input[0] < 14; input[0]++)
    {
        // for(input[1] = 0; input[1] < 14; input[1]++)
        {
            // for(input[2] = 0; input[2] < 14; input[2]++)
            {
                while(true)
                // for(input[3] = 0; input[3] < 14; input[3]++)
                {
                    for(int i = 0; i < 4; ++i)
                    {
                        std::cin >> input[i];
                    }
                    for(size_t i = 0; i < 4; i++)
                    {
                        printf("%d#", input[i]);
                    }
                    if(trarange(input, range, caculate))
                    {
                        if(caculate[3] == 0)
                        {
                            printf("(%d%c%d)%c(%d%c%d)=24\n",
                                   range[0],
                                   sing[caculate[0]],
                                   range[1],
                                   sing[caculate[2]],
                                   range[2],
                                   sing[caculate[1]],
                                   range[3]);
                        }
                        else
                        {
                            printf("%d%c%d%c%d%c%d=24\n",
                                   range[0],
                                   sing[caculate[0]],
                                   range[1],
                                   sing[caculate[1]],
                                   range[2],
                                   sing[caculate[2]],
                                   range[3]);
                        }
                    }
                    else
                    {
                        printf("%d,%d,%d,%d.can't solve.\n",
                               input[0],
                               input[1],
                               input[2],
                               input[3]);
                    }
                }
            }
        }
    }
    // getchar();
    return 0;
}
