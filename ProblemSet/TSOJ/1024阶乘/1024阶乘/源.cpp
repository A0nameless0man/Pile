#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
const int  BUFFER_SIZE = 256;
const char CtoI[]      = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int  DEM         = 10;
void       strset(char *input, char target)
{
    for(size_t i = strlen(input); i > 0; i--)
    {
        input[i - 1] = target;
    }
}
void strnset(char *input, char target, unsigned int i)
{
    for(; i > 0; i--)
    {
        input[i - 1] = target;
    }
}
int chartoint(char input, int max)
{
    for(int i = 0; i < strlen(CtoI) && i < max; i++)
    {
        if(input == CtoI[i])
            return i;
    }
    return 0;
}
bool charadd(char a, char b, char *c, bool jinwei)
{
    int d = chartoint(a, DEM) + chartoint(b, DEM);
    if(jinwei)
    {
        d += 1;
    }
    *c = CtoI[d >= DEM ? d - DEM : d];
    if(d >= DEM)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int strturn(char *input)
{
    int inputlen = strlen(input);

    char temp[BUFFER_SIZE];
    for(int i = 1; i <= inputlen; i++)
    {
        temp[i - 1] = input[inputlen - i];
    }
    temp[inputlen] = '\0';
    strcpy(input, temp);
    return inputlen;
}
void stradd(char *x, char *y, char *out)
{
    char a[BUFFER_SIZE] = { 0 }, b[BUFFER_SIZE] = { 0 };
    strcpy(a, x);
    strcpy(b, y);
    strset(out, '\0');

    bool jinwei = false;
    strturn(a);
    strturn(b);
    for(size_t i = 0; i < BUFFER_SIZE && ((a[i] != '\0' || b[i] != '\0') || jinwei == true); i++)
    {
        jinwei = charadd(a[i], b[i], out + i * sizeof(char), jinwei);
    }
    strturn(out);
}
int charmul(char a, char b, char *c, int jinwei)
{
    jinwei += chartoint(a, 10) * chartoint(b, 10);
    *c = CtoI[jinwei % DEM];
    return jinwei / DEM;
}
void strmul(char *x, char *y, char *out)
{
    char buffer[BUFFER_SIZE] = { 0 };
    int  jinwei              = 0;
    char a[BUFFER_SIZE] = { 0 }, b[BUFFER_SIZE] = { 0 };
    strcpy(a, x);
    strcpy(b, y);
    strset(out, '\0');
    strturn(a);
    strturn(b);
    for(size_t i = 0; i < BUFFER_SIZE && a[i] != '\0'; i++)
    {
        strnset(buffer, '0', i);
        for(size_t j = 0; j < BUFFER_SIZE && ((b[j] != '\0') || jinwei != 0); j++)
        {
            jinwei = charmul(a[i], b[j], buffer + j + i, jinwei);
        }
        strturn(buffer);
        stradd(buffer, out, out);
    }
}
int main(void)
{
    char a[BUFFER_SIZE] = "1", b[BUFFER_SIZE] = "0", c[BUFFER_SIZE] = "1";
    int  n = 0;
    while(scanf("%d", &n) != EOF)
    {
        for(size_t i = 0; i < n; i++)
        {
            stradd(b, c, b);
            strmul(a, b, a);
        }
        printf("%s\n", a);
        // 1025阶乘的位数
        // printf("%d\n",strlen(a));
        strset(a, '\0');
        strset(b, '\0');
        a[0] = '1';
        b[0] = '0';
    }
}