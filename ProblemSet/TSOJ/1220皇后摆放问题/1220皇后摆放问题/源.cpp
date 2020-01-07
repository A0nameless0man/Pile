#define _CRT_SECURE_NO_WARNINGS  // shut up MS//NOT fo CPP//scanf VS. scanf_s
//#define DEBUG
#include <algorithm>
#include <ctype.h>
#include <fstream>   //file
#include <iostream>  //stream
#include <math.h>
#include <sstream>  //stringstream
#include <stdio.h>
#include <string.h>
#include <string>
// STL
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
// STL
#ifdef DEBUG
#    include <Windows.h>  //sleep()
#    include <stdlib.h>   //system("pause")
#endif                    // DEBUG

// template <typename T> void swap(T &a, T &b)
//{
//	T t = a;
//	a = b;
//	b = t;
//}
using namespace std;
using LL        = long long;
using ULL       = unsigned long long;
const int MAX_N = 8;
bool      row[MAX_N];
bool      column[MAX_N];
bool      rc[2 * MAX_N];
bool      cr[2 * MAX_N];
bool      conflict(int ro, int wo)
{
    return row[ro] || column[wo] || rc[ro + wo] || cr[7 + ro - wo];
}
void mark(int ro, int co)
{
    if(!conflict(ro, co))
    {
        row[ro]         = true;
        column[co]      = true;
        rc[ro + co]     = true;
        cr[7 + ro - co] = true;
    }
    else
    {
        throw std::exception();
    }
}
void unmark(int ro, int co)
{
    if(conflict(ro, co))
    {
        row[ro]         = false;
        column[co]      = false;
        rc[ro + co]     = false;
        cr[7 + ro - co] = false;
    }
    else
    {
        throw std::exception();
    }
}
vector<int> putableInRow(int ro)
{
    vector<int> ans;
    if(!row[ro])
    {
        for(size_t i = 0; i < 8; i++)
        {
            if(!conflict(ro, i))
            {
                ans.push_back(i);
            }
        }
    }
    return ans;
}
int dfs(int ro)
{
    if(ro == 7)
    {
        return putableInRow(ro).size();
    }
    else
    {
        if(row[ro])
        {
            return dfs(ro + 1);
        }
        else
        {
            int ans = 0;
            for(int i: putableInRow(ro))
            {
                mark(ro, i);
                ans += dfs(ro + 1);
                unmark(ro, i);
            }
            return ans;
        }
    }
}
int n, m, a, b, j, k;
int main(void)
{
#ifdef DEBUG
    std::fstream fin;
    fin.open("./in.txt", std::ios::in);
    std::cin.rdbuf(fin.rdbuf());
#endif  // DEBUG

    while(!std::cin.eof())
    {
        try
        {
            for(size_t i = 0; i < 8; i++)
            {
                for(size_t j = 0; j < 8; j++)
                {
                    cin >> k;
                    if(k == 1)
                    {
                        mark(i, j);
                    }
                }
            }
            cout << dfs(0) << endl;
        }
        catch(const std::exception &)
        {
            cout << 0 << endl;
        }
    }
#ifdef DEBUG
    system("pause");
    Sleep(-1);
#endif  // DEBUG
    return 0;
}
