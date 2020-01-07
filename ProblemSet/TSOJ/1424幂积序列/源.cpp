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
int       n, m, a, b, j, k;
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
int main(void)
{
#ifdef InFile
    std::fstream fin;
    fin.open("./in.txt", std::ios::in);
    std::cin.rdbuf(fin.rdbuf());
#endif  // InFile

    while(std::cin >> n >> m)
    {
        std::vector<ULL> buffer;
        for(ULL i = 0; Qpow(2, i) <= n; i++)
        {
            ULL p = Qpow(2, i);
            for(ULL j = 0; p * Qpow(3, j) <= n; j++)
            {
                buffer.push_back(Qpow(2, i) * Qpow(3, j));
            }
        }
        std::sort(buffer.begin(), buffer.end());
        std::cout << buffer.size() << std::endl;
        std::cout << buffer[m - 1] << std::endl;
    }
#ifdef InFile
    system("pause");
    Sleep(-1);
#endif  // InFile
    return 0;
}
