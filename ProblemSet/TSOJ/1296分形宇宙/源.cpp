#define _CRT_SECURE_NO_WARNINGS  // shut up MS//NOT fo CPP//scanf VS. scanf_s
//#define DEBUG
//#define InFile
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
int       n, a, b, j, k;
ULL       Qpow(ULL k, ULL n)
{
    ULL ans = 1;
    while(n)
    {
        if(n & 1)
        {
            ans *= k;
        }
        k *= k;
        n >>= 1;
    }
    return ans;
}
bool m[3][3] = { { 1, 0, 1 }, { 0, 1, 0 }, { 1, 0, 1 } };
bool fll(int x, int y, int stage)
{
    if(stage == 1)
    {
        return true;
    }
    else
    {
        ULL p = Qpow(3, stage - 2);
        return m[x / p][y / p] && fll(x % p, y % p, stage - 1);
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
        ULL side = Qpow(3, n - 1);
        for(size_t i = 0; i < side; i++)
        {
            for(size_t j = 0; j < side; j++)
            {
                if(fll(i, j, n))
                {
                    std::cout << 'X';
                }
                else
                {
                    std::cout << ' ';
                }
            }
            std::cout << std::endl;
        }
        std::cout << '-' << std::endl;
    }
#ifdef InFile
    system("pause");
    Sleep(-1);
#endif  // InFile
    return 0;
}
