#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using ULL = unsigned long long;
void buildRankVector(std::vector<size_t> &res, const char *tar, ULL n)  //开头在i的后缀的排名
{
    res.clear();
    res.resize(n);
    {                                            //
        std::vector<ULL> buckets[26];            //
        for(ULL j = 0; j < n; j++)               //
        {                                        //
            buckets[tar[j] - 'a'].push_back(j);  //
        }                                        //
        ULL rank = 0;
        for(ULL j = 0; j < 26; j++)  //
        {                            //
            if(!buckets[j].empty())
            {
                rank++;
            }
            for(auto k: buckets[j])  //
            {                        //
                res[k] = rank;
            }  //
        }      //
    }          //

    for(ULL i = 1; i < n; i <<= 1)
    {
        std::vector<ULL> buckets[26][27];  //
        for(ULL j = 0; j < n; j++)
        {
            buckets[res[j]][((j + i < n) ? (res[j + i] + 1) : 0)].push_back(j);
        }
        ULL rank = 0;
        for(ULL m = 0; m < 26; m++)
        {
            for(ULL n = 0; n < 27; n++)
            {
                if(!buckets[m][n].empty())
                {
                    rank++;
                }
                for(auto k: buckets[m][n])  //
                {                           //
                    res[k] = rank;
                }  //
            }
        }
    }
    return;
}
void buildSuffixVector(std::vector<size_t> &res, const char *tar, ULL n)  //排名第i的后缀是哪个
{
    std::vector<size_t> rank;
    buildRankVector(rank, tar, n);
    res.clear();
    res.resize(n + 1);
    res[0] = n;
    for(ULL i = 0; i < n; i++)
    {
        res[rank[i]] = i;
    }
    return;
}
void buildBothVector(std::vector<size_t> &rank, std::vector<size_t> &Suffix, const char *tar, ULL n)
{
    buildRankVector(rank, tar, n);
    Suffix.clear();
    Suffix.resize(n + 1);
    Suffix[0] = n;
    for(ULL i = 0; i < n; i++)
    {
        Suffix[rank[i]] = i;
    }
    return;
}
char str[2000000];
int  main(void)
{
    ULL t, n, q;
    std::cin >> t;
    while(t--)
    {
        std::cin >> n >> q;
        ULL k    = 0;
        ULL mel2 = n;
        while(mel2)
        {
            mel2 >>= 1;
            ++k;
        }
        memset(str, 0, sizeof(char) << k);
        scanf("%s", str);
        std::vector<size_t> Rank, Suffix;
        buildBothVector(Rank, Suffix, str, n);
        while(q--)
        {
            ULL       l, r, k;
            long long ans = -1;
            std::cin >> l >> r >> k;
            if(Rank[l] + k <= n) {}
        }
    }
}