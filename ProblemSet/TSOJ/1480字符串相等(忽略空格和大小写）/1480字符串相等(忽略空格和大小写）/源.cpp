#define _CRT_SECURE_NO_WARNINGS
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
const int MAX_LEN = 10007;
char      s[2][MAX_LEN];
void      clean(char in[])
{
    int i, j;
    i = j = 0;
    while(in[j] != '\n')
    {
        if(isalpha(in[j]))
        {
            in[i++] = tolower(in[j]);
        }
        j++;
    }
    in[i] = '\0';
}
int main(void)
{
    int n;
    scanf("%d", &n);
    getchar();
    while(n-- > 0)
    {
        fgets(s[0], MAX_LEN, stdin);
        fgets(s[1], MAX_LEN, stdin);
        clean(s[0]), clean(s[1]);
        printf("%s\n", strcmp(s[0], s[1]) == 0 ? "YES" : "NO");
    }
    return 0;
}
