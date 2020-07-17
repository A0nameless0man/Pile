#include <algorithm>
#include <cstdio>
int time(void)
{
    int h, m, s;
    if(scanf("%d:%d:%d", &h, &m, &s) != EOF)
        return s + 60 * (m + 60 * h);
    else
    {
        return EOF;
    }
}

int main(void)
{
    int t1 = time();
    int t2 = time();
    printf("%d\n", std::abs(t2 - t1));
}
