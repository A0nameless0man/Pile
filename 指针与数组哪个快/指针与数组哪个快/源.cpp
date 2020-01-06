#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const int          MAX = 100000007;
unsigned short int a[MAX], b[MAX];
int                main(void)
{
    FILE *  f = fopen("out.txt", "w");
    clock_t start, end;
    float   pc = 0, ac = 0;
    a[0] = 0;
    b[0] = 0;
    for(size_t i = 0; i < MAX; i++)
    {
        a[i] = i;
        a[i] += i;
        a[i] *= i;
    }
    unsigned short int *p = b;
    for(size_t i = 0; i < MAX; i++)
    {
        *(p + i) = i;
        *(p + i) += i;
        *(p + i) *= i;
    }
    for(size_t j = 0; j < 100; j++)
    {
        start = clock();
        for(size_t i = 0; i < MAX; i++)
        {
            a[i] = i;
            a[i] += i;
            a[i] *= i;
        }
        end = clock();
        printf("a %f	", (float) (end - start) / CLOCKS_PER_SEC);
        fprintf(f, "%f	", (float) (end - start) / CLOCKS_PER_SEC);
        ac += (float) (end - start) / CLOCKS_PER_SEC;
        start = clock();

        for(size_t i = 0; i < MAX; i++)
        {
            *(p + i) = i;
            *(p + i) += i;
            *(p + i) *= i;
        }
        end = clock();
        printf("p %f\n", (float) (end - start) / CLOCKS_PER_SEC);
        fprintf(f, "%f\n", (float) (end - start) / CLOCKS_PER_SEC);
        pc += (float) (end - start) / CLOCKS_PER_SEC;
    }
    printf("ac %f	pc %f\n", ac, pc);
    fclose(f);
    // system("pause");
}