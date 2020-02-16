#include<iostream>
#include<cstdio>

int main(void)
{
    int n, t, c;
    while(std::cin>>n>>t>>c)
    {
        int cnt = 0;
        int ans = 0;
        for(int i = 0; i < n;++i)
        {
            int cm;
            scanf("%d", &cm);
            if(cm>t)
            {
                if(cnt>=c)
                {
                    ans += cnt - c + 1;
                }
                cnt = 0;
            }
            else
            {
                ++cnt;
            }
            
        }
        if(cnt >= c)
        {
            ans += cnt - c + 1;
        }
        std::cout << ans << std::endl;
    }
}