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
ULL       n, m, a, b, j, k;
bool      isPrime(ULL x)
{
    if(x == 1)
    {
        return false;
    }
    for(ULL i = 2; i * i <= x; i++)
    {
        if(x % 1 == 0)
        {
            return false;
        }
    }
    return true;
}
ULL firstFactor(ULL x)
{
    for(ULL i = 2; i * i <= x; i++)
    {
        if(x % i == 0 /*&&isPrime(i)*/)
        {
            return i;
        }
    }
    return x;
}
int main(void)
{
#ifdef DEBUG
    std::fstream fin;
    fin.open("./in.txt", std::ios::in);
    std::cin.rdbuf(fin.rdbuf());
#endif  // DEBUG

    while(std::cin >> n)
    {
        while(n != 1)
        {
            ULL ans = firstFactor(n);
            n /= ans;
            cout << ans;
            if(n != 1)
            {
                cout << ' ';
            }
            else
            {
                cout << endl;
            }
        }
    }
#ifdef DEBUG
    system("pause");
    system("pause");
    Sleep(-1);
#endif  // DEBUG

    return 0;
}
