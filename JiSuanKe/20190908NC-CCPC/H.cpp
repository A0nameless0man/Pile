#include <iostream>
using namespace std;
typedef long long int ll;
const ll mod = 998244353;
ll q, n;
typedef unsigned long long LL;
const int Len = 2;
struct Matrix
{
    LL num[Len][Len];
    Matrix(void)
    {
        ;
    }
    Matrix(const Matrix &o)
    {
        for (int i = 0; i < Len; i++)
            for (int j = 0; j < Len; j++)
                num[i][j] = o.num[i][j];
    }
    void operator*=(const Matrix &o)
    {
        LL temp[Len][Len];
        for (int i = 0; i < Len; i++)
            for (int j = 0; j < Len; j++)
                temp[i][j] = 0;
        for (int i = 0; i < Len; i++)
            for (int j = 0; j < Len; j++)
                for (int k = 0; k < Len; k++)
                {
                    temp[i][j] += num[i][k] * o.num[k][j]; //骷髅注意是自己的乘别人的
                    temp[i][j] %= mod;
                }
        for (int i = 0; i < Len; i++)
            for (int j = 0; j < Len; j++)
                num[i][j] = temp[i][j];
    }
};
void quickPower(Matrix base, LL exp, Matrix &res)
{
    res.num[0][0] = res.num[1][1] = 1;
    res.num[1][0] = res.num[0][1] = 0;
    while (exp)
    {
        if (exp & 1)
        {
            res *= base;
        }
        base *= base;
        exp >>= 1;
    }
    return;
}
Matrix a;
long long F(long long x)
{
    if (x)
    {
        Matrix res;
        quickPower(a, --x, res);
        return res.num[0][0];
    }
    else
    {
        return 0;
    }
}

int main(void)
{
    int k[2][2] = {3, 2, 1, 0};
    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 2; j++)
        {
            a.num[i][j] = k[i][j];
        }
    }
    long long q,n,ans=0,lastF,thisF;
    while(    std::cin>>q>>n)
    {
        while(q--)
        {
            thisF = F(n);
            ans^=thisF;
            lastF = thisF;  
            // if(n==(n^(lastF*lastF)))
            // {
            //     break;
            // }
            n = n^(lastF*lastF);
            //std::cout<<ans<<' '<<  (q&1) <<std::endl;
        }
        std::cout<<ans<<std::endl;
    }
}