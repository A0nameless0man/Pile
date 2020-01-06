#include <stdio.h>
const int   S        = 1007;
int         num[108] = { 0 };
int         input[S], n, swaps;
int         host(int addr);
inline void swap(int &a, int &b)
{
    int t = a;
    a     = b;
    b     = t;
    swaps++;
}
void sort(int from, int to)
{

    for(int i = from; i < to; i++)
    {
        num[input[i]]++;
    }
    for(int i = 1; i <= 100; i++)
    {
        num[i] += num[i - 1];
    }
}
int find(int in, int tar)
{
    for(int i = num[in - 1]; i < num[i]; i++)
    {
        if(input[i] == tar)
        {
            return i;
        }
    }
    return -1;
}
int finde(int in)
{
    for(int i = num[in - 1]; i < num[in]; i++)
    {
        if(in != input[i])
        {
            int h = host(i);
            int g = find(input[i], h);
            if(g != -1)
            {
                swap(input[i], input[g]);
                continue;
            }
            return i;
        }
    }
    return -1;
}
int host(int addr)
{
    for(int i = 1; i <= 100; i++)
    {
        if(num[i - 1] <= addr)
            return i;
    }
    return -1;
}
int main(void)
{
    scanf("%*d");
    while(scanf("%d", &n) != EOF)
    {
        swaps = 0;
        for(int i = 0; i < 104; i++)
            num[i] = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &input[i]);
        }
        sort(0, n);
        for(int i = 0; i < n; i++)
        {
            if(i >= num[input[i] - 1] && i < num[input[i]]) {}
            else
            {
                int h = host(i);
                int g = find(input[i], h);
                if(g != -1)
                {
                    swap(input[i], input[g]);
                }
                else
                {
                    swap(input[i], input[finde(input[i])]);
                    i--;
                }
            }
        }
        printf("%d\n", swaps);
    }
    return 0;
}
