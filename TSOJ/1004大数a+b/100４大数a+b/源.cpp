#include <stdio.h>
#include <string.h>
const char ctoi[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
bool       jinwei = false;
int        chartoint(char input, int max)
{
    for(int i = 0; i < strlen(ctoi) && i < max; i++)
    {
        if(input == ctoi[i])
            return i;
    }
    return 0;
}
bool charadd(char a, char b, char *c, bool jinwei)
{
    int d = chartoint(a, 10) + chartoint(b, 10);
    if(jinwei)
    {
        d += 1;
    }
    *c = ctoi[d >= 10 ? d - 10 : d];
    if(d >= 10)
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

    char temp[410];
    for(int i = 1; i <= inputlen; i++)
    {
        temp[i - 1] = input[inputlen - i];
    }
    temp[inputlen] = '\0';
    strcpy(input, temp);
    return inputlen;
}
void stradd(char *a, char *b, char *out)
{
    strturn(a);
    strturn(b);
    // bool jinwei;
    for(size_t i = 0; i < 410 && (a[i] != '\0' || b[i] != '\0'); i++)
    {
        jinwei = charadd(a[i], b[i], out + i * sizeof(char), jinwei);
    }
    strturn(out);
}

int main(void)
{
    char a[4100] = { 0 };
    char b[4100] = { 0 };
    char c[4100] = { 0 };

    while(scanf("%s%s", a, b) != EOF)
    {
        jinwei = false;
        stradd(a, b, c);
        printf("%s\n", c);
    }
}