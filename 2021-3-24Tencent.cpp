#include <iostream>
#include <stack>
#include <tuple>

template <int T>
struct Status
{
    long double      prob[T][T];
    static Status<T> GetOne()
    {
        Status<T> res;
        for(int i = 0; i < T; ++i)
        {
            for(int j = 0; j < T; ++j)
            {
                res.prob[i][j] = (i == j ? 1.0 : 0.0);
            }
        }
        return res;
    }
    static Status<T> GetZero()
    {
        Status<T> res;
        for(int i = 0; i < T; ++i)
        {
            for(int j = 0; j < T; ++j)
            {
                res.prob[i][j] = 0.0;
            }
        }
        return res;
    }
    static Status<T> GetProb()
    {
        Status<T>   res = Status<T>::GetZero();
        long double DP[T / 2 + 1][T / 2 + 1];
        for(int i = 0; i <= T / 2; ++i)
        {
            for(int j = 0; j <= T / 2; ++j)
            {
                DP[i][j] = 0.0L;
            }
        }
        DP[0][0] = 1.0L;
        for(int i = 0; i <= T / 2; ++i)
        {
            for(int j = 0; j <= T / 2; ++j)
            {
                if(i != T / 2 && j != T / 2)
                {
                    DP[i + 1][j] += DP[i][j] / 2;
                    DP[i][j + 1] += DP[i][j] / 2;
                    res.prob[i][i + j] =
                      res.prob[T / 2 + j][i + j] =
                        DP[i][j] / 2;
                }
                else if(i == T / 2 && j != T / 2)
                {
                    DP[i][j + 1] += DP[i][j];
                    res.prob[T / 2 + j][i + j] = DP[i][j];
                }
                else if(i != T / 2 && j == T / 2)
                {
                    DP[i + 1][j] += DP[i][j];
                    res.prob[i][i + j] = DP[i][j];
                }
            }
        }
        return res;
    }
    void print()
    {
        for(int i = 0; i < T; ++i)
        {
            for(int j = 0; j < T; ++j)
            {
                // std::cout << prob[i][j] << " ";
                printf("%15.14Lf ", prob[i][j]);
            }
            std::cout << std::endl;
        }
    }
};

template <int T>
Status<T> shuffleOnce(const Status<T> &cur)
{
    static const Status<T> prob = Status<T>::GetProb();
    Status<T>              res  = Status<T>::GetZero();
    for(int i = 0; i < T; ++i)  // for every cur pos,
    {
        for(int j = 0; j < T; ++j)
        {
            for(int k = 0; k < T; ++k)
            {
                res.prob[i][j] +=
                  prob.prob[j][k] * (cur.prob[i][k]);
            }
        }
    }
    return res;
}

int main()
{
    Status<6> sta = Status<6>::GetOne();
    for(int i = 0; i < 10; ++i)
    {
        std::cout << "------------------------------- "
                  << i + 1
                  << "------------------------------- "
                  << std::endl;
        sta = shuffleOnce(sta);
        sta.print();
        std::cout << "-------------------------------"
                  << std::endl;
    }
    // Status<6>::GetProb().print();
}