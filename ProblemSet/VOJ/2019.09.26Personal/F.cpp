//#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#define C(x) std::cout << #x << ":\t" << (x) << std::endl;
// int forgNumArry[100007];
// int singleForgIndex[100007];
char rawInput[100007];
int  inx[26][1007];
int  sqrt(int i)
{
    return i * i;
}
int main(void)
{
    int T, t = 0;

    // scanf("%d",&T);
    std::cin >> T;
    while(T--)
    {
        int ans          = 0xffffff;
        int inxCount[26] = { 0 };
        for(int i = 0; i < 26; i++)
        {
            inxCount[i] = 0;
        }
        // scanf("%d",&n);
        scanf_s("%s", rawInput, 100007);
        int n = strlen(rawInput);
        {
            int i = 0;
            do
            {
                int c               = (int) rawInput[i] - 'a';
                inx[c][inxCount[c]] = i;
                inxCount[c]++;
                // C(c);
                // C(inxCount[c]);
                // std::cout<<inxCount[c]<<std::endl;
                i++;
            } while(i != n);
        }
        for(int c = 0; c < 26; c++)
        {
            for(int i = 0; i < inxCount[c] - 1; i++)
            {
                ans = std::min(ans, (inx[c][i + 1] - inx[c][i]));
            }
        }
        if(ans == 0xffffff)
            ans = -1;
        {
            std::cout << "Case #" << ++t << ": " << ans << std::endl;
        }
    }

    return 0;
}