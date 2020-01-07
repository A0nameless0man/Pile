#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <string.h>
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
int main(void)
{
    char m[10000];
    int  n;
    scanf("%d", &n);
    getchar();
    for(int i = 1; i < n; i++)
    {
        fgets(m, 10000, stdin);
        // m[strlen(m)] = '\0';
        strev(m);
        puts(m + 1);
    }
    fgets(m, 10000, stdin);
    // m[strlen(m)] = '\0';
    strev(m);
    puts(m);
    return 0;
}
