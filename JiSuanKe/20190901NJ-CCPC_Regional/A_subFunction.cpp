//#include <algrithm>
#include <algorithm>
#include <iostream>
// ij
// 00 01 02 03 04
// 10 11 12 13 14
// 20 21 22 23 24
// 30 31 32 33 34
// 40 41 42 43 44
// n==5
// mid == 2
// dis == 2
// pos1 == 4
// pos0 == 0
int fun(int i, int j, int n)  //
{
    if(n & 1)
    {
        int mid          = n / 2;
        int dis          = std::max(std::abs(i - mid), std::abs(j - mid));
        int inSideSquare = dis * 2 - 1;
        int pos0         = mid - dis;
        int pos1         = mid + dis;
        int startFrom    = n * n - inSideSquare * inSideSquare;
        if(j >= i && i + j < n - 1)  //<
        {
            return startFrom - (pos1 - 1 - j);
        }
        else if(j < i && i + j < n - 1)  // v
        {
            return startFrom - (2 * dis - 1) - (i - pos0);
        }
        else if(j < i && i + j >= n - 1)  //>
        {
            return startFrom - (4 * dis - 1) - (j - pos0);
        }
        else if(j >= i && i + j >= n - 1)  //^
        {
            return startFrom - (6 * dis - 1) - (pos1 - i);
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}
int main(void)
{
    for(int n = 0; n < 10; n++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                std::cout << fun(i, j, n) << ' ';
            }
            std::cout << '\n';
        }
    }
    return 0;
}