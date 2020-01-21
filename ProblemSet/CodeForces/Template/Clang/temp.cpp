//#define DEBUG
//#define InFile
/*
User:$%U%$
Time:$%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctype.h>
#include <fstream>   //file
#include <iostream>  //stream
#include <sstream>   //stringstream
#include <string>
// STL
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
// STL
#ifdef InFile
#    include <cstdlib>  //system("pause")
#    include <thread>   //sleep()
#endif                  // InFile
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
int       main(void)
{
#ifdef InFile
    std::fstream fin;
    fin.open("./in.txt", std::ios::in);
    std::cin.rdbuf(fin.rdbuf());
#endif  // InFile

    while(std::cin >> n)
    {
        for(decltype(n) i = 0; i < n; ++i)
        {
            //
        }
    }
#ifdef InFile
    system("pause")
#endif  // InFile
      return 0;
}
