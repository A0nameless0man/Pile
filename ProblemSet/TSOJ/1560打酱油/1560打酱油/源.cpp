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
const int MAX_N = 10007;
int       n, m, a, b, j, k;
int       main(void)
{
#ifdef DEBUG
    std::fstream fin;
    fin.open("./in.txt", std::ios::in);
    std::cin.rdbuf(fin.rdbuf());
#endif  // DEBUG

    while(std::cin >> n)
    {
        n /= 10;
        int ans = 0;
        while(n >= 3)
        {
            if(n >= 5)
            {
                ans += 7;
                n -= 5;
            }
            else
            {
                if(n >= 3)
                {
                    ans += 4;
                    n -= 3;
                }
            }
        }
        ans += n;
        n = 0;
        cout << ans << std::endl;
    }
#ifdef DEBUG
    system("pause");
    Sleep(-1);
#endif  // DEBUG
    return 0;
}
