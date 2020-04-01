#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

const int DIR[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };

int main(void)
{
    int T;
    while(std::cin >> T)
    {
        for(int t = 0; t < T; ++t)
        {
            std::vector<std::vector<int>> image;
            std::vector<std::vector<int>> block;
            std::vector<int>              adj;
            int                           m, n;
            bool                          found = false;
            std::cin >> m >> n;
            block.resize(m + 2, std::vector<int>(n + 2, -1));
            image.resize(m + 2);
            {
                for(int i = 0; i < n + 2; ++i)
                {
                    image[0].push_back(0);
                }
                std::string buf;
                for(int j = 1; j <= m; ++j)
                {
                    std::cin >> buf;
#ifdef DEBUG
                    if(buf.length() != n)
                    {
                        throw 0;
                    }
#endif  // DEBUG
                    image[j].push_back(0);
                    for(const auto &c: buf)
                    {
                        image[j].push_back(c - '0');
                    }
                    image[j].push_back(0);
                }
                for(int i = 0; i < n + 2; ++i)
                {
                    image[m + 1].push_back(0);
                }
                n += 2;
                m += 2;
            }
            {
                for(int i = 0; i < m; ++i)
                {
                    for(int j = 0; j < n; ++j)
                    {
                        if(block[i][j] == -1)
                        {
                            std::queue<std::pair<int, int>> que;
                            int                             num = adj.size();
                            que.push(std::make_pair(i, j));
                            adj.emplace_back(image[i][j]);
                            block[i][j] = num;
                            while(!que.empty())
                            {
                                auto cur = que.front();
                                que.pop();
                                for(int k = 0; k < 4; ++k)
                                {
                                    auto next =
                                      std::make_pair(cur.first + DIR[k][0], cur.second + DIR[k][1]);
                                    if(next.first >= 0 && next.first < m && next.second >= 0
                                       && next.second < n
                                       && image[next.first][next.second]
                                            == image[cur.first][cur.second]
                                       && block[next.first][next.second] == -1)
                                    {
                                        block[next.first][next.second] = num;
                                        que.push(next);
                                    }
                                }
                            }
                        }
                    }
                }
            }
            {
                // std::cout << adj.size() << std::endl;
                for(int curb = 0; curb < adj.size(); ++curb)
                {
                    if(adj[curb] == 1)
                    {
                        std::vector<std::vector<int>> cblock;
                        int                           cnt = 0;
                        cblock.resize(m, std::vector<int>(n, -1));
                        for(int i = 0; i < m; ++i)
                        {
                            for(int j = 0; j < n; ++j)
                            {
                                if(cblock[i][j] == -1)
                                {
                                    std::queue<std::pair<int, int>> que;
                                    int                             num = cnt;
                                    que.push(std::make_pair(i, j));
                                    cnt++;
                                    cblock[i][j] = num;
                                    while(!que.empty())
                                    {
                                        auto cur = que.front();
                                        que.pop();
                                        for(int k = 0; k < 4; ++k)
                                        {
                                            auto next = std::make_pair(cur.first + DIR[k][0],
                                                                       cur.second + DIR[k][1]);
                                            if(next.first >= 0 && next.first < m && next.second >= 0
                                               && next.second < n
                                               && (block[next.first][next.second] == curb)
                                                    == (block[cur.first][cur.second] == curb)
                                               && cblock[next.first][next.second] == -1)
                                            {
                                                cblock[next.first][next.second] = num;
                                                que.push(next);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if(cnt > 3)
                        {
                            found = true;
#ifdef DEBUG
                            std::cout << "Block " << curb << " is +1s" << std::endl;
                            std::cout << "Cblock" << std::endl;
                            for(int i = 0; i < m; ++i)
                            {
                                for(int j = 0; j < n; ++j)
                                {
                                    std::cout << cblock[i][j];
                                }
                                std::cout << '\n';
                            }
#endif  // DEBUG
                        }
                    }
                }
            }
            {
                if(found)
                {
                    std::cout << "+1s" << std::endl;
                }
                else
                {
                    std::cout << "I had seen this a lot." << std::endl;
                }
            }
#ifdef DEBUG
            {
                std::cout << "image" << std::endl;
                for(int i = 0; i < m; ++i)
                {
                    for(int j = 0; j < n; ++j)
                    {
                        std::cout << image[i][j];
                    }
                    std::cout << '\n';
                }
                std::cout << "block" << std::endl;
                for(int i = 0; i < m; ++i)
                {
                    for(int j = 0; j < n; ++j)
                    {
                        std::cout << block[i][j];
                    }
                    std::cout << '\n';
                }
            }
#endif  // DEBUG
        }
    }
    return 0;
}