#include <algorithm>
#include <iostream>

using namespace std;
long long a[6];

int main()
{
    long long t;
    cin >> t;
    while(t--)
    {
        for(long long i = 0; i < 6; i++)
        {
            cin >> a[i];
        }
        long long ans = 1e19;
        for(long long i = 0; i < 3; i++)
        {
            long long chs1 = i * 2, chs2 = (i + 1) % 3 * 2, chs3 = (i + 2) % 3 * 2;
            for(long long j = 0; j < 8; j++)
            {
                long long chsr1 = j % 2, chsr2 = (j / 2) % 2, chsr3 = j / 4;
                long long chsx1 = a[chs1 + chsr1], chsy1 = a[chs1 + (!chsr1)];
                long long chsx2 = a[chs2 + chsr2], chsy2 = a[chs2 + (!chsr2)];
                long long chsx3 = a[chs3 + chsr3], chsy3 = a[chs3 + (!chsr3)];
                long long x = std::max(chsx1 + chsx2, chsx3);
                long long y = std::max(chsy1, chsy2) + chsy3;
                ans         = std::min(x * y, ans);
                x           = chsx1 + chsx2 + chsx3;
                y           = std::max(chsy1, std::max(chsy2, chsy3));
                ans         = std::min(x * y, ans);
            }
        }
        std::cout << ans << std::endl;
    }
    return 0;
}
