#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
long long a[200010], allwin, setwin, now, all, ans, ans2;
const int inf = 1e7;
int       main()
{
    int n, k, k2;
    cin >> n >> k;
    k2     = k;
    all    = -1;
    allwin = 0;
    setwin = 0;
    int i;
    for(i = 0; i < n; i++)
    {
        int aa;
        scanf("%d", &aa);
        if(aa < 0)
        {
            allwin++;
            // all++;
            setwin++;
            break;
        }
    }
    now = -1;
    for(i++; i < n; i++)
    {
        int aa;
        scanf("%d", &aa);
        if(aa >= 0)
        {
            if(now != 1)  //-1=1
            {
                all++;
                a[all]++;
                now = 1;
            }
            else
            {
                a[all]++;
            }
        }
        else
        {
            allwin++;
            if(now != -1)
            {  // 1=-1
                now = -1;
                setwin++;
            }
        }
    }
    // cout<<allwin<<" "<<all<<" "<<setwin<<endl;
    // input end
    // cout<<a[setwin]<<endl;
    if(all > 1)
        sort(a, a + setwin - 1);
    k -= allwin + a[setwin - 1];  // lefday
    // if (n == 200000)cout << k << ' ' ;
    if(k < 0)
        ans = inf;
    else
    {
        ans += 2 * setwin - 1;  //
        i = 0;
        while(k >= a[i] && i < setwin - 1)
        {
            // cout<<"K:"<<k<<"A[i]:"<<a[i]<<endl;
            k -= a[i];
            i++;
            ans -= 2;
        }
    }
    k2 -= allwin;
    // if (n == 200000)cout << k2 << ' ';

    if(k2 < 0)
        ans2 = inf;
    else
    {
        ans2 += 2 * setwin;
        i = 0;
        while(k2 >= a[i] && i < setwin - 1)
        {
            // cout<<"K2:"<<k2<<"A[i]:"<<a[i]<<endl;
            k2 -= a[i];
            i++;
            ans2 -= 2;
        }
    }
    // cout<<ans<<" "<<ans2<<endl;
    ans = min(ans, ans2);
    // if (n == 200000)cout << allwin << ' ' << ans << ' ' << ans2 << ' ';
    if(ans == inf)
        ans = -1;
    // if (n == 200000)cout << allwin << ' ';
    if(allwin == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << ans << endl;
    }
    return 0;
}
