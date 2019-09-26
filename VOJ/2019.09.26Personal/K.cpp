#include <cstdio>
#include <iostream>
#include <algorithm>
int forgNumArry[100007];
int singleForgIndex[100007];
char rawInput[100007];
int sqrt(int i) { return i * i; }
int main(void)
{
    int T, t = 0;
    //scanf("%d",&T);
    std::cin >> T;
    while (T--)
    {
        int n;
        //scanf("%d",&n);
        scanf_s("%s", rawInput, 100007);
        char lastColour = rawInput[0];
        int lastColourCount = 0;
        int arryCount = 0;
        for (int i = 0; rawInput[i]; i++)
        {
            if (rawInput[i] == lastColour)
            {
                ++lastColourCount;
            }
            else
            {
                forgNumArry[arryCount++] = lastColourCount;
                lastColourCount = 1;
                lastColour = rawInput[i];
            }
        }
        forgNumArry[arryCount++] = lastColourCount;

        //Debug
        // {
        //     for (int i = 0; i < arryCount; i++)
        //     {
        //         printf("%d\n", forgNumArry[i]);
        //     }
        // }

        //caculate
        {
            int singleForgCount = 0;
            int bestAdd = 0;//-(0x7fffffff);

            //find single forg
            {

                for (int i = 0; i < arryCount; i++)
                {
                    if (forgNumArry[i] == 1)
                    {
                        singleForgIndex[singleForgCount++] = i;
                    }
                }
            }

            //figure best ans;
            {
                for (int i = 0; i < arryCount; i++)
                {
                    int left = i ? forgNumArry[i - 1] : 0;
                    int right = (i != arryCount - 1) ? forgNumArry[i + 1] : 0;
                    int mid = forgNumArry[i];
                    if (mid == 1)
                    {
                        bestAdd = std::max(bestAdd, sqrt(left + mid + right) - (sqrt(left) + sqrt(mid) + sqrt(right)));
                    }
                    else
                    {
                        bestAdd = std::max(bestAdd, sqrt(left + 1) + sqrt(mid - 1) - sqrt(left) - sqrt(mid));
                        bestAdd = std::max(bestAdd, sqrt(right + 1) + sqrt(mid - 1) - sqrt(right) - sqrt(mid));
                    }
                }
                int ans = 0;
                for (int i = 0; i < arryCount; i++)
                {
                    ans += sqrt(forgNumArry[i]);
                }
                std::cout << "Case #" << ++t << ": " << ans + bestAdd << std::endl;
            }
        }
    }
    return 0;
}