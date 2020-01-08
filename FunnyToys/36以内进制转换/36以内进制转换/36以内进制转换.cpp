#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
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
    while(true)
    {
        printf("输入数字和进制，以空格分隔。\n");
        char buffer[BUFFERSIZE] = "11";
        int  decimal            = 10;
        scanf("%s", buffer);
        scanf("%d", &decimal);
        strcln(buffer);
        int result = strtoint(buffer, decimal);
        printf("您输入的数字以十进制表示为%d\n", result);
        getchar();
        printf("请输入目标进制\n");
        scanf("%d", &decimal);
        inttostr(result, decimal, buffer);
        printf("结果是：\n%s", buffer);
        getchar();
        getchar();
    }
}