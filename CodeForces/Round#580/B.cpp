#include <iostream>
#include <vector>
#include <stack>
std::vector<short> edges[128];
bool vis[128] = {0};
short ans = 256;
void dfs(short pos, short s, short dis = 0)
{
    vis[pos] = true;
    //std::cout<<pos<<" "<<s<<" "<<dis<<std::endl;
    for (auto i : edges[pos])
    {
        if (!vis[i])
        {
            dfs(i, s, dis + 1);
        }
        if (i == s && dis < ans && dis > 2)
        {
            ans = dis;
            //vis[pos] = false;
            //return;
            break;
        }
        if(dis>ans)
        {
            break;
        }
    }
    vis[pos] = false;
}
int main(void)
{
    std::vector<unsigned long long> raw;
    short bits[64] = {0};
    int n,k;
    std::cin>>n;
    k = n;
    while (k--)
    {
        unsigned long long buffer;
        std::cin >> buffer;
        if(buffer)
            raw.push_back(buffer);
        for (short i = 0; i < 64; i++)
        {
            if (buffer & (1ll << i))
            {
                bits[i]++;
                if (bits[i] == 3)
                {
                    std::cout << 3 << std::endl;
                    return 0;
                }
            }
        }
        //for (auto i : bits){std::cout << i << " ";}std::cout<<std::endl;
    }
    //std::cout<<"#"<<std::endl;
    n= raw.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (raw[i] & raw[j])
            {
                //std::cout<<i<<" "<<j<<std::endl;
                edges[i].push_back(j);
                edges[j].push_back(i);
            }
        }
    }
    for (int i = 0; i < n; i++)
        dfs(i, i,1);
    if(ans!=256)
        std::cout << ans << std::endl;
    else
    {
        std::cout<<-1<<std::endl;
    }
    
    return 0;
}