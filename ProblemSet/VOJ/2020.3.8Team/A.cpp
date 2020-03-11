#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <vector>

long long gcd(long long a, long long b)
{
    if(a < b)
    {
        return gcd(b, a);
    }
    if(b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
long long mcl(long long a, long long b)
{
    return a * b / gcd(a, b);
}

int main(void)
{
    int side, cnt;

    while(std::cin >> side >> cnt)
    {
        std::map<std::string, int>      map;
        size_t                          atomCnt = 0;
        std::vector<std::map<int, int>> drugs;
        do
        {
            drugs.emplace_back();
            for(int i = 0; i < cnt; ++i)
            {
                std::string atom;
                int         atomNum;
                int         num;
                std::cin >> atom >> num;
                auto it = map.find(atom);
                if(it == map.end())
                {
                    map[atom] = atomCnt;
                    atomNum   = atomCnt;
                    ++atomCnt;
                }
                else
                {
                    atomNum = it->second;
                }
                ((*drugs.rbegin())[atomNum]) += num * side;
            }
        } while(std::cin >> side >> cnt, side != 0);
        // for(auto &drug: drugs)
        // {
        //     for(auto &p: drug)
        //     {
        //         std::cout << p.first << " " << p.second << ":";
        //     }
        //     std::cout << std::endl;
        // }
        // for(auto &p: map)
        // {
        //     std::cout << p.first << ":" << p.second << " ; ";
        // }
        // std::cout << std::endl;
        std::vector<std::vector<long long>> matrix;
        matrix.resize(atomCnt);
        for(auto &row: matrix)
        {
            row.resize(drugs.size());
        }
        for(size_t i = 0; i < drugs.size(); ++i)
        {
            for(auto &p: drugs[i])
            {
                matrix[p.first][i] = p.second;
            }
        }
#ifdef DEBUG
        for(auto &r: matrix)
        {
            for(auto &i: r)
            {
                std::cout << i << " ";
            }
            std::cout << "\n";
        }
        std::cout << "---------------------\n";
#endif
        for(size_t i = 0; i < drugs.size(); ++i)
        {
            {
                size_t max = i;
                for(size_t j = i + 1; j < atomCnt; ++j)
                {
                    if(std::abs(matrix[j][i]) > std::abs(matrix[max][i]))
                    {
                        max = j;
                    }
                }
                if(i != max)
                {
                    std::swap(matrix[i], matrix[max]);
                }
            }

            for(size_t j = i + 1; j < atomCnt; ++j)
            {
                long long g = gcd(std::abs(matrix[i][i]), std::abs(matrix[j][i]));
                if(g == 0 || matrix[j][i] == 0)
                {
                    continue;
                }
                long long a = matrix[i][i] / g;
                long long b = matrix[j][i] / g;
                for(size_t k = i; k < drugs.size(); ++k)
                {
                    matrix[j][k] *= a;
                    matrix[j][k] -= b * matrix[i][k];
                }
            }
#ifdef DEBUG
            for(auto &r: matrix)
            {
                for(auto &i: r)
                {
                    std::cout << i << " ";
                }
                std::cout << "\n";
            }
            std::cout << "----------------\n";
#endif
        }
#ifdef DEBUG

        for(auto &p: map)
        {
            std::cout << p.first << ":" << p.second << " ; ";
        }
        std::cout << std::endl;
        for(auto &r: matrix)
        {
            for(auto &i: r)
            {
                std::cout << i << " ";
            }
            std::cout << "--------------------\n";
        }
#endif
        std::vector<long long> ans;
        ans.resize(drugs.size());
        {
            bool empty = true;
            while(empty)
            {
                for(auto &i: matrix[matrix.size() - 1])
                {
                    if(i)
                    {
                        empty = false;
                    }
                }
                if(empty)
                {
                    matrix.pop_back();
                }
            }
            ans[drugs.size() - 1] -= matrix[matrix.size() - 1][drugs.size() - 2];
            ans[drugs.size() - 2] = matrix[matrix.size() - 1][drugs.size() - 1];
        }
        for(size_t i = atomCnt - 2, j = drugs.size() - 3; ~j && ~i; --i, --j)
        {
            while(matrix[i][j] == 0)
            {
                --i;
            }
            long long sum = 0;
            for(size_t k = j + 1; k < drugs.size(); ++k)
            {
                sum += ans[k] * matrix[i][k];
            }
            ans[j] -= (sum / matrix[i][j]);
        }
        for(auto &i: ans)
        {
            i = std::abs(i);
        }
        long long g = ans[0];
        for(auto &i: ans)
        {
            g = gcd(g, i);
        }
#ifdef DEBUG
        std::cout << "ans" << std::endl;
#endif
        for(auto &i: ans)
        {
            std::cout << i / g << " ";
        }
        std::cout << "\n";
    }
}