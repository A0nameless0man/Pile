#include <cmath>
#include <iomanip>
#include <iostream>
#include <utility>
#include <vector>

std::vector<std::vector<int>>                    inputbuffer;
std::vector<std::vector<int>>                    edges;
std::vector<char>                                vis;
std::vector<std::pair<long double, long double>> ans;
std::vector<int>                                 tree_size;

int get_tree_size(int n)
{
    if(tree_size[n] != 0)
    {
        return tree_size[n];
    }
    int sum = 1;
    for(auto e: edges[n])
    {
        sum += get_tree_size(e);
    }
    tree_size[n] = sum;
    return sum;
}

void make_tree(int n = 0)
{
    vis[n] = true;
    for(auto e: inputbuffer[n])
    {
        if(!vis[e])
        {
            vis[e] = true;
            edges[n].push_back(e);
            make_tree(e);
        }
    }
}

void output(int n, long double from, long double to, long double curx, long double cury)
{
    long double step = (to - from) / (tree_size[n] - 1);
    for(auto e: edges[n])
    {
        long double nxx = curx + cos(from), nxy = cury + sin(from),
                    nxto = from + step * tree_size[e];
#ifdef DEBUG
        std::cout << "Point: " << e + 1 << " ";
        std::cout << std::setprecision(std::numeric_limits<long double>::digits10 + 1) << nxx << " "
                  << nxy << '\n';
#endif
        ans[e] = std::make_pair(nxx, nxy);
        output(e, from, nxto, nxx, nxy);
        from = nxto;
    }
}

int main(void)
{
    int n;
    while(std::cin >> n)
    {
        edges.resize(n);
        inputbuffer.resize(n);
        tree_size.resize(n);
        vis.resize(n);
        ans.resize(n);
        for(int i = 1; i < n; ++i)
        {

            int a, b;
            std::cin >> a >> b;
            --a, --b;
            inputbuffer[a].push_back(b);
            inputbuffer[b].push_back(a);
            vis[i] = false;
        }
        make_tree(0);
        get_tree_size(0);
        // std::cout << "0 0\n";
        ans[0] = std::make_pair(0.0L, 0.0L);
        output(0, 0.0, 3.14, 0.0, 0.0);
        for(auto p: ans)
        {
            std::cout << std::setprecision(std::numeric_limits<long double>::digits10 + 1)
                      << p.first << " " << p.second << '\n';
        }
    }
}
