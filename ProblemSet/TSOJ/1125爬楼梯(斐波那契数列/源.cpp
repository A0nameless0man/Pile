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
int       main(void)
{
#ifdef DEBUG
    std::fstream fin;
    fin.open("./in.txt", std::ios::in);
    std::cin.rdbuf(fin.rdbuf());
#endif  // DEBUG

    while(std::cin >> n)
    {
        unsigned long long a[2] = { 1, 1 };
        for(int i = 0; i < n; i++)
        {
            a[i % 2] += a[(i + 1) % 2];
        }
        std::cout << a[n % 2] << std::endl;
    }
#ifdef DEBUG
    system("pause");
    system("pause");
    Sleep(-1);
#endif  // DEBUG

    return 0;
}
