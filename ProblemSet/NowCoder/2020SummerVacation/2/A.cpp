#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

constexpr unsigned long long HASH_CONST_A = 12345678909827;
constexpr unsigned long long HASH_CONST_B = 19260817;
constexpr unsigned long long HASH_MOD     = 1ull << 63;
constexpr unsigned long long ANS_MOD      = 998244353;

std::vector<size_t> get_next_vector(const std::string &s)
{
    std::vector<size_t> next(s.length(), 0);
    size_t              j = 0;
    for(size_t i = 1; i < s.length(); ++i)
    {
        while(s.at(i) != s.at(j) && j != 0)
        {
            j = next.at(j-1);
            // j = next.at(j);
        }
        if(s.at(i) == s.at(j))
        {
            ++j;
        }
        next[i] = j;
    }
    return next;
}

unsigned long long suffixHash(char                      cur,
                              unsigned long long        last,
                              const unsigned long long &A,
                              const unsigned long long &B)
{
    return last + A * (cur + B);
}

unsigned long long prefixHash(char                      cur,
                              unsigned long long        last,
                              const unsigned long long &A,
                              const unsigned long long &B)
{
    return last * A + (cur + B);
}

int main(void)
{
    size_t n;
    while(std::cin >> n)
    {
        std::unordered_map<unsigned long long, unsigned long long> hashBucket;
        std::vector<std::string>                                   strings;
        {
            strings.clear();
            strings.resize(n);
            for(size_t i = 0; i < n; ++i)
            {
                std::cin >> strings[i];
            }
        }  // Input

        {
            for(const auto &s: strings)
            {
                unsigned long long A       = 1;
                unsigned long long curHash = 0;
                for(size_t i = s.length() - 1; ~i; --i)
                {
                    const auto c = s.at(i);
                    curHash      = suffixHash(c, curHash, A, HASH_CONST_B);
                    ++(hashBucket[curHash]);
                    A *= HASH_CONST_A;
                }
                // std::cout << curHash << std::endl;
            }
        }  // Hash
        {
            unsigned long long ans = 0;
            // unsigned long long sum = 0;
            for(const auto &s: strings)
            {
                std::vector<unsigned long long> cnt;
                auto                            next    = get_next_vector(s);
                unsigned long long              curHash = 0;
                for(const auto &c: s)
                {
                    curHash = prefixHash(c, curHash, HASH_CONST_A, HASH_CONST_B);
                    if(hashBucket.count(curHash))
                    {
                        cnt.push_back(hashBucket[curHash]);
                    }
                    else
                    {
                        cnt.push_back(0);
                    }
                }
                for(size_t i = 0; i < s.length(); ++i)
                {
                    // std::cout << cnt[i] << " ";
                    if(next[i] != 0)
                    {
                        cnt[next[i] - 1] -= cnt[i];
                    }
                }
                // std::cout << "\n";
                for(size_t i = 0; i < s.length(); ++i)
                {
                    // std::cout << cnt[i] << " ";
                    ans += ((((static_cast<unsigned long long>(i + 1))
                              * static_cast<unsigned long long>(i + 1))
                             % ANS_MOD)
                            * cnt[i])
                           % ANS_MOD;
                    ans %= ANS_MOD;
                    // sum += cnt[i];
                }
                // std::cout << "\n";
                // std::cout << "\n";
                // for(size_t i = 0; i < s.length(); ++i)
                // {
                // std::cout << next[i] << " ";
                // }
                // std::cout << "\n";

                // std::cout << curHash << std::endl;
            }
            std::cout << ans << std::endl;
            // std::cout << "sum: " << sum << std::endl;
        }
    }
}