#include <stdio.h>
#include <math.h>
bool IsPrime(long long int input)
{
    for(size_t i = 2; i <= 0.5 + pow(input, 0.5); i++)
    {
        if((input % i) == 0)
        {
            /*-利用求余和循环判断是否是素数-*/
            return false;
        }
    }
    return true;
}
int main(void)
{
    int a = 0;
    while(scanf("%d", &a) != EOF)
    {
        if(IsPrime(a))
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
}
