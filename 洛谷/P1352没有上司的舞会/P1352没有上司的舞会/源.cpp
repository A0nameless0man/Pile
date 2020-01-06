#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <string.h>
/*
��Ŀ����
ĳ��ѧ��N��ְԱ�����Ϊ1~N������֮���д�����ϵ��Ҳ����˵���ǵĹ�ϵ����һ����У��Ϊ�����������������ӽ���ֱ����˾�������и���������ᣬ���ÿ������һ��ְԱ��������һ���Ŀ���ָ��Ri�������أ����ĳ��ְԱ����˾���μ�����ˣ���ô���ְԱ���������Ҳ�������μ�����ˡ����ԣ������̼��㣬������ЩְԱ����ʹ����ָ����������Ŀ���ָ����

���������ʽ
�����ʽ��
��һ��һ������N��(1<=N<=6000)

������N�У���i+1�б�ʾi��ְԱ�Ŀ���ָ��Ri��(-128<=Ri<=127)

������N-1�У�ÿ������һ������L,K����ʾK��L��ֱ����˾��

���һ������0 0

�����ʽ��
������Ŀ���ָ����
*/
const int  MAX_N = 6007;
int        HappyPoint[MAX_N];
int        Boos[MAX_N][MAX_N];  //ÿ�ж�Ӧһ����˾��ÿ��Ԫ�ض�Ӧһ��ְԱ
int        Boosy[MAX_N];        //ÿ���˵�ֱ��������
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
