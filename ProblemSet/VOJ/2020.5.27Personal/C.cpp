#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

const int MAX_N = 2e5 + 7;
const int MAX_H = 10;
char      buffer[MAX_N];
int       MinHeiByLen[MAX_N];
int       color[MAX_N];
int       rec[MAX_H];
int       maxLen = 0;

int main(void)
{
    int t;
    while(std::cin >> t)
    {
        for(int case_ = 0; case_ < t; ++case_)
        {
            int n;
            maxLen = 0;
            std::cin >> n;
            scanf("%s", buffer);
            for(int i = 0; i < n; ++i)
            {
                buffer[i] -= '0';
                color[i]       = 1;
                MinHeiByLen[i] = 0;
            }
            for(int i = 0; i < MAX_H; ++i)
            {
                rec[i] = 0;
            }
            MinHeiByLen[0] = buffer[0];
            for(int i = 0; i < n; ++i)
            {
                if(MinHeiByLen[0] > buffer[i])
                {
                    MinHeiByLen[0] = buffer[i];
                }
                else
                {
                    int l = 0;
                    int r = maxLen + 1;
                    while(l < r)
                    {
                        int mid = (l + r) / 2;
                        if(MinHeiByLen[mid] > buffer[i])
                        {
                            r = mid;
                        }
                        else
                        {
                            l = mid + 1;
                        }
                        // MinHeiByLen[mid] = buffer[i];
                    }
                    MinHeiByLen[l] = buffer[i];
                    maxLen         = std::max(maxLen, l);
                }
            }
            for(int i = 0; i < n; ++i)
            {
                printf("%d", MinHeiByLen[i]);
            }
            printf("\n");
        }
    }
}