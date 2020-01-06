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
using LL          = long long;
using ULL         = unsigned long long;
const int   MAX_N = 10007;
short       n, m, a, b, j, k;
inline bool check(short n)
{
    if(n > 0)
    {
        while(n != 0)
        {
            if(n % 10 == 4 || n % 10 == 2)
            {
                return false;
            }
            n /= 10;
        }
        return true;
    }
    else
    {
        return false;
    }
}
int main(void)
{
#ifdef DEBUG
    std::fstream fin;
    fin.open("./in.txt", std::ios::in);
    std::cin.rdbuf(fin.rdbuf());
#endif  // DEBUG
        // n = 0;
        // std::cout << "int nn[]={";
    while(std::cin >> n)
    {
        register int ans = 0;
        for(register short i = (n) / 3 + 1; i <= n - 3; i++)
        {
            if(check(i))
            {
                for(register short j = (n - i) / 2 + 1; j < i; j++)
                {
                    if(check(j))
                    {

                        int k = n - i - j;
                        if(check(j) && check(k))
                        {
                            ans++;
                            // std::cout << i << " " << k << " " << j << std::endl;
                        }
                    }
                }
            }
        }
        std::cout << ans << std::endl;
        // n++;
    }
    // std::cout <<"};"<< std::endl;
#ifdef DEBUG
    system("pause");
    Sleep(-1);
#endif  // DEBUG
    return 0;
}
