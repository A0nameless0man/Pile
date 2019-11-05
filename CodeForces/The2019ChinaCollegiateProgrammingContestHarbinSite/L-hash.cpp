#include <iostream>
#include <cstdio>
#include <vector>
#include <cctype>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#define CHECK(x) std::cout << #x << " is : " << (x) << std::endl;
const int HASH_A = 19301;
const int HASH_B = 19889;
const int HASH_C = 817;
const int MODDER = 1000007;
const int MAX_N = 5007;
int raw[MAX_N];
int rawHash[MAX_N][MAX_N];
int rawHashCount[MAX_N];
int rawCount = 0;
inline void Read(int &p)
{
    p = 0;
    char c = getchar();
    while (!isdigit(c))
        c = getchar();
    while (isdigit(c))
        p = p * 10 + (c - '0'), c = getchar();
}
int main(void)
{
    int t;
    // std::cin >> t;
    //scanf("%d",&t);
    Read(t);
    while (t--)
    {
        int n, q;
        // scanf("%d%d",&n,&q);
        Read(n);
        Read(q);
        // std::cin >> n >> q;
        // std::vector<int> raw;
        rawCount = 0;
        for(int i = 0;i<n+5;i++)rawHashCount[i]=0;
        // raw.reserve(n+5);
        //std::unordered_map<int, std::vector<int>> hashQue;
        // std::vector<std::vector<int>> hashRaw;
        // hashRaw.resize(n + 5);
        int buf;
        std::vector<bool> ok(q, false);
        for (int i = 0; i < n; i++)
        {
            //std::cin >> buf;
            // scanf("%d",&buf);
            Read(raw[rawCount]);
            ++rawCount;
            // raw.push_back(buf);
        } //O(n)
        std::reverse(raw, raw + rawCount);
        // raw.push_back(0);
        raw[rawCount] = 0;
        ++rawCount;
        for (int i = 0; i < rawCount; i++)
        {
            std::unordered_set<int> inULA;
            //std::vector<int> ULA;
            int prefixHash = 0;
            for (int j = i; j < rawCount; j++)
            {
                if (inULA.find(raw[j]) == inULA.end())
                {
                    //ULA.push_back(raw[j]);
                    inULA.insert(raw[j]);
                    prefixHash = (prefixHash * HASH_A + raw[j]) % MODDER;
                    //hashRaw[i].push_back(prefixHash);
                    rawHash[i][rawHashCount[i]]=prefixHash;
                    ++rawHashCount[i];
                    // if (hashs.find(prefixHash)==hashs.end()&&hashQue.find(prefixHash) != hashQue.end())
                    // {
                    //     // // std::cout<<i<<" "<<j<<":\n"<<std::endl;
                    //     // //ok[hashQue[prefixHash]] = true;
                    //     // for (auto i : hashQue[prefixHash])
                    //     // {
                    //     //     // std::cout<<i<<" ";
                    //     //     ok[i] = true;
                    //     // }
                    //     // // std::cout<<std::endl;
                    //     hashs.insert(prefixHash);
                    // }
                }
            }
        } //o(n^2)
        // for (auto i : hashRaw)
        // {
        //     for (auto j : i)
        //     {
        //         std::cout << j << " ";
        //     }
        //     std::cout << std::endl;
        // }
        for (int i = 0; i < q; i++)
        {
            int m;
            // scanf("%d",&m);
            Read(m);
            // std::cin >> m;
            int hash = 0;
            bool noZ = true;
            int cnt = 0;
            int j;
            for (j = 0; j < m; j++)
            {
                //int buf;
                // scanf("%d", &buf);
                Read(buf);
                // std::cin >> buf;
                if (noZ && buf != 0)
                {
                    hash = (hash * HASH_A + buf) % MODDER;
                    cnt++;
                    // CHECK(hash);
                    // CHECK(buf)
                }
                else
                {
                    noZ = false;
                }
            } //o(sum(m))
            if (!noZ)
            {
                hash = (hash * HASH_A) % MODDER;
                cnt++;
            }
            // CHECK(hash);
            // CHECK(cnt);
            cnt--;
            //j--;
            //hashQue.insert({hash, i});
            //hashQue[hash].push_back(i);
            bool ok = false;
            for (int i = 0; i < n+1&&!ok; i++)
            {
                ok |= (cnt< rawHashCount[i]&& hash == rawHash[i][cnt]);
            }
            if (ok)
            {
                // std::cout << "Yes" << std::endl;
                printf("Yes\n");
            }
            else
            {
                // std::cout << "No" << std::endl;
                printf("No\n");
            }
        }
        //std::unordered_set<int> hashs;
        // std::cout<<"hash:\n";
        // for(auto hash:hashQue){std::cout<<hash.first<<":\n";for(auto i:hash.second)std::cout<<i<<" ";std::cout<<std::endl;}
        // std::cout<<std::endl;
        // for (auto b : ok)
        // {
        //     if (b)
        //     {
        //         // std::cout << "Yes" << std::endl;
        //         printf("Yes\n");
        //     }
        //     else
        //     {
        //         // std::cout << "No" << std::endl;
        //         printf("No\n");
        //     }
        // }
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