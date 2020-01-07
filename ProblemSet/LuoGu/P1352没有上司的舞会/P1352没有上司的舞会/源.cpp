#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <string.h>
/*
题目描述
某大学有N个职员，编号为1~N。他们之间有从属关系，也就是说他们的关系就像一棵以校长为根的树，父结点就是子结点的直接上司。现在有个周年庆宴会，宴会每邀请来一个职员都会增加一定的快乐指数Ri，但是呢，如果某个职员的上司来参加舞会了，那么这个职员就无论如何也不肯来参加舞会了。所以，请你编程计算，邀请哪些职员可以使快乐指数最大，求最大的快乐指数。

输入输出格式
输入格式：
第一行一个整数N。(1<=N<=6000)

接下来N行，第i+1行表示i号职员的快乐指数Ri。(-128<=Ri<=127)

接下来N-1行，每行输入一对整数L,K。表示K是L的直接上司。

最后一行输入0 0

输出格式：
输出最大的快乐指数。
*/
const int  MAX_N = 6007;
int        HappyPoint[MAX_N];
int        Boos[MAX_N][MAX_N];  //每行对应一个上司，每个元素对应一个职员
int        Boosy[MAX_N];        //每个人的直接下属数
bool       IsMaster[MAX_N];
int        Master;
int        N, bos, boy;
int        TreeDpNotInivte(int n);
int        TreeDpInVite(int n);
int        memDPin[MAX_N];
int        memDpnoin[MAX_N];
inline int max(int a, int b)
{
    return a > b ? a : b;
}
int TreeDpInVite(int n)
{
    if(memDPin[n] != -1)
    {
        return memDPin[n];
    }
    int HappyPointWithoutHim = 0;
    for(size_t i = 0; i < Boosy[n]; i++)
    {
        HappyPointWithoutHim += TreeDpInVite(Boos[n][i]);
        // HappyPointLose += HappyPoint[Boos[n][i]];
        // HappyPointLose -= TreeDp(Boos[n][i]);
    }
    int HappyPointWithHim = HappyPoint[n];
    for(size_t i = 0; i < Boosy[n]; i++)
    {
        HappyPointWithHim += TreeDpNotInivte(Boos[n][i]);
    }
    return memDPin[n] = max(HappyPointWithHim, HappyPointWithoutHim);
}
int TreeDpNotInivte(int n)
{
    if(memDpnoin[n] != -1)
    {
        return memDpnoin[n];
    }
    int HappyPointGain = 0;
    for(size_t i = 0; i < Boosy[n]; i++)
    {
        HappyPointGain += max(TreeDpInVite(Boos[n][i]), TreeDpNotInivte(Boos[n][i]));
    }
    return memDpnoin[n] = HappyPointGain;
}
int main(void)
{
    // freopen("testdata.in", "r", stdin);
    while(scanf("%d", &N) != EOF)
    {
        for(size_t i = 0; i <= N; i++)
        {
            HappyPoint[i] = 0;
            Boosy[i]      = 0;
            IsMaster[i]   = true;
        }
        for(size_t i = 1; i <= N; i++)
        {
            scanf("%d", &HappyPoint[i]);
        }
        for(size_t i = 0; i < N - 1; i++)
        {
            scanf("%d%d", &boy, &bos);
            Boos[bos][Boosy[bos]++] = boy;
            IsMaster[boy]           = false;
        }
        scanf("%*d%*d");
        for(size_t i = 0; i < N + 1; i++)
        {
            memDPin[i] = memDpnoin[i] = -1;
        }
        for(Master = 1; IsMaster[Master] != true; Master++)
            ;
        printf("%d\n", TreeDpInVite(Master));
    }
    return 0;
}
