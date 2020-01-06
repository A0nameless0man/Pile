#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <string.h>
const int MAX_N = 10007;
int       TheNum[MAX_N];
int       NumLen;
void      read(void)
{
    char buffer;
    NumLen = 1;
    while((buffer = getchar()) != '\n')
    {
        TheNum[NumLen++] = buffer - '0';
    }
}
bool _3, _5, _8, _11;
bool Is3(void)
{
    int is3 = 0;
    for(int i = 0; i < NumLen; i++)
    {
        is3 += TheNum[i];
        is3 %= 3;
    }
    if(NumLen >= 2)
    {
        return _3 = (is3 == 0);
    }
    else
    {
        return _3 = (TheNum[0] % 3 == 0 && TheNum[0] != 0);
    }
}
bool Is5(void)
{
    return _5 = (((NumLen != 1) && (TheNum[NumLen - 1] == 0)) || (TheNum[NumLen - 1] == 5));
}
bool Is8(void)
{
    if(NumLen >= 3)
        return _8 =
                 ((TheNum[NumLen - 3] * 100 + TheNum[NumLen - 2] * 10 + TheNum[NumLen - 1]) % 8 ==
                  0);
    if(NumLen == 2)
    {
        return _8 = ((TheNum[NumLen - 2] * 10 + TheNum[NumLen - 1]) % 8 == 0);
    }
    if(NumLen == 1)
    {
        return _8 = (TheNum[NumLen - 1] == 8);
    }
    return _8 = false;
}
bool Is11(void)
{

    if(NumLen > 1)
    {
        int sum = TheNum[0];
        for(int i = 1; i < NumLen; i++)
        {
            sum = sum * 10 + TheNum[i];
            sum %= 11;
        }
        return _11 = (sum) == 0;
    }
    else
    {
        return _11 = false;
    }
}
int main(void)
{
    while((TheNum[0] = getchar()) != EOF)
    {
        TheNum[0] -= '0';
        read();
        _3 = _5 = _8 = _11 = false;
        Is3();
        Is5();
        Is8();
        Is11();
        if(_3 || _5 || _8 || _11)
        {
            puts("Yes");
        }
        else
        {
            puts("No");
        }
        int out[4];
        for(int i = 0; i < 4; i++)
        {
            out[i] = 0;
        }
        int k = 0;
        if(_3)
        {
            out[k++] = 3;
        }
        if(_5)
        {
            out[k++] = 5;
        }
        if(_8)
        {
            out[k++] = 8;
        }
        if(_11)
        {
            out[k++] = 11;
        }
        for(int i = 0; i < k; i++)
        {
            printf("%d", out[i]);
            if(i != k - 1)
            {
                putchar(' ');
            }
            else
            {
                putchar('\n');
            }
        }
    }

    return 0;
}
