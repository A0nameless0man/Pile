#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#include<algorithm>
#include <set>
const long long int     MAX_N = 100007;
long long int           b, q, l, m;
std::set<long long int> bad;
long long int           qn[MAX_N];
long long int           badInt[MAX_N];
long long int           Qpow(long long int n)
{
    long long int w = 0;
    long long int r = 1;
    while(n != 0)
    {
        if(n & 1)
        {
            r *= qn[w];
        }
        ++w;
        n >>= 1;
    }
    return r * b;
}
bool IsBad(long long int n)
{
    // if (m == 0)
    //{
    //	return false;
    //}
    // long long int left = 0;
    // long long int right = m - 1;
    // long long int mid;
    // while (left < right)
    //{
    //	mid = (left + right) / 2;
    //	if (badInt[mid] >= n)
    //	{
    //		right = mid;
    //	}
    //	else
    //	{
    //		left = mid + 1;
    //	}
    //}
    // return badInt[left] == n || badInt[right] == n;
    return bad.count(n) == 1;
}
void swap(long long int &a, long long int &b)
{
    long long int t = a;
    a               = b;
    b               = t;
}
void sort(long long int from, long long int to)
{
    if(from < 0)
    {
        from = 0;
    }
    if(to > m - 1)
    {
        to = m - 1;
    }
    if(from >= to)
    {
        return;
    }
    long long int left = from, right = to, mid = badInt[(from + to) / 2];
    while(left < right)
    {
        while(badInt[left] < mid)
        {
            left++;
        }
        while(badInt[right] > mid)
        {
            --right;
        }
        swap(badInt[left], badInt[right]);
        ++left, --right;
    }
    if(right - from > 1)
    {
        sort(from, right);
    }
    // else
    //{
    //	if (badInt[right]<badInt[from])
    //	{
    //		swap(badInt[right], badInt[from]);
    //	}
    //}
    if(to - left > 1)
    {
        sort(left, to);
    }
    // else
    //{
    //	if (badInt[left] > badInt[from])
    //	{
    //		swap(badInt[left], badInt[from]);
    //	}
    //}
}
long long int abs(long long int n)
{
    return n > 0 ? n : -n;
}
int main(void)
{
    while(scanf("%lld%lld%lld%lld", &b, &q, &l, &m) != EOF)
    {
        for(long long int i = 0; i < m; i++)
        {
            scanf("%lld", &badInt[i]);
            bad.insert(badInt[i]);
        }
        sort(0, m - 1);
        if((b == 0) && !IsBad(0) || (q == 1) && !IsBad(b) ||
           (q == -1 && (!IsBad(b) || !IsBad(-b))) || (q == 0 && !IsBad(0)))
        {
            printf("inf\n");
        }
        else
        {
            if((b == 0) && IsBad(0) || (q == 1 && IsBad(b)) || (q == -1 && IsBad(b) && IsBad(-b)))
            {
                printf("0\n");
            }
            else
            {
                if(q == 0 && IsBad(0) && !IsBad(b))
                {
                    printf("1\n");
                    continue;
                }
                long long int _b    = b;
                long long int inter = 0;
                int           i     = 0;
                while(abs(_b) < l && i < l)
                {
                    if(!IsBad(_b))
                    {
                        inter++;
                    }
                    _b *= q;
                    i++;
                }
                if(i < l && inter != 0)
                {
                    printf("%lld\n", inter);
                }
                else
                {
                    printf("inf\n");
                }
            }
        }
    }
    return 0;
}