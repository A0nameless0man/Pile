#include <cstdio>
#include <iostream>
#include <map>
#include <vector>

int main(void)
{
    int n;
    while(std::cin >> n)
    {
        std::map<int, int> homeCnt, AwayCnt;
        std::vector<int>   homeRec, AwayRec;
        for(int i = 0; i < n; ++i)
        {
            int homeKit, AwayKit;
            scanf("%d%d", &homeKit, &AwayKit);
            ++homeCnt[homeKit];
            ++AwayCnt[AwayKit];
            homeRec.push_back(homeKit);
            AwayRec.push_back(AwayKit);
        }
        for(int i = 0; i < n; ++i)
        {
            int home = n - 1 + homeCnt[AwayRec[i]];
            int away = 2 * (n - 1) - home;
            printf("%d %d\n", home, away);
        }
    }
}