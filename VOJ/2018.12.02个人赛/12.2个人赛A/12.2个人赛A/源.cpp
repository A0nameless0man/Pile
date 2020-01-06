#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
double    p;
int       n;
double    sum_a = 0;
const int MAX_N = 100007;
struct device
{
    double a;
    double b;
    double time;
};
device devices[MAX_N];
void   swap(device &a, device &b)
{
    device temp = a;
    a           = b;
    b           = temp;
    return;
}
void sort(int from, int to)
{
    if(from >= to)
    {
        return;
    }
    else
    {
        device mid = devices[(from + to) / 2];
        int    i = from, j = to;
        while(i < j)
        {
            while(devices[i].time < mid.time && i <= to)
            {
                i++;
            }
            while(devices[j].time > mid.time && j >= from)
            {
                j--;
            }
            swap(devices[i], devices[j]);
            i++;
            j--;
        }
        sort(from, j);
        sort(i, to);
    }
}
int main(void)
{
    while(scanf("%d%lf", &n, &p) != EOF)
    {
        sum_a = 0;
        for(size_t i = 0; i < n; i++)
        {
            scanf("%lf%lf", &devices[i].a, &devices[i].b);
            sum_a += devices[i].a;
            devices[i].time = (double) devices[i].b / devices[i].a;
        }
        if(sum_a <= p)
        {
            printf("-1\n");
        }
        else
        {
            sort(0, n - 1);
            sum_a        = 0;
            double sum_b = 0;
            for(size_t i = 0; i < n; i++)
            {
                sum_a += devices[i].a;
                sum_b += devices[i].b;
                if(sum_a > p &&
                   (i == n - 1 || (double) sum_b / (sum_a - p) < devices[i + 1].time * 1.0000001))
                {
                    printf("%f\n", (double) sum_b / (sum_a - p));
                    break;
                }
            }
        }
    }
}