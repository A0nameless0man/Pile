#include <iostream>
using namespace std;
double jc[5010], dp1[5010], dp2[5010], p, temp;
int    n;
int    main()
{
    scanf("%d%lf", &n, &p);
    if(p == 0 || p == 1)
        printf("0.000000\n");
    else
    {
        jc[0] = 1;
        for(int i = 1; i <= n; i++)
        {
            jc[i] = jc[i - 1] * (1 - p);
        }
        dp1[1] = 0;
        dp2[1] = 1;
        for(int i = 2; i <= n; i++)
        {
            dp1[i] = i;
            dp2[i] = i;
            for(int j = 1; j < i; j++)
            {
                temp =
                  jc[j] * (dp1[i - j] + 1)
                  + (1 - jc[j]) * (dp2[i - j] + dp1[j] + 1);
                if(temp < dp1[i])
                    dp1[i] = temp;
            }
            for(int j = 1; j < i; j++)
            {
                temp =
                  jc[j] * (1 + dp2[i - j])
                  + (1 - jc[j]) * (1 + dp1[j] + dp2[i - j]);
                if(temp < dp2[i])
                    dp2[i] = temp;
            }
            temp = dp1[i] * (1 - jc[i]) + 1;
            if(temp < dp2[i])
                dp2[i] = temp;
        }
        printf("%.6lf\n", dp2[n]);
    }
    return 0;
}