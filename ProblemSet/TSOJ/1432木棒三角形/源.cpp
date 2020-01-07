#define _CRT_SECURE_NO_WARNINGS  // shut up MS//NOT fo CPP//scanf VS. scanf_s
//#define DEBUG
//#define InFile
#include <algorithm>
#include <ctype.h>
#include <fstream>  //file
#include <iomanip>
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
#ifdef InFile
#    include <Windows.h>  //sleep()
#    include <stdlib.h>   //system("pause")
#endif                    // InFile
#ifdef DEBUG
#    define Check(X) std::cout << "Express \"" << #    X << "\" is " << (X) << std::endl
#else
#    define Check(X) ;
#endif
// template <typename T> void swap(T &a, T &b)
//{
//	T t = a;
//	a = b;
//	b = t;
//}
using namespace std;
using LL        = long long;
using ULL       = unsigned long long;
const int MAX_N = 10007;
int       n, m, a, b, j, k;
struct node
{
    int a, b;
};
bool operator<(const node &a, const node &b)
{
    return (a.a * a.b) < (b.a * b.b);
}
int isqrt(int n)
{
    int l = 1, r = n;
    while(l < r)
    {
        int mid = (l + r) / 2;
        if(mid * mid < n)
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    if(l * l == n)
    {
        return l;
    }
    else
    {
        return -1;
    }
}
int main(void)
{
#ifdef InFile
    std::fstream fin;
    fin.open("./in.txt", std::ios::in);
    std::cin.rdbuf(fin.rdbuf());
#endif  // InFile

    while(std::cin >> n)
    {
        std::set<int>             rawInput;
        std::priority_queue<node> que;
        for(int i = 0; i < n; i++)
        {
            int buf;
            std::cin >> buf;
            if(buf > 0)
            {
                rawInput.insert(buf);
            }
        }
        for(auto i = rawInput.begin(); i != rawInput.end(); i++)
        {
            for(auto j = rawInput.begin(); j != i; j++)
            {
                que.push(node({ *i, *j }));
            }
        }
        while(!que.empty())
        {
            if(rawInput.count(isqrt(que.top().a * que.top().a + que.top().b * que.top().b)) != 0)
            {
                std::cout << setiosflags(std::ios_base::fixed) << setprecision(3)
                          << (double) (que.top().a * que.top().b) / 2 << std::endl;
                break;
            }
            else
            {
                que.pop();
            }
        }
        if(que.empty())
        {
            std::cout << "No" << std::endl;
        }
    }
#ifdef InFile
    system("pause");
    Sleep(-1);
#endif  // InFile
    return 0;
}
