#define _CRT_SECURE_NO_WARNINGS
//#define DEBUG
#include <algorithm>
#include <ctype.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <vector>
template <typename T>
void swap(T &a, T &b)
{
    T t = a;
    a   = b;
    b   = t;
}  //
const int     MAX_N = 1700007;
long long int n, m, a, b, j, k;
int           main(void)
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif  // DEBUG

    while(scanf("%lld", &n) != EOF)
    {
        long long left = 0, right = n;
        long long mid;
        while(left < right)
        {
            mid = (left + right) / 2;
            if(mid * mid < n)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
#ifdef DEBUG
        printf("sqrt:%lld;left:%lld;right:%lld\n", n, left, right);
#endif  // DEBUG
        if(left * left != n)
        {
            left--;
        }
        n = left;
        for(long long i = 1; i <= n; i++)
        {
            printf("%lld", i * i);
            if(i != n)
            {
                putchar(' ');
            }
            else
            {
                putchar('\n');
            }
        }
    }
#ifdef DEBUG
    system("pause");
    system("pause");
    // Sleep(-1);
#endif  // DEBUG

    return 0;
}
