#include<iostream>
#include<vector>
#include<set>
#include<unordered_set>
const long long HASH_A = 234578197;
const long long HASH_B = 4238972569;
const long long HASH_C = 19260817; 
const long long MOD = 100000007;
int main(void)
{
    int t;
    std::cin>>t;
    while(t--)
    {
        int n,q;
        std::cin>>n>>q;
        std::vector<long long> raw;
        std::unordered_set<long long> hashQue;
        std::vector<bool> ok(q);
        for(int i =0;i<n;i++)
        {
            long long buf;
            std::cin>>buf;
            raw.push_back(buf);
        }
        for(int i = 0;i<q;i++)
        {
            long long m;
            std::cin>>m;
            long long hash = 0;
            for(int j = 0;j<m;j++)
            {
                long long buf;
                std::cin>>buf;
                hash = (hash*HASH_A+buf*HASH_B+HASH_C)%MOD;
            }
            hashQue.insert(hash);
        }
        for(int i = 0;i<n;i++)
        {
            
        }
    }
}