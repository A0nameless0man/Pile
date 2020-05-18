#include <algorithm>
#include <iostream>

template <int n>
struct Matrix
{
    int       data[n][n] = { 0 };
    Matrix<n> operator+(const Matrix &rop) const
    {
        Matrix<n> ans;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                ans.data[i][j] = data[i][j] + rop.data[i][j];
            }
        }
        return ans;
    }
    Matrix<n> operator-(const Matrix &rop) const
    {
        Matrix<n> ans;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                ans.data[i][j] = data[i][j] - rop.data[i][j];
            }
        }
        return ans;
    }
    Matrix<n / 2> getSub(int side) const
    {
        int           mid = n / 2;
        Matrix<n / 2> ans;
        for(int i = 0; i < mid; ++i)
        {
            for(int j = 0; j < mid; ++j)
            {
                ans.data[i][j] = data[i + (side / 2) * mid][j + (side % 2) * mid];
            }
        }
        return ans;
    }
    void input(void)
    {
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                std::cin >> data[i][j];
            }
        }
    }
    void print(void)
    {
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    Matrix<n> operator*(const Matrix<n> &rop);
};

template <>
Matrix<2> Matrix<2>::operator*(const Matrix<2> &rop)
{
    {
        Matrix<2> ans;
        for(int i = 0; i < 2; ++i)
        {
            for(int j = 0; j < 2; ++j)
            {
                for(int k = 0; k < 2; ++k)
                {
                    ans.data[i][j] += data[i][k] * rop.data[k][j];
                }
            }
        }
        return ans;
    }
}
template <int n>
Matrix<n> Matrix<n>::operator*(const Matrix<n> &rop)
{
    auto      l11 = this->getSub(0);
    auto      l12 = this->getSub(1);
    auto      l21 = this->getSub(2);
    auto      l22 = this->getSub(3);
    auto      r11 = rop.getSub(0);
    auto      r12 = rop.getSub(1);
    auto      r21 = rop.getSub(2);
    auto      r22 = rop.getSub(3);
    auto      m1  = l11 * (r12 - r22);
    auto      m2  = (l11 + l12) * r22;
    auto      m3  = (l21 + l22) * r11;
    auto      m4  = l22 * (r21 - r11);
    auto      m5  = (l11 + l22) * (r11 + r22);
    auto      m6  = (l12 - l22) * (r21 + r22);
    auto      m7  = (l11 - l21) * (r11 + r12);
    auto      a11 = m5 + m4 - m2 + m6;
    auto      a12 = m1 + m2;
    auto      a21 = m3 + m4;
    auto      a22 = m5 + m1 - m3 - m7;
    Matrix<n> ans;
    int       mid = n / 2;
    for(int i = 0; i < mid; ++i)
    {
        for(int j = 0; j < mid; ++j)
        {
            ans.data[i][j] = a11.data[i][j];
        }
    }
    for(int i = 0; i < mid; ++i)
    {
        for(int j = 0; j < mid; ++j)
        {
            ans.data[i][j + mid] = a12.data[i][j];
        }
    }
    for(int i = 0; i < mid; ++i)
    {
        for(int j = 0; j < mid; ++j)
        {
            ans.data[i + mid][j] = a21.data[i][j];
        }
    }
    for(int i = 0; i < mid; ++i)
    {
        for(int j = 0; j < mid; ++j)
        {
            ans.data[i + mid][j + mid] = a22.data[i][j];
        }
    }
    return ans;
}

int main(void)
{
    Matrix<4> a, b;
    a.input();
    b.input();
    (a * b).print();
}