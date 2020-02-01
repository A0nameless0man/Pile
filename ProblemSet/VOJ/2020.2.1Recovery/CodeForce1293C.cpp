#include <cstdio>
#include <iostream>

const int MAX_N = 1e5 + 7;

bool map[MAX_N][2];

bool checkGap(int q)
{
    return !((map[q][0] && map[q + 1][0]) || (map[q][1] && map[q + 1][1]));
}

int checkBlock(int q)
{
    return static_cast<int>(checkGap(q - 1)) + static_cast<int>(checkGap(q));
}

int main(void)
{
    int n, q;
    while(std::cin >> n >> q)
    {
        int blockCnt = 0;
        for(int i = 0; i < n + 3; ++i)
        {
            map[i][0] = map[i][1] = true;
        }
        for(int i = 0; i < q; ++i)
        {
            int r, c;
            scanf("%d%d", &r, &c);
            --r;
            int pastBlock  = checkBlock(c);
            map[c][r]      = !map[c][r];
            int afterBlock = checkBlock(c);
            blockCnt += afterBlock - pastBlock;
            if(blockCnt)
            {
                std::cout << "No\n";
            }
            else
            {
                std::cout << "Yes\n";
            }
            
        }
    }
    return 0;
}