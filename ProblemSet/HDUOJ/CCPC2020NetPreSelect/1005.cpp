#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
// #include <unordered_map>
#define asc(i, s, e) for((i) = (s); (i) <= (e); ++(i))
typedef long long ll;
using namespace std;

ll gcd(ll a, ll b)
{
    ll t = a % b;
    while(t)
    {
        a = b;
        b = t;
        t = a % b;
    }
    return b;
}

ll qpow(ll a, ll b, ll n)
{
    a %= n;
    b %= n;
    ll ans = 0;
    while(b)
    {
        if(b & 1)
        {
            ans += a;
            ans %= n;
        }
        a <<= 1;
        a %= n;
        b >>= 1;
    }
    return ans;
}

ll getr(ll a, ll u, ll n)
{
    ll cur = 1;
    ll nxt = a;
    while(u)
    {
        if((u & 1) > 0)
        {
            cur = qpow(cur, nxt, n);
        }
        nxt = qpow(nxt, nxt, n);
        u >>= 1;
    }
    return cur % n;
}

bool cp(ll n)
{
    for(int i = 0; i < 20; ++i)
    {
        ll a  = rand() % (n - 1);
        ll x  = getr(a, n - 1, n);
        ll y  = x;
        ll tu = n - 1;
        while(tu < n)
        {
            y = qpow(x, x, n);
            if(y == 1 && x != 1 && x != n - 1)
            {
                return false;
            }
            x = y;
            tu *= 2;
        }
        if(x != 1)
        {
            return false;
        }
    }
    return true;
}
ll next(ll x, ll c, ll n)
{
    return (x * x + c) % n;
}
ll pollard_rho(ll n)
{
    if(n > 1e6 && cp(n))
    {
        return n;
    }
    ll  x   = 2;
    ll  y   = 2;
    ll  c   = 5;  //
    ll  val = 1;
    int gal = 1;
    while(1)
    {
        for(int stp = 1; stp <= gal; ++stp)
        {
            x   = next(x, c, n);
            val = (val * abs(x - y)) % n;
            if((stp % 127) == 0)
            {
                ll g = gcd(val, n);
                if(g > 1)
                {
                    return g;
                }
            }
        }
        ll g = gcd(val, n);
        if(g > 1)
        {
            return g;
        }
        // printf("gal=%ld\n", gal);
        // printf("g=%ld\n", g);
        gal <<= 1;
        // x = y;
        y   = x;
        val = 1;
    }
    // for (;;) {
    //     ll d = 1;

    //     while (d == 1) {
    //         x = (x * x - 1) % n;
    //         y = (y * y - 1) % n;
    //         y = (y * y - 1) % n;
    //         d = gcd(abs(x - y), n);
    //     }
    //     if (d == n) {
    //         x = y = (rand() % n + 2);
    //     } else {
    //         return d;
    //     }
    // }
}

// unordered_map<int, int> memo;

int calc_xi(int n)
{
    // if(memo.count(n))
    // {
    //     return memo[n];
    // }

    int xi = 0;
    if(n % 2 == 0)
    {
        xi += 1;
        while(n % 2 == 0)
        {
            n /= 2;
        }
    }
    while(n != 1)
    {
        int f = pollard_rho(n);
        // printf("f = %lld\n", f);
        while(n % f == 0)
        {
            n /= f;
            // xi += 1;
            ++xi;
        }
    }
    // memo[n] = xi;
    return xi;
}

int main()
{
    int test;
    asc(test, 1e7, 1e7 + 1e6)
    {
        int f = calc_xi(test);
        if(test % 10000 == 0)
        {
            printf("%d", f);
        }
        // printf("%d / %d ... ok\n", test, f);
    }
    return 0;

    srand(time(NULL));

    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);

        int l[32];
        int i;
        asc(i, 1, n)
        {
            scanf("%d", &l[i]);
        }

        int x = 0;
        asc(i, 1, n)
        {
            x ^= calc_xi(l[i]);
        }

        if(x == 0)
        {
            printf("L\n");
        }
        else
        {
            printf("W\n");
        }
    }
}