#define _CRT_SECURE_NO_WARNINGS
//#define DEBUG
#include <algorithm>
#include <ctype.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
template <typename T>
void swap(T &a, T &b)
{
    T t = a;
    a   = b;
    b   = t;
}
const int MAX_N = 107;
class bigint
{
public:
    bigint(long long);
    bigint()
    {
        bigint(0);
    }
    ~bigint();
    char  num[MAX_N];
    char  revnum[MAX_N];
    char *get(void)
    {
        strcpy(num, revnum);
        strev(num);
        return num;
    }
    bigint operator+(bigint b)
    {
        bigint r(0);
        int    len    = std::min(strlen(this->revnum), strlen(b.revnum));
        int    jinwei = 0;
        int    i      = 0;
        while(i < len)
        {
            r.revnum[i] = itoc(ctoi(this->revnum[i]) + ctoi(b.revnum[i]));
            i++;
        }
        if(strlen(this->revnum) > len)
        {
            strcpy(r.revnum + len, this->revnum + len);
        }
        else
        {
            strcpy(r.revnum + len, b.revnum + len);
        }
        i = 0;
        while(i < len || jinwei != 0)
        {
            if(r.revnum[i] == 0)
            {
                r.revnum[i] = '0';
            }
            r.revnum[i] += jinwei;
            jinwei      = ctoi(r.revnum[i]) / 10;
            r.revnum[i] = itoc(ctoi(r.revnum[i]) % 10);
            i++;
        }
        //	r.revnum[i] = 0;
        strcpy(r.num, r.revnum);
        strev(r.num);
        return r;
    }

    bigint operator*(int n)
    {
        bigint r(0);
        for(int i = 0; i < n; i++)
        {
            r = r + (*this);
        }
        return r;
    }

private:
    char *strev(char *input)
    {
        int inputlen = strlen(input);

        char temp[30000];
        for(int i = 1; i <= inputlen; i++)
        {
            temp[i - 1] = input[inputlen - i];
        }
        temp[inputlen] = '\0';
        strcpy(input, temp);
        return input;
    }
    inline int ctoi(char in)
    {
        return in - '0';
    }
    inline char itoc(int in)
    {
        return in + '0';
    }
};

bigint::bigint(long long in)
{
    memset(revnum, 0, MAX_N * sizeof(char));
    strcpy(num, std::to_string(in).c_str());
    strcpy(revnum, num);
    strev(revnum);
}

bigint::~bigint() {}
bigint pow(int a, int b)
{
    bigint r(1);
    for(int i = 0; i < b; i++)
    {
        r = r * a;
    }
    return r;
}
int    n, m, a, b, j, k;
bigint mem[MAX_N][MAX_N];

bigint p(int m, int n)
{
    if(mem[m][n].num[0] != 0)
    {
        return mem[m][n];
    }
    if(m == n || m == 1)
    {
        return bigint(1);
    }
    else
    {
        return mem[m][n] = p(m - 1, n - 1) + p(m, n - 1) * m;
    }
}
long long intp(int m, int n)
{
    if(m == n || m == 1)
    {
        return 1;
    }
    else
    {
        return intp(m - 1, n - 1) + m * intp(m, n - 1);
    }
}
int main(void)
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif  // DEBUG

    while(scanf("%d%d", &n, &m) != EOF)
    {
        if(n < m)
        {
            printf("0\n");
        }
        else
        {
            // bigint r(0);
            //	long long r = 0;
            //	for (int i = 1; i <= m; i++)
            //	{
            //		if ((m - i) % 2 == 0)
            //		{
            //			r = r + pow(i, n-1);
            //		}
            //		else
            //		{
            //			r = r - pow(i, n-1);
            //		}
            //	}
            for(int i = 0; i < MAX_N; i++)
            {
                for(int j = 0; j < MAX_N; j++)
                {
                    mem[i][j].num[0] = 0;
                }
            }
            printf("%s\n", p(m, n).get());
            // printf("%lld\n", intp(m,n));
        }
    }
#ifdef DEBUG
    system("pause");
    system("pause");
#endif  // DEBUG

    return 0;
}
