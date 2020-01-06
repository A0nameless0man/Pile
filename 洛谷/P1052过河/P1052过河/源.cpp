// luogu-judger-enable-o2
#define _CRT_SECURE_NO_WARNINGS
#define DEBUG
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
#include <vector>
template <typename T>
void swap(T &a, T &b)
{
    T t = a;
    a   = b;
    b   = t;
}
const int     MAX_M = 10007;
long long     stones[MAX_M];
long long int n, m, t, s, l, j, k;

void sort(int from, int to)
{
    if(from < to)
    {
        if(to - from == 1)
        {
            if(stones[from] > stones[to])
            {
                swap(stones[from], stones[to]);
            }
            return;
        }
        long long mid   = stones[(from + to) / 2];
        int       left  = from;
        int       right = to;
        while(left < right)
        {
            while(stones[left] < mid)
            {
                left++;
            }
            while(stones[right] > mid)
            {
                right--;
            }
            if(left < right)
            {
                swap(stones[left], stones[right]);
                left++;
                right--;
            }
        }
        sort(from, left);
        sort(right, to);
    }
    else
    {
        return;
    }
}
int main(void)
{
#ifdef DEBUG
    freopen("testdata.in", "r", stdin);
#endif  // DEBUG

    while(scanf("%lld%lld%lld%lld", &l, &s, &t, &m) != EOF)
    {
        l += 20;
        int       currentstone = 0;
        long long mem[20]      = { 0 };
        for(long long i = 0; i < m; i++)
        {
            scanf("%lld", &stones[i]);
        }
        sort(0, m - 1);
        if(s == t)
        {
            int sto = 0;
            for(long long i = 0; i < m; i++)
            {
                if(stones[i] % s == 0)
                {
                    sto++;
                }
            }
            printf("%d\n", sto);
            continue;
        }
        int key = t + t * t / (t - s) + 1;
        for(long long i = 1; i < s; i++)
        {
            mem[i] = 200;
        }
        for(long long i = s; i < l; i++)
        {
            int min = 200;
            for(long long k = s; k <= t && k <= i; k++)
            {
                if(mem[(i - k) % 20] < min)
                {
                    min = mem[(i - k) % 20];
                }
            }
            mem[i % 20] = min;
            if(i == stones[currentstone])
            {
                mem[i % 20]++;
                currentstone++;
            }
            if(currentstone > 0 && i - stones[currentstone - 1] > key &&
               stones[currentstone] - i > key)
            {
                for(int i = 0; i < 20; i++)
                {
                    mem[i] = min;
                }
                i = stones[currentstone] - key;
            }
            if(currentstone == m && l - i - 20 > key)
            {
                for(int i = 0; i < 20; i++)
                {
                    mem[i] = min;
                }
                i = l - 20 - key;
            }
        }
        int min = 200;
        for(int i = 0; i < 20; i++)
        {
            if(mem[i] < min)
            {
                min = mem[i];
            }
        }
        printf("%d\n", min);
    }
#ifdef DEBUG
    system("pause");
    system("pause");
#endif  // DEBUG

    return 0;
}
