#include <cstdio>
#include <iostream>
char input[1000007];
int  main(void)
{
    while(scanf("%s", input) != EOF)
    {
        long long ans = 0, sum = 0;
        int       i = 0;
        while(input[i] != '\0')
        {
            if(input[i] == 'a')
            {
                sum += 1 + sum;
            }
            else
            {
                ans += sum;
            }
            ans %= 1000000007;
            sum %= 1000000007;
            ++i;
        }
        // printf("%d\n", ans);
        std::cout << ans << std::endl;
    }
    return 0;
}