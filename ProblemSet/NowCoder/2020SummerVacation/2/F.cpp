#include <iostream>
#include <stack>
#include <tuple>

const long long N = 5007;
long long       M[N][N];

int main(void)
{
    long long n, m, k;
    while(std::cin >> n >> m >> k)
    {
        {
            for(long long i = 1; i <= n; ++i)
            {
                for(long long j = 1; j <= m; ++j)
                {
                    M[i][j] = 0;
                }
            }
        }
        {
            for(long long i = 1; i <= n; ++i)
            {
                for(long long j = 1; j <= m; ++j)
                {
                    if(!M[i][j])
                    {
                        for(long long k = 1; k * i <= n && k * j <= m; ++k)
                        {
                            M[i * k][j * k] = i * j * k;
                        }
                    }
                }
            }
        }
#ifdef DEBUG
        std::cout << "raw\n";
        for(long long i = 1; i <= n; ++i)
        {
            for(long long j = 1; j <= m; ++j)
            {
                std::cout << M[i][j] << " ";
            }
            std::cout << std::endl;
        }
#endif  // DEBUG
        {
            for(long long j = 1; j <= m; ++j)
            {
                std::stack<std::tuple<long long, long long>> stack;
                for(long long i = 1; i <= n; ++i)
                {
                    while(!stack.empty() && i - std::get<1>(stack.top()) + 1 > k)
                    {
                        stack.pop();
                    }
                    if(stack.empty() || std::get<0>(stack.top()) < M[i][j])
                    {
                        stack.push(std::make_tuple(M[i][j], i));
                    }
                    M[i][j] = std::get<0>(stack.top());
                }
            }
        }
#ifdef DEBUG
        std::cout << "ver\n";
        for(long long i = 1; i <= n; ++i)
        {
            for(long long j = 1; j <= m; ++j)
            {
                std::cout << M[i][j] << " ";
            }
            std::cout << std::endl;
        }
#endif  // DEBUG
        {
            for(long long i = 1; i <= n; ++i)
            {
                std::stack<std::tuple<long long, long long>> stack;
                for(long long j = 1; j <= m; ++j)
                {
                    while(!stack.empty() && j - std::get<1>(stack.top()) + 1 > k)
                    {
                        stack.pop();
                    }
                    if(stack.empty() || std::get<0>(stack.top()) < M[i][j])
                    {
                        stack.push(std::make_tuple(M[i][j], j));
                    }
                    M[i][j] = std::get<0>(stack.top());
                }
            }
        }
#ifdef DEBUG
        std::cout << "hor\n";
        for(long long i = 1; i <= n; ++i)
        {
            for(long long j = 1; j <= m; ++j)
            {
                std::cout << M[i][j] << " ";
            }
            std::cout << std::endl;
        }
#endif  // DEBUG
        {
            long long sum = 0;
            for(long long i = k; i <= n; ++i)
            {
                for(long long j = k; j <= m; ++j)
                {
                    sum += M[i][j];
                }
            }
            std::cout << sum << std::endl;
        }
    }
}