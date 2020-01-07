#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <vector>
char buf[2000007];
int  oldmain(void)
{
    int n, k;
    while(scanf("%d%d%s", &n, &k, buf) != EOF)
    {
        bool add = false;
        for(int i = k; i < n; ++i)
        {
            if(buf[i] > buf[i % k])
            {
                add = true;
            }
        }
        if(add)
        {
            buf[k - 1]++;
            for(int i = k - 1; i > 0; --i)
            {
                if(buf[i] > '9')
                {
                    ++buf[i - 1];
                    buf[i] = '0';
                }
            }
        }
        for(int i = 0; i < n; ++i)
        {
            buf[i] = buf[i % k];
        }
        printf("%d\n%s\n", n, buf);
        // putchar('\n');
    }
    return 0;
}
#include <iostream>
#include <string>
int main(void)
{
    std::string x, y;
    int         n, k;
    while(std::cin >> n >> k >> x)
    {
        y.clear();
        for(int i = 0; i < n; ++i)
        {
            y.push_back(x[i % k]);
        }
        if(y < x)
        {
            ++(y[k - 1]);
            for(int i = k - 1; i > 0; --i)
            {
                if(y[i] > '9')
                {
                    y[i] = '0';
                    ++(y[i - 1]);
                }
            }
            for(int i = k; i < n; ++i)
            {
                y[i] = y[i % k];
            }
        }
        std::cout << n << std::endl << y << std::endl;
    }
}