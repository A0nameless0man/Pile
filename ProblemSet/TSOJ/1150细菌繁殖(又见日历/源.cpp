#define _CRT_SECURE_NO_WARNINGS  // shut up MS
//#define DEBUG
#include <algorithm>
#include <ctype.h>
#include <fstream>
#include <iostream>
#include <math.h>
#include <sstream>
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
int       Mounth[13] = { 0, 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 };
int       main(void)
{
#ifdef DEBUG
    std::fstream fin;
    fin.open("./in.txt", std::ios::in);
    std::cin.rdbuf(fin.rdbuf());
#endif  // DEBUG
    for(size_t i = 1; i < 13; i++)
    {
        Mounth[i] += Mounth[i - 1];
    }
    while(std::cin >> n)
    {
        for(int i = 0; i < n; i++)
        {
            int a, b, c, d, e;
            std::cin >> a >> b >> c >> d >> e;
            int prev = b + Mounth[a];
            int aft  = e + Mounth[d];
            int diff = aft - prev;
            for(int i = 0; i < diff; i++)
            {
                c *= 2;
            }
            std::cout << c << std::endl;
        }
    }
#ifdef DEBUG
    system("pause");
    system("pause");
    Sleep(-1);
#endif  // DEBUG

    return 0;
}
