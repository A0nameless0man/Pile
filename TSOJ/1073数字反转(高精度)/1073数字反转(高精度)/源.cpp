#define _CRT_SECURE_NO_WARNINGS
//#define DEBUG
#include <algorithm>
#include <ctype.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
template <typename T>
void swap(T &a, T &b)
{
    T t = a;
    a   = b;
    b   = t;
}
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
void output(char in[])
{
    bool miners = (in[0] == '-');
    strev(in + miners);
    if(miners)
    {
        putchar('-');
        in++;
    }
    while(*in == '0' && *(in + 1) != '\0')
        in++;
    while(*in != '\0')
        putchar(*in);
    putchar('\n');
}
const int MAX_N = 10007;
int       n, m, a, b, j, k;
char      buffer[MAX_N];
int       main(void)
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif  // DEBUG

    while(scanf("%s", buffer) != EOF)
    {
        output(buffer);
    }
#ifdef DEBUG
    system("pause");
    system("pause");
#endif  // DEBUG

    return 0;
}
