#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <vector>
/*
Time: 2020-01-23 11:16:23
Describe: Accepted with my code
Statue: ACCEPTED
*/
const long long MAX_N = 1e6 + 7;
char            buf[MAX_N];

int ctoi(char c)
{
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

std::vector<long double> prefix1, prefix2;

int main(void)
{
    {
        long double sum1 = 0;
        //, sum2 = 0;

        for(long long i = 1; i < MAX_N; i++)
        {
            sum1 += 1.0 / i;
            prefix1.push_back(sum1);
        }
    }
    while(scanf("%s", buf) != EOF)
    {
        char *           p = buf;
        std::vector<int> vec;
        while(*p)
        {
            vec.push_back(ctoi(*p));
            ++p;
        }
        long double cnt = 0;
        long long   sum = [](size_t n) -> long long {
            long long sum = 0;
            for(long long i = 1; i <= n; ++i)
            {
                long long da = i;  //* (n - i + 1);
                sum += da;
            }
            return sum;
        }(vec.size());
        long long n = vec.size();

        {
            prefix2.clear();
            long double sum2 = 0;
            for(int i = 1; i < n; ++i)
            {
                prefix2.push_back(sum2);
                sum2 += 1.0 * i / (n - i+1);
            }
        }
        for(long long i = 0; i < vec.size(); ++i)
        {
            // cnt += vec[i] * (i + 1) * (vec.size() - i);
            if(vec[i])
            {
                cnt += std::min(i + 1, n - i);  //[1,min(i,n-i+1) )
                cnt += (prefix1[std::max(i + 1, n - i) - 1] - prefix1[std::min(i + 1, n - i) - 1]) *
                       std::min(i + 1, n - i);  //[min ,max)
                cnt += prefix2[n - std::max(i + 1, n - i)];
            }
        }
        // std::cout << cnt << "/" << sum << std::endl;
        std::cout << std::setprecision(11)
                  << static_cast<long double>(cnt) / static_cast<long double>(sum) << std::endl;
    }
}