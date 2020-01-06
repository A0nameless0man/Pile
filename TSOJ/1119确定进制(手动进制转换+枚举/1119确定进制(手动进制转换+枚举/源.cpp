#define _CRT_SECURE_NO_WARNINGS  // shut up MS
//#define DEBUG
#include <stdio.h>
//#include<stdio.h>
#include <algorithm>
#include <ctype.h>
#include <fstream>
#include <iostream>
#include <math.h>
#include <sstream>
#include <string.h>
#include <string>
// STL
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
// STL
#ifdef DEBUG
#    include <Windows.h>  //sleep()
#    include <stdlib.h>   //system("pause")
#endif                    // DEBUG

// template <typename T> void swap(T &a, T &b)
//{
//	T t = a;
//	a = b;
//	b = t;
//}
using namespace std;
using LL         = long long;
using ULL        = unsigned long long;
const int  MAX_N = 10007;
int        n, m, a, b, j, k;
const char ctoi[]     = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int  BUFFERSIZE = 512;
int        strcln(char *input)
{
    for(int i = 0; i < strlen(input); i++)
    {
        if(isalnum(input[i]))
        {
            input[i] = toupper(input[i]);
        }
        else
        {
            input[i] = '\0';
            break;
        }
    }
    return strlen(input);
}
int strturn(char *input)
{
    int inputlen = strlen(input);

    char temp[BUFFERSIZE];
    for(int i = 1; i <= inputlen; i++)
    {
        temp[i - 1] = input[inputlen - i];
    }
    temp[inputlen] = '\0';
    strcpy(input, temp);
    return inputlen;
}
int chartoint(char input, int max)
{
    for(int i = 0; i < strlen(ctoi) && i < max; i++)
    {
        if(input == ctoi[i])
            return i;
    }
    throw std::exception();
    return -1;
}
int strtoint(char *input, int decimal)
{
    int output   = 0;
    int inputlen = strlen(input);
    for(size_t i = 0; i < inputlen; i++)
    {
        output += pow(decimal, inputlen - i - 1) * chartoint(input[i], decimal);
    }
    return output;
}
void inttostr(int input, int decimal, char *output)
{
    char temp[BUFFERSIZE] = { 0 };
    for(size_t i = 0; pow(decimal, i) <= input; i++)
    {

        int a   = (int) (input % (int) (pow(decimal, i + 1)) / pow(decimal, i));
        temp[i] = ctoi[a];
    }
    strturn(temp);
    strcpy(output, temp);
}
int main(void)
{
#ifdef DEBUG
    std::fstream fin;
    fin.open("./in.txt", std::ios::in);
    std::cin.rdbuf(fin.rdbuf());
#endif  // DEBUG
    scanf("%d", &n);
    char p[BUFFERSIZE], q[BUFFERSIZE], r[BUFFERSIZE];
    while(n--)
    {
        scanf("%s%s%s", &p, &q, &r);
        for(int i = 1; i < 50; i++)
        {
            try
            {
                if(strtoint(p, i) * strtoint(q, i) == strtoint(r, i))
                {
                    cout << i << endl;
                    break;
                }
            }
            catch(const std::exception &)
            {
                continue;
            }
            if(i == 49)
            {
                cout << 0 << endl;
            }
        }
    }
#ifdef DEBUG
    system("pause");
    system("pause");
    Sleep(-1);
#endif  // DEBUG

    return 0;
}
