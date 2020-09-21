// #include<iostream>
#include <cstdio>
int A[57][57];
int K[3][3];
int main(void)
{
    int T;
    // while(std::cin >> T){
    while(scanf("%d", &T) != EOF)
        for(int t = 0; t < T; ++t)
        {
            int  n   = 0;
            bool raw = true;
            scanf("%d", &n);
            for(int i = 0; i < n; ++i)
            {
                for(int j = 0; j < n; ++j)
                {
                    scanf("%d", &A[i][j]);
                }
            }
            scanf("%d", &K[0][0]);
            for(int i = 0; i < 8; ++i)
            {
                int k;
                scanf("%d", &k);
                if(k)
                {
                    raw = false;
                }
            }
            if(raw)
            {
                for(int i = 0; i < n; ++i)
                {
                    for(int j = 0; j < n; ++j)
                    {
                        printf("%d", A[i][j]);
                        if(j == n - 1)
                        {
                            printf("\n");
                        }
                        else
                        {
                            printf(" ");
                        }
                    }
                }
            }
            else
            {
                for(int i = 0; i < n; ++i)
                {
                    for(int j = 0; j < n; ++j)
                    {
                        printf("%d", 0);
                        if(j == n - 1)
                        {
                            printf("\n");
                        }
                        else
                        {
                            printf(" ");
                        }
                    }
                }
            }
        }
}