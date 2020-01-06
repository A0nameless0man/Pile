#include <algorithm>
#include <cctype>
#include <cstdio>
#include <iostream>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define CHECK(x) std::cout << #x << " is : " << (x) << std::endl;
const long long HASH_A = 19301;
const long long HASH_B = 19889;
const long long HASH_C = 817;
const long long MODDER = 1000000007;
const long long MAX_N  = 5007;
int             show[MAX_N];  //
long long       raw[MAX_N];   //
long long       rawHash[MAX_N][MAX_N];
long long       rawHashCount[MAX_N];  //
long long       rawCount = 0;         //
inline void     Read(long long &p)
{
    p      = 0;
    char c = getchar();
    // while (!isdigit(c))
    while(c < '0' || c > '9')
        c = getchar();
    while(c >= '0' && c <= '9')
        p = p * 10 + (c - '0'), c = getchar();
}
int main(void)
{
    long long t;
    Read(t);
    while(t--)
    {
        long long n, q;
        Read(n);
        Read(q);
        for(long long i = 0; i < n + 5; i++)
        {
            rawHashCount[i] = 0;
            // memset(rawHash[i],0,(n+1)*sizeof(long long));
        }
        long long buf;
        // std::vector<bool> ok(q, false);
        for(long long i = 0; i < n; i++)
        {
            Read(raw[n - i - 1]);
        }  // O(n)
        // std::reverse(raw, raw + rawCount);
        raw[n]   = 0;
        rawCount = n + 1;
        for(long long i = 0; i < rawCount; i++)
        {
            long long prefixHash = 0;
            // memset(show,0,(n+1)*sizeof(int));
            for(int i = 0; i < n + 5; i++)
                show[i] = 0;
            for(long long j = i; j < rawCount; j++)
            {
                if(show[raw[j]] == 0)
                {
                    show[raw[j]]                = 1;
                    prefixHash                  = (prefixHash * HASH_A + raw[j]) % MODDER;
                    rawHash[i][rawHashCount[i]] = prefixHash;
                    // CHECK(rawHash[i][rawHashCount[i]]);
                    ++rawHashCount[i];
                }
            }
        }
        for(long long i = 0; i < q; i++)
        {
            long long m;
            Read(m);
            long long hash = 0;
            bool      noZ  = true;
            long long cnt  = 0;
            long long j;
            for(j = 0; j < m; j++)
            {
                Read(buf);
                if(noZ && buf != 0)
                {
                    hash = (hash * HASH_A + buf) % MODDER;
                    cnt++;
                }
                else
                {
                    noZ = false;
                }
            }  // o(sum(m))
            if(!noZ)
            {
                hash = (hash * HASH_A) % MODDER;
                cnt++;
            }
            cnt--;
            bool ok = false;
            for(long long i = 0; i < rawCount && !ok; i++)
            {
                ok = ok || (hash == rawHash[i][cnt]);
                // CHECK(i);
                // CHECK(rawHash[i][cnt]);
            }
            // CHECK(hash);
            // CHECK(cnt);
            if(ok)
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
        }
        // for(int i = 0;i<rawCount;i++)std::cout<<raw[i]<<" ";std::cout<<std::endl;
    }
    return 0;
}
/*
1
7 15
4 3 4 2 3 1 4
1 0
2 0 0
1 4
2 3 4
2 3 0
2 4 0
3 3 4 0
4 3 4 0 0
4 3 2 4 0
4 4 1 3 2
1 4
2 2 3
3 3 2 1
4 4 1 3 2
4 3 4 0 0
*/
/*
Yes
Yes
Yes
Yes
No
Yes
Yes
Yes
Yes
Yes
Yes
No
No
Yes
Yes
*/
/*
1
50 2
32 19 44 29 38 33 40 36 34 13 29 1 43 46 18 24 29 39 27 17 49 38 1 46 42 37 17 17 9 35 29 22 6 10 22
9 33 37 2 23 46 38 21 2 3 37 50 33 27 42 1 44 2 29 13
*/
/*
2
50 10
23 30 34 20 27 11 21 29 12 7 21 42 45 48 8 15 6 16 19 35 16 14 29 11 31 18 22 4 45 22 14 4 13 40 43
48 27 15 15 15 15 10 15 11 31 37 34 34 50 14 1 25 2 23 6 3 29 21 11 4 12 29 18 39 5 29 21 11 27 20
6 21 10 9 3 34 14
7 49 36 36 43 50 50 35
8 12 29 21 11 27 20 34 30
9 11 27 20 34 30 23 0 0 0
10 21 34 1 44 20 50 28 14 16 41
50 2
32 19 44 29 38 33 40 36 34 13 29 1 43 46 18 24 29 39 27 17 49 38 1 46 42 37 17 17 9 35 29 22 6 10 22
9 33 37 2 23 46 38 21 2 3 37 50 33 27 42 1 44 2 29 13
*/