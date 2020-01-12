#include <iostream>
#include <string>
#include <vector>

short ctoi(const char &c)
{
    return islower(c) ? c - 'a' : c - 'A' + 26;
}

char itoc(const short &i)
{
    return i < 26 ? i + 'a' : i - 26 + 'A';
}

int                                  m, n;
std::vector<std::pair<short, short>> operate;
std::vector<std::vector<short>>      strings;

void decode(const short &x, const short &y)
{
    for(size_t i = 0; i < strings[y].size(); ++i)
    {
        strings[y][i] = (strings[y][i] + 52 - strings[x][i % strings[x].size()]) % 52;
    }
}

int main(void)
{
    while(std::cin >> n >> m)
    {
        operate.clear();
        strings.clear();
        strings.resize(n);
        for(int i = 0; i < m; ++i)
        {
            short x, y;
            std::cin >> x >> y;
            operate.emplace_back(x, y);
        }
        std::string inputbuf;
        for(int i = 0; i < n; ++i)
        {
            std::cin >> inputbuf;
            for(const auto &c: inputbuf)
            {
                strings[i].push_back(ctoi(c));
            }
        }
        for(auto p = operate.rbegin(); p != operate.rend(); ++p)
        {
            decode(p->first - 1, p->second - 1);
        }
        for(const auto &s: strings)
        {
            for(const auto &i: s)
            {
                std::cout << itoc(i);
            }
            std::cout << "\n";
        }
    }
    return 0;
}