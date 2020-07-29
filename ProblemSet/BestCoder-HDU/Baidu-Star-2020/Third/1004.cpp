#include <cstdio>
#include <iostream>
int main(void)
{
    int t;
    while(std::cin >> t)
    {
        for(int caseid = 0; caseid < t; ++caseid)
        {
            int n;
            int lasty[2] = { -1 };
            int x, y;
            int outer;
            std::cin >> n;
            lasty[0] = lasty[1] = -1;
            for(int i = 0; i < n; ++i)
            {
                std::cin >> x >> y;
                --x;
                if(y > lasty[x])
                {
                    lasty[x] = y;
                }
            }
            int innert = lasty[0] + 1;
            if(lasty[1] != -1)
            {

                outer = lasty[1] + 3;
                if(lasty[0] <= lasty[1])
                {
                    --outer;
                }
            }
            else
            {
                outer = 0;
            }

            if(outer > innert)
            {
                innert = outer;
            }
            printf("%d\n", innert);
        }
    }
}