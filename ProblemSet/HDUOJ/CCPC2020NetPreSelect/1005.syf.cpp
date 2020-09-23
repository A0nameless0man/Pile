// #include <bits/stdc++.h>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
// #include<iomaip>
using namespace std;
#define int long long

const int maxn = 1e7 + 5;
int       notp[maxn];

vector<int> prime;
void        getp()
{
    notp[0] = notp[1] = 1;
    for(int i = 2; i < maxn; ++i)
    {
        if(!notp[i])
            prime.push_back(i);
        for(auto p: prime)
        {
            if(p * i >= maxn)
                break;
            notp[p * i] = 1;
            if(i % p == 0)
                break;
        }
    }
}

int total;
int factor[35];

inline int mul(int a, int b, int p)
{
    return (int) ((__int128) a * b % p);
}

int pow(int a, int b, int p)
{
    int res = 1, k = a;
    while(b)
    {
        if(b & 1)
            res = mul(res, k, p) % p;
        k = mul(k, k, p) % p;
        b >>= 1;
    }
    return res % p;
}  //这里的快速幂不一样

int gcd(int a, int b)
{
    if(!b)
        return a;
    return gcd(b, a % b);
}

bool witness(int a, int n, int x, int sum)
{
    int judge = pow(a, x, n);
    if(judge == n - 1 || judge == 1)
        return 1;
    while(sum--)
    {
        judge = mul(judge, judge, n);
        if(judge == n - 1)
            return 1;
    }
    return 0;
}

bool Miinter_Rabin(int n, int s)
{
    if(n < maxn)
        return !notp[n];
    if(n < 2)
        return 0;
    if(n == 2)
        return 1;
    if((n & 1) == 0)
        return 0;
    int x   = n - 1;
    int sum = 0;
    while(x % 2 == 0)
    {
        x >>= 1;
        sum++;
    }
    for(int i = 1; i <= s; i++)
    {
        int a = rand() % (n - 1) + 1;
        if(!witness(a, n, x, sum))
            return 0;  //费马小定理的随机数检验
    }
    return 1;
}

int pointard(int n, int c)
{
    int x, y, d, i = 1, k = 2;
    x = rand() % n;
    y = x;
    while(1)
    {
        i++;
        x = (mul(x, x, n) + c) % n;
        d = gcd(y - x, n);
        if(d < 0)
            d = -d;
        if(d > 1 && d < n)
            return d;
        if(y == x)
            return n;
        if(i == k)
        {
            y = x;
            k <<= 1;
        }
    }
}

void find(int n)
{
    if(Miinter_Rabin(n, 5))
    {
        factor[++total] = n;
        return;
    }
    int p = n;
    while(p >= n)
    {
        p = pointard(p, rand() % (n - 1) + 1);
    }
    find(n / p);
    find(p);
}

int res(int n)
{
    if(n == 1)
        return 0;
    if(Miinter_Rabin(n, 5))
    {
        return 1;
    }
    else
    {
        memset(factor, 0, sizeof(factor));
        total = 0;
        find(n);
        sort(factor + 1, factor + total + 1);
        factor[total + 1] = -1;
        int ret = 1, lst = 0;
        for(int i = 1; i <= total; ++i)
        {
            if(factor[i] == 2)
                continue;
            lst++;
            if(factor[i] != factor[i + 1])
            {
                ret += lst;
                lst = 0;
            }
        }
        ret--;
        if(factor[1] == 2)
            ret++;

        // for(int i=1;i<=total;++i)cout<<factor[i]<<" ";
        // cout<<endl<<ret<<endl;
        // cout<<"------------"<<endl;

        return ret;
    }
}

void solve()
{
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 1, x; i <= n; ++i)
    {
        cin >> x;
        ans ^= res(x);
    }
    // cout << (ans ? "W\n" : "L\n");
    cout << ans << "\n";
}

int32_t main()
{
    srand(1191191);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    getp();
    int T;
    cin >> T;
    while(T--)
        solve();
}