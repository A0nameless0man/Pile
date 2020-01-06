#include <cstdio>
#include <iostream>
using namespace std;
int n, q;
int servers[107];
int t, k, d;
int main()
{
    scanf("%d%d", &n, &q);
    while(q--)
    {
        scanf("%d%d%d", &t, &k, &d);
        int ser = 0;
        int sum = 0;
        for(int i = 1; i <= n; i++)
        {
            if(servers[i] < t)
                ser++;
        }
        if(ser >= k)
        {
            for(int i = 1; i <= n && k; i++)
            {
                if(servers[i] < t)
                {
                    servers[i] = t + d - 1;
                    k--;
                    sum += i;
                }
            }
            cout << sum << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}
