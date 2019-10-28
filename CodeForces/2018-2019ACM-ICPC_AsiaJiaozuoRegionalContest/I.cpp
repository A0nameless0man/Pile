#include <iostream>
#include <vector>
int main(void)
{
    int t;
    std::cin >> t;
    while (t--)
    {
        long long n;
        std::cin >> n;
        long long l = 1, r = 1, lsum = 0, rsum = 0, midSum = 0, sum = 0;
        std::vector<long long> dis;
        std::vector<long long> ans;
        dis.push_back(0); //dis[1] 1~2 dis[n-1] n-1~n
        for (int i = 0; i < n - 1; i++)
        {
            long long buf;
            std::cin >> buf;
            dis.push_back(buf);
            midSum += buf;
        }
        ans.push_back(0);
        ans.push_back(midSum);
        sum = midSum;
        for (int i = 2; i < n; i++)
        {
            if (i & 1)
            {
                lsum += l * dis[l];
                midSum -= dis[l];
                sum += lsum;
                sum += rsum + midSum * r;
                l++;
            }
            else
            {
                rsum += r * dis[n - r];
                midSum -= dis[n - r];
                sum += rsum;
                sum += lsum + l * (midSum);
                r++;
            }
            ans.push_back(sum);
        }
        for(int i = 0;i<n;i++)
        {
            std::cout<<ans[i];
            if (i != n - 1)
            {
                std::cout << " ";
            }
            else
            {
                std::cout << std::endl;
            }
        }
    }
}