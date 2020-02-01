#include <iostream>
#include <map>
#include <vector>

const int        MAX_SN = 1e5;
bool             prime[MAX_SN];
std::vector<int> primes;
void             init(void)
{
    primes.clear();
    for(int i = 0; i < MAX_SN; ++i)
    {
        prime[i] = true;
    }
    for(int i = 2; i < MAX_SN; ++i)
    {
        if(prime[i])
        {
            primes.push_back(i);
            for(int j = 2; j * i < MAX_SN; ++j)
            {
                if(prime[i * j])
                {
                    prime[i * j] = false;
                }
            }
        }
    }
}
int f(long long n, long long na = 0, long long nb = 0)
{
    for(long long p = 2; p * p < n; ++p)
    {
        if(n % p == 0 && p != na && p != nb)
        {
            return p;
        }
    }
    return -1;
}
int main(void)
{
    init();
    int t;
    while(std::cin >> t)
        for(int i = 0; i < t; ++i)
        {
            long long n;
            std::cin >> n;
            long long a, b, c;
            a = f(n);
            if(a != -1)
            {
                b = f(n / a, a);
                c = n / (a * b);
            }
            else
            {
                b = c = -1;
            }
            if(b != -1 && a != c && b != c)
            {
                std::cout << "YES" << std::endl;
                std::cout << a << " " << b << " " << c << std::endl;
            }
            else
            {
                std::cout << "NO" << std::endl;
            }
        }
}