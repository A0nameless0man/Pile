#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstdio>
inline int fun(int pos, int n)
{
    //register int base = pos % n;
    //base *= 2;
    if (pos >= n)
    {
        return (pos - n)*2 + (pos - n+1) % 2 + 1;
    }
    else
    {
        return pos*2 + (pos) % 2 +1;
    }

    //return base + 1;
}
inline void print(char* c)
{
    while(*c)
    {
        putchar(*c);
        ++c;
    }
    
}
inline void read(int & n)
{
    ;
}
int main(void)
{
    int n;
    while (~scanf("%d",&n))
    {
        //while(n--)
        if (n % 2 != 0)
        {
            //std::cout << "YES" << std::endl;
            print("YES\n");
            for ( int i = 0; i < n * 2; i++)
            {
                //std::cout << fun(i, n);
                printf("%d",fun(i,n));
                if (i != 2 * n - 1)
                {
                    //std::cout << " ";
                    putchar(' ');
                }
                else
                {
                    //std::cout << std::endl;
                    putchar('\n');
                }
            }
        }
        else
        {
            //std::cout << "NO" << std::endl;
            print("NO\n");
        }
    }
    return 0;
}