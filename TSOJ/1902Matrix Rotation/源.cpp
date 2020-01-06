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
const int MAX_N = 20;
size_t    n, m, a, b, j, k;
long long matrix[MAX_N][MAX_N];
int       main(void)
{
#ifdef DEBUG
    std::fstream fin;
    fin.open("./in.txt", std::ios::in);
    std::cin.rdbuf(fin.rdbuf());
#endif  // DEBUG

    while(std::cin >> n)
    {
        for(size_t i = 0; i < n; i++)
        {
            for(size_t j = 0; j < n; j++)
            {
                cin >> matrix[i][j];
            }
        }
        cin >> k;
        a = k / 4;
        k %= 4;
        for(size_t i = 0; i < n; i++)
        {
            for(size_t j = 0; j < n; j++)
            {
                long long ans = 0;
                ans += a * (matrix[i][j] + matrix[j][n - i - 1] + matrix[n - i - 1][n - j - 1] +
                            matrix[n - j - 1][i]);
                switch(k)
                {
                    case 3:
                        ans += matrix[j][n - i - 1];
                    case 2:
                        ans += matrix[n - i - 1][n - j - 1];
                    case 1:
                        ans += matrix[n - j - 1][i];
                    case 0:
                        ans += matrix[i][j];
                    default:
                        break;
                }
                cout << ans;
                if(j == n - 1)
                {
                    cout << endl;
                }
                else
                {
                    cout << " ";
                }
            }
        }
    }
#ifdef DEBUG
    system("pause");
    Sleep(-1);
#endif  // DEBUG
    return 0;
}
