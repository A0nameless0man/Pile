#include <bit>
#include <cstdio>

const int MAX_N = 200;
const int MAX_K = 10;

int numbers[1 << MAX_K][MAX_N * 2];
int pairs[1 << MAX_K][2];

int main(void)
{
    int T;
    while(scanf("%d", &T) != EOF)
    {
        for(int id = 0; id < T; ++id)
        {
            int n, k;
            scanf("%d", &n);
            scanf("%d", &k);
            int curp = (1 << k) - 1;
            int curx = 1;
            int sum  = 0;
            while(true)
            {
                pairs[curp][curx]  = sum;
                pairs[curp][!curx] = sum + 1;
                sum += 2;
                if(curx)
                {
                    curp = (1 << k) - curp - 1;
                }
                else
                {
                    curp = std::bit_ceil(curp)
                           - (curp - std::bit_floor(curp));
                }
                curx ^= 1;
            }
#ifdef DEBUG
            for(int i = 0; i < (1 << k); ++i)
            {
                for(int j = 0; j < 2; ++j)
                {
                    printf("%5d", pairs[i][j]);
                }
                printf("\n");
            }
#endif  // DEBUG
        }
    }
}